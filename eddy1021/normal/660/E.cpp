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
#define N 1010101
ll n , m;
void build(){

}
ll mp[ N ] , m1p[ N ] , s[ N ] , fac[ N ] , ifac[ N ] , c[ N ];
void init(){
  n = getint(); m = getint();
  mp[ 0 ] = 1;
  for( ll i = 1 ; i <= n ; i ++ )
    mp[ i ] = mul( mp[ i - 1 ] , m );
  m1p[ 0 ] = 1;
  for( ll i = 1 ; i <= n ; i ++ )
    m1p[ i ] = mul( m1p[ i - 1 ] , m - 1 );
  ifac[ 0 ] = fac[ 0 ] = 1;
  for( ll i = 1 ; i <= n ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
}
void solve(){
  for( ll i = 0 ; i <= n ; i ++ )
    c[ i ] = mul( fac[ n ] , mul( ifac[ i ] , ifac[ n - i ] ) );
  for( ll i = 0 ; i <= n ; i ++ )
    s[ i ] = mul( c[ i ] , m1p[ n - i ] );
  for( ll i = n - 1 ; i >= 0 ; i -- )
    s[ i ] = add( s[ i ] , s[ i + 1 ] );
  ll ans = 0;
  for( ll i = 0 ; i <= n ; i ++ )
    ans = add( ans , mul( s[ i ] , mp[ i ] ) );
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}