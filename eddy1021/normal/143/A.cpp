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
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
void build(){

}
int r[ 2 ] , c[ 2 ] , d[ 2 ];
bool usd[ 10 ];
void init(){
  for( int i = 0 ; i < 2 ; i ++ )
    r[ i ] = getint();
  for( int i = 0 ; i < 2 ; i ++ )
    c[ i ] = getint();
  for( int i = 0 ; i < 2 ; i ++ )
    d[ i ] = getint();
}
int a[ 2 ][ 2 ];
void find_ans( int n , int m ){
  if( n == 2 ){
    if( a[ 0 ][ 0 ] + a[ 0 ][ 1 ] != r[ 0 ] ) return;
    if( a[ 1 ][ 0 ] + a[ 1 ][ 1 ] != r[ 1 ] ) return;
    if( a[ 0 ][ 0 ] + a[ 1 ][ 0 ] != c[ 0 ] ) return;
    if( a[ 0 ][ 1 ] + a[ 1 ][ 1 ] != c[ 1 ] ) return;
    if( a[ 0 ][ 0 ] + a[ 1 ][ 1 ] != d[ 0 ] ) return;
    if( a[ 1 ][ 0 ] + a[ 0 ][ 1 ] != d[ 1 ] ) return;
    for( int i = 0 ; i < 2 ; i ++ )
      for( int j = 0 ; j < 2 ; j ++ )
        printf( "%d%c" , a[ i ][ j ] , " \n"[ j + 1 == 2 ] );
    exit( 0 );
  }
  for( int i = 1 ; i <= 9 ; i ++ )
    if( !usd[ i ] ){
      a[ n ][ m ] = i;
      usd[ i ] = true;
      if( m == 1 ) find_ans( n + 1 , 0 );
      else find_ans( n , m + 1 );
      usd[ i ] = false;
    }
}
void solve(){
  find_ans( 0 , 0 );
  puts( "-1" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}