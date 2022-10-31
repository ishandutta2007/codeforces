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
#define N 30303
#define K 202
struct DJS{
  int p[ N ];
  void init( int n ){
    for( int i = 1 ; i <= n ; i ++ )
      p[ i ] = i;
  }
  int f( int x ){
    return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
  }
  void uni( int x , int y ){
    p[ f( x ) ] = f( y );
  }
} djs;
int n , k , d[ K ][ N ] , who[ N ];
void build(){

}
void imp(){
  puts( "-1" );
  exit(0);
}
void init(){
  n = getint();
  k = getint();
  for( int i = 0 ; i < k ; i ++ ){
    for( int j = 1 ; j <= n ; j ++ ){
      d[ i ][ j ] = getint();
      if( d[ i ][ j ] == 0 ){
        if( who[ i ] ) imp();
        who[ i ] = j;
      }
    }
  }
  djs.init( n );
}
set< pair<int,int> > S;
int nd[ K ][ N ] , dep[ N ];
bool gt[ N ];
vector< int > v[ N ];
void go( int now , int prt , int tdep ){
  if( dep[ now ] ) imp();
  dep[ now ] = tdep;
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    go( son , now , tdep + 1 );
  }
}
void add_edge( int ai , int bi ){
  if( ai > bi ) swap( ai , bi );
  auto it = S.find( { ai , bi } );
  if( it != S.end() ) return;
  if( djs.f( ai ) == djs.f( bi ) ) imp();
  gt[ ai ] = gt[ bi ] = true;
  djs.uni( ai , bi );
  S.insert( { ai , bi } );
  v[ ai ].push_back( bi );
  v[ bi ].push_back( ai );
}
void output(){
  for( auto i : S )
    printf( "%d %d\n" , i.first , i.second );
  Bye;
}
vector< pair<int,int> > wt[ N ];
void cons( int id ){
  if( wt[ id ].empty() ) return;
  sort( wt[ id ].begin() , wt[ id ].end() );
  vector<int> dd;
  for( auto i : wt[ id ] )
    dd.push_back( i.first );
  dd.resize( unique( dd.begin() , dd.end() ) - dd.begin() );
  if( dd[ 0 ] == 0 ) imp();
  for( size_t i = 0 ; i < dd.size() ; i ++ )
    if( dd[ i ] != (int)i + 1 ) imp();
  int pre = id;
  for( size_t i = 0 ; i < wt[ id ].size() ; i ++ ){
    add_edge( pre , wt[ id ][ i ].second );
    if( i + 1 < wt[ id ].size() and
        wt[ id ][ i ].first != wt[ id ][ i + 1 ].first )
      pre = wt[ id ][ i ].second;
  }
}
void gogo( int id , int now , int prt , int tdep ){
  if( d[ id ][ now ] != tdep ) imp();
  for( int son : v[ now ] ){
    if( son == prt ) continue;
    gogo( id , son , now , tdep + 1 );
  }
}
void recheck(){
  if( (int)S.size() + 1 != n ) imp();
  for( int i = 0 ; i < k ; i ++ )
    gogo( i , who[ i ] , who[ i ] , 0 );
}
void solve2(){
  for( int i = 1 ; i < k ; i ++ ){
    if( d[ 0 ][ who[ i ] ] != d[ i ][ who[ 0 ] ] )
      imp();
    int dst = d[ 0 ][ who[ i ] ];
    for( int j = 1 ; j <= n ; j ++ )
      if( d[ 0 ][ j ] + d[ i ][ j ] == dst ){
        if( nd[ i ][ d[ 0 ][ j ] ] ) imp();
        nd[ i ][ d[ 0 ][ j ] ] = j;
      }
    for( int j = 1 ; j <= dst ; j ++ ){
      if( !nd[ i ][ j ] ) imp();
      add_edge( nd[ i ][ j - 1 ] , nd[ i ][ j ] );
    }
  }
  go( who[ 0 ] , -1 , 1 );
  for( int i = 1 ; i <= n ; i ++ ){
    if( gt[ i ] ) continue;
    int bst = who[ 0 ];
    for( int j = 1 ; j < k ; j ++ ){
      int tmp = who[ 0 ];
      int dlt = abs( d[ 0 ][ i ] - d[ j ][ i ] );
      if( dlt == d[ 0 ][ who[ j ] ] ){
        if( d[ 0 ][ i ] > d[ j ][ i ] )
          tmp = who[ j ];
      }else{
        if( dlt % 2 != d[ 0 ][ who[ j ] ] % 2 ) imp();
        dlt = d[ j ][ i ] - d[ 0 ][ i ];
        int at = ( d[ 0 ][ who[ j ] ] - dlt ) / 2;
        tmp = nd[ j ][ at ];
      }
      if( dep[ tmp ] > dep[ bst ] )
        bst = tmp;
    }
    wt[ bst ].push_back( { d[ 0 ][ i ] - dep[ bst ] + 1 , i } );
  }
  for( int i = 1 ; i <= n ; i ++ )
    cons( i );
  recheck();
  output();
}
void solve(){
  if( k == 1 ){
    vector<int> vv;
    for( int i = 1 ; i <= n ; i ++ )
      vv.push_back( d[ 0 ][ i ] );
    sort( vv.begin() , vv.end() );
    if( vv[ 0 ] != 0 ) imp();
    if( vv[ 1 ] == 0 ) imp();
    vv.resize( unique( vv.begin() , vv.end() ) - vv.begin() );
    for( size_t i = 0 ; i < vv.size() ; i ++ )
      if( vv[ i ] != (int)i ) imp();
    vector< pair<int,int> > v2;
    for( int i = 1 ; i <= n ; i ++ )
      v2.push_back( { d[ 0 ][ i ] , i } );
    sort( v2.begin() , v2.end() );
    int pre = v2[ 0 ].second;
    for( size_t i = 1 ; i < v2.size() ; i ++ ){
      add_edge( pre , v2[ i ].second );
      if( i + 1 < v2.size() and v2[ i ].first != v2[ i + 1 ].first )
        pre = v2[ i ].second;
    }
    output();
  }
  solve2();
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}