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
#define N 101010
void build(){

}
int n , m;
set<int> s[ N ];
void build_edge( int ai , int bi ){
  s[ ai ].insert( bi );
  s[ ai ].insert( bi + n );
}
void init(){
  n = getint();
  m = getint();
  for( int i = 1 ; i <= n ; i ++ )
    build_edge( i == n ? 1 : i + 1 , i );
  for( int i = 0 ; i < m ; i ++ ){
    int ai = getint();
    int bi = getint();
    build_edge( ai , bi );
    build_edge( bi , ai );
  }
}
map< pair<int,int> , int > M;
vector<int> vv[ N * 3 ] , t[ N ];
int mid , id;
void add_edge( int ai , int bi ){
  if( M.count( { ai , bi } ) ) return;
  M[ { ai , bi } ] =
  M[ { bi , ai } ] = mid ++;
}
vector<int> nn[ N ];
void go( int now ){
  int st = now , nxt = *--s[ now ].end();
  if( nxt > n ) nxt -= n;
  s[ now ].erase( nxt );
  s[ now ].erase( nxt + n );
  vector< pair<int,int> > edges;
  edges.push_back( { now , nxt } );
  while( nxt != st ){
    int nnxt = *s[ nxt ].lower_bound( now + 1 );
    if( nnxt > n ) nnxt -= n;
    s[ nxt ].erase( nnxt );
    s[ nxt ].erase( nnxt + n );
    now = nxt;
    nxt = nnxt;
    edges.push_back( { now , nxt } );
  }
  for( auto e : edges ){
    add_edge( e.first , e.second );
    vv[ M[ e ] ].push_back( id );
    nn[ id ].push_back( e.first );
    nn[ id ].push_back( e.second );
  }
  sort( nn[ id ].begin() , nn[ id ].end() , greater<int>() );
  nn[ id ].resize( unique( nn[ id ].begin() , nn[ id ].end() ) - nn[ id ].begin() );
  nn[ id ].resize( 3 );
  ++ id;
}
int clr[ N ] , sz[ N ] , oid[ N ];
void go2( int now , int prt ){
  sz[ now ] = 1;
  for( int son : t[ now ] ){
    if( clr[ son ] or son == prt ) continue;
    go2( son , now );
    sz[ now ] += sz[ son ];
  }
}
int cen , bst;
void go3( int now , int prt , int psz ){
  int tmx = psz;
  for( int son : t[ now ] ){
    if( clr[ son ] or son == prt ) continue;
    tmx = max( tmx , sz[ son ] );
  }
  if( tmx < bst )
    bst = tmx , cen = now;
  for( int son : t[ now ] ){
    if( clr[ son ] or son == prt ) continue;
    go3( son , now , psz + sz[ now ] - sz[ son ] );
  }
}
void go( int now , int tclr ){
  go2( now , now );
  cen = now; bst = n + n;
  go3( now , now , 0 );
  clr[ cen ] = tclr;
  for( int x : t[ cen ] ){
    if( clr[ x ] ) continue;
    go( x , tclr + 1 );
  }
}
bool cmp( int id1 , int id2 ){
  for( int i = 0 ; i < 3 ; i ++ )
    if( nn[ id1 ][ i ] != nn[ id2 ][ i ] )
      return nn[ id1 ][ i ] > nn[ id2 ][ i ];
  return false;
}
void solve(){
  for( int i = n ; i >= 1 ; i -- )
    while( s[ i ].size() )
      go( i );
  for( int i = 0 ; i < mid ; i ++ )
    for( auto ii : vv[ i ] )
      for( auto jj : vv[ i ] )
        if( ii != jj )
          t[ ii ].push_back( jj );
  go( 0 , 1 );
  for( int i = 0 ; i < id ; i ++ )
    assert( 1 <= clr[ i ] and clr[ i ] <= 20 );
  for( int i = 0 ; i < id ; i ++ )
    oid[ i ] = i;
  sort( oid , oid + id , cmp );
  for( int i = 0 ; i < id ; i ++ )
    printf( "%d%c" , clr[ oid[ id - i - 1 ] ] , " \n"[ i + 1 == id ] );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}