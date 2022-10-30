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
#define N 3010
int n , m , k;
vector<int> v[ N ];
set< tuple<int,int,int> > S;
void build(){

}
void init(){
  n = getint();
  m = getint();
  k = getint();
  while( m -- ){
    int tu = getint();
    int tv = getint();
    v[ tu ].PB( tv );
    v[ tv ].PB( tu );
  }
  while( k -- ){
    int ta = getint();
    int tb = getint();
    int tc = getint();
    S.insert( MT( ta , tb , tc ) );
  }
}
typedef tuple<int,int,int,int> tiiii;
queue< tiiii > Q;
int dis[ N ][ N ];
bool got[ N ][ N ];
int bk[ N ][ N ];
void SP(){
  dis[ 1 ][ 1 ] = 0;
  got[ 1 ][ 1 ] = true;
  bk[ 1 ][ 1 ] = 1;
  Q.push( MT( 0 , 1 , 1 , 1 ) );
  while( Q.size() ){
    tiiii ti = Q.front(); Q.pop();
    int tdist = get<0>( ti );
    int now   = get<1>( ti );
    int pre   = get<3>( ti );
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
      if( S.count( MT( pre , now , v[ now ][ i ] ) ) == 0 ){
        if( !got[ now ][ v[ now ][ i ] ] ){
          got[ now ][ v[ now ][ i ] ] = true;
          dis[ now ][ v[ now ][ i ] ] = tdist + 1;
          bk[ now ][ v[ now ][ i ] ] = pre;
          Q.push( MT( tdist + 1 , v[ now ][ i ] , pre , now ) );
        }
      }
  }
}
void solve(){
  SP();
  int mdist = -1 , pre = -1;
  for( int i = 1 ; i < n ; i ++ )
    if( got[ i ][ n ] &&
        ( mdist == -1 || dis[ i ][ n ] < mdist ) ){
      mdist = dis[ i ][ n ];
      pre = i;
    }
  if( mdist == -1 ){
    puts( "-1" );
    return;
  }
  printf( "%d\n" , mdist );
  vector<int> vans;
  int now = n;
  while( now != 1 ){
    vans.PB( now );
    int npre = pre;
    pre = bk[ pre ][ now ];
    now = npre;
  }
  printf( "1" );
  for( int i = mdist - 1 ; i >= 0 ; i -- )
    printf( " %d" , vans[ i ] );
  puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}