// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
ll getint(){
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
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 514
class Mat{
public:
  ll a[ N ][ N ] , dim;
  Mat(){
    for( int i = 0 ; i < N ; i ++ )
      for( int j = 0 ; j < N ; j ++ )
        a[ i ][ j ] = 0;
  }
  Mat( int _dim ){
    for( int i = 0 ; i < _dim ; i ++ )
      for( int j = 0 ; j < _dim ; j ++ )
        a[ i ][ j ] = 0;
    dim = _dim;
  }
  void resize( int _dim ){ dim = _dim; }
  void normalize( int _mod ){
    for( int i = 0 ; i < dim ; i ++ )
      for( int j = 0 ; j < dim ; j ++ ){
        a[ i ][ j ] %= _mod;
        a[ i ][ j ] = ( a[ i ][ j ] + _mod ) % _mod;
      }
  }
  ll det( int _mod ){
    ll ans = 1;
    for( int i = 0 ; i < dim ; i ++ ){
      int pt = i;
      while( pt < dim && a[ pt ][ i ] == 0 ) pt ++;
      if( pt >= dim ) return 0;
      if( pt != i ){
        ans = ( ans * ( _mod - 1 ) ) % _mod;
        for( int j = i ; j < dim ; j ++ )
          swap( a[ i ][ j ] , a[ pt ][ j ] );
      }
      ans = ( ans * a[ i ][ i ] ) % _mod;
      ll tmp = mypow( a[ i ][ i ] , _mod - 2 , _mod );
      for( int j = i ; j < dim ; j ++ )
        a[ i ][ j ] = ( a[ i ][ j ] * tmp ) % _mod;
      for( int j = i + 1 ; j < dim ; j ++ ) if( a[ j ][ i ] != 0 ){
        ll dlt = a[ j ][ i ];
        dlt = ( dlt + _mod ) % _mod;
        for( int k = i ; k < dim ; k ++ ){
          a[ j ][ k ] = ( a[ j ][ k ] - dlt * a[ i ][ k ] ) % _mod;
          a[ j ][ k ] = ( a[ j ][ k ] + _mod ) % _mod;
        }
      }
    }
    return ans;
  }
};
Mat mat[ 2 ];
int p[ N * N ];
int n , m , mod;
char c[ N ][ N ];
int cidx[ N * N ] , pidx[ 2 ];
int kd[ N * N ];
int idx( int x , int y ){
  return x * ( m + 1 ) + y;
}
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  p[ x ] = y;
}
void connect( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  if( x == y ) return;
  mat[ kd[ x ] ].a[ cidx[ x ] ][ cidx[ x ] ] ++;
  mat[ kd[ x ] ].a[ cidx[ x ] ][ cidx[ y ] ] --;
  mat[ kd[ x ] ].a[ cidx[ y ] ][ cidx[ x ] ] --;
  mat[ kd[ x ] ].a[ cidx[ y ] ][ cidx[ y ] ] ++;
}
void build(){

}
bool flag;
void init(){
  n = getint();
  m = getint();
  mod = getint();
  flag = true;
  for( int i = 0 ; i < n ; i ++ )
    scanf( "%s" , c[ i ] );
  for( int i = 0 ; i <= ( n + 1 ) * ( m + 1 ) ; i ++ )
    p[ i ] = i;
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j <= m ; j ++ )
      kd[ idx( i , j ) ] = ( i & 1 ) ^ ( j & 1 );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      if( c[ i ][ j ] == '\\' ){
        if( find_p( idx( i , j ) ) == find_p( idx( i + 1 , j + 1 ) ) )
          flag = false;
        Union( idx( i , j ) , idx( i + 1 , j + 1 ) );
      }else if( c[ i ][ j ] == '/' ){
        if( find_p( idx( i + 1 , j ) ) == find_p( idx( i , j + 1 ) ) )
          flag = false;
        Union( idx( i + 1 , j ) , idx( i , j + 1 ) );
      }
}
void solve(){
  if( !flag ){
    puts( "0" );
    return;
  }
  for( int i = 0 ; i <= n ; i ++ )
    for( int j = 0 ; j <= m ; j ++ )
      if( idx( i , j ) == find_p( idx( i , j ) ) )
        cidx[ idx( i , j ) ] = pidx[ kd[ idx( i , j ) ] ] ++;
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < m ; j ++ )
      if( c[ i ][ j ] == '*' ){
        connect( idx( i , j ) , idx( i + 1 , j + 1 ) );
        connect( idx( i + 1 , j ) , idx( i , j + 1 ) );
      }
  mat[ 0 ].resize( pidx[ 0 ] - 1 );
  mat[ 1 ].resize( pidx[ 1 ] - 1 );
  mat[ 0 ].normalize( mod );
  mat[ 1 ].normalize( mod );
  ll ans = ( mat[ 0 ].det( mod ) +
             mat[ 1 ].det( mod ) ) % mod;
  cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}