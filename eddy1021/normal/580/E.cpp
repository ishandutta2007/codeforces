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
#define N 100010
#define BS 13131
int n , m;
ll bs[ N ] , psum[ N ];
char c[ N ];
ll st[ N << 2 ] , tag[ N << 2 ];
void build(){
  psum[ 0 ] = bs[ 0 ] = 1;
  for( int i = 1 ; i < N ; i ++ )
    bs[ i ] = ( bs[ i - 1 ] * BS ) % mod7;
  for( int i = 1 ; i < N ; i ++ )
    psum[ i ] = ( psum[ i - 1 ] + bs[ i ] ) % mod7;
}
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void build_st( int no , int l , int r ){
  tag[ no ] = -1;
  if( l == r ){
    st[ no ] = c[ l ] - '0';
    return;
  }
  int mid = ( l + r ) >> 1;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  st[ no ] = ( st[ L( no ) ] * bs[ r - mid ] + st[ R( no ) ] ) % mod7;
}
void push( int no , int l , int r ){
  if( tag[ no ] != -1 && l != r ){
    int mid = ( l + r ) >> 1;
    st[ L( no ) ] = ( tag[ no ] * psum[ mid - l ] ) % mod7;
    st[ R( no ) ] = ( tag[ no ] * psum[ r - mid - 1 ] ) % mod7;
    tag[ L( no ) ] = tag[ R( no ) ] = tag[ no ];
  }
  tag[ no ] = -1;
}
void modify( int no , int l , int r , int ql , int qr , int num ){
  push( no , l , r );
  if( l == ql && r == qr ){
    st[ no ] = ( num * psum[ r - l ] ) % mod7;
    tag[ no ] = num;
    return;
  }
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) modify( L( no ) , l , mid , ql , qr , num );
  else if( mid < ql ) modify( R( no ) , mid + 1 , r , ql , qr , num );
  else{
    modify( L( no ) , l , mid , ql , mid , num );
    modify( R( no ) , mid + 1 , r , mid + 1 , qr , num );
  }
  st[ no ] = ( st[ L( no ) ] * bs[ r - mid ] + st[ R( no ) ] ) % mod7;
}
ll query( int no , int l , int r , int ql , int qr ){
  push( no , l , r );
  if( l == ql && r == qr ) return st[ no ];
  int mid = ( l + r ) >> 1;
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  ll lh = query( L( no ) , l , mid , ql , mid );
  ll rh = query( R( no ) , mid + 1 , r , mid + 1 , qr );
  return ( lh * bs[ qr - mid ] + rh ) % mod7;
}
void init(){
  n = getint(); m = getint() + getint();
  scanf( "%s" , c + 1 );
  build_st( 1 , 1 , n );
}
void solve(){
  while( m -- ){
    int kd = getint();
    int ql = getint();
    int qr = getint();
    int qn = getint();
    if( kd == 2 ){
      if( qn == qr - ql + 1 ) puts( "YES" );
      else if( query( 1 , 1 , n , ql , qr - qn ) ==
          query( 1 , 1 , n , ql + qn , qr ) ) puts( "YES" );
      else puts( "NO" );
    }else
      modify( 1 , 1 , n , ql , qr , qn );
  }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}