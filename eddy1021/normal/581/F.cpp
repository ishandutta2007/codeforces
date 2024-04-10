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
#define N 5010
int n , deg[ N ] , sn;
vector<int> v[ N ];
void build(){

}
void init(){
  n = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int tu = getint();
    int tv = getint();
    v[ tu ].PB( tv );
    v[ tv ].PB( tu );
    deg[ tu ] ++;
    deg[ tv ] ++;
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( deg[ i ] != 1 )
      sn = i;
}
int dp[ 2 ][ N ][ N ];
int tdp[ 2 ][ N ];
int lf[ N ] , all;
int DFS1( int now , int prt = -1 ){
  for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt )
      lf[ now ] += DFS1( v[ now ][ i ] , now );
  if( lf[ now ] == 0 ) lf[ now ] = 1;
  return lf[ now ];
}
bool cmp( int _x , int _y ){
  return lf[ _x ] > lf[ _y ];
}
void DP( int now , int prt = -1 ){
  for( int i = 0 ; i <= min( lf[ now ] , all ) ; i ++ )
    dp[ 0 ][ now ][ i ] = 
    dp[ 1 ][ now ][ i ] = N;
  if( lf[ now ] == 1 ){
    dp[ 0 ][ now ][ 0 ] = 0;
    dp[ 1 ][ now ][ 1 ] = 0;
    return;
  }
  bool first = true;
  for( int _ = 0 ; _ < (int)v[ now ].size() ; _ ++ ){
    int son = v[ now ][ _ ];
    if( son == prt ) continue;
    DP( son , now );
    if( first ){
      first = false;
      for( int i = 0 ; i <= min( lf[ son ] , all ) ; i ++ ){
        dp[ 0 ][ now ][ i ] = min( dp[ 0 ][ son ][ i ] ,
                                   dp[ 1 ][ son ][ i ] + 1 );
        dp[ 1 ][ now ][ i ] = min( dp[ 1 ][ son ][ i ] ,
                                   dp[ 0 ][ son ][ i ] + 1 );
      }
    }else{
      for( int i = 0 ; i <= min( lf[ now ] , all ) ; i ++ ){
        tdp[ 0 ][ i ] = dp[ 0 ][ now ][ i ],
        tdp[ 1 ][ i ] = dp[ 1 ][ now ][ i ];
        dp[ 0 ][ now ][ i ] =
        dp[ 1 ][ now ][ i ] = N;
      }
      for( int i = 0 ; i <= min( lf[ son ] , all ) ; i ++ )
        for( int j = min( lf[ now ] , all ) ; j >= i ; j --  ){
          int nxtdp0 = tdp[ 0 ][ j - i ] +
                       min( dp[ 0 ][ son ][ i ] ,
                            dp[ 1 ][ son ][ i ] + 1 );
          int nxtdp1 = tdp[ 1 ][ j - i ] +
                       min( dp[ 1 ][ son ][ i ] ,
                            dp[ 0 ][ son ][ i ] + 1 );
          dp[ 0 ][ now ][ j ] = min( dp[ 0 ][ now ][ j ] , nxtdp0 );
          dp[ 1 ][ now ][ j ] = min( dp[ 1 ][ now ][ j ] , nxtdp1 );
        }
    }
  }
//  printf( "%d\n" , now );
//  for( int i = 0 ; i <= lf[ now ] ; i ++ )
//    printf( "%d : (%d %d)\n" , i , dp[ 0 ][ now ][ i ] ,
//                                 dp[ 1 ][ now ][ i ] );
}
void solve(){
  DFS1( sn );
  all = lf[ sn ] / 2;
  for( int i = 1 ; i <= n ; i ++ )
    sort( ALL( v[ i ] ) , cmp );
  DP( sn );
  printf( "%d\n" , min( dp[ 0 ][ sn ][ all ] ,
                        dp[ 1 ][ sn ][ all ] ) );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}