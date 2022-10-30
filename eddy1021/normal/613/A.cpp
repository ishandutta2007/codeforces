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
#define N 101010
ll n , mx , mn;
ll xx[ N ] , yy[ N ];
void build(){

}
inline ll sqr( ll _ ){ return _ * _; }
inline D sqr( D _ ){ return _ * _; }
ll px , py;
void init(){
  n = getint();
  px = getint();
  py = getint();
  for( int i = 0 ; i < n ; i ++ ){
    ll tx = getint();
    ll ty = getint();
    xx[ i ] = tx;
    yy[ i ] = ty;
    ll dd = sqr( px - tx ) + sqr( py - ty );
    if( i == 0 ) mx = mn = dd;
    else{
      mx = max( mx , dd );
      mn = min( mn , dd );
    }
  }
  xx[ n ] = xx[ 0 ];
  yy[ n ] = yy[ 0 ];
}
void solve(){
  D rmin = sqrt( (D)mn );
  D rmax = sqrt( (D)mx );
  for( int i = 0 ; i < n ; i ++ ){
    ll dx = xx[ i + 1 ] - xx[ i ];
    ll dy = yy[ i + 1 ] - yy[ i ];
    D tt = (D)( px * dx + py * dy - xx[ i ] * dx - yy[ i ] * dy ) /
           (D)( dx * dx + dy * dy );
    // printf( "%d %.12f\n" , i , tt );
    if( tt > 0 && tt < 1 ){
      D nnx = xx[ i ] + tt * dx;
      D nny = yy[ i ] + tt * dy;
      D fuckd = sqrt( sqr( px - nnx ) + sqr( py - nny ) );
      rmin = min( rmin , fuckd );
      rmax = max( rmax , fuckd );
    }
  }
  printf( "%.12f\n" , acos( -1.0 ) * ( sqr( rmax ) - sqr( rmin ) ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}