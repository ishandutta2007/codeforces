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
ll fac[ N ] , ifac[ N ];
void build(){
  fac[ 0 ] = ifac[ 0 ] = 1;
  for( ll i = 1 ; i < N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    ifac[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
  }
}
inline ll C( ll a , ll b ){
  if( a < b || b < 0 ) return 0;
  return mul( fac[ a ] , mul( ifac[ b ] , ifac[ a - b ] ) );
}
inline bool lucky( ll x ){
  while( x ){
    if( x % 10 != 4 && x % 10 != 7 )
      return false;
    x /= 10;
  }
  return true;
}
ll n , k , c[ N ] , cnt;
vector<int> l , li;
void init(){
  n = getint();
  k = getint();
  for( ll i = 0 ; i < n ; i ++ ){
    ll ta = getint();
    if( lucky( ta ) ){
      l.PB( ta );
      li.PB( ta );
    }else cnt ++;
  }
  sort( ALL( li ) );
  li.resize( unique( ALL( li ) ) - li.begin() );
  for( size_t i = 0 ; i < l.size() ; i ++ )
    c[ ( lower_bound( ALL( li ) , l[ i ] ) - li.begin() ) + 1 ] ++;
}
ll dp[ 3333 ][ 3333 ];
void solve(){
  dp[ 0 ][ 0 ] = 1;
  int sz = (int)li.size();
  for( int i = 1 ; i <= sz ; i ++ ){
    dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ];
    for( int j = 1 ; j <= i ; j ++ )
      dp[ i ][ j ] = add( dp[ i - 1 ][ j ] , mul( dp[ i - 1 ][ j - 1 ] , c[ i ] ) );
  }
  ll ans = 0;
  for( int i = 0 ; i <= min( (int)k , sz ) ; i ++ )
    ans = add( ans , mul( dp[ sz ][ i ] , C( cnt , k - i ) ) );
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