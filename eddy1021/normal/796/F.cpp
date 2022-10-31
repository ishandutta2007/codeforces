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
#define N 303030
const int inf = 1000000000;
int st[ N << 2 ] , tg[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void build_st( int no , int l , int r ){
  st[ no ] = tg[ no ] = inf + 1;
  if( l == r ) return;
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
}
void push( int no , int l , int r ){
  if( tg[ no ] == inf + 1 ) return;
  st[ L( no ) ] = min( st[ L( no ) ] , tg[ no ] );
  st[ R( no ) ] = min( st[ R( no ) ] , tg[ no ] );
  tg[ L( no ) ] = min( tg[ L( no ) ] , tg[ no ] );
  tg[ R( no ) ] = min( tg[ R( no ) ] , tg[ no ] );
  tg[ no ] = inf + 1;
}
void modify( int no , int l , int r , int ql , int qr , int qv ){
  if( r < ql or l > qr ) return;
  if( ql <= l and r <= qr ){
    st[ no ] = min( st[ no ] , qv );
    tg[ no ] = min( tg[ no ] , qv );
    return;
  }
  push( no , l , r );
  modify( L( no ) , l , mid , ql , qr , qv );
  modify( R( no ) , mid + 1 , r , ql , qr , qv );
  st[ no ] = max( st[ L( no ) ] , st[ R( no ) ] );
}
int query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ];
  push( no , l , r );
  return max( query( L( no ) , l , mid , ql , qr ) ,
              query( R( no ) , mid + 1 , r , ql , qr ) );
}
int st2[ N << 2 ];
void modify2( int no , int l , int r , int p , int v ){
  if( l == r ){
    st2[ no ] = v;
    return;
  }
  if( p <= mid ) modify2( L( no ) , l , mid , p , v );
  else modify2( R( no ) , mid + 1 , r , p , v );
  st2[ no ] = max( st2[ L( no ) ] , st2[ R( no ) ] );
}
int query2( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st2[ no ];
  return max( query2( L( no ) , l , mid , ql , qr ) ,
              query2( R( no ) , mid + 1 , r , ql , qr ) );
}
void build(){

}
int n , m;
void init(){
  n = getint();
  m = getint();
}
bool fix[ N ];
int a[ N ];
void no(){
  puts( "NO" );
  Bye;
}
bool ff[ N ];
void solve(){
  set<int> nd;
  build_st( 1 , 1 , n );
  while( m -- ){
    int ti = getint();
    if( ti == 1 ){
      int li = getint();
      int ri = getint();
      int xi = getint();
      int vl1 = query( 1 , 1 , n , li , ri );
      int vl2 = query2( 1 , 1 , n , li , ri );
      if( vl2 > xi ) no();
      if( vl1 < xi and vl2 < xi ) no();
      modify( 1 , 1 , n , li , ri , xi );
      if( vl2 < xi ) nd.insert( xi );
    }else{
      int ki = getint();
      int di = getint();
      if( not fix[ ki ] )
        a[ ki ] = query( 1 , 1 , n , ki , ki );
      fix[ ki ] = true;
      modify2( 1 , 1 , n , ki , di );
    }
  }
  for( int i = 1 ; i <= n ; i ++ )
    if( not fix[ i ] )
      a[ i ] = query( 1 , 1 , n , i , i );
  int tans = 0;
  for( int i = 1 ; i <= n ; i ++ )
    if( nd.count( a[ i ] ) ){
      nd.erase( a[ i ] );
      ff[ i ] = true;
      tans |= a[ i ];
    }
  if( nd.size() ) no();
  vector< pair<int,int> > v;
  for( int i = 1 ; i <= n ; i ++ ){
    if( ff[ i ] ) continue;
    a[ i ] = min( a[ i ] , inf );
    v.push_back( { a[ i ] , i } );
  }
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
  for( auto _ : v ){
    int i = _.second;
    int cc = 0;
    for( int b = 29 ; b >= 0 ; b -- )
      if( ( ( tans >> b ) & 1 ) == 0 and
          ( cc | ( 1 << b ) ) <= a[ i ] )
        cc |= ( 1 << b );
    a[ i ] = cc;
    tans |= cc;
  }
  cerr << tans << endl;
  puts( "YES" );
  for( int i = 1 ; i <= n ; i ++ )
    printf( "%d%c" , a[ i ] , " \n"[ i == n ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}