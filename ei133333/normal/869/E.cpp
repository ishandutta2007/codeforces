#include<bits/stdc++.h>

using namespace std;

struct BinaryIndexedTree
{
  vector< int > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  int sum(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret ^= data[k];
    return (ret);
  }

  void add(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] ^= x;
  }
};

struct SegmentTree2D
{
  vector< BinaryIndexedTree > add;
  vector< vector< int > > vs;
  int sz;

  SegmentTree2D(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    vs.resize(2 * sz - 1);
  }

  void set(int k, int height)
  {
    vs[k + sz - 1].push_back(height);
  }

  void build()
  {
    for(int k = sz - 1; k < vs.size(); k++) {
      sort(begin(vs[k]), end(vs[k]));
      vs[k].erase(unique(begin(vs[k]), end(vs[k])), end(vs[k]));
    }
    for(int k = sz - 2; k >= 0; k--) {
      vs[k].resize(vs[2 * k + 1].size() + vs[2 * k + 2].size());
      merge(begin(vs[2 * k + 1]), end(vs[2 * k + 1]),
            begin(vs[2 * k + 2]), end(vs[2 * k + 2]),
            begin(vs[k]));
    }
    for(int k = 0; k < vs.size(); k++) {
      add.emplace_back(BinaryIndexedTree(vs[k].size() + 1));
    }
  }

  inline int lb(int k, int height)
  {
    return (lower_bound(begin(vs[k]), end(vs[k]), height) - begin(vs[k]));
  }

  void update(int a, int b, int Low, int High, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) {
      return;
    } else if(a <= l && r <= b) {
      add[k].add(lb(k, Low), x);
      add[k].add(lb(k, High), x);
    } else {
      update(a, b, Low, High, x, 2 * k + 1, l, (l + r) >> 1);
      update(a, b, Low, High, x, 2 * k + 2, (l + r) >> 1, r);
    }
  }

  void update(int a, int b, int Low, int High, int x)
  {
    update(a, b, Low, High, x, 0, 0, sz);
  }

  int get(int k, int height)
  {
    k += sz - 1;
    int ret = add[k].sum(lb(k, height));
    while(k > 0) {
      k = (k - 1) >> 1;
      ret ^= add[k].sum(lb(k, height));
    }
    return (ret);
  }
};

int xor128(void)
{
  static int x = 123456789;
  static int y = 362436069;
  static int z = 521288629;
  static int w = 88675123;
  int t;

  t = x ^ (x << 11);
  x = y;
  y = z;
  z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main()
{
  int N, M, Q;
  int T[100000], A[100000], B[100000], C[100000], D[100000], R[100000];
  vector< int > xs;

  cin >> N >> M >> Q;
  map< tuple< int, int, int, int >, int > rd;
  for(int i = 0; i < Q; i++) {
    scanf("%d %d %d %d %d", &T[i], &A[i], &B[i], &C[i], &D[i]);
    if(T[i] <= 2) ++C[i], ++D[i];

    if(T[i] == 1) {
      R[i] = xor128();
      rd[make_tuple(A[i], B[i], C[i], D[i])] = R[i];
    } else if(T[i] == 2) {
      R[i] = rd[make_tuple(A[i], B[i], C[i], D[i])];
    }
  }

  SegmentTree2D tree(N + 1);
  for(int i = 0; i < Q; i++) {
    if(T[i] == 3) {
      tree.set(A[i], B[i]);
      tree.set(C[i], D[i]);
    }
  }
  tree.build();

  for(int i = 0; i < Q; i++) {
    if(T[i] == 3) {
      puts(tree.get(A[i], B[i]) == tree.get(C[i], D[i]) ? "Yes" : "No");
    } else {
      tree.update(A[i], C[i], B[i], D[i], R[i]);
    }
  }
}