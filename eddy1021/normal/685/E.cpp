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
#define N 1010
#define M 202020
void build(){

}
int n , m , q , x[ M ] , y[ M ];
vector< PII > qry;
int ql[ M ] , qr[ M ] , qs[ M ] , qt[ M ];
bool ans[ M ];
int mn[ N ][ N ];
inline void add( int idx ){
  mn[ x[ idx ] ][ y[ idx ] ] =
  mn[ y[ idx ] ][ x[ idx ] ] = idx;
  for( int i = 1 ; i <= n ; i ++ ){
    mn[ x[ idx ] ][ i ] = min( mn[ x[ idx ] ][ i ] , mn[ y[ idx ] ][ i ] );
    mn[ y[ idx ] ][ i ] = min( mn[ y[ idx ] ][ i ] , mn[ x[ idx ] ][ i ] );
  }
}
void init(){
  n = getint(); m = getint(); q = getint();
  for( int i = 1 ; i <= m ; i ++ ){
    x[ i ] = getint();
    y[ i ] = getint();
  }
  for( int i = 0 ; i < q ; i ++ ){
    ql[ i ] = getint();
    qr[ i ] = getint();
    qs[ i ] = getint();
    qt[ i ] = getint();
    qry.push_back( { ql[ i ] , i } );
    if( qs[ i ] == qt[ i ] )
      ans[ i ] = true;
  }
  sort( ALL( qry ) );
  reverse( ALL( qry ) );
}
void solve(){
  int midx = m;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      mn[ i ][ j ] = M;
  for( size_t _ = 0 ; _ < qry.size() ; _ ++ ){
    int i = qry[ _ ].SE;
    while( midx >= 1 && midx >= ql[ i ] ) add( midx -- );
    if( mn[ qs[ i ] ][ qt[ i ] ] <= qr[ i ] )
      ans[ i ] = true;
  }
  for( int i = 0 ; i < q ; i ++ )
    puts( ans[ i ] ? "Yes" : "No" );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}