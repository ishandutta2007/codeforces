// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 505050
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
LL st[ N << 2 ];
LL mx[ N << 2 ];
LL mn[ N << 2 ];
LL as[ N << 2 ];
void push( int no , int l , int r ){
  if( as[ no ] == 0 ) return;
  mx[ L( no ) ] = mn[ L( no ) ] =
  mx[ R( no ) ] = mn[ R( no ) ] = as[ no ];
  st[ L( no ) ] = mx[ L( no ) ] * ( mid - l + 1 );
  st[ R( no ) ] = mx[ R( no ) ] * ( r - mid );
  as[ L( no ) ] = as[ R( no ) ] = as[ no ];
  as[ no ] = 0;
}
void maxify( int no , int l , int r , int ql , int qr , LL to ){
  if( r < ql or l > qr ) return;
  if( mn[ no ] >= to ) return;
  if( ql <= l and r <= qr  and mx[ no ] <= to ){
    mx[ no ] = mn[ no ] = to;
    st[ no ] = mx[ no ] * ( r - l + 1 );
    as[ no ] = to;
    return;
  }
  push( no , l , r );
  maxify( L( no ) , l , mid , ql , qr , to );
  maxify( R( no ) , mid + 1 , r , ql , qr , to );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
  mx[ no ] = max( mx[ L( no ) ] , mx[ R( no ) ] );
  mn[ no ] = min( mn[ L( no ) ] , mn[ R( no ) ] );
}  
void build(){

}
LL n , p , q , r;
vector< pair<int,int> > v[ N ];
void init(){
  n = getint();
  p = getint();
  q = getint();
  r = getint();
  while( n -- ){
    LL pi = getint();
    LL qi = getint();
    LL ri = getint();
    v[ pi ].push_back( { qi , r } );
    v[ pi ].push_back( { q , ri } );
    v[ p ].push_back( { qi , ri } );
  }
}
void solve(){
  LL ans = p * q * r;
  for( int i = p ; i >= 1 ; i -- ){
    for( auto j : v[ i ] )
      maxify( 1 , 1 , q , 1 , j.first , j.second );
    //printf( "%d %lld\n" , i , st[ 1 ] );
    ans -= st[ 1 ];
  }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}