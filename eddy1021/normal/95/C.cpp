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
#define N 1021
void build(){

}
int n , m , x , y;
vector< pair<int,int> > v[ N ];
LL t[ N ] , c[ N ];
void init(){
  n = getint();
  m = getint();
  x = getint();
  y = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    int wi = getint();
    v[ ui ].push_back( { vi , wi } );
    v[ vi ].push_back( { ui , wi } );
  }
  for( int i = 1 ; i <= n ; i ++ ){
    t[ i ] = getint();
    c[ i ] = getint();
  }
}
LL dst[ N ][ N ];
int stmp[ N ];
void sp( int now ){
typedef pair<LL,int> PLI;
  priority_queue< PLI , vector<PLI> , greater<PLI> > heap;
  heap.push( { 0 , now } );
  while( heap.size() ){
    LL td; int cur;
    tie( td , cur ) = heap.top(); heap.pop();
    if( td > t[ now ] ) return;
    if( stmp[ cur ] == now ) continue;
    dst[ now ][ cur ] = td;
    stmp[ cur ] = now;
    for( auto j : v[ cur ] ){
      if( stmp[ j.first ] == now ) continue;
      heap.push( { td + j.second , j.first } );
    }
  }
}
LL ans[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      dst[ i ][ j ] = INF16;
  for( int i = 1 ; i <= n ; i ++ )
    sp( i );
  for( int i = 1 ; i <= n ; i ++ )
    ans[ i ] = INF16;
  ans[ x ] = 0;
  for( int _ = 1 ; _ <= n ; _ ++ ){
    int bst = -1;
    for( int i = 1 ; i <= n ; i ++ ){
      if( stmp[ i ] == -1 ) continue;
      if( bst == -1 or ans[ i ] < ans[ bst ] )
        bst = i;
    }
    if( bst == -1 ) break;
    stmp[ bst ] = -1;
    for( int i = 1 ; i <= n ; i ++ )
      if( dst[ bst ][ i ] <= t[ bst ] )
        ans[ i ] = min( ans[ i ] , ans[ bst ] + c[ bst ] );
  }
  if( ans[ y ] == INF16 ) ans[ y ] = -1;
  cout << ans[ y ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}