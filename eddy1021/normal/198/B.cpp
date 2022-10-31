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
#define N 101010
void build(){

}
int n , k;
char c[ 2 ][ N ];
void init(){
  n = getint();
  k = getint();
  scanf( "%s" , c[ 0 ] );
  scanf( "%s" , c[ 1 ] );
}
bool ok;
int dst[ 2 ][ N ];
bool vst[ 2 ][ N ];
void solve(){
  dst[ 0 ][ 0 ] = 0;
  vst[ 0 ][ 0 ] = true;
  queue< pair<int,int> > Q;
  Q.push( { 0 , 0 } ); while( Q.size() and not ok ){
    int id , x; tie( id , x ) = Q.front(); Q.pop();
    if( x + 1 > n ) ok = true;
    else if( not vst[ id ][ x + 1 ] and c[ id ][ x + 1 ] != 'X' ){
      vst[ id ][ x + 1 ] = true;
      dst[ id ][ x + 1 ] = dst[ id ][ x ] + 1;
      Q.push( { id , x + 1 } );
    }
    if( x - 1 >= 0 and
        dst[ id ][ x ] + 1 <= x - 1 and
        not vst[ id ][ x - 1 ] and
        c[ id ][ x - 1 ] != 'X' ){
      vst[ id ][ x - 1 ] = true;
      dst[ id ][ x - 1 ] = dst[ id ][ x ] + 1;
      Q.push( { id , x - 1 } );
    }
    if( x + k > n ) ok = true;
    else if( not vst[ 1 - id ][ x + k ] and c[ 1 - id ][ x + k ] != 'X' ){
      vst[ 1 - id ][ x + k ] = true;
      dst[ 1 - id ][ x + k ] = dst[ id ][ x ] + 1;
      Q.push( { 1 - id , x + k } );
    }
  }
  puts( ok ? "YES" : "NO" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}