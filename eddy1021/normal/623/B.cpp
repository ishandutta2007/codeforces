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
ll n , a , b , v[ N ];
bool ip[ N + N ];
vector<ll> pset;
void build(){
  for( ll i = 2 ; i < N ; i ++ ) if( !ip[ i ] ){
    pset.PB( i );
    for( ll j = N / i ; j >= i ; j -- )
      ip[ i * j ] = true;
  }
}
set<ll> pp;
typedef set<ll>::iterator si;
void decom( ll xx ){
  for( size_t i = 0 ; i < pset.size() ; i ++ ){
    ll pr = pset[ i ];
    if( pr * pr > xx ) break;
    if( xx % pr == 0 ){
      pp.insert( pr );
      while( xx % pr == 0 ) xx /= pr;
    }
  }
  if( xx > 2 ) pp.insert( xx );
}
void init(){
  n = getint();
  a = getint();
  b = getint();
  for( int i = 1 ; i <= n ; i ++ )
    v[ i ] = getint();
  for( ll dlt = -1 ; dlt <= 1 ; dlt ++ ){
    decom( v[ 1 ] + dlt );
    decom( v[ n ] + dlt );
  }
}
ll dp[ N ][ 4 ];
// 0 
// 1 from 1
// 2 from others
// 3 used
inline ll cal( ll p ){
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ )
      dp[ i ][ j ] = INF16;
  dp[ 0 ][ 0 ] = 0;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < 4 ; j ++ ){
      if( dp[ i ][ j ] == INF16 ) continue;
      if( i == 0 && j == 0 )
        dp[ i + 1 ][ 1 ] = min( dp[ i + 1 ][ 1 ] , dp[ i ][ j ] + a );
      else if( j == 0 )
        dp[ i + 1 ][ 2 ] = min( dp[ i + 1 ][ 2 ] , dp[ i ][ j ] + a );
      else if( j == 1 && i + 1 != n )
        dp[ i + 1 ][ 1 ] = min( dp[ i + 1 ][ 1 ] , dp[ i ][ j ] + a );
      else if( j == 2 )
        dp[ i + 1 ][ 2 ] = min( dp[ i + 1 ][ 2 ] , dp[ i ][ j ] + a );
      if( j == 0 ){
        if( v[ i + 1 ] % p == 0 )
          dp[ i + 1 ][ 0 ] = min( dp[ i + 1 ][ 0 ] , dp[ i ][ j ] );
        else if( ( v[ i + 1 ] + 1 ) % p == 0 ||
                 ( v[ i + 1 ] - 1 ) % p == 0 )
          dp[ i + 1 ][ 0 ] = min( dp[ i + 1 ][ 0 ] , dp[ i ][ j ] + b );
      }else{
        if( v[ i + 1 ] % p == 0 )
          dp[ i + 1 ][ 3 ] = min( dp[ i + 1 ][ 3 ] , dp[ i ][ j ] );
        else if( ( v[ i + 1 ] + 1 ) % p == 0 ||
                 ( v[ i + 1 ] - 1 ) % p == 0 )
          dp[ i + 1 ][ 3 ] = min( dp[ i + 1 ][ 3 ] , dp[ i ][ j ] + b );
      }
    }
  ll tans = INF16;
  for( int i = 0 ; i < 4 ; i ++ )
    tans = min( tans , dp[ n ][ i ] );
  return tans;
}
void solve(){
  ll ans = INF16;
  for( si it = pp.begin() ; it != pp.end() ; it ++ )
    ans = min( ans , cal( *it ) );
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