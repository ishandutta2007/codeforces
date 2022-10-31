// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
ll mypow( ll _a , ll _x , ll _mod = mod7 ){
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
int __ = 1 , cs;
/*********default*********/
#define N 222222
int n;
vector<int> v[ N ];
int dp[ N ][ 2 ];
int ans[ N ];
vector<int> lft[ N ][ 2 ] , rgt[ N ][ 2 ];
void build(){

}
void init(){
  n = getint();
  for( int i = 2 ; i <= n ; i ++ ){
    int pi = getint();
    v[ pi ].PB( i );
  }
}
void DP( int now ){
  dp[ now ][ 0 ] = dp[ now ][ 1 ] = 1;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    DP( v[ now ][ i ] );
    lft[ now ][ 0 ].PB( dp[ now ][ 0 ] );
    lft[ now ][ 1 ].PB( dp[ now ][ 1 ] );
    dp[ now ][ 0 ] = mul( dp[ now ][ 0 ] , dp[ v[ now ][ i ] ][ 0 ] );
    dp[ now ][ 1 ] = mul( dp[ now ][ 1 ] , add( dp[ v[ now ][ i ] ][ 0 ] ,
                                                dp[ v[ now ][ i ] ][ 1 ] ) );
  }
  dp[ now ][ 0 ] = dp[ now ][ 1 ] = 1;
  for( int i = (int)v[ now ].size() - 1 ; i >= 0 ; i -- ){
    rgt[ now ][ 0 ].PB( dp[ now ][ 0 ] );
    rgt[ now ][ 1 ].PB( dp[ now ][ 1 ] );
    dp[ now ][ 0 ] = mul( dp[ now ][ 0 ] , dp[ v[ now ][ i ] ][ 0 ] );
    dp[ now ][ 1 ] = mul( dp[ now ][ 1 ] , add( dp[ v[ now ][ i ] ][ 0 ] ,
                                                dp[ v[ now ][ i ] ][ 1 ] ) );
  }
  reverse( ALL( rgt[ now ][ 0 ] ) );
  reverse( ALL( rgt[ now ][ 1 ] ) );
  debug( "%d : %d %d\n" , now , dp[ now ][ 0 ] , dp[ now ][ 1 ] );
}
void DP2( int now , int bns0 , int bns1 ){
  ans[ now ] = mul( add( bns0 , bns1 ) , dp[ now ][ 1 ] );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int tdp0 = mul( lft[ now ][ 0 ][ i ] , rgt[ now ][ 0 ][ i ] );
    int tdp1 = mul( lft[ now ][ 1 ][ i ] , rgt[ now ][ 1 ][ i ] );
    tdp0 = mul( tdp0 , bns0 );
    tdp1 = mul( tdp1 , add( bns0 , bns1 ) );
    debug( "%d %d\n" , tdp0 , tdp1 );
    DP2( v[ now ][ i ] , tdp0 , tdp1 );
  }
}
void solve(){
  DP( 1 );
  DP2( 1 , 1 , 0 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , ans[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}