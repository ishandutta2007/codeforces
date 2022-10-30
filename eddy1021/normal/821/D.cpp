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
#define N 10101
void build(){

}
int dst( int sn , int sm , int dn , int dm ){
  if( sn == dn ) return abs( sm - dm ) > 1;
  if( sm == dm ) return abs( sn - dn ) > 1;
  if( abs( sn - dn ) == 1 ) return 1;
  if( abs( sm - dm ) == 1 ) return 1;
  if( abs( sn - dn ) == 2 ) return 1;
  if( abs( sm - dm ) == 2 ) return 1;
  return -1;
}
int n , m , k;
int r[ N ] , c[ N ] , dp[ N ];
bool g[ N ];
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 0 ; i < k ; i ++ ){
    dp[ i ] = -1;
    r[ i ] = getint();
    c[ i ] = getint();
    if( r[ i ] == 1 and c[ i ] == 1 )
      dp[ i ] = 0;
  }
}
void solve(){
  for( int i = 0 ; i < k ; i ++ ){
    int who = -1;
    for( int j = 0 ; j < k ; j ++ )
      if( !g[ j ] and dp[ j ] != -1 ){
        if( who == -1 or dp[ j ] < dp[ who ] )
          who = j;
      }
    if( who == -1 ) break;
    g[ who ] = true;
    for( int j = 0 ; j < k ; j ++ ){
      int dd = dst( r[ who ] , c[ who ] , r[ j ] , c[ j ] );
      if( dd == -1 ) continue;
      dd += dp[ who ];
      if( dp[ j ] == -1 or dd < dp[ j ] )
        dp[ j ] = dd;
    }
  }
  int ans = -1;
  for( int i = 0 ; i < k ; i ++ ){
    if( dp[ i ] == -1 ) continue;
    int dd = dst( r[ i ] , c[ i ] , n , m );
    if( dd == -1 ) continue;
    if( ( r[ i ] != n or c[ i ] != m ) and dd == 0 )
      dd = 1;
    if( abs( r[ i ] - n ) >= 2 and
        abs( c[ i ] - m ) >= 2 )
      continue;
    dd += dp[ i ];
    if( ans == -1 or dd < ans )
      ans = dd;
  }
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