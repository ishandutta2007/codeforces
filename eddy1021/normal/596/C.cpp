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
#define N 202020
int BIT[ N ];
int lb( int x ){ return x & (-x); }
void modify( int pos , int num ){
  while( pos < N ){
    BIT[ pos ] = max( BIT[ pos ] , num );
    pos += lb( pos );
  }
}
int query( int pos ){
  int mx = 0;
  while( pos ){
    mx = max( BIT[ pos ] , mx );
    pos -= lb( pos );
  }
  return mx;
}
void build(){

}
bool inq[ N + N ];
vector<int> v;
deque<PII> dq[ N + N ];
int n , x[ N ] , y[ N ] , no[ N ];
int ax[ N ] , ay[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    dq[ y[ i ] - x[ i ] + N ].PB( MP( x[ i ] , i ) );
    if( !inq[ y[ i ] - x[ i ] + N ] ){
      inq[ y[ i ] - x[ i ] + N ] = true;
      v.PB( y[ i ] - x[ i ] + N );
    }
  }
  for( int i = 0 ; i < (int)v.size() ; i ++ )
    sort( ALL( dq[ v[ i ] ] ) );
  for( int i = 1 ; i <= n ; i ++ ){
    int mi = getint();
    if( (int)dq[ mi + N ].size() == 0 ){
      puts( "NO" );
      exit( 0 );
    }
    PII tp = dq[ mi + N ].front(); dq[ mi + N ].pop_front();
    no[ tp.SE ] = i;
    ax[ i ] = x[ tp.SE ];
    ay[ i ] = y[ tp.SE ];
  }
}
vector< pair<PII,int> > tv;
void solve(){
  for( int i = 1 ; i <= n ; i ++ )
    tv.PB( MP( MP( y[ i ] , x[ i ] ) , no[ i ] ) );
  sort( ALL( tv ) );
  for( int i = 0 ; i < n ; i ++ ){
    int nx = tv[ i ].FI.SE;
    int tmp = query( nx + 1 );
    if( tmp > tv[ i ].SE ){
      puts( "NO" );
      exit( 0 );
    }
    modify( nx + 1 , tv[ i ].SE );
  }
  puts( "YES" );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d %d\n" , ax[ i ] , ay[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}