#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

struct SegmentTree
{
  int n;
  vector< int > seg;

  void update( int k, int x)
  {
    k += n - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = min( seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  int query( int a, int b, int k, int l, int r)
  {
    if( r <= a || b <= l ) return INF;
    if( a <= l && r <= b ) return seg[k];
    int vl = query( a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query( a, b, k * 2 + 2, (l + r) / 2, r);
    return min( vl, vr);
  }
  int query( int a, int b)
  {
    return(query(a, b, 0, 0, n));
  }
  SegmentTree(const int& size)
  {
    n = 1;
    while(n < size) n *= 2;
    seg.assign(2 * n + 1, INF);
  }
};


int main()
{
  int N, D[100000];
  cin >> N;

  int ret = 0, left = 0;

  SegmentTree rmq1(N), rmq2(N);
  for(int i = 0; i < N; i++) {
    cin >> D[i];
    rmq1.update(i, D[i]);
    rmq2.update(i, -D[i]);
    while(left < i &&  
          (abs(rmq1.query(left, i) - D[i]) > 1 ||
          abs(-rmq2.query(left, i) - D[i]) > 1)) {
      ++left;
    }
    ret = max(ret, i - left + 1);
  }
  cout << ret << endl;
};