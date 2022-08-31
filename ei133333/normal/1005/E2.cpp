#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;


struct BinaryIndexedTree {
  vector< int > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  int sum(int k) {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, int x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

struct SegmentTreeBIT {
  int sz;
  vector< BinaryIndexedTree > seg;
  vector< vector< int > > beet;

  SegmentTreeBIT(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    beet.resize(2 * sz - 1);
  }

  void update(int x, int y, int64 z) {
    x += sz - 1;
    seg[x].add(lower_bound(begin(beet[x]), end(beet[x]), y) - begin(beet[x]), z);
    while(x > 0) {
      x = (x - 1) >> 1;
      seg[x].add(lower_bound(begin(beet[x]), end(beet[x]), y) - begin(beet[x]), z);
    }
  }

  void build() {
    for(int k = beet.size() - 1; k >= 0; k--) {
      sort(begin(beet[k]), end(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
    }
    for(int k = 0; k < beet.size(); k++) {
      seg.emplace_back(BinaryIndexedTree(beet[k].size()));
    }
  }


  int64 query(int a, int b, int x, int k, int l, int r) {
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) {
      x = lower_bound(begin(beet[k]), end(beet[k]), x) - begin(beet[k]);
      return (seg[k].sum(x-1));
    }
    return (query(a, b, x, 2 * k + 1, l, (l + r) >> 1) + query(a, b, x, 2 * k + 2, (l + r) >> 1, r));
  }

  int64 query(int a, int b, int x) {
    return (query(a, b, x, 0, 0, sz));
  }


  void preupdate(int x, int y) {
    x += sz - 1;
    beet[x].push_back(y);
    while(x > 0) {
      x = (x - 1) >> 1;
      beet[x].push_back(y);
    }
  }

  void prequery(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      beet[k].push_back(y);
      beet[k].push_back(x);
      return;
    }
    prequery(a, b, x, y, 2 * k + 1, l, (l + r) >> 1);
    prequery(a, b, x, y, 2 * k + 2, (l + r) >> 1, r);
  }

  void prequery(int a, int b, int x, int y) {
    prequery(a, b, x, y, 0, 0, sz);
  }
};


int main() {
  int N, M, P[200000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    if(P[i] < M) P[i] = -1;
    else if(P[i] == M) P[i] = 0;
    else P[i] = 1;
  }
  int X = 0, Y = 0, Z = 0;

  int latte[202020], malta[202020];


  latte[0] = malta[0] = 0;
  for(int i = 1; i <= N; i++) {
    if(P[i - 1] == 1) ++Z;
    else if(P[i - 1] == 0) ++Y;
    else ++X;
    latte[i] = X + Y - Z;
    malta[i] = Z + Y - X;
  }

  SegmentTreeBIT seg(404040);
  const int shift = 202020;
  for(int i = 0; i <= N; i++) {
    seg.preupdate(latte[i] + shift, malta[i]);
  }
  seg.build();

  X = Y = Z = 0;
  seg.update(latte[0] + shift, malta[0], 1);
  int64 ret = 0;
  for(int i = 1; i <= N; i++) {
    if(P[i - 1] == 1) ++Z;
    else if(P[i - 1] == 0) ++Y;
    else ++X;
    ret += seg.query(0, X + Y - Z + shift + 1, Z + Y - X);
    seg.update(latte[i] + shift, malta[i], 1);
  }

  cout << ret << endl;

}