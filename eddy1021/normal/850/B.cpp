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
#define N 2010101
void build(){

}
LL n , x , y , a[ N ] , c[ N ];
void init(){
  n = getint();
  x = getint();
  y = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    LL v = getint();
    c[ v ] ++;
    a[ v ] += v;
  }
  for( int i = 1 ; i < N ; i ++ ){
    c[ i ] += c[ i - 1 ];
    a[ i ] += a[ i - 1 ];
  }
}
bool np[ N ];
void solve(){
  LL ans = x * n;
  LL atmst = x / y;
  for( LL p = 2 ; p < N ; p ++ ) if( !np[ p ] ){
    for( LL j = p ; j < N ; j += p ) np[ j ] = true;
    LL tans = 0;
    for( LL j = p ; j < N ; j += p ){
      if( c[ j - p ] >= n ) break;
      { // delete
        LL bl = j - p + 1 , br = j - atmst - 1;
        if( bl <= br )
          tans += ( c[ br ] - c[ bl - 1 ] ) * x;
      }
      { // add
        LL bl = max( j - p + 1 , j - atmst ) , br = j;
        if( bl <= br ){
          LL cnt = c[ br ] - c[ bl - 1 ];
          tans += ( cnt * j - ( a[ br ] - a[ bl - 1 ] ) ) * y;
        }
      }
    }
    ans = min( ans , tans );
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}