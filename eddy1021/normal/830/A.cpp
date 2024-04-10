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
#define N 2020
void build(){

}
LL n , k , p , a[ N ] , b[ N ];
void init(){
  n = getint();
  k = getint();
  p = getint();
  for( int i = 0 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 0 ; i < k ; i ++ )
    b[ i ] = getint();
  sort( a , a + n );
  sort( b , b + k );
}
LL dp[ 2 ][ N ];
void solve(){
  for( int i = 0 ; i < k ; i ++ )
    dp[ 0 ][ i ] = abs( a[ 0 ] - b[ i ] ) + abs( b[ i ] - p );
  for( int i = 1 ; i < n ; i ++ ){
    int now = i & 1 , pre = 1 - now;
    for( int j = 0 ; j < k ; j ++ )
      dp[ now ][ j ] = INF16;
    LL bst = INF16;
    for( int j = 0 ; j < k ; j ++ ){
      dp[ now ][ j ] = min( dp[ now ][ j ] ,
                            max( bst , abs( a[ i ] - b[ j ] ) + abs( b[ j ] - p ) ) );
      bst = min( bst , dp[ pre ][ j ] );
    }
  }
  LL ans = INF16;
  for( int j = 0 ; j < k ; j ++ )
    ans = min( ans , dp[ ( n - 1 ) & 1 ][ j ] );
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}