// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
int n , m , k , x[ N ] , y[ N ];
vector<int> ad[ 4 * N ] , sb[ 4 * N ];
long long ans[ N ];
void init(){
  n = getint();
  m = getint();
  k = getint();
  for( int i = 0 ; i < k ; i ++ ){
    ans[ i ] = -1;
    x[ i ] = getint();
    y[ i ] = getint();
    ad[ x[ i ] + y[ i ] ].push_back( i );
    sb[ x[ i ] - y[ i ] + N ].push_back( i );
  }
}
set< pair<int,int> > vst;
void go( int sx , int sy , int tx , int ty , long long pre ){
  // printf( "%d %d %d %d %lld\n" , sx , sy , tx , ty , pre );
  if( sx + sy == tx + ty ){
    for( auto i : ad[ sx + sy ] )
      if( ans[ i ] == -1 )
        ans[ i ] = pre + abs( x[ i ] - sx );
  }
  if( sx - sy == tx - ty ){
    for( auto i : sb[ sx - sy + N ] )
      if( ans[ i ] == -1 )
        ans[ i ] = pre + abs( x[ i ] - sx );
  }
  if( tx == 0 && ty == 0 ) return;
  if( tx == 0 && ty == m ) return;
  if( tx == n && ty == 0 ) return;
  if( tx == n && ty == m ) return;
  int dx = 0 , dy = 0;
  if( tx == 0 ){
    if( ty > sy )
      dx = 1 , dy = 1;
    else
      dx = 1 , dy = -1;
  }else if( tx == n ){
    if( ty > sy )
      dx = -1 , dy = 1;
    else
      dx = -1 , dy = -1;
  }else if( ty == 0 ){
    if( tx > sx )
      dx = 1 , dy = 1;
    else
      dx = -1 , dy = 1;
  }else if( ty == m ){
    if( tx > sx )
      dx = 1 , dy = -1;
    else
      dx = -1 , dy = -1;
  }else assert( false );
  int mx = N;
  if( dx > 0 ) mx = min( mx , n - tx );
  else mx = min( mx , tx );
  if( dy > 0 ) mx = min( mx , m - ty );
  else mx = min( mx , ty );
  if( vst.count( { tx + dx * mx , ty + dy * mx } ) )
    return;
  vst.insert( { tx + dx * mx , ty + dy * mx } );
  // printf( "===%d %d %d %d %d\n" , sx , sy , tx , ty , mx );
  go( tx , ty , tx + dx * mx , ty + dy * mx , pre + abs( tx - sx ) );
}
void solve(){
  vst.insert( { 0 , 0 } );
  vst.insert( { min( n , m ) , min( n , m ) } );
  go( 0 , 0 , min( n , m ) , min( n , m ) , 0 );
  for( int i = 0 ; i < k ; i ++ )
    printf( "%lld\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}