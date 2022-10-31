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
#define N 1010101
int st[ 4 ][ N << 2 ] , tag[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int n , m;
char c[ N ];
inline void pull( int no ){
  st[ 0 ][ no ] = st[ 0 ][ L( no ) ] + st[ 0 ][ R( no ) ];
  st[ 1 ][ no ] = st[ 1 ][ L( no ) ] + st[ 1 ][ R( no ) ];
  st[ 2 ][ no ] = max( st[ 2 ][ L( no ) ] + st[ 1 ][ R( no ) ] ,
                       st[ 0 ][ L( no ) ] + st[ 2 ][ R( no ) ] );
  st[ 3 ][ no ] = max( st[ 3 ][ L( no ) ] + st[ 0 ][ R( no ) ] ,
                       st[ 1 ][ L( no ) ] + st[ 3 ][ R( no ) ] );
}
void build_st( int no , int l , int r ){
  if( l == r ){
    if( c[ l ] == '4' ){
      st[ 0 ][ no ] = st[ 2 ][ no ] = st[ 3 ][ no ] = 1;
      st[ 1 ][ no ] = 0;
    }else{
      st[ 1 ][ no ] = st[ 2 ][ no ] = st[ 3 ][ no ] = 1;
      st[ 0 ][ no ] = 0;
    }
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  pull( no );
}
void push( int no , int l , int r ){
  if( tag[ no ] && l < r ){
    tag[ L( no ) ] ^= 1;
    tag[ R( no ) ] ^= 1;
    swap( st[ 0 ][ L( no ) ] , st[ 1 ][ L( no ) ] );
    swap( st[ 2 ][ L( no ) ] , st[ 3 ][ L( no ) ] );
    swap( st[ 0 ][ R( no ) ] , st[ 1 ][ R( no ) ] );
    swap( st[ 2 ][ R( no ) ] , st[ 3 ][ R( no ) ] );
  }
  tag[ no ] = 0;
}
void modify( int no , int l , int r , int ql , int qr ){
  if( l > qr || r < ql ) return;
  if( ql <= l && r <= qr ){
    tag[ no ] ^= 1;
    swap( st[ 0 ][ no ] , st[ 1 ][ no ] );
    swap( st[ 2 ][ no ] , st[ 3 ][ no ] );
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr );
  modify( R( no ) , mid + 1 , r , ql , qr );
  pull( no );
}
tuple<int,int,int> query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return MT( st[ 0 ][ no ] , st[ 1 ][ no ] , st[ 2 ][ no ] );
  push( no , l , r );
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql  ) return query( R( no ) , mid + 1 , r , ql , qr );
  tuple<int,int,int> tl = query( L( no ) , l , mid , ql , mid );
  tuple<int,int,int> tr = query( R( no ) , mid + 1 , r , mid + 1 , qr );
  int c4 = get<0>( tl ) + get<0>( tr );
  int c7 = get<1>( tl ) + get<1>( tr );
  int c47 = max( get<0>( tl ) + get<2>( tr ) , get<2>( tl ) + get<1>( tr ) );
  return MT( c4 , c7 , c47 );
}
void build(){

}
void init(){
  n = getint(); m = getint();
  scanf( "%s" , c + 1 );
  build_st( 1 , 1 , n );
}
void solve(){
  while( m -- ){
    char cc[ 100 ];
    scanf( "%s" , cc );
    if( cc[ 0 ] == 'c' ){
      tuple<int,int,int> ti = query( 1 , 1 , n , 1 , n );
      printf( "%d\n" , max( get<0>( ti ) , max( get<1>( ti ) , get<2>( ti ) ) ) );
    }else{
      int l = getint();
      int r = getint();
      modify( 1 , 1 , n , l , r );
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