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
#define N 1021
char c[ N ][ N ];
int n , m , q , dp[ N ][ N ];
bool usd[ N ][ N ];
bool usd2[ N ][ N ];
void build(){

}
bool in( int xn , int xm ){
  return 1 <= xn && xn <= n &&
         1 <= xm && xm <= m;
}
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
int cnt;
void DFS( int xn , int xm ){
  usd[ xn ][ xm ] = true;
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxtn = xn + dn[ i ];
    int nxtm = xm + dm[ i ];
    if( in( nxtn , nxtm ) && !usd[ nxtn ][ nxtm ] ){
      if( c[ nxtn ][ nxtm ] == '*' ) cnt ++;
      else DFS( nxtn , nxtm );
    }
  }
}
void DFS2( int xn , int xm ){
  usd2[ xn ][ xm ] = true;
  dp[ xn ][ xm ] = cnt;
  for( int i = 0 ; i < 4 ; i ++ ){
    int nxtn = xn + dn[ i ];
    int nxtm = xm + dm[ i ];
    if( in( nxtn , nxtm ) &&
        c[ nxtn ][ nxtm ] == '.' &&
        !usd2[ nxtn ][ nxtm ] )
      DFS2( nxtn , nxtm );
  }
}
void go( int xn , int xm ){
  cnt = 0;
  DFS( xn , xm );
  DFS2( xn , xm );
}
void init(){
  n = getint();
  m = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      if( !usd[ i ][ j ] && c[ i ][ j ] == '.' )
        go( i , j );
}
void solve(){
  while( q -- ){
    int qx = getint();
    int qy = getint();
    printf( "%d\n" , dp[ qx ][ qy ] );
  }
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}