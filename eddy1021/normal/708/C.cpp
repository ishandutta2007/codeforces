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
#define N 404040
void build(){

}
int n , sz[ N ] , bst[ N ] , n2;
vector< int > v[ N ] , xl[ N ] , xr[ N ];
bool pos[ N ];
void init(){
  n = getint(); n2 = n / 2;
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    v[ ui ].push_back( vi );
    xl[ ui ].push_back( 0 );
    xr[ ui ].push_back( 0 );
    v[ vi ].push_back( ui );
    xl[ vi ].push_back( 0 );
    xr[ vi ].push_back( 0 );
  }
}
void go( int now , int prt ){
  sz[ now ] = bst[ now ] = 1;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    go( son , now );
    sz[ now ] += sz[ son ];
    if( bst[ son ] <= n2 ){
      bst[ now ] = max( bst[ now ] , bst[ son ] );
      xl[ now ][ i ] = bst[ son ];
      xr[ now ][ i ] = bst[ son ];
    }
  }
  if( sz[ now ] <= n2 )
    bst[ now ] = sz[ now ];
}
void go2( int now , int prt , int psz , int pbst ){
  int mx = psz , mbst = pbst;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    if( sz[ son ] > mx ){
      mx = sz[ son ];
      mbst = bst[ son ];
    }
  }
  if( mx <= n2 || ( mbst <= n2 && mx - mbst <= n2 ) )
    pos[ now ] = true;
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ ){
    int son = v[ now ][ i ];
    if( son == prt ) continue;
    int nxtsz = psz + sz[ now ] - sz[ son ];
    int nxtbst = pbst;
    if( i > 0 )
      nxtbst = max( nxtbst , xl[ now ][ i - 1 ] );
    if( i + 1 < v[ now ].size() )
      nxtbst = max( nxtbst , xr[ now ][ i + 1 ] );
    if( nxtsz <= n2 )
      nxtbst = max( nxtbst , nxtsz );
    go2( son , now , nxtsz , nxtbst );
  }
}
void solve(){
  go( 1 , 1 );
  for( int i = 1 ; i <= n ; i ++ ){
    int tsz = (int)v[ i ].size();
    for( int j = 1 ; j < tsz ; j ++ )
      xl[ i ][ j ] = max( xl[ i ][ j ] , xl[ i ][ j - 1 ] );
    for( int j = tsz - 2 ; j >= 0 ; j -- )
      xr[ i ][ j ] = max( xr[ i ][ j ] , xr[ i ][ j + 1 ] );
  }
  go2( 1 , 1 , 0 , 0 );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , pos[ i ] ? 1 : 0 , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}