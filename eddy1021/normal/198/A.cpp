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
// k^n + k^{n-1} b + k^{n-2} b + ... + b
//       t * k^i b + k^{i-1} b + ... + b
inline LL bdr_mul( LL a , LL b , LL X ){
  if( a > X / b ) return X;
  return a * b;
}
inline LL pp( LL a , LL b ){
  if( b == 0 ) return 1;
  LL ret = pp( a , b / 2 );
  ret = bdr_mul( ret , ret , 1e14 );
  if( b & 1LL ) ret = bdr_mul( ret , a , 1e14 );
  return ret;
}
inline LL ppp( LL a0 , LL r , LL tn ){
  if( r == 1 ) return bdr_mul( a0 , tn , 1e14 );
  LL ret = bdr_mul( a0 , pp( r , tn ) - 1 , 1e14 );
  ret /= ( r - 1 );
  return ret;
}
LL k , b , n , t;
void init(){
  k = getint();
  b = getint();
  n = getint();
  t = getint();
}
void solve(){
  LL tmp = 1;
  for( LL i = 1 ; i <= n and tmp <= t ; i ++ )
    tmp = tmp * k + b;
  if( tmp <= t ){
    puts( "0" );
    Bye;
  }
  LL ans = n;
  if( t > b ){
    for( LL i = n - 1 ; i >= 1 ; i -- ){
      // k^n + k^{n-1} b + k^{n-2} b + ... +     k^i b + k^{i-1} b
      //                                         k^i t + k^{i-1} b
      // k^{n-i} + k^{n-1-i} b + k^{n-2-i} b + ... +     0
      //                                                 t - b
      LL dlt = t - b;
      LL ttt = pp( k , n - i );
      if( n - 1 - i >= 1 )
        ttt += bdr_mul( b , ppp( k , k , n - 1 - i ) , 1e14 );
      if( dlt >= ttt )
        ans = i;
    }
  }
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