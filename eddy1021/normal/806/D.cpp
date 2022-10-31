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
#define N 2222
void build(){

}
LL n , a[ N ][ N ] , mn;
void init(){
  n = getint();
  mn = INF16;
  for( int i = 1 ; i <= n ; i ++ ){
    for( int j = i + 1 ; j <= n ; j ++ ){
      a[ i ][ j ] = a[ j ][ i ] = getint();
      mn = min( mn , a[ i ][ j ] );
    }
    a[ i ][ i ] = INF16;
  }
}
LL ans[ N ] , bs;
bool vst[ N ];
void solve(){
  bs = ( n - 1 ) * mn;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      a[ i ][ j ] -= mn;
  for( int i = 1 ; i <= n ; i ++ ){
    ans[ i ] = INF16;
    for( int j = 1 ; j <= n ; j ++ )
      ans[ i ] = min( ans[ i ] , a[ i ][ j ] );
    ans[ i ] <<= 1;
  }
  for( int _ = 0 ; _ < n ; _ ++ ){
    int i = -1;
    for( int j = 1 ; j <= n ; j ++ )
      if( not vst[ j ] and ( i == -1 or ans[ j ] < ans[ i ] ) )
        i = j;
    for( int j = 1 ; j <= n ; j ++ )
      ans[ j ] = min( ans[ j ] , ans[ i ] + a[ i ][ j ] );
    vst[ i ] = true;
  }
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%lld\n" , ans[ i ] + bs );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}