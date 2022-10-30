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
#define LG 20
#define N 100010
int n , m , _ , p[ N ] , dep[ N ] , mn;
vector<int> v[ N ];
vector<PII> q[ N ];
int x[ N ] , y[ N ] , lca[ N ] , a[ N ] , pr[ LG ][ N ];
vector<int> st[ LG ][ N ];
bool got[ N ];
void operator+=( vector<int>& _v , const int & _x ){
  _v.PB( _x );
  sort( ALL( _v ) );
  if( (int)_v.size() > 10 )
    _v.resize( 10 );
}
vector<int> operator+( const vector<int>& v1 , const vector<int>& v2 ){
  vector<int> _v = v1;
  for( int i = 0 ; i < (int)v2.size() ; i ++ )
    _v += v2[ i ];
  return _v;
}
int find_p( int w ){
  return w == p[ w ] ? w : p[ w ] = find_p( p[ w ] );
}
void Union( int w , int l ){
  p[ w ] = l;
}
void build(){

}
void init(){
  n = getint();
  m = getint();
  _ = getint();
  for( int i = 1 ; i <= n ; i ++ ) p[ i ] = i;
  for( int i = 1 ; i < n ; i ++ ){
    int _u = getint();
    int _v = getint();
    v[ _u ].PB( _v );
    v[ _v ].PB( _u );
  }
  for( int i = 1 ; i <= m ; i ++ )
    st[ 0 ][ getint() ] += i;
  for( int i = 1 ; i <= _ ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
    a[ i ] = getint();
    q[ x[ i ] ].PB( MP( y[ i ] , i ) );
    q[ y[ i ] ].PB( MP( x[ i ] , i ) );
  }
}
void Tarjan( int now , int ndep = 1 , int prt = 0 ){
  got[ now ] = true; dep[ now ] = ndep;
  pr[ 0 ][ now ] = prt;
  mn = max( mn , ndep );
  for( int i = 0 ; i < (int)q[ now ].size() ; i ++ )
    if( got[ q[ now ][ i ].FI ] )
      lca[ q[ now ][ i ].SE ] = find_p( q[ now ][ i ].FI );
  for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      Tarjan( v[ now ][ i ] , ndep + 1 , now );
      Union( v[ now ][ i ] , now );
    }
}
void build_table(){
  for( int i = 1 ; i < LG ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      pr[ i ][ j ] = pr[ i - 1 ][ pr[ i - 1 ][ j ] ];
      st[ i ][ j ] = st[ i - 1 ][ j ] + st[ i - 1 ][ pr[ i - 1 ][ j ] ];
    }
}
vector<int> find_ans( int dn , int up , int in ){
  int dlt = dep[ dn ] - dep[ up ] + in;
  vector<int> tans; int now = dn;
  for( int i = LG - 1 ; i >= 0 ; i -- )
    if( ( 1 << i ) & dlt ){
      tans = tans + st[ i ][ now ];
      now = pr[ i ][ now ];
    }
  return tans;
}
void solve(){
  Tarjan( 1 );
  build_table();
  for( int i = 1 ; i <= _ ; i ++ ){
    vector<int> ans;
    ans = ans + find_ans( x[ i ] , lca[ i ] , 1 );
    ans = ans + find_ans( y[ i ] , lca[ i ] , 0 );
    int _got = min( a[ i ] , (int)ans.size() );
    printf( "%d" , _got );
    for( int j = 0 ; j < _got ; j ++ )
      printf( " %d" , ans[ j ] );
    puts( "" );
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