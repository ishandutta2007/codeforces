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
#define N 1010
int n , a[ 2 ][ N ] , b[ N ];
int ls[ 2 ][ N ] , rs[ 2 ][ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 0 ; i < 2 ; i ++ )
    for( int j = 1 ; j < n ; j ++ )
      a[ i ][ j ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    b[ i ] = getint();
  for( int i = 0 ; i < 2 ; i ++ ){
    for( int j = 1 ; j <= n ; j ++ )
      ls[ i ][ j ] = ls[ i ][ j - 1 ] + a[ i ][ j - 1 ];
    for( int j = n ; j ; j -- )
      rs[ i ][ j ] = rs[ i ][ j + 1 ] + a[ i ][ j ];
  }
}
void solve(){
  vector<int> vans;
  for( int i = 1 ; i <= n ; i ++ )
    vans.PB( ls[ 0 ][ i ] + rs[ 1 ][ i ] + b[ i ] );
  sort( ALL( vans ) );
  printf( "%d\n" , vans[ 0 ] + vans[ 1 ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}