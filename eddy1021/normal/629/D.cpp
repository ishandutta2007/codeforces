// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
#define MAX 10000000000000ll
struct Node{
  int l , r; ll vl;
  Node(){ l = r = vl = 0; }
}pool[ N * 52 ];
int pidx;
inline int newNode(){ return ++ pidx; }
inline void pull( int now ){
  pool[ now ].vl = max( pool[ pool[ now ].l ].vl , 
                        pool[ pool[ now ].r ].vl );
}
void modify( int now , ll l , ll r , ll p , ll tvl ){
  if( l == r ){
    pool[ now ].vl = max( pool[ now ].vl , tvl );
    return;
  }
  ll mid = ( l + r ) >> 1;
  if( p <= mid ){
    if( pool[ now ].l == 0 )
      pool[ now ].l = newNode();
    modify( pool[ now ].l , l , mid , p , tvl );
  }else{
    if( pool[ now ].r == 0 )
      pool[ now ].r = newNode();
    modify( pool[ now ].r , mid + 1 , r , p , tvl );
  }
  pull( now );
}
ll query( int now , ll l , ll r , ll ql , ll qr ){
  if( ql > qr ) return 0ll;
  if( now == 0 || l > qr || r < ql ) return 0ll;
  if( l >= ql && r <= qr ) return pool[ now ].vl;
  ll mid = ( l + r ) >> 1;
  return max( query( pool[ now ].l , l , mid , ql , qr ),
              query( pool[ now ].r , mid + 1 , r , ql , qr ) );
}
const LD PI = acosl( -1.0 );
void build(){

}
ll n , v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    ll r = getint();
    ll h = getint();
    v[ i ] = r * r * h;
  }
}
void solve(){
  int root = newNode();
  ll ans = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    ll tdp = query( root , 1 , MAX , 1 , v[ i ] - 1 );
    ll dp = tdp + v[ i ];
    ans = max( ans , dp );
    modify( root , 1 , MAX , v[ i ] , dp );
  }
  LD rans = (LD)ans * PI;
  printf( "%.12f\n" , (D)rans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}