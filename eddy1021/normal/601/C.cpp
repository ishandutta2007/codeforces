// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
int __ = 1 , cs;
/*********default*********/
#define N 110
#define M 2010
D dp[ 2 ][ N * M ];
D psum[ 2 ][ N * M ];
int n , m , mark[ N ] , sum;
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < n ; i ++ ){
    mark[ i ] = getint();
    sum += mark[ i ];
  }
}
void solve(){
  if( m == 1 ){
    puts( "1.00000000" );
    return;
  }
  for( int i = 1 ; i <= m + m ; i ++ ){
    if( mark[ 0 ] != i && i <= m )
      dp[ 0 ][ i ] = 1.0 / ( m - 1 );
    psum[ 0 ][ i ] = psum[ 0 ][ i - 1 ] + dp[ 0 ][ i ];
  }
  // for( int i = 1 ; i <= m ; i ++ )
    // printf( "%.3f %.3f\n" , (double)dp[ 0 ][ i ] , (double)psum[ 0 ][ i ] );
  for( int i = 1 , now = 1 ; i < n ; i ++ , now = 1 - now ){
    int pre = 1 - now;
    int bdr = ( i + 1 ) * m;
    for( int j = 0 ; j <= bdr + m ; j ++ ) dp[ now ][ j ] = 0.0;
    for( int j = i + 1 ; j <= bdr ; j ++ ){
      int lft = max( j - m , i );
      int rgt = j - 1;
      dp[ now ][ j ] = psum[ pre ][ rgt ] - psum[ pre ][ lft - 1 ];
      // printf( "%d %d\n" , lft , rgt );
      // printf( "%d %d => %.3f\n" , i , j , (double)dp[ i ][ j ] );
      if( j - mark[ i ] >= i ) dp[ now ][ j ] -= dp[ pre ][ j - mark[ i ] ];
      dp[ now ][ j ] /= (D)( m - 1 );
      // printf( "%d %d => %.3f\n" , i , j , (double)dp[ i ][ j ] );
    }
    psum[ now ][ 0 ] = 0.0;
    for( int j = 1 ; j <= bdr + m ; j ++ )
      psum[ now ][ j ] = psum[ now ][ j - 1 ] + dp[ now ][ j ];
    // printf( "%d\n" , i );
    // for( int j = 1 ; j <= bdr ; j ++ )
      // printf( "%d : %.3f %.3f\n" , j , (double)dp[ now ][ j ] , (double)psum[ now ][ j ] );
  }
  D ans = psum[ ( n - 1 ) & 1 ][ sum - 1 ];
  printf( "%.12f\n" , (double)ans * (D)( m - 1 ) + 1.0 );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}