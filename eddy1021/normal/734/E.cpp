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
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 202020
void build(){

}
int n , clr[ N ];
vector< int > v[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    clr[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    v[ ai ].push_back( bi );
    v[ bi ].push_back( ai );
  }
}
int dp[ N ];
vector< int > dpl[ N ] , dpr[ N ];
void go( int now , int prt ){
  dpl[ now ].resize( v[ now ].size() );
  dpr[ now ].resize( v[ now ].size() );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    dpl[ now ][ i ] = dpr[ now ][ i ] = 0;
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    go( son , now );
    if( clr[ now ] == clr[ son ] ){
      dpl[ now ][ i ] = dpr[ now ][ i ] = dp[ son ];
      dp[ now ] = max( dp[ now ] , dp[ son ] );
    }else{
      dpl[ now ][ i ] = dpr[ now ][ i ] = dp[ son ] + 1;
      dp[ now ] = max( dp[ now ] , dp[ son ] + 1 );
    }
  }
  for( size_t i = 1 ; i < dpl[ now ].size() ; i ++ )
    dpl[ now ][ i ] = max( dpl[ now ][ i ] , dpl[ now ][ i - 1 ] );
  for( int i = (int)dpr[ now ].size() - 2 ; i >= 0 ; i -- )
    dpr[ now ][ i ] = max( dpr[ now ][ i ] , dpr[ now ][ i + 1 ] );
}
int ans;
void go2( int now , int prt , int pdp ){
  ans = min( ans , max( dp[ now ] , pdp ) );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    int idp = pdp;
    if( i ) idp = max( idp , dpl[ now ][ i - 1 ] );
    if( i + 1 < v[ now ].size() )
      idp = max( idp , dpr[ now ][ i + 1 ] );
    if( clr[ now ] != clr[ son ] ) idp ++;
    go2( son , now , idp );
  }
}
void solve(){
  go( 1 , 1 );
  ans = n;
  go2( 1 , 1 , 0 );
  printf( "%d\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}