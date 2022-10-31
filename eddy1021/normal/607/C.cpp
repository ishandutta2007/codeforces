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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
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
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 1111111
struct Hash{
  ll a[ N ] , bs , md , hs[ N ] , n , BS[ N ];
  Hash(){ bs = 13131; md = mod7;}
  Hash( ll _bs , ll _md ) : bs( _bs ) , md( _md ) {}
  void build_hs(){
    BS[ 0 ] = 1ll;
    for( ll i = 1 ; i < N ; i ++ )
      BS[ i ] = mul( BS[ i - 1 ] , bs , md );
    hs[ 0 ] = 0;
    for( ll i = 1 ; i <= n ; i ++ )
      hs[ i ] = add( mul( hs[ i - 1 ] , bs , md ) , a[ i ] , md );
  }
  ll query( int l , int r ){
    if( l > r ) return -1;
    return sub( hs[ r ] , mul( hs[ l - 1 ] , BS[ r - l + 1 ] , md ) , md );
  }
}h1[ 2 ] , h2[ 2 ];
char c[ 2 ][ N ];
int n;
void build(){

}
int dir( char ctmp ){
  if( ctmp == 'N' ) return 1;
  if( ctmp == 'W' ) return 2;
  if( ctmp == 'E' ) return 3;
  if( ctmp == 'S' ) return 4;
  return INF;
}
void init(){
  n = getint() - 1;
  scanf( "%s%s" , c[ 0 ] + 1 , c[ 1 ] + 1 );
  h2[ 0 ] = Hash( 13131 , mod9 );
  h2[ 1 ] = Hash( 13131 , mod9 );
  h1[ 0 ].n = h1[ 1 ].n = h2[ 0 ].n = h2[ 1 ].n = n;
  for( int i = 1 ; i <= n ; i ++ ){
    h1[ 0 ].a[ i ] = dir( c[ 0 ][ i ] );
    h2[ 0 ].a[ i ] = dir( c[ 0 ][ i ] );
    h1[ 1 ].a[ n - i + 1 ] = 5 - dir( c[ 1 ][ i ] );
    h2[ 1 ].a[ n - i + 1 ] = 5 - dir( c[ 1 ][ i ] );
  }
  h1[ 0 ].build_hs();
  h1[ 1 ].build_hs();
  h2[ 0 ].build_hs();
  h2[ 1 ].build_hs();
}
// ...NW
// ...ES
// =>
// ...NW
// NW...
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    if( h1[ 0 ].query( n - i + 1 , n ) == h1[ 1 ].query( 1 , i ) &&
        h2[ 0 ].query( n - i + 1 , n ) == h2[ 1 ].query( 1 , i ) ){
      puts( "NO" );
      exit( 0 );
    }
  puts( "YES" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}