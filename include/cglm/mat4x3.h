/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT4X3_ZERO_INIT
   GLM_MAT4X3_ZERO

 Functions:
   CGLM_INLINE void  glm_mat4x3_make(float * restrict src, mat4x3 dest)
 */

#ifndef cglm_mat4x3_h
#define cglm_mat4x3_h

#include "common.h"

#define GLM_MAT4X3_ZERO_INIT {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT4X3_ZERO GLM_MAT4X3_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat4x3_copy(mat4x3 mat, mat4x3 dest) {
  dest[0][0] = mat[0][0];
  dest[0][1] = mat[0][1];

  dest[1][0] = mat[1][0];
  dest[1][1] = mat[1][1];

  dest[2][0] = mat[2][0];
  dest[2][1] = mat[2][1];

  dest[3][0] = mat[3][0];
  dest[3][1] = mat[3][1];
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat4x3_zero(mat4x3 mat) {
  CGLM_ALIGN_MAT mat4x3 t = GLM_MAT4X3_ZERO_INIT;
  glm_mat4x3_copy(t, mat);
}

/*!
 * @brief Create mat4x3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat4x3_make(float * __restrict src, mat4x3 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];

  dest[1][0] = src[3];
  dest[1][1] = src[4];
  dest[1][2] = src[5];

  dest[2][0] = src[6];
  dest[2][1] = src[7];
  dest[2][2] = src[8];

  dest[3][0] = src[9];
  dest[3][1] = src[10];
  dest[3][2] = src[11];
}

/*!
 * @brief multiply m1 and m2 to dest
 *
 * m1, m2 and dest matrices can be same matrix, it is possible to write this:
 *
 * @code
 * glm_mat4x3_mul(m, m, m);
 * @endcode
 *
 * @param[in]  m1   left matrix
 * @param[in]  m2   right matrix
 * @param[out] dest destination matrix
 */
CGLM_INLINE
void
glm_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat4 dest) {
  float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2],
        a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2],
        a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2],
        a30 = m1[3][0], a31 = m1[3][1], a32 = m1[3][2],

        b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2], b03 = m2[0][3],
        b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2], b13 = m2[1][3],
        b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2], b23 = m2[2][3];

  dest[0][0] = a00 * b00 + a01 * b10 + a02 * b20;
  dest[0][1] = a00 * b01 + a01 * b11 + a02 * b21;
  dest[0][2] = a00 * b02 + a01 * b12 + a02 * b22;
  dest[0][3] = a00 * b03 + a01 * b13 + a02 * b23;

  dest[1][0] = a10 * b00 + a11 * b10 + a12 * b20;
  dest[1][1] = a10 * b01 + a11 * b11 + a12 * b21;
  dest[1][2] = a10 * b02 + a11 * b12 + a12 * b22;
  dest[1][3] = a10 * b03 + a11 * b13 + a12 * b23;

  dest[2][0] = a20 * b00 + a21 * b10 + a22 * b20;
  dest[2][1] = a20 * b01 + a21 * b11 + a22 * b21;
  dest[2][2] = a20 * b02 + a21 * b12 + a22 * b22;
  dest[2][3] = a20 * b03 + a21 * b13 + a22 * b23;

  dest[3][0] = a30 * b00 + a31 * b10 + a32 * b20;
  dest[3][1] = a30 * b01 + a31 * b11 + a32 * b21;
  dest[3][2] = a30 * b02 + a31 * b12 + a32 * b22;
  dest[3][3] = a30 * b03 + a31 * b13 + a32 * b23;
}
#endif
