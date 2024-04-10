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
#define N 202020
int st[ N << 2 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
void modify( int no , int l , int r , int p ){
  if( l == r ){
    st[ no ] ++;
    return;
  }
  if( p <= mid )
    modify( L( no ) , l , mid , p );
  else
    modify( R( no ) , mid + 1 , r , p );
  st[ no ] = st[ L( no ) ] + st[ R( no ) ];
}
int query( int no , int l , int r , int ql , int qr ){
  if( r < ql or l > qr ) return 0;
  if( ql <= l and r <= qr ) return st[ no ];
  return query( L( no ) , l , mid , ql , qr ) +
         query( R( no ) , mid + 1 , r , ql , qr );
}
void build(){

}
int n , m , p[ N ] , at[ N ];
vector< pair<int,int> > qry[ N ];
vector<int> vv[ N ];
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    p[ i ] = getint();
    at[ p[ i ] ] = i;
  }
  for( int i = 0 ; i < m ; i ++ ){
    int ql = getint();
    int qr = getint();
    qry[ qr ].push_back( { ql , i } );
  }
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = i ; j <= n ; j += i )
      vv[ max( at[ i ] , at[ j ] ) ].push_back( min( at[ i ] , at[ j ] ) );
}
int ans[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    for( auto j : vv[ i ] )
      modify( 1 , 1 , n , j );
    for( auto j : qry[ i ] )
      ans[ j.second ] = query( 1 , 1 , n , j.first , i );
  }
  for( int i = 0 ; i < m ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}