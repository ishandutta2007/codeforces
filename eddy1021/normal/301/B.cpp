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
#define N 111
LL n , d , a[ N ] , x[ N ] , y[ N ];
LL dst[ N ][ N ];
void init(){
  n = getint();
  d = getint();
  for( int i = 2 ; i < n ; i ++ )
    a[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      dst[ i ][ j ] = abs( x[ i ] - x[ j ] ) +
                      abs( y[ i ] - y[ j ] );
}
LL bst[ N ];
bool gt[ N ];
bool okay( LL st ){
  for( int i = 1 ; i <= n ; i ++ ){
    bst[ i ] = -INF16;
    gt[ i ] = false;
  }
  bst[ 1 ] = st;
  for( int _ = 0 ; _ < n ; _ ++ ){
    int now = -1;
    for( int i = 1 ; i <= n ; i ++ ){
      if( bst[ i ] < 0 ) continue;
      if( gt[ i ] ) continue;
      if( now == -1 or bst[ i ] > bst[ now ] )
        now = i;
    }
    if( now == n ) return true;
    if( now == -1 ) return false;
    gt[ now ] = true;
    for( int i = 1 ; i <= n ; i ++ ){
      if( gt[ i ] ) continue;
      LL vl = bst[ now ] + a[ now ] - d * dst[ now ][ i ];
      if( vl < 0 ) continue;
      bst[ i ] = max( bst[ i ] , vl );
    }
  }
  return bst[ n ] >= 0;
}
void solve(){
  LL bl = 0 , br = d * 400 , ba = br;
  while( bl <= br ){
    LL bm = (bl + br) >> 1;
    if( okay( bm ) )
      ba = bm , br = bm - 1;
    else
      bl = bm + 1;
  }
  cout << ba << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}