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
#define N 236
#define L 1010101
int n , m , q;
char c[ N ][ N ];
int dx[ N ], dy[ N ];
int nxti[ N ][ N ];
int nxtj[ N ][ N ];
int indeg[ N ][ N ];
int dp[ N ][ N ];
void build(){

}
bool isin( int nx , int ny ){
  return 1 <= nx && nx <= n &&
         1 <= ny && ny <= m;
}
void init(){
  n = getint();
  m = getint();
  q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%s" , c[ i ] + 1 );
  for( int i = 0 ; i < 10 ; i ++ ){
    dx[ i ] = getint();
    dy[ i ] = getint();
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ ){
      nxti[ i ][ j ] = i + dx[ c[ i ][ j ] - '0' ];
      nxtj[ i ][ j ] = j + dy[ c[ i ][ j ] - '0' ];
      if( !isin( nxti[ i ][ j ] , nxtj[ i ][ j ] ) ){
        nxti[ i ][ j ] = i;
        nxtj[ i ][ j ] = j;
      }
      indeg[ nxti[ i ][ j ] ][ nxtj[ i ][ j ] ] ++;
    }
}
bool got[ N ][ N ];
bool got2[ N ][ N ];
char in[ L ];
int st[ L ], len , now;
bool flag;
int DP( int ni , int nj ){
  if( got2[ ni ][ nj ] ) return dp[ ni ][ nj ];
  got2[ ni ][ nj ] = true;
  int tst = ( 1 << ( c[ ni ][ nj ] - '0' ) );
  tst |= DP( nxti[ ni ][ nj ] , nxtj[ ni ][ nj ] );
  return dp[ ni ][ nj ] = tst;
}
void DFS( int ni , int nj ){
  now = 0;
  while( !got[ ni ][ nj ] ){
    got[ ni ][ nj ] = true;
    if( c[ ni ][ nj ] == in[ now + 1 ] ){
      now ++;
      if( now >= len ){
        flag = true;
        return;
      }
    }
    int nni = nxti[ ni ][ nj ];
    int nnj = nxtj[ ni ][ nj ];
    ni = nni; nj = nnj;
  }
  dp[ ni ][ nj ] = DP( ni , nj );
  if( ( dp[ ni ][ nj ] & st[ now + 1 ] ) == st[ now + 1 ] )
    flag = true;
}
void solve(){
  while( q -- ){
    scanf( "%s" , in + 1 );
    len = strlen( in + 1 );
    st[ len + 1 ] = 0;
    for( int i = len ; i >= 1 ; i -- )
      st[ i ] = st[ i + 1 ] | ( 1 << ( in[ i ] - '0' ) );
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= m ; j ++ )
        got[ i ][ j ] = false;
    flag = false;
    for( int i = 1 ; i <= n && !flag ; i ++ )
      for( int j = 1 ; j <= m && !flag ; j ++ )
        if( indeg[ i ][ j ] == 0 )
          DFS( i , j );
    for( int i = 1 ; i <= n && !flag ; i ++ )
      for( int j = 1 ; j <= m && !flag ; j ++ )
        if( !got[ i ][ j ] )
          DFS( i , j );
    puts( flag ? "YES" : "NO" );
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