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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 111
void build(){

}
int n , m;
vector< int > v[ N ][ 26 ];
void init(){
  n = getint();
  m = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    char buf[ 8 ]; scanf( "%s" , buf );
    v[ ui ][ buf[ 0 ] - 'a' ].push_back( vi );
  }
}
bool win[ N ][ N ][ 26 ][ 2 ];
bool gt[ N ][ N ][ 26 ][ 2 ];
bool Win( int i , int j , int s , int who ){
  if( gt[ i ][ j ][ s ][ who ] ) return win[ i ][ j ][ s ][ who ];
  gt[ i ][ j ][ s ][ who ] = true;
  if( who == 0 ){
    for( int cc = s ; cc < 26 ; cc ++ )
      for( int nxt : v[ i ][ cc ] )
        if( !Win( nxt , j , cc , 1 - who ) )
          return win[ i ][ j ][ s ][ who ] = true;
  }else{
    for( int cc = s ; cc < 26 ; cc ++ )
      for( int nxt : v[ j ][ cc ] )
        if( !Win( i , nxt , cc , 1 - who ) )
          return win[ i ][ j ][ s ][ who ] = true;
  }
  return win[ i ][ j ][ s ][ who ] = false;
}
void solve(){
  for( int i = 1 ; i <= n ; i ++ , puts( "" ) )
    for( int j = 1 ; j <= n ; j ++ )
      if( Win( i , j , 0 , 0 ) )
        putchar( 'A' );
      else
        putchar( 'B' );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}