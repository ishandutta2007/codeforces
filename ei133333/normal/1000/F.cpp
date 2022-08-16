#include <bits/stdc++.h>

using namespace std;

int lastupdate[500001];

struct SegmentTree {
  int sz;
  vector< vector< pair< int, int > > > seg;

  SegmentTree(int n) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.resize(2 * sz);
  }

  void add(int a, int b, int x, int y) {
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) seg[a++].emplace_back(x, y);
      if(b & 1) seg[--b].emplace_back(x, y);
    }
  }

  void sweep(int k) {
    while(seg[k].size() && lastupdate[seg[k].back().first] != seg[k].back().second) {
      seg[k].pop_back();
    }
  }

  int query(int k) {
    k += sz;
    int ans = 0;
    sweep(k);
    if(seg[k].size()) ans = seg[k].back().first;
    while(k >>= 1) {
      sweep(k);
      if(seg[k].size()) ans = seg[k].back().first;
    }
    return ans;
  }
};

int main() {
  int N, T[500000];
  int Q;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
  }
  scanf("%d", &Q);
  vector< pair< int, int > > querys[500000];
  for(int i = 0; i < Q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    querys[y].emplace_back(i, x);
  }
  vector< int > last(500001, -1), pv(N);
  for(int i = 0; i < N; i++) {
    pv[i] = last[T[i]];
    last[T[i]] = i;
  }

  vector< int > ans(Q);

  SegmentTree seg(N);

  // candidatei
  memset(lastupdate, -1, sizeof(lastupdate));
  for(int i = 0; i < N; i++) {
    seg.add(pv[i] + 1, i + 1, T[i], i);
    lastupdate[T[i]] = i;
    for(auto &p : querys[i]) {
      ans[p.first] = seg.query(p.second);
    }
  }
  for(int i = 0; i < Q; i++) {
    printf("%d\n", ans[i]);
  }
}