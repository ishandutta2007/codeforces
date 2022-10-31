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
void build(){

}
int n , m , A , q;
void init(){
  n = getint();
  m = getint();
  A = getint();
  q = getint();
}
int mod;
int phi(){
  for( int i = 1 , cur = A ; ; i ++ ){
    if( cur == 1 ) return i;
    cur = mul( cur , A , q );
  }
}
#define N 1010101
int fac[ N ] , inv[ N ] , ifac[ N ];
int C( int a , int b ){
  if( a < b ) return 0;
  return mul( fac[ a ] , mul( ifac[ b ] , ifac[ a - b ] , mod ) , mod );
}
int a[ N ];
void solve(){
  mod = phi();
	inv[ 1 ] = 1;
	for( int i = 2 ; i < mod ; i ++ )
		inv[ i ] = ((LL)(mod - mod / i) * inv[mod % i]) % mod;
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( int i = 1 ; i < mod ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i , mod );
    ifac[ i ] = mul( ifac[ i - 1 ] , inv[ i ] , mod );
  }
  int s = 0;
  for( int i = n ; i >= max( 1 , n - m ) ; i -- ){
    s = add( s , C( m , n - i ) , mod );
    a[ i ] = mypow( A , s , q );
  }
  for( int i = n - m - 1 ; i >= 1 ; i -- )
    a[ i ] = a[ i + 1 ];
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}