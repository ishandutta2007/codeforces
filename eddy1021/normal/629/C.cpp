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
#define M 2222
ll pdp[ M + 2 ][ M + 2 ];
void build(){
  pdp[ 0 ][ 0 ] = 1ll;
  for( int i = 0 ; i < M - 1 ; i ++ )
    for( int j = 0 ; j <= i ; j ++ )
      if( pdp[ i ][ j ] ){
        if( j )
          pdp[ i + 1 ][ j - 1 ] = add( pdp[ i + 1 ][ j - 1 ] , 
                                       pdp[ i ][ j ] );
        pdp[ i + 1 ][ j + 1 ] = add( pdp[ i + 1 ][ j + 1 ] , 
                                     pdp[ i ][ j ] );
      }
}
int n , m;
char c[ N ];
void init(){
  n = getint();
  m = getint();
  scanf( "%s" , c + 1 );
}
void solve(){
  int sum = 0 , lft = 0 , mn = 0 , mx = 0;
  for( int i = 1 ; i <= m ; i ++ ){
    if( c[ i ] == '(' ) sum ++ , lft ++;
    else sum --;
    mn = min( mn , sum );
    mx = max( mx , sum );
  }
  if( lft > n / 2 || m - lft > n / 2 || n % 2 == 1 ){
    puts( "0" );
    return;
  }
  ll ans = 0;
  for( int i = 0 ; i <= n - m ; i ++ ){
    for( int k = -mn ; k <= i ; k ++ )
      if( pdp[ i ][ k ] ){
        int tsum = sum + k;
        if( tsum < M )
          ans = add( ans , mul( pdp[ i ][ k ] , pdp[ n - m - i ][ tsum ] ) );
      }
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