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
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 66
#define K 1021
int n , m , r;
ll d[ N ][ N ][ N ];
ll dp[ N ][ N ][ K ];
void build(){
  
}
void init(){
  n = getint(); m = getint(); r = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      dp[ i ][ j ][ 0 ] = INF16;
  for( int i = 0 ; i < m ; i ++ ){
    for( int j = 1 ; j <= n ; j ++ )
      for( int k = 1 ; k <= n ; k ++ )
        d[ i ][ j ][ k ] = getint();
    for( int u = 1 ; u <= n ; u ++ )
      for( int j = 1 ; j <= n ; j ++ )
        for( int k = 1 ; k <= n ; k ++ )
          if( d[ i ][ j ][ u ] + d[ i ][ u ][ k ] < d[ i ][ j ][ k ] )
            d[ i ][ j ][ k ] = d[ i ][ j ][ u ] + d[ i ][ u ][ k ];
    for( int j = 1 ; j <= n ; j ++ )
      for( int k = 1 ; k <= n ; k ++ )
        if( d[ i ][ j ][ k ] < dp[ j ][ k ][ 0 ] )
          dp[ j ][ k ][ 0 ] = d[ i ][ j ][ k ];
  }
}
inline void go_dp(){
  for( int rr = 1 ; rr <= n ; rr ++ )
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= n ; j ++ ){
        dp[ i ][ j ][ rr ] = dp[ i ][ j ][ rr - 1 ];
        for( int k = 1 ; k <= n ; k ++ )
          if( dp[ i ][ k ][ rr - 1 ] + dp[ k ][ j ][ 0 ] <
              dp[ i ][ j ][ rr ] ){
            dp[ i ][ j ][ rr ] =
              dp[ i ][ k ][ rr - 1 ] + dp[ k ][ j ][ 0 ];
          }
      }
}
void solve(){
  go_dp();
  while( r -- ){
    int si = getint();
    int ei = getint();
    int ki = getint();
    if( ki > n ) ki = n;
    printf( "%lld\n" , dp[ si ][ ei ][ ki ] );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}