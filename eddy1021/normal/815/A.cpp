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
#define N 111
void build(){

}
int n , m , g[ N ][ N ];
vector<int> row , col;
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      g[ i ][ j ] = getint();
}
void Row(){
  for( int i = 1 ; i <= n ; i ++ ){
    int mn = g[ i ][ 1 ];
    for( int j = 1 ; j <= m ; j ++ )
      mn = min( mn , g[ i ][ j ] );
    int x = mn;
    while( x -- ) row.push_back( i );
    for( int j = 1 ; j <= m ; j ++ )
      g[ i ][ j ] -= mn;
    //printf( "%d %d\n" , i , mn );
  }
}
void Col(){
  for( int i = 1 ; i <= m ; i ++ ){
    int mn = g[ 1 ][ i ];
    for( int j = 1 ; j <= n ; j ++ )
      mn = min( mn , g[ j ][ i ] );
    int  x = mn;
    while( x -- ) col.push_back( i );
    for( int j = 1 ; j <= n ; j ++ )
      g[ j ][ i ] -= mn;
  }
}
void solve(){
  if( n < m ){
    Row();
    Col();
  }else{
    Col();
    Row();
  }
  int mx = 0;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      mx = max( mx , g[ i ][ j ] );
  if( mx > 0 ){
    puts( "-1" );
    return;
  }
  printf( "%d\n" , (int)row.size() + (int)col.size() );
  for( auto i : row )
    printf( "row %d\n" , i );
  for( auto i : col )
    printf( "col %d\n" , i );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}