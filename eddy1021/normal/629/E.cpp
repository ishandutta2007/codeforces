// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
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
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 101010
int p[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  p[ x ] = y;
}
void build(){

}
int n , m;
vector<int> v[ N ] , q[ N ];
#define K 20
int a[ N ] , b[ N ] , pp[ K ][ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].PB( vi );
    v[ vi ].PB( ui );
  }
  for( int i = 1 ; i <= m ; i ++ ){
    a[ i ] = getint();
    b[ i ] = getint();
    q[ a[ i ] ].PB( i );
    q[ b[ i ] ].PB( i );
  }
  for( int i = 1 ; i <= n ; i ++ )
    p[ i ] = i;
}
ll dp[ N ] , s[ N ] , udp[ N ] , dep[ N ];
void DP( int now , int prt , int tdep ){
  s[ now ] = 1; dp[ now ] = 0; dep[ now ] = tdep;
  pp[ 0 ][ now ] = prt;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      DP( v[ now ][ i ] , now , tdep + 1 );
      s[ now ] += s[ v[ now ][ i ] ];
      dp[ now ] += dp[ v[ now ][ i ] ] + s[ v[ now ][ i ] ];
    }
}
inline int parent( int xx , int oo ){
  for( int i = 0 ; i < K ; i ++ )
    if( ( oo >> i ) & 1 )
      xx = pp[ i ][ xx ];
  return xx;
}
LD ans[ N ];
bool got[ N ];
void DP2( int now , int prt , ll tdp , ll ts ){
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt ){
      ll nts = ts + s[ now ] - s[ v[ now ][ i ] ];
      ll ntdp = tdp + dp[ now ] - dp[ v[ now ][ i ] ] - s[ v[ now ][ i ] ] + nts;
      DP2( v[ now ][ i ] , now , ntdp , nts );
      Union( v[ now ][ i ] , now );
    }
  got[ now ] = true;
  for( size_t i = 0 ; i < q[ now ].size() ; i ++ ){
    int qi = q[ now ][ i ];
    int tn = a[ qi ];
    if( tn == now ) tn = b[ qi ];
    if( !got[ tn ] ) continue;
    int lca = find_p( tn );
    int dst = dep[ tn ] + dep[ now ] - 2 * dep[ lca ];
    if( lca == now ){
      int nson = parent( tn , dep[ tn ] - dep[ now ] - 1 );
      ll as = ts + s[ now ] - s[ nson ];
      ll adp = tdp + dp[ now ] - dp[ nson ] - s[ nson ];
      LD dp1 = (LD)dp[ tn ] / (LD)s[ tn ];
      LD dp2 = (LD)adp / (LD)as;
      ans[ qi ] = dp1 + dp2 + (LD)dst + 1.0;
    }else{
      LD dp1 = (LD)dp[ tn ] / (LD)s[ tn ];
      LD dp2 = (LD)dp[ now ] / (LD)s[ now ];
      ans[ qi ] = dp1 + dp2 + (LD)dst + 1.0;
    }
  }
}
void solve(){
  DP( 1 , -1 , 0 );
  for( int i = 1 ; i < K ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      pp[ i ][ j ] = pp[ i - 1 ][ pp[ i - 1 ][ j ] ];
  DP2( 1 , -1 , 0 , 0 );
  for( int i = 1 ; i <= m ; i ++ )
    printf( "%.12f\n" , (D)ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}