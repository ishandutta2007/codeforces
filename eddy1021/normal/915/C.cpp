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
void build(){

}
LL a , b;
int len( LL x ){
  int ret = 0;
  while( x ){
    ret ++;
    x /= 10;
  }
  return ret;
}
void init(){
  cin >> a >> b;
}
int cnt[ 10 ] , vl[ 20 ] , tl , vv[ 20 ];
void go( int at , bool bnd ){
  if( at < 0 ){
    for( int i = tl - 1 ; i >= 0 ; i -- )
      putchar( vv[ i ] + '0' );
    puts( "" );
    Bye;
  }
  int st = bnd ? vl[ at ] : 9;
  for( int i = st ; i >= 0 ; i -- )
    if( cnt[ i ] ){
      cnt[ i ] --;
      vv[ at ] = i;
      go( at - 1 , bnd ? i == st : false );
      cnt[ i ] ++;
    }
}
void solve(){
  {
    LL tmp = a;
    while( tmp ){
      cnt[ tmp % 10 ] ++;
      tmp /= 10;
    }
  }
  if( len( a ) < len( b ) ){
    for( int i = 9 ; i >= 0 ; i -- )
      while( cnt[ i ] -- )
        putchar( i + '0' );
    puts( "" );
    Bye;
  }
  tl = len( a );
  for( int i = 0 ; i < tl ; i ++ ){
    vl[ i ] = b % 10;
    b /= 10;
  }
  go( tl - 1 , true );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}