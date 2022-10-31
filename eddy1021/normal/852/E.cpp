// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
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
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
int n;
vector<int> v[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int a = getint();
    int b = getint();
    v[ a ].push_back( b );
    v[ b ].push_back( a );
  }
}
int dp[ N ];
vector<int> l[ N ] , r[ N ];
void go( int now , int prt ){
  int p = 1 , cc = 0;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    l[ now ].push_back( 1 );
    r[ now ].push_back( 1 );
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    go( son , now );
    p = mul( p , dp[ son ] );
    l[ now ][ i ] = dp[ son ];
    r[ now ][ i ] = dp[ son ];
    cc ++;
  }
  for( size_t i = 1 ; i < v[ now ].size() ; i ++ )
    l[ now ][ i ] = mul( l[ now ][ i ] , l[ now ][ i - 1 ] );
  for( int i = (int)v[ now ].size() - 2 ; i >= 0 ; i -- )
    r[ now ][ i ] = mul( r[ now ][ i ] , r[ now ][ i + 1 ] );
  if( cc == 0 )
    dp[ now ] = p;
  else
    dp[ now ] = add( p , p );
}
int ans;
void go2( int now , int prt , int up ){
  int tmp = mul( r[ now ][ 0 ] , up );
  int cur = mul( tmp , 2 );
  //printf( "now=%d prt=%d up=%d, tmp=%d, cur=%d\n",
          //now , prt , up , tmp , cur );
  ans = add( ans , cur );
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    int nxt = up;
    if( i ) nxt = mul( nxt , l[ now ][ i - 1 ] );
    if( i + 1 < v[ now ].size() ) nxt = mul( nxt , r[ now ][ i + 1 ] );
    if( now == prt and v[ now ].size() == 1 )
      nxt = 1;
    else
      nxt = add( nxt , nxt );
    go2( son , now , nxt );
  }
}
void solve(){
  go( 1 , 1 );
  go2( 1 , 1 , 1 );
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