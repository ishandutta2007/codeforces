#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

struct Matrix
{
  int a[17][17];

  Matrix()
  {
    memset(a, 0, sizeof(a));
  }

  Matrix operator*(const Matrix &kj)
  {
    Matrix ret;
    for(int i = 0; i < 17; i++) {
      for(int j = 0; j < 17; j++) {
        unsigned long long st = 0;
        for(int k = 0; k < 17; k++) {
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
    for(int i = 0; i < 17; i++) ret.a[i][i] = 1;
    while(n > 0) {
      if(n & 1) ret = ret * x;
      x = x * x;
      n >>= 1;
    }
    return (ret);
  }
};

int main()
{
  int64 N, K;

  cin >> N >> K;


  vector< int > vect(17, 0);
  vect[0] = 1;

  int64 curr = 0;

  for(int i = 0; i < N; i++) {

    Matrix mat;
    int64 A, B, C;
    cin >> A >> B >> C;
    B = min(B, K);
    for(int j = 0; j <= C; j++) {
      for(int k = -1; k <= 1; k++) {
        int nk = j + k;
        if(nk < 0 || nk > C) continue;
        mat.a[j][nk] = 1;
      }
    }
    mat = mat ^ (B - curr);
    curr = B;
    vector< int > st(17, 0);
    for(int j = 0; j <= C; j++) {
      for(int k = 0; k <= C; k++) {
        (st[j] += 1LL * mat.a[k][j] * vect[k] % mod) %= mod;
      }
    }
    st.swap(vect);
  }

  cout << vect[0] << endl;
}