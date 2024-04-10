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
#define N 262144
// sum ST vl(x) * m(x)
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
ll st[ N << 1 ] , vl[ N << 1 ] , mt[ N << 1 ];
ll tagm[ N << 1 ];
void build_st( int no , int l , int r ){
  tagm[ no ] = mt[ no ] = 1ll;
  if( l == r ) return;
  int mid = ( l + r ) >> 1;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
}
void push( int no , int l , int r ){
  if( tagm[ no ] == 1 ) return;
  int mid = ( l + r ) >> 1;
  if( l == mid ) mt[ L( no ) ] = mul( mt[ L( no ) ] , tagm[ no ] );
  else tagm[ L( no ) ] = mul( tagm[ L( no ) ] , tagm[ no ] );
  if( mid + 1 == r ) mt[ R( no ) ] = mul( mt[ R( no ) ] , tagm[ no ] );
  else tagm[ R( no ) ] = mul( tagm[ R( no ) ] , tagm[ no ] );
  st[ L( no ) ] = mul( st[ L( no ) ] , tagm[ no ] );
  st[ R( no ) ] = mul( st[ R( no ) ] , tagm[ no ] );
  tagm[ no ] = 1;
}
void pull( int no , int l , int r ){
  st[ no ] = add( st[ L( no ) ] , st[ R( no ) ] );
}
void modify_vl( int no , int l , int r , int pos , ll _vl ){
  push( no , l , r );
  if( l == r ){
    vl[ no ] = _vl;
    st[ no ] = mul( _vl , mt[ no ] );
    return;
  }
  int mid = ( l + r ) >> 1;
  if( pos <= mid ) modify_vl( L( no ) , l , mid , pos , _vl );
  else modify_vl( R( no ) , mid + 1 , r , pos , _vl );
  pull( no , l , r );
}
void modify_mt( int no , int l , int r , int ql , int qr , ll multi ){
  push( no , l , r );
  if( l == ql && r == qr ){
    if( l == r ) mt[ no ] = mul( mt[ no ] , multi );
    else tagm[ no ] = mul( tagm[ no ] , multi );
    st[ no ] = mul( st[ no ] , multi );
    return;
  }
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) modify_mt( L( no ) , l , mid , ql , qr , multi );
  else if( mid < ql ) modify_mt( R( no ) , mid + 1 , r , ql , qr , multi );
  else{
    modify_mt( L( no ) , l , mid , ql , mid , multi );
    modify_mt( R( no ) , mid + 1 , r , mid + 1 , qr , multi );
  }
  pull( no , l , r );
}
ll query( int no , int l , int r , int ql , int qr ){
  push( no , l , r );
  if( l == ql && r == qr ) return st[ no ];
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  return add( query( L( no ) , l , mid , ql , mid ) ,
              query( R( no ) , mid + 1 , r , mid + 1 , qr ) );
}
ll querym( int no , int l , int r , int pos ){
  push( no , l , r );
  if( l == r ) return mt[ no ];
  int mid = ( l + r ) >> 1;
  if( pos <= mid ) return querym( L( no ) , l , mid , pos );
  return querym( R( no ) , mid + 1 , r , pos );
}
int in[ N ] , out[ N ] , tidx;
vector<int> v[ N ];
ll a[ N ] , deg[ N ] , inv[ N ];
int q , tp[ N ] , qq[ N ][ 3 ];
void build(){
  for( int i = 1 ; i < N ; i ++ )
    inv[ i ] = mypow( i , mod7 - 2 , mod7 );
}
void DFS( int now ){
  in[ now ] = ++ tidx;
  for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
    DFS( v[ now ][ i ] );
  out[ now ] = tidx;
}
int n;
void init(){
  a[ 1 ] = getint(); q = getint();
  int nidx = 1;
  deg[ 1 ] = 1;
  for( int i = 1 ; i <= q ; i ++ ){
    tp[ i ] = getint();
    for( int j = 0 ; j <= 2 - tp[ i ] ; j ++ )
      qq[ i ][ j ] = getint();
    if( tp[ i ] == 1 ){
      v[ qq[ i ][ 0 ] ].PB( ++ nidx );
      qq[ i ][ 2 ] = nidx;
    }
  }
  n = nidx;
  build_st( 1 , 1 , n );
  DFS( 1 );
  modify_vl( 1 , 1 , n , in[ 1 ] , a[ 1 ] );
}
void solve(){
  for( int i = 1 ; i <= q ; i ++ ){
    if( tp[ i ] == 1 ){
      int prt = qq[ i ][ 0 ];
      int avl = qq[ i ][ 1 ];
      int x = qq[ i ][ 2 ];
      ll mdlt = mul( deg[ prt ] + 1 , inv[ deg[ prt ] ] );
      modify_vl( 1 , 1 , n , in[ x ] , avl );
      modify_mt( 1 , 1,  n , in[ prt ] , out[ prt ] , mdlt );
      deg[ x ] = 1; deg[ prt ] ++;
    }else{
      int x = qq[ i ][ 0 ];
      ll tans = query( 1 , 1 , n , in[ x ] , out[ x ] );
      tans = mul( tans , mul( deg[ x ] , mypow( querym( 1 , 1 , n , in[ x ] ) , mod7 - 2 , mod7 ) ) );
      printf( "%lld\n" , tans );
    }
    // for( int j = 1 ; j <= n ; j ++ )
      // debug( "%d : %lld\n" , j , querym( 1 , 1 , n , in[ j ] ) );
    // debug( "================\n" );
    // break;
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