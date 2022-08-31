#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct Matrix
{
  int a[2][2];

  Matrix operator+(const Matrix& kj)
  {
    Matrix ret;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        ret.a[i][j] = a[i][j] + kj.a[i][j];
        ret.a[i][j] %= mod;
      }
    }
    return (ret);
  }

  Matrix operator*(const Matrix& kj)
  {
    Matrix ret = Matrix::Zero();
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * kj.a[k][j]) % mod;
        }
      }
    }
    return (ret);
  }

  Matrix operator^(int n)
  {
    Matrix ret = Matrix::I();
    Matrix x = *this;
    while(n > 0) {
      if(n & 1) (ret = ret * x);
      x = x * x;
      n >>= 1;
    }
    return (ret);
  }

  static Matrix Zero()
  {
    Matrix ret;
    memset(ret.a, 0, sizeof(ret.a));
    return (ret);
  }

  static Matrix I()
  {
    Matrix ret;
    memset(ret.a, 0, sizeof(ret.a));
    for(int i = 0; i < 2; i++) ret.a[i][i] = 1;
    return (ret);
  }
};

struct SegmentTree
{
  vector< Matrix > seg, add;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, Matrix::Zero());
    add.assign(2 * sz - 1, Matrix::I());
  }

  void update(int a, int b, Matrix& x, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      add[k] = add[k] * x;
      return;
    }
    update(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    update(a, b, x, 2 * k + 2, (l + r) >> 1, r);
    seg[k] = seg[2 * k + 1] * add[2 * k + 1] + seg[2 * k + 2] * add[2 * k + 2];
  }

  Matrix query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (Matrix::Zero());
    if(a <= l && r <= b) return (seg[k] * add[k]);
    Matrix L = query(a, b, 2 * k + 1, l, (l + r) >> 1);
    Matrix R = query(a, b, 2 * k + 2, (l + r) >> 1, r);
    return (add[k] * (L + R));
  }

  void update(int a, int b, Matrix x)
  {
    update(a, b, x, 0, 0, sz);
  }

  int query(int a, int b)
  {
    return (query(a, b, 0, 0, sz).a[0][1]);
  }

  void set(int k, Matrix x)
  {
    seg[k + sz - 1] = x;
  }

  void build()
  {
    for(int i = sz - 2; i >= 0; i--) {
      seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
  }
};

int main()
{
  Matrix tt;
  tt.a[0][0] = 0;
  tt.a[1][0] = tt.a[0][1] = tt.a[1][1] = 1;

  int N, M;

  scanf("%d %d", &N, &M);

  SegmentTree tree(N);

  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    tree.set(i, tt ^ A);
  }
  tree.build();

  for(int i = 0; i < M; i++) {
    int type, l, r, x;
    scanf("%d", &type);
    if(type == 1) {
      scanf("%d %d %d", &l, &r, &x);
      tree.update(--l, r, tt ^ x);
    } else {
      scanf("%d %d", &l, &r);
      printf("%d\n", tree.query(--l, r));
    }
  }
}