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
#define N 1021
ll n , x[ N ] , y[ N ] , s[ N ];
ll C[ N ][ N ] , lvl[ N ];
void build(){
  for( ll i = 0 ; i < N ; i ++ )
    C[ i ][ 0 ] = C[ i ][ i ] = 1;
  for( ll i = 2 ; i < N ; i ++ )
    for( ll j = 1 ; j < i ; j ++ )
      C[ i ][ j ] = add( C[ i - 1 ][ j - 1 ] , C[ i - 1 ][ j ] );
}
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    s[ i ] = s[ i - 1 ] + x[ i ];
  }
  for( int i = 1 ; i <= n ; i ++ )
    y[ i ] = getint();
}
ll dp[ N ][ N ];
void solve(){
  dp[ 0 ][ 0 ] = 1;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j <= s[ i ] ; j ++ )
      if( dp[ i ][ j ] ){
        ll pp = j + x[ i + 1 ];
        ll bdr = min( pp , y[ i + 1 ] );
        for( int k = 0 ; k <= bdr ; k ++ )
          dp[ i + 1 ][ pp - k ] = add( dp[ i + 1 ][ pp - k ] ,
                                       mul( dp[ i ][ j ] , C[ pp ][ k ] ) );
      }
  ll all = s[ n ] , ans = dp[ n ][ 0 ];
  for( int i = 1 ; i <= n ; i ++ ){
    ans = mul( ans , C[ all ][ x[ i ] ] );
    all -= x[ i ];
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