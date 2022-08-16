#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

struct Matrix
{
  int a[100][100];

  Matrix()
  {
    memset(a, 0, sizeof(a));
  }

  Matrix operator*(const Matrix &kj)
  {
    Matrix ret;
    for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
        unsigned long long st = 0;
        for(int k = 0; k < 100; k++) {
          st += 1LL * a[i][k] * kj.a[k][j];
          st %= mod;
        }
        ret.a[i][j] = st;

      }
    }
    return (ret);
  }

  Matrix operator^(long long n)
  {
    Matrix ret;
    Matrix x = *this;
    for(int i = 0; i < 100; i++) ret.a[i][i] = 1;
    while(n > 0) {
      if(n & 1) ret = ret * x;
      x = x * x;
      n >>= 1;
    }
    return (ret);
  }
};


int N, L, M, A[100], B[100], C[1000000], D[1000000];

int main()
{


  scanf("%d %d %d", &N, &L, &M);
  for(int i = 0, X; i < N; i++) scanf("%d", &X), ++A[X % M];
  for(int i = 0; i < N; i++) scanf("%d", &D[i]), ++B[D[i] % M];
  for(int i = 0; i < N; i++) scanf("%d", &C[i]), (C[i] += D[i]) %= M;


  Matrix mat;
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      mat.a[(i - j + M) % M][i] += B[j];
    }
  }

  mat = mat ^ (L - 2);

  int divide[100] = {};
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      (divide[(i + j) % M] += 1LL * mat.a[0][i] * A[j] % mod) %= mod;
    }
  }

  int ret = 0;
  for(int j = 0; j < N; j++) {
    (ret += divide[(M - C[j]) % M]) %= mod;
  }

  cout << ret << endl;
}