#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair< int64, int64 > Pi;
const int64 INF = 1LL << 55;
struct SegmentTree{
  int n;
  vector< Pi > seg;
  void update(int id, int64 x){
    int i = id + n - 1;

    seg[i].first = x;
    seg[i].second = id;

    while(i > 0){
      i = ( i - 1 ) / 2;
      seg[i] = min( seg[i * 2 + 1], seg[i * 2 + 2]);
    }
  }
  Pi query( int a, int b, int k, int l, int r){
    if( r <= a || b <= l ) return Pi(INF, INF);
    if( a <= l && r <= b ) return seg[k];
    Pi vl = query( a, b, k * 2 + 1, l, (l + r) / 2);
    Pi vr = query( a, b, k * 2 + 2, (l + r) / 2, r);
    return min( vl, vr);
  }
  Pi query( int a, int b){
    return(query( a, b, 0, 0, n));
  }
  SegmentTree(const int& size){
    n = 1;
    while(n < size) n <<= 1;
    seg.assign(2 * n - 1, Pi(INF, INF));
  }
};

int main()
{
  int64 n, a[200000];
  cin >> n;
  SegmentTree seg(2 * n);
  for(int i = 0; i < n; i++) {
    int64 a;
    cin >> a;
    seg.update(i    , a);
    seg.update(i + n, a);
  }

  int64 ret = 0;
  for(int i = 0; i < n; i++) {
    int B = i, G = i + n;
    Pi rmq = seg.query(B, G);
    ret = max(ret, rmq.first * n + (rmq.second - B));
  }
  cout << ret << endl;
}
//24223
//24222
//14222
//13222
//13122
//13112
//13111
//03111
//02111
//01011
//01001
//00000