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
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 202020
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int st[ N << 2 ][ 2 ];
bool swp[ N << 2 ];
void modify( int no , int l , int r , int p , int who ){
  if( l == r ){
    st[ no ][ who ] ++;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p , who );
  else
    modify( R( no ) , mid + 1 , r , p , who );
  for( int i = 0 ; i < 2 ; i ++ )
    st[ no ][ i ] = st[ L( no ) ][ i ] + st[ R( no ) ][ i ];
}
void push( int no , int l , int r ){
  if( not swp[ no ] ) return;
  for( int id : { L( no ) , R( no ) } ){
    swp[ id ] = not swp[ id ];
    swap( st[ id ][ 0 ] , st[ id ][ 1 ] );
  }
  swp[ no ] = false;
}
void swtch( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    swp[ no ] = not swp[ no ];
    swap( st[ no ][ 0 ] , st[ no ][ 1 ] );
    return;
  }
  push( no , l , r );
  swtch( L( no ) , l , mid , ql , qr );
  swtch( R( no ) , mid + 1 , r , ql , qr );
  for( int i = 0 ; i < 2 ; i ++ )
    st[ no ][ i ] = st[ L( no ) ][ i ] + st[ R( no ) ][ i ];
}
int query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ][ 1 ];
  push( no , l , r );
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
void build(){

}
int n , t[ N ] , in[ N ] , out[ N ] , stmp;
vector<int> v[ N ];
void go( int now ){
  in[ now ] = ++ stmp;
  for( int son : v[ now ] )
    go( son );
  out[ now ] = stmp;
}
void init(){
  n = getint();
  for( int i = 2 ; i <= n ; i ++ )
    v[ getint() ].push_back( i );
  go( 1 );
  for( int i = 1 ; i <= n ; i ++ )
    t[ i ] = getint();
  for( int i = 1 ; i <= n ; i ++ )
    modify( 1 , 1 , n , in[ i ] , t[ i ] );
}
char cmd[ 9 ];
int qv;
void solve(){
  int q = getint(); while( q -- ){
    scanf( "%s" , cmd );
    qv = getint();
    if( cmd[ 0 ] == 'p' )
      swtch( 1 , 1 , n , in[ qv ] , out[ qv ] );
    else
      printf( "%d\n" , query( 1 , 1 , n , in[ qv ] , out[ qv ] ) );
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