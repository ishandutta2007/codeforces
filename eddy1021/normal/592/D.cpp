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
#define N 654321
vector<int> v[ N ];
int n , m , dp[ N ][ 3 ] , cnt[ N ];
int from[ N ][ 3 ];
int sz[ N ];
// 0 back 1 not back 
void add( int tno , int tfrom , int tcst ){
  for( int i = 0 ; i < 2 ; i ++ ){
    if( sz[ tno ] == i ){
      ++ sz[ tno ];
      dp[ tno ][ i + 1 ] = tcst;
      from[ tno ][ i + 1 ] = tfrom;
      return;
    }
    if( tcst < dp[ tno ][ i + 1 ] ){
      swap( dp[ tno ][ i + 1 ] , tcst );
      swap( from[ tno ][ i + 1 ] , tfrom );
    }
  }
}
int tk( int tno , int fb ){
  for( int i = 1 ; i <= sz[ tno ] ; i ++ )
    if( fb != from[ tno ][ i ] )
      return dp[ tno ][ i ];
  return -1;
}
bool mk[ N ];
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int tu = getint();
    int tv = getint();
    v[ tu ].PB( tv );
    v[ tv ].PB( tu );
  }
  while( m -- ) mk[ getint() ] = true;
}
void pDP( int now , int prt ){
  if( mk[ now ] ) cnt[ now ] ++;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      pDP( v[ now ][ i ] , now );
      cnt[ now ] += cnt[ v[ now ][ i ] ];
    }
}
// 0 back 1 not back
void DP1( int now , int prt ){
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      if( cnt[ v[ now ][ i ] ] == 0 ) continue;
      DP1( v[ now ][ i ] , now );
      dp[ now ][ 0 ] += 2 + dp[ v[ now ][ i ] ][ 0 ];
    }
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      if( cnt[ v[ now ][ i ] ] == 0 ) continue;
      int tmp = dp[ now ][ 0 ] - 2 - dp[ v[ now ][ i ] ][ 0 ];
      tmp += 1 + dp[ v[ now ][ i ] ][ 1 ];
      add( now , v[ now ][ i ] , tmp );
    }
}
int ans , mcst;
void DP2( int now , int prt , int bns0 , int bns1 ){
// 0 back 1 not back
  int tans = min( bns0 + dp[ now ][ 1 ] , bns1 + dp[ now ][ 0 ] );
  if( tans < mcst || ( tans == mcst && now < ans ) )
    ans = now, mcst = tans;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      if( cnt[ v[ now ][ i ] ] == 0 ) continue;
      int nbns0 = bns0 + dp[ now ][ 0 ] - dp[ v[ now ][ i ] ][ 0 ];
      int nbns1 = bns1 + dp[ now ][ 0 ] - dp[ v[ now ][ i ] ][ 0 ] - 1;
      int tmp = tk( now , v[ now ][ i ] );
      if( tmp != -1 ){
        int nbns2 = bns0 + tmp - dp[ v[ now ][ i ] ][ 0 ] - 1;
        nbns1 = min( nbns1 , nbns2 );
      }
      if( cnt[ 1 ] == cnt[ v[ now ][ i ] ] )
        nbns0 = nbns1 = 0;
      DP2( v[ now ][ i ] , now , nbns0 , nbns1 );
    }
}
void solve(){
  pDP( 1 , 1 );
  DP1( 1 , 1 );
  ans = 1; mcst = dp[ 1 ][ 0 ];
  DP2( 1 , 1 , 0 , 0 );
  printf( "%d\n%d\n" , ans , mcst );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}