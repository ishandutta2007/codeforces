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
// #define X FI
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
#define X 42
#define N 262145
LL p[ X ];
void build(){
  p[ 0 ] = 1;
  for( ll i = 1 ; i < X ; i ++ )
    p[ i ] = p[ i - 1 ] * X;
}
LL st[ N << 1 ] , tag1[ N << 1 ] , tag2[ N << 1 ];
int idx[ N << 1 ];
int n , q , t[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  if( l == r ){
    idx[ no ] = 0;
    while( p[ idx[ no ] ] < t[ l ] ) idx[ no ] ++;
    st[ no ] = p[ idx[ no ] ] - t[ l ];
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
void push( int no , int l , int r ){
  if( tag1[ no ] ){
    tag1[ L( no ) ] = tag1[ R( no ) ] = tag1[ no ];
    tag2[ L( no ) ] = tag2[ R( no ) ] = 0;
    idx[ L( no ) ] = 0;
    while( p[ idx[ L( no ) ] ] < tag1[ no ] ) idx[ L( no ) ] ++;
    st[ L( no ) ] = st[ R( no ) ] = p[ idx[ L( no ) ] ] - tag1[ no ];
    idx[ R( no ) ] = idx[ L( no ) ];
    tag1[ no ] = 0;
  }
  if( tag2[ no ] ){
    if( tag1[ L( no ) ] ) tag1[ L( no ) ] += tag2[ no ];
    else tag2[ L( no ) ] += tag2[ no ];
    if( tag1[ R( no ) ] ) tag1[ R( no ) ] += tag2[ no ];
    else tag2[ R( no ) ] += tag2[ no ];
    st[ L( no ) ] -= tag2[ no ];
    st[ R( no ) ] -= tag2[ no ];
    tag2[ no ] = 0;
  }
}
void modify( int no , int l , int r , int ql , int qr , LL xi ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    idx[ no ] = 0;
    while( p[ idx[ no ] ] < xi ) idx[ no ] ++;
    st[ no ] = p[ idx[ no ] ] - xi;
    tag1[ no ] = xi;
    tag2[ no ] = 0;
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , xi );
  modify( R( no ) , mid + 1 , r , ql , qr , xi );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
void normalize( int no , int l , int r ){
  if( st[ no ] >= 0 ) return;
  if( l == r ){
    while( st[ no ] < 0 ){
      st[ no ] = p[    idx[ no ] ] - st[ no ];
      st[ no ] = p[ ++ idx[ no ] ] - st[ no ];
    }
    return;
  }
  push( no , l , r );
  normalize( L( no ) , l , mid );
  normalize( R( no ) , mid + 1 , r );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
void add( int no , int l , int r , int ql , int qr , LL xi ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    if( tag1[ no ] ) tag1[ no ] += xi;
    else tag2[ no ] += xi;
    st[ no ] -= xi;
    return;
  }
  push( no , l , r );
  add( L( no ) , l , mid , ql , qr , xi );
  add( R( no ) , mid + 1 , r , ql , qr , xi );
  st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
LL query( int no , int l , int r , int x ){
  if( l == r ) return p[ idx[ no ] ] - st[ no ];
  push( no , l , r );
  if( x <= mid ) return query( L( no ) , l , mid , x );
  return query( R( no ) , mid + 1 , r , x );
}
void init(){
  n = getint(); q = getint();
  for( int i = 1 ; i <= n ; i ++ )
    t[ i ] = getint();
  build_st( 1 , 1 , n );
}
void solve(){
  while( q -- ){
    int cmd = getint();
    if( cmd == 1 ) printf( "%lld\n" , query( 1 , 1 , n , getint() ) );
    else{
      int ql = getint();
      int qr = getint();
      LL  xi = getint();
      if( cmd == 2 ) modify( 1 , 1 , n , ql , qr , xi );
      else{
        do{
          add( 1 , 1 , n , ql , qr , xi );
          normalize( 1 , 1 , n );
        }while( st[ 1 ] == 0 );
      }
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