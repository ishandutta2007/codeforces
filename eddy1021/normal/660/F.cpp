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
void build(){

}
#define N 202020
ll n , a[ N ] , u[ N ] , s[ N ];
void init(){
  n = getint();
  for( ll i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  a[ ++ n ] = -10000000;
  for( ll i = n ; i >= 1 ; i -- )
    u[ i ] = u[ i + 1 ] + a[ i ];
  for( ll i = n ; i >= 1 ; i -- )
    s[ i ] = s[ i + 1 ] + u[ i ];
}
// ans = s[ l ] - s[ r ] - ( r - l ) * u[ r ];
// ans = s[ l ] + l * u[ r ] - s[ r ] - r * u[ r ];
// maintain s[ l ] + l * x;
// [l,r)
vector<ll> stk;
void solve(){
  ll ans = max( 0ll , s[ 1 ] );
  for( ll i = 1 ; i <= n ; i ++ ){
    if( i > 1 ){
      ll pos = 0 , l = 1 , r = (int)stk.size() - 1 , mid;
      while( l <= r ){
        mid = ( l + r ) >> 1;
        ll ii = stk[ mid ] , jj = stk[ mid - 1 ];
        if( u[ i ] * ( ii - jj ) > s[ jj ] - s[ ii ] )
          pos = mid , l = mid + 1;
        else r = mid - 1;
      }
      ll tx = stk[ pos ];
      ll tans = s[ tx ] - s[ i ] - ( i - tx ) * u[ i ];
      ans = max( ans , tans );
    }
// maintain s[ l ] + l * x;
    while( true ){
      if( (int)stk.size() < 2 ) break;
      int ii = stk[ (int)stk.size() - 2 ];
      int jj = stk[ (int)stk.size() - 1 ];
      if( ( s[ ii ] - s[ i ] ) * ( jj - ii ) <=
          ( s[ ii ] - s[ jj ] ) * ( i - ii ) )
        stk.pop_back();
      else  break;
    }
    stk.PB( i );
  }
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