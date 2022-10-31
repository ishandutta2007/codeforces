// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
void build(){

}
LL s , x1 , x2;
LL t1 , t2 , p , d;
void init(){
  s = getint();
  x1 = getint();
  x2 = getint();
  t1 = getint();
  t2 = getint();
  p = getint();
  d = getint();
}
void solve(){
  LL ans = abs( x1 - x2 ) * t2;
  if( x2 > x1 ){
    x1 = s - x1;
    x2 = s - x2;
    p = s - p;
    d = -d;
  }
  LL el = 0;
  if( ( d == -1 && p < x1 ) ||
      ( d == 1 && p <= x2 && p < x1 ) ){
    if( d == -1 ){
      el += ( p + x1 ) * t1;
      el += ( s - x1 ) * t1;
      el += ( s - x2 ) * t1;
      ans = min( ans , el );
    }else{
      el += ( s - p + s - x2 ) * t1;
      ans = min( ans , el );
    }
  }else if( p < x2 ){
    if( d == -1 ){
      el += ( p + x2 ) * t1;
      ans = min( ans , el );
    }else{
      el = ( x2 - p ) * t1;
      ans = min( ans , el );
    }
  }else{
    if( d == -1 ){
      el = ( p - x2 ) * t1;
      ans = min( ans , el );
    }else{
      el = ( s - p + s - x2 ) * t1;
      ans = min( ans , el );
    }
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