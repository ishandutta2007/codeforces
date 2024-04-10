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
#define N 222
#define K 1111
void build(){

}
ll n , k , a[ N ];
void init(){
  n = getint();
  k = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  sort( a + 1 , a + n + 1 );
}
ll dp[ 2 ][ N ][ K ];
void solve(){
  dp[ 0 ][ 0 ][ 0 ] = 1ll;
  for( int _ = 1 ; _ <= n ; _ ++ ){
    int now = _ & 1;
    int pre = 1 - now;
    for( int i = 0 ; i <= n ; i ++ )
      for( int j = 0 ; j <= k ; j ++ )
        dp[ now ][ i ][ j ] = 0;
    for( int i = 0 ; i <= n ; i ++ )
      for( int j = 0 ; j <= k ; j ++ ){
        if( dp[ pre ][ i ][ j ] == 0 ) continue;
        int nxtj = j + i * ( a[ _ ] - a[ _ - 1 ] );
        if( nxtj > k ) continue;
        dp[ now ][ i ][ nxtj ] = add( dp[ now ][ i ][ nxtj ] , mul( dp[ pre ][ i ][ j ] , i + 1 ) );
        dp[ now ][ i + 1 ][ nxtj ] = add( dp[ now ][ i + 1 ][ nxtj ] , dp[ pre ][ i ][ j ] );
        if( i )
          dp[ now ][ i - 1 ][ nxtj ] = add( dp[ now ][ i - 1 ][ nxtj ] , mul( dp[ pre ][ i ][ j ] , i ) );
      }
  }
  ll ans = 0;
  for( int i = 0 ; i <= k ; i ++ )
    ans = add( ans , dp[ n & 1 ][ 0 ][ i ] );
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