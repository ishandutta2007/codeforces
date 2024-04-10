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
#define P 20000000
bool p[ P + P ];
int psum[ P ];
vector<ll> pset;
void build(){
  for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
    psum[ i ] ++;
    pset.PB( i );
    for( int j = P / i ; j >= i ; j -- )
      p[ i * j ] = true;
  }
  for( int i = 3 ; i < P ; i ++ )
    psum[ i ] += psum[ i - 1 ];
}
ll n , ans;
inline int Pi( ll );
ll DP( ll x , ll k ){
  if( x <= 0 ) return 0;
  if( k == 0 ) return x;
  if( pset[ k - 1 ] * pset[ k - 1 ] >= x ) return Pi( x ) - k + 1;
  return DP( x , k - 1 ) - DP( x / pset[ k - 1 ] , k - 1 );
}
inline int Pi( ll x ){
  if( x < P ) return psum[ x ];
  ll x3 = 1, x2 = 1;
  while( x3 * x3 * x3 <= x ) x3 ++;
  while( x2 * x2 <= x ) x2 ++;
  x2 --; x3 --;
  ll tsum = 0;
  for( ll i = x3 + 1 ; i <= x2 ; i ++ ) if( !p[ i ] )
    tsum += Pi( x / i ) - Pi( i ) + 1;
  return DP( x , psum[ x3 ] ) + psum[ x3 ] - 1 - tsum;
}
void init(){
  n = getint();
}
void solve(){
  for( size_t i = 0 ; i < pset.size() ; i ++ ){
    if( pset[ i ] * pset[ i ] * pset[ i ] > n ) break;
    ans ++;
  }
  for( size_t i = 0 ; i < pset.size() ; i ++ ){
    if( pset[ i ] * pset[ i ] >= n ) break;
    ans += Pi( n / pset[ i ] ) - Pi( pset[ i ] );
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}