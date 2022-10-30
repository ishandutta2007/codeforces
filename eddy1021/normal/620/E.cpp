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
#define N 456456
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void build(){

}
int n , m , in[ N ] , out[ N ] , clr[ N ] , pc[ N ] , stap;
vector<int> v[ N ];
ll st[ N << 2 ] , tag[ N << 2 ];
void build_st( int no , int l , int r ){
  tag[ no ] = 0;
  if( l == r ){
    st[ no ] = 1ll << pc[ l ];
    return;
  }
  int mid = ( l + r ) >> 1;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = st[ L( no ) ] | st[ R( no ) ];
}
void push( int no , int l , int r ){
  if( tag[ no ] && l < r ){
    st[ L( no ) ] = tag[ L( no ) ] =
    st[ R( no ) ] = tag[ R( no ) ] = tag[ no ];
  }
  tag[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr , int nc ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    st[ no ] = tag[ no ] = 1ll << nc;
    return;
  }
  push( no , l , r );
  int mid = ( l + r ) >> 1;
  modify( L( no ) , l , mid , ql , qr , nc );
  modify( R( no ) , mid + 1 , r , ql , qr , nc );
  st[ no ] = st[ L( no ) ] | st[ R( no ) ];
}
ll query( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return 0ll;
  if( ql <= l && r <= qr ) return st[ no ];
  push( no , l , r );
  int mid = ( l + r ) >> 1;
  return query( L( no ) , l , mid , ql , qr ) |
         query( R( no ) , mid + 1 , r , ql , qr );
}
void DFS( int now , int prt ){
  in[ now ] = ++ stap;
  pc[ stap ] = clr[ now ];
  for( size_t i = 0 ; i < v[ now ].size() ; i ++ )
    if( v[ now ][ i ] != prt )
      DFS( v[ now ][ i ] , now );
  out[ now ] = stap;
}
void init(){
  n = getint(); m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    clr[ i ] = getint();
  for( int i = 1 ; i < n ; i ++ ){
    int ai = getint();
    int bi = getint();
    v[ ai ].PB( bi );
    v[ bi ].PB( ai );
  }
  DFS( 1 , -1 );
  build_st( 1 , 1 , n );
}
void solve(){
  while( m -- ){
    int d = getint();
    int u = getint();
    if( d == 2 )
      printf( "%d\n" , __builtin_popcountll( query( 1 , 1 , n , in[ u ] , out[ u ] ) ) );
    else
      modify( 1 , 1 , n , in[ u ] , out[ u ] , getint() );
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