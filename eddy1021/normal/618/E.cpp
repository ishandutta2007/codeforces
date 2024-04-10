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
#define N 333333
Pt st[ N << 2 ];
int tag[ N << 2 ];
int n , m;
const LD pi = acosl( -1.0 );
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
inline Pt operator+( const Pt& p1 , const Pt& p2 ){
  return MP( p1.X + p2.X , p1.Y + p2.Y );
}
inline Pt operator*( const Pt& tp , const LD& tk ){
  return MP( tp.X * tk , tp.Y * tk );
}
inline LD operator%( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
inline LD norm( const Pt& tp ){
  return sqrt( tp % tp );
}
Pt rotate( const Pt& p1 , LD tdeg ){
  tdeg = tdeg / 180.0 * pi;
  return MP( cosl( tdeg ) * p1.X - sinl( tdeg ) * p1.Y ,
             sinl( tdeg ) * p1.X + cosl( tdeg ) * p1.Y );
}
void pull( int no ){
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
void build_st( int no , int l , int r ){
  tag[ no ] = 0;
  if( l == r ){
    st[ no ] = MP( 1 , 0 );
    return;
  }
  int mid = ( l + r ) >> 1;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  pull( no );
}
void push( int no , int l , int r ){
  if( l != r ){
    tag[ L( no ) ] = add( tag[ L( no ) ] , tag[ no ] , 360 );
    tag[ R( no ) ] = add( tag[ R( no ) ] , tag[ no ] , 360 );
    st[ L( no ) ] = rotate( st[ L( no ) ] , tag[ no ] );
    st[ R( no ) ] = rotate( st[ R( no ) ] , tag[ no ] );
  }
  tag[ no ] = 0;
}
void modify_l( int no , int l , int r , int x , int p ){
  push( no , l , r );
  if( l == r ){
    LD tl = norm( st[ no ] );
    st[ no ] = st[ no ] * ( ( tl + p ) / tl );
    return;
  }
  int mid = ( l + r ) >> 1;
  if( x <= mid ) modify_l( L( no ) , l , mid , x , p );
  else modify_l( R( no ) , mid + 1 , r , x , p );
  pull( no );
}
void modify_d( int no , int l , int r , int ql , int qr , int ddeg ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    st[ no ] = rotate( st[ no ] , ddeg );
    tag[ no ] = add( tag[ no ] , ddeg , 360 );
    return;
  }
  push( no , l , r );
  int mid = ( l + r ) >> 1;
  modify_d( L( no ) , l , mid , ql , qr , ddeg );
  modify_d( R( no ) , mid + 1 , r , ql , qr , ddeg );
  pull( no );
}
inline Pt query( int no , int l , int r ){
  push( no , l , r );
  return st[ no ];
}
void build(){

}
void init(){
  n = getint();
  m = getint();
  build_st( 1 , 1 , n );
}
void solve(){
  while( m -- ){
    int tx = getint();
    int ty = getint();
    int tz = getint();
    if( tx == 1 ) modify_l( 1 , 1 , n , ty , tz );
    else modify_d( 1 , 1 , n , ty , n , 360 - tz );
    Pt tp = query( 1 , 1 , n );
    printf( "%.12f %.12f\n" , (double)tp.X , (double)tp.Y );
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