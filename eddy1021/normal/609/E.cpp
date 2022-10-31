// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
int __ = 1 , cs;
/*********default*********/
#define N 222222
int n , m , from[ N ];
int ui[ N ] , vi[ N ] , wi[ N ];
int p[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  p[ x ] = y;
}
vector< pair<PII,PII> > v;
ll ans[ N ];
struct Arc{
  int des , nxt;
  ll w; bool flag;
}e[ N + N ];
int mcnt = 1;
void build(){

}
void build_edge( int tu , int tv , int tw ){
  ++ mcnt;
  e[ mcnt ].des = tv; e[ mcnt ].nxt = from[ tu ];
  e[ mcnt ].w = tw; e[ mcnt ].flag = false; from[ tu ] = mcnt;
  ++ mcnt;
  e[ mcnt ].des = tu; e[ mcnt ].nxt = from[ tv ];
  e[ mcnt ].w = tw; e[ mcnt ].flag = false; from[ tv ] = mcnt;
}
void init(){
  n = getint(); m = getint();
  for( int i = 0 ; i < m ; i ++ ){
    ui[ i ] = getint();
    vi[ i ] = getint();
    wi[ i ] = getint();
    build_edge( ui[ i ] , vi[ i ] , wi[ i ] );
    v.PB( MP( MP( wi[ i ] , i + 1 ) , MP( ui[ i ] , vi[ i ] ) ) );
  }
  for( int i = 1 ; i <= n ; i ++ ) p[ i ] = i;
}
ll tans;
int dep[ N ];
int pp[ N ][ 20 ];
ll pm[ N ][ 20 ];
void DFS( int now , int prt , int mm = 0 , int tdep = 1 ){
  pp[ now ][ 0 ] = prt;
  pm[ now ][ 0 ] = mm;
  // printf( "%d -> %d %d\n" , now , prt , mm );
  dep[ now ] = tdep;
  for( int i = from[ now ] ; i ; i = e[ i ].nxt ){
    int des = e[ i ].des;
    if( des != prt && e[ i ].flag )
      DFS( des , now , e[ i ].w , tdep + 1 );
  }
}
ll cal( int tu , int tv , int tw ){
  // printf( "== %d %d %d ==\n" , tu , tv , tw ) 
  if( dep[ tu ] < dep[ tv ] ) swap( tu , tv );
  ll bst = 0;
  int dlt = dep[ tu ] - dep[ tv ];
  for( int i = 0 ; i < 20 ; i ++ )
    if( ( dlt >> i ) & 1 ){
      // printf( "%d\n" , i );
      bst = max( bst , pm[ tu ][ i ] );
      tu = pp[ tu ][ i ];
    }
  // printf( "== %d %d %d : %lld ==\n" , tu , tv , tw , bst );
  if( tu == tv ) return tans - bst + tw;
  for( int i = 19 ; i >= 0 ; i -- )
    if( pp[ tu ][ i ] != pp[ tv ][ i ] ){
      bst = max( bst , pm[ tu ][ i ] );
      bst = max( bst , pm[ tv ][ i ] );
      tu = pp[ tu ][ i ];
      tv = pp[ tv ][ i ];
    }
  for( int i = 0 ; i < 20 ; i ++ )
    if( pp[ tu ][ i ] == pp[ tv ][ i ] ){
      bst = max( bst , pm[ tu ][ i ] );
      bst = max( bst , pm[ tv ][ i ] );
      return tans - bst + tw;
    }
  return tans - bst + tw;
}
void solve(){
  sort( ALL( v ) );
  for( int i = 0 ; i < m ; i ++ ){
    int tw = v[ i ].FI.FI;
    int txx = v[ i ].FI.SE;
    int tu = v[ i ].SE.FI;
    int tv = v[ i ].SE.SE;
    if( find_p( tu ) != find_p( tv ) ){
      tans += tw;
      e[ txx * 2 ].flag = e[ txx * 2 + 1 ].flag = true;
      Union( tu , tv );
    }
  }
  DFS( 1 , 1 );
  for( int i = 1 ; i < 20 ; i ++ )
    for( int j = 1 ; j <= n ; j ++ ){
      pp[ j ][ i ] = pp[ pp[ j ][ i - 1 ] ][ i - 1 ];
      pm[ j ][ i ] = max( pm[ j ][ i - 1 ] , pm[ pp[ j ][ i - 1 ] ][ i - 1 ] );
      // if( i < 2 ) printf( "%d %d -> %lld %lld\n" , j , i , pm[ j - 1 ][ i ] ,
                                              // pm[ j - 1 ][ pp[ j - 1 ][ i ] ] );
    }
  for( int i = 2 ; i < 2 * m + 2 ; i += 2 )
    if( e[ i ].flag ) ans[ i / 2 ] = tans;
    else ans[ i / 2 ] = cal( ui[ i / 2 - 1 ] , vi[ i / 2 - 1 ] , wi[ i / 2 - 1 ] );
  for( int i = 1 ; i <= m ; i ++ ){
    debug( "%d %d : " , ui[ i - 1 ] , vi[ i - 1 ] );
    printf( "%lld\n" , ans[ i ] );
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