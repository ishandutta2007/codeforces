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
#define N 60
void build(){

}
ll dp[ N ][ N ][ N ];
bool gt[ N ][ N ][ N ];
int n , m , k;
void init(){
  n = getint();
  m = getint();
  k = getint();
}
ll DP( int xn , int xm , int xk ){
  if( xk == 0 ) return 0;
  if( xn > xm ) swap( xn , xm );
  if( gt[ xn ][ xm ][ xk ] ) return dp[ xn ][ xm ][ xk ];
  gt[ xn ][ xm ][ xk ] = true;
  if( xn * xm == xk ) return dp[ xn ][ xm ][ xk ] = 0;
  if( xn * xm < xk ) return dp[ xn ][ xm ][ xk ] = INF16;
  ll tans = INF16;
  for( int i = 1 ; i <= xm / 2 ; i ++ )
    for( int j = 0 ; j <= min( xk , i * xn ) ; j ++ ){
      ll cst = xn * xn + DP( xn , i , j ) +
                         DP( xn , xm - i , xk - j );
      tans = min( tans , cst );
    }
  for( int i = 1 ; i <= xn / 2 ; i ++ )
    for( int j = 0 ; j <= min( xk , i * xm ) ; j ++ ){
      ll cst = xm * xm + DP( i , xm , j ) +
                         DP( xn - i , xm , xk - j );
      tans = min( tans , cst );
    }
  return dp[ xn ][ xm ][ xk ] = tans;
}
void solve(){
  printf( "%lld\n" , DP( n , m , k ) );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}