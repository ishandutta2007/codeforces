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
#define N 200010
int n , q;
int pt[ N ], pv[ N ];
int dis[ N ];
ll vl[ N ];
vector< PII > v[ N ];
void build(){

}
void DFS( int now , int prt , int nd = 0 ){
  dis[ now ] = nd;
  for( int i = 0 ; i < (int)v[ now ].size() ; i ++ ){
    if( v[ now ][ i ].FI == prt ) continue;
    pt[ v[ now ][ i ].FI ] = now;
    pv[ v[ now ][ i ].FI ] = v[ now ][ i ].SE;
    DFS( v[ now ][ i ].FI , now , nd + 1 );
  }
}
void init(){
  n = getint(); q = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int tu = getint();
    int tv = getint();
    vl[ i ] = getint();
    v[ tu ].PB( MP( tv , i ) );
    v[ tv ].PB( MP( tu , i ) );
  }
  DFS( 1 , -1 );
}
int find_p( int x ){
  if( x == 1 ) return pt[ x ] = x;
  if( vl[ pv[ x ] ] != 1 ) return x;
  return pt[ x ] = find_p( pt[ x ] );
}
ll cal( int ai , int bi , ll yi ){
  while( yi && ai != bi ){
    if( dis[ ai ] < dis[ bi ] ) swap( ai , bi );
    yi /= vl[ pv[ ai ] ];
    ai = find_p( pt[ ai ] );
  }
  return yi;
}
void solve(){
  while( q -- ){
    int tp = getint();
    if( tp == 1 ){
      int ai = getint();
      int bi = getint();
      ll yi = getint();
      printf( "%lld\n" , cal( ai , bi , yi ) );
    }else{
      int tx = getint();
      ll ty = getint();
      vl[ tx ] = ty;
    }
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