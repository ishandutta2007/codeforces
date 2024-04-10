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
LL n , a[ 3 ][ N ] , dp[ N ][ 4 ];
void init(){
  n = getint();
  for( int j = 0 ; j < 3 ; j ++ )
    for( int i = 1 ; i <= n ; i ++ )
      a[ j ][ i ] = getint();
}
inline LL sum( int col , int fr , int to ){
  if( fr > to ) swap( fr , to );
  LL ret = 0;
  for( int i = fr ; i <= to ; i ++ )
    ret += a[ i ][ col ];
  return ret;
}
void solve(){
  dp[ 0 ][ 0 ] = 0;
  dp[ 0 ][ 1 ] = -INF16;
  dp[ 0 ][ 2 ] = -INF16;
  dp[ 0 ][ 3 ] = -INF16;
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = 0 ; j < 4 ; j ++ )
      dp[ i ][ j ] = -INF16;
    for( int j = 0 ; j < 3 ; j ++ )
      for( int nj = 0 ; nj < 3 ; nj ++ )
        dp[ i ][ nj ] = max( dp[ i ][ nj ] ,
                             dp[ i - 1 ][ j ] + sum( i , j , nj ) );
    LL al = sum( i , 0 , 2 );
    for( int j : { 0 , 2 } ){
      dp[ i ][ 3 ] = max( dp[ i ][ 3 ] , dp[ i - 1 ][ j ] + al );
      dp[ i ][ j ] = max( dp[ i ][ j ] , dp[ i - 1 ][ 3 ] + al );
    }
  }
  printf( "%lld\n" , dp[ n ][ 2 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}