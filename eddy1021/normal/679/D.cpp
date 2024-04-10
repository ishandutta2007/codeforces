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
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 514
int n , m , d[ N ][ N ];
vector<int> v[ N ];
void build(){

}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      d[ i ][ j ] = d[ j ][ i ] = ( i == j ? 0 : N );
  for( int i = 0 ; i < m ; i ++ ){
    int ai = getint();
    int bi = getint();
    d[ ai ][ bi ] = d[ bi ][ ai ] = 1;
    v[ ai ].PB( bi );
    v[ bi ].PB( ai );
  }
  for( int k = 1 ; k <= n ; k ++ )
    for( int i = 1 ; i <= n ; i ++ )
      for( int j = 1 ; j <= n ; j ++ )
        d[ i ][ j ] = min( d[ i ][ j ] , 
                           d[ i ][ k ] + d[ k ][ j ] );
}
D sum[ N ] , dsum[ N ];
bool got[ N ];
inline D cal( int pn , int pdst ){
  for( int i = 0 ; i <= n ; i ++ )
    got[ i ] = false, sum[ i ] = 0.0;
  vector<int> pos;
  for( int i = 1 ; i <= n ; i ++ )
    if( d[ pn ][ i ] == pdst ){
      for( int x : v[ i ] ){
        sum[ x ] += ( 1.0 / (D)n ) / (D)v[ i ].size();
        if( !got[ x ] ){
          got[ x ] = true;
          pos.PB( x );
        }
      }
    }
  D tans = 0.0;
  for( int i = 1 ; i <= n ; i ++ ){
    D xans = 0.0;
    for( int x : pos )
      dsum[ d[ x ][ i ] ] = max( dsum[ d[ x ][ i ] ] , sum[ x ] );
    for( int x : pos ){
      xans += dsum[ d[ x ][ i ] ];
      dsum[ d[ x ][ i ] ] = 0.0;
    }
    tans = max( tans , xans );
  }
  return tans;
}
void solve(){
  D ans = 0.0;
  for( int i = 1 ; i <= n ; i ++ ){
    D tans = 0;
    for( int dst = 0 ; dst <= n ; dst ++ ){
      int cnt = 0;
      for( int j = 1 ; j <= n ; j ++ )
        if( d[ i ][ j ] == dst ) cnt ++;
      if( cnt == 0 ) continue;
      D xans = 1.0 / (D)n;
      xans = max( xans , cal( i , dst ) );
      tans += xans;
    }
    ans = max( ans , tans );
  }
  printf( "%.12f\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}