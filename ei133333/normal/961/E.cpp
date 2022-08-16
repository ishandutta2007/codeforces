#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

struct SegmentTreeFractionalCascading {
  vector< vector< int > > seg;
  vector< vector< int > > LL, RR;
  int sz;

  SegmentTreeFractionalCascading(vector< int > &array) {
    sz = 1;
    while(sz < array.size()) sz <<= 1;
    seg.resize(2 * sz - 1);
    LL.resize(2 * sz - 1);
    RR.resize(2 * sz - 1);
    for(int k = 0; k < array.size(); k++) {
      seg[k + sz - 1].emplace_back(array[k]);
    }
    for(int k = sz - 2; k >= 0; k--) {
      seg[k].resize(seg[2 * k + 1].size() + seg[2 * k + 2].size());
      LL[k].resize(seg[k].size() + 1);
      RR[k].resize(seg[k].size() + 1);
      merge(begin(seg[2 * k + 1]), end(seg[2 * k + 1]), begin(seg[2 * k + 2]), end(seg[2 * k + 2]), begin(seg[k]));
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < seg[k].size(); i++) {
        while(tail1 < seg[2 * k + 1].size() && seg[2 * k + 1][tail1] < seg[k][i]) ++tail1;
        while(tail2 < seg[2 * k + 2].size() && seg[2 * k + 2][tail2] < seg[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][seg[k].size()] = (int) seg[2 * k + 1].size();
      RR[k][seg[k].size()] = (int) seg[2 * k + 2].size();
    }
  }

  int query(int a, int b, int lower, int upper, int k, int l, int r) {
    if(a >= r || b <= l) {
      return (0);
    } else if(a <= l && r <= b) {
      return (upper - lower);
    } else {
      return (query(a, b, LL[k][lower], LL[k][upper], 2 * k + 1, l, (l + r) >> 1) + query(a, b, RR[k][lower], RR[k][upper], 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r) {
    l = lower_bound(begin(seg[0]), end(seg[0]), l) - begin(seg[0]);
    r = lower_bound(begin(seg[0]), end(seg[0]), r) - begin(seg[0]);
    return (query(a, b, l, r, 0, 0, sz));
  }
};

using int64 = long long;

int main() {
  int N;
  scanf("%d", &N);
  vector< int > A(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  SegmentTreeFractionalCascading seg(A);

  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    ret += seg.query(i + 1, min(N, A[i]), i + 1, 1 << 30);
  }
  cout << ret << endl;

}