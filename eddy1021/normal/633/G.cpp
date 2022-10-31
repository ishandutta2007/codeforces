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
#define M 1000
int n , m , a[ N ] , v[ N ] , in[ N ] , out[ N ] , tcnt;
vector<int> g[ N ];
bitset<M> st[ N << 2 ] , msk;
int tag[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  st[ no ].reset();
  if( l == r ){
    st[ no ].set( v[ l ] );
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = st[ L( no ) ] | st[ R( no ) ];
}
inline void rotate( bitset<M>& bs , int sft ){
  bs = ( ( bs << sft ) | ( bs >> ( m - sft ) ) ) & msk;
}
inline void push( int no , int l , int r ){
  if( tag[ no ] && l != r ){
    rotate( st[ L( no ) ] , tag[ no ] );
    rotate( st[ R( no ) ] , tag[ no ] );
    tag[ L( no ) ] = add( tag[ L( no ) ] , tag[ no ] , m );
    tag[ R( no ) ] = add( tag[ R( no ) ] , tag[ no ] , m );
  }
  tag[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr , int sft ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    rotate( st[ no ] , sft );
    tag[ no ] = add( tag[ no ] , sft , m );
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , sft );
  modify( R( no ) , mid + 1 , r , ql , qr , sft );
  st[ no ] = st[ L( no ) ] | st[ R( no ) ];
}
bitset<M> query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return st[ no ];
  push( no , l , r );
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return query( L( no ) , l , mid , ql , mid ) |
         query( R( no ) , mid + 1 , r , mid + 1 , qr );
}
bitset<M> pri;
void build(){
}
void DFS( int now , int prt ){
  in[ now ] = ++ tcnt;
  for( size_t i = 0 ; i < g[ now ].size() ; i ++ )
    if( g[ now ][ i ] != prt )
      DFS( g[ now ][ i ] , now );
  out[ now ] = tcnt;
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = getint() % m;
  for( int i = 1 ; i < n ; i ++ ){
    int ui = getint();
    int vi = getint();
    g[ ui ].PB( vi );
    g[ vi ].PB( ui );
  }
  DFS( 1 , -1 );
  for( int i = 1 ; i <= n ; i ++ )
    v[ in[ i ] ] = a[ i ];
  build_st( 1 , 1 , n );
  for( int i = 2 ; i < m ; i ++ ) pri[ i ] = 1;
  for( int i = 2 ; i < m ; i ++ ) if( pri[ i ] )
    for( int j = i + i ; j < m ; j += i )
      pri[ j ] = 0;
  for( int i = 0 ; i < m ; i ++ ) msk[ i ] = 1;
}
void solve(){
  int q = getint(); while( q -- ){
    int cmd = getint();
    int qv = getint();
    if( cmd == 1 ){
      int qx = getint() % m;
      if( qx == 0 ) continue;
      modify( 1 , 1 , n , in[ qv ] , out[ qv ] , qx );
    }else{
      bitset<M> bs = query( 1 , 1 , n , in[ qv ] , out[ qv ] );
      printf( "%d\n" , (int)( bs & pri ).count() );
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