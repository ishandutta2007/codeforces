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
#define L 200010
typedef unsigned long long ull;
int num( char ctmp ){
  if( ctmp == 'A' ) return 0;
  if( ctmp == 'T' ) return 1;
  if( ctmp == 'G' ) return 2;
  if( ctmp == 'C' ) return 3;
  return -1;
}
int n , m , k;
bool pnk[ 4 ][ L ];
ull nk[ 4 ][ L ] , mk[ 4 ][ L ];
char s[ L ] , t[ L ];
int tag[ 4 ][ L ];
void build(){

}
void mark(){
  for( int i = 0 ; i < 4 ; i ++ ){
    int psum = 0;
    for( int j = 0 ; j < n ; j ++ )
      if( num( s[ j ] ) == i ){
        if( j - k < 0 ) psum ++;
        else tag[ i ][ j - k ] ++;
        if( j + k < n ) tag[ i ][ j + k + 1 ] --;
      }
    for( int j = 0 ; j < n ; j ++ ){
      psum += tag[ i ][ j ];
      if( psum ) pnk[ i ][ j ] = true;
    }
  }

  for( int kd = 0 ; kd < 4 ; kd ++ )
    for( int i = 0 ; i < n ; i ++ )
      for( int j = 0 ; j < 64 && i + j < n ; j ++ )
        if( pnk[ kd ][ i + j ] )
          nk[ kd ][ i ] |= ( 1llu << j );

  for( int kd = 0 ; kd < 4 ; kd ++ )
    for( int i = 0 ; i < m ; i ++ )
      for( int j = 0 ; j < 64 && i + j < m ; j ++ )
        if( num( t[ i + j ] ) == kd )
          mk[ kd ][ i ] |= ( 1llu << j );
}
void init(){
  n = getint();
  m = getint();
  k = getint();
  scanf( "%s" , s );
  scanf( "%s" , t );
  mark();
}
int mth[ 4 ][ L ];
void solve(){
  for( int kd = 0 ; kd < 4 ; kd ++ )
    for( int i = 0 ; i <= n - m ; i ++ ){
      bool good = true;
      for( int j = 0 ; j < m ; j += 64 ){
        if( m - j < 64 ){
          ll msk = ( 1llu << ( m - j ) ) - 1llu;
          if( ( ( nk[ kd ][ i + j ] & msk ) &
                ( mk[ kd ][ j ] & msk ) ) !=
                ( mk[ kd ][ j ] & msk ) ){
            good = false;
            break;
          }
        }else if( ( nk[ kd ][ i + j ] &
                    mk[ kd ][ j ] ) !=
                    mk[ kd ][ j ] ){
          good = false;
          break;
        }
      }
      if( good ) mth[ kd ][ i ] = true;
    }
  int ans = 0;
  for( int i = 0 ; i <= n - m ; i ++ )
    if( mth[ 0 ][ i ] &&
        mth[ 1 ][ i ] && 
        mth[ 2 ][ i ] &&
        mth[ 3 ][ i ] )
      ans ++;
  cout << ans << endl;
}
int main(){
  build();
  // __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}