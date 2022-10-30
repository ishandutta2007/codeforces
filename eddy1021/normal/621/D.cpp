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
string ans[ 12 ] = { "x^y^z" , "x^z^y" ,
                     "(x^y)^z" , "(x^z)^y" ,
                     "y^x^z" , "y^z^x" ,
                     "(y^x)^z" , "(y^z)^x" ,
                     "z^x^y" , "z^y^x" ,
                     "(z^x)^y" , "(z^y)^x" };
void build(){

}
LD v[ 12 ] , x , y , z;
void init(){
  D tt;
  scanf( "%lf" , &tt ); x = (LD)tt;
  scanf( "%lf" , &tt ); y = (LD)tt;
  scanf( "%lf" , &tt ); z = (LD)tt;
}
void solve(){
  v[ 0 ] = logl( x ) * powl( y , z );
  v[ 1 ] = logl( x ) * powl( z , y );
  v[ 2 ] = logl( x ) * y * z;
  v[ 3 ] = logl( x ) * z * y - 1.0;
  v[ 4 ] = logl( y ) * powl( x , z );
  v[ 5 ] = logl( y ) * powl( z , x );
  v[ 6 ] = logl( y ) * x * z;
  v[ 7 ] = logl( y ) * z * x - 1.0;
  v[ 8 ] = logl( z ) * powl( x , y );
  v[ 9 ] = logl( z ) * powl( y , x );
  v[ 10 ] = logl( z ) * x * y;
  v[ 11 ] = logl( z ) * y * x - 1.0;
  int at = 0;
  for( int i = 1 ; i < 12 ; i ++ )
    if( v[ i ] > v[ at ] )
      at = i;
  cout << ans[ at ] << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}