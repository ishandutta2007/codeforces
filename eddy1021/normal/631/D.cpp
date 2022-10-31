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
#define N 303030
int n[ 2 ] , len[ 2 ];
vector< pair<ll,char> > v[ 2 ];
void build(){

}
void init(){
  n[ 0 ] = getint();
  n[ 1 ] = getint();
  for( int i = 0 ; i < 2 ; i ++ ){
    while( n[ i ] -- ){
      int li; char  ci[ 3 ];
      scanf( "%d-%s" , &li , ci );
      v[ i ].PB( MP( (ll)li , ci[ 0 ] ) );
    }
    int sz = 1;
    for( size_t j = 1 ; j < v[ i ].size() ; j ++ )
      if( v[ i ][ j ].SE == v[ i ][ sz - 1 ].SE )
        v[ i ][ sz - 1 ].FI += v[ i ][ j ].FI;
      else v[ i ][ sz ++ ] = v[ i ][ j ];
    v[ i ].resize( sz );
    len[ i ] = sz;
  }
  v[ 0 ].PB( MP( 1 , '$' ) );
  v[ 0 ].PB( MP( 1 , '%' ) );
  v[ 0 ].PB( MP( 1 , '*' ) );
  v[ 1 ].PB( MP( 1 , '!' ) );
  v[ 1 ].PB( MP( 1 , '?' ) );
  v[ 1 ].PB( MP( 1 , '#' ) );
}
int dp[ N + N ];
void buildf(){
  int tlen = len[ 1 ] - 2;
  dp[ 0 ] = 0;
  for( int i = 1 ; i < tlen ; i ++ ){
    dp[ i ] = dp[ i - 1 ];
    while( dp[ i ] > 0 && v[ 1 ][ i + 1 ] != v[ 1 ][ dp[ i ] + 1 ] )
      dp[ i ] = dp[ dp[ i ] - 1 ];
    if( v[ 1 ][ i + 1 ] == v[ 1 ][ dp[ i ] + 1 ] ) dp[ i ] ++;
  }
}
void solve(){
  if( len[ 0 ] < len[ 1 ] ){
    puts( "0" );
    exit( 0 );
  }
  if( len[ 1 ] == 1 ){
    ll ans = 0;
    for( size_t i = 0 ; i < v[ 0 ].size() ; i ++ )
      if( v[ 1 ][ 0 ].SE == v[ 0 ][ i ].SE &&
          v[ 1 ][ 0 ].FI <= v[ 0 ][ i ].FI ){
        ans += v[ 0 ][ i ].FI - v[ 1 ][ 0 ].FI + 1;
      }
    cout << ans << endl;
    exit( 0 );
  }
  if( len[ 1 ] == 2 ){
    ll ans = 0;
    for( size_t i = 0 ; i + 1 < v[ 0 ].size() ; i ++ )
      if( v[ 1 ][ 0 ].SE == v[ 0 ][ i ].SE &&
          v[ 1 ][ 1 ].SE == v[ 0 ][ i + 1 ].SE &&
          v[ 1 ][ 0 ].FI <= v[ 0 ][ i ].FI &&
          v[ 1 ][ 1 ].FI <= v[ 0 ][ i + 1 ].FI )
        ans ++;
    cout << ans << endl;
    exit( 0 );
  }
  buildf();
  ll ans = 0;
  int len1 = len[ 0 ] - 2;
  int len2 = len[ 1 ] - 2;
  for( int mat = 0 , i = 0 ; i < len1 ; i ++ ){
    while( mat > 0 && v[ 1 ][ mat + 1 ] != v[ 0 ][ i + 1 ] )
      mat = dp[ mat - 1 ];
    if( v[ 1 ][ mat + 1 ] == v[ 0 ][ i + 1 ] ) mat ++;
    // printf( "%d %d\n" , i , mat );
    if( mat == len2 ){
      if( v[ 0 ][ i + 1 - len2 ].SE == v[ 1 ][ 0 ].SE &&
          v[ 0 ][ i + 1 - len2 ].FI >= v[ 1 ][ 0 ].FI &&
          v[ 0 ][ i + 2 ].SE == v[ 1 ][ len[ 1 ] - 1 ].SE && 
          v[ 0 ][ i + 2 ].FI >= v[ 1 ][ len[ 1 ] - 1 ].FI )
        ans ++;
      mat = dp[ mat - 1 ];
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