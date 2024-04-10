// eddy1021
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
#define bye exit(0)
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
#define N 1021
void build(){

}
int n , m , w , p[ N ];
inline int f( int x ){
  return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
}
inline void uni( int x , int y ){
  p[ f( x ) ] = f( y );
}
int ww[ N ] , bb[ N ];
void init(){
  n = getint();
  m = getint();
  w = getint();
  for( int i = 1 ; i <= n ; i ++ )
    ww[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    bb[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
  while( m -- ){
    int ai = getint();
    int bi = getint();
    uni( ai , bi );
  }
}
vector< int > g[ N ];
int dp[ 2 ][ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    g[ f( i ) ].push_back( i );
  int lst = 0;
  for( int i = 1 ; i <= n ; i ++ ){
    if( g[ i ].empty() ) continue;
    int now = 1 - lst;
    for( int j = 0 ; j <= w ; j ++ )
      dp[ now ][ j ] = dp[ lst ][ j ];
    int sumw = 0 , sumb = 0;
    for( auto j : g[ i ] ){
      sumw += ww[ j ];
      sumb += bb[ j ];
      for( int k = w ; k >= ww[ j ] ; k -- )
        if( dp[ lst ][ k - ww[ j ] ] + bb[ j ] >
            dp[ now ][ k ] )
          dp[ now ][ k ] = dp[ lst ][ k - ww[ j ] ] + bb[ j ];
    }
    for( int j = w ; j >= sumw ; j -- )
      if( dp[ lst ][ j - sumw ] + sumb >
          dp[ now ][ j ] )
        dp[ now ][ j ] = dp[ lst ][ j - sumw ] + sumb;
    lst = now;
  }
  printf( "%d\n" , dp[ lst ][ w ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}