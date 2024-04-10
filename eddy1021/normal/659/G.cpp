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
ll n , h[ N ];
void build(){

}
void init(){
  n = getint();
  for( ll i = 1 ; i <= n ; i ++ )
    h[ i ] = getint() - 1;
}
ll dp[ N ][ 2 ];
// 0 above 1 ok
void solve(){
  if( n == 1 ){
    cout << h[ 1 ] << endl;
    return;
  }
  dp[ 1 ][ 0 ] = max( 0ll , h[ 1 ] - h[ 2 ] );
  dp[ 1 ][ 1 ] = h[ 1 ] - dp[ 1 ][ 0 ];
  for( ll i = 2 ; i < n ; i ++ ){
    if( h[ i - 1 ] >= h[ i + 1 ] ){
      ll tdp0 = max( 0ll , h[ i ] - h[ i - 1 ] );
      ll tdp1 = max( 0ll , h[ i ] - h[ i + 1 ] ) - tdp0;
      ll tdp2 = h[ i ] - tdp0 - tdp1;
      dp[ i ][ 0 ] = add( tdp0 , mul( tdp1 , add( dp[ i - 1 ][ 1 ] , 1 ) ) );
      dp[ i ][ 1 ] = mul( tdp2 , add( dp[ i - 1 ][ 1 ] , 1 ) );
    }else{
      ll tdp0 = max( 0ll , h[ i ] - h[ i + 1 ] );
      ll tdp1 = max( 0ll , h[ i ] - h[ i - 1 ] ) - tdp0;
      ll tdp2 = h[ i ] - tdp0 - tdp1;
      dp[ i ][ 0 ] = tdp0;
      dp[ i ][ 1 ] = add( tdp1 , mul( tdp2 , add( dp[ i - 1 ][ 1 ] , 1 ) ) );
    }
  }
  ll tdp0 = max( 0ll , h[ n ] - h[ n - 1 ] );
  ll tdp1 = h[ n ] - tdp0;
  dp[ n ][ 1 ] = add( tdp0 , mul( tdp1 , add( dp[ n - 1 ][ 1 ] , 1 ) ) );
  ll ans = 0;
  for( ll i = 1 ; i <= n ; i ++ ){
    ans = add( ans , dp[ i ][ 0 ] );
    ans = add( ans , dp[ i ][ 1 ] );
    // printf( "%lld : %lld %lld\n" , i , dp[ i ][ 0 ] , dp[ i ][ 1 ] );
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