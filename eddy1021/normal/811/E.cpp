#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
struct DJS{
  int cc , p[ 42 ];
  void init( int n , int _cc ){
    cc = _cc;
    for( int i = 0 ; i < n ; i ++ )
      p[ i ] = i;
  }
  int f( int x ){
    return x == p[ x ] ? x : p[ x ] = f( p[ x ] );
  }
  void uni( int x , int y ){
    if( f( x ) == f( y ) ) return;
    p[ f( x ) ] = f( y );
    cc --;
  }
};
#define N 101010
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
int n , m , q , a[ 11 ][ N ];
int who[ 44 ];
inline DJS merge( const DJS& lhs , const DJS& rhs , int pos ){
  DJS djs; djs.init( n * 4 , 0 );
  djs.cc = lhs.cc + rhs.cc;
  for( int i = 0 ; i < n + n ; i ++ ){
    djs.p[ i ] = lhs.p[ i ];
    djs.p[ n + n + i ] = n + n + rhs.p[ i ];
  }
  for( int i = 0 ; i < n ; i ++ )
    if( a[ i ][ pos ] == a[ i ][ pos + 1 ] )
      djs.uni( i + n , i + n + n );
  DJS ret; ret.init( n + n , djs.cc );
  for( int i = 0 ; i < n * 4 ; i ++ )
    who[ i ] = -1;
  for( int i = 0 ; i < n ; i ++ ){
    if( who[ djs.f( i ) ] == -1 )
      who[ djs.f( i ) ] = i;
    ret.p[ i ] = who[ djs.f( i ) ];
  }
  for( int i = 0 ; i < n ; i ++ ){
    if( who[ djs.f( 3 * n + i ) ] == -1 )
      who[ djs.f( 3 * n + i ) ] = n + i;
    ret.p[ n + i ] = who[ djs.f( 3 * n + i ) ];
  }
  return ret;
}
struct SegT{
  DJS djs[ N << 2 ];
  void build_st( int no , int l , int r ){
    if( l == r ){
      djs[ no ].init( n + n , n + n );
      for( int i = 0 ; i < n ; i ++ )
        djs[ no ].uni( i , i + n );
      for( int i = 1 ; i < n ; i ++ )
        if( a[ i ][ l ] == a[ i - 1 ][ l ] )
          djs[ no ].uni( i - 1 , i );
      return;
    }
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
    djs[ no ] = merge( djs[ L( no ) ] , djs[ R( no ) ] , mid );
  }
  DJS query( int no , int l , int r , int ql , int qr ){
    if( l == ql and r == qr ) return djs[ no ];
    if( qr <= mid )
      return query( L( no ) , l , mid , ql , qr );
    if( mid < ql )
      return query( R( no ) , mid + 1 , r , ql , qr );
    return merge( query( L( no ) , l , mid , ql , mid ) ,
                  query( R( no ) , mid + 1 , r , mid + 1 , qr ) , mid );
  }
} st;
void init(){
  //n = 10;
  //m = 100000;
  //q = 100000;
  scanf( "%d%d%d" , &n , &m , &q );
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 1 ; j <= m ; j ++ )
      //a[ i ][ j ] = rand() % 100;
      scanf( "%d" , &a[ i ][ j ] );
}
void solve(){
  st.build_st( 1 , 1 , m );
  while( q -- ){
    int li , ri; scanf( "%d%d" , &li , &ri );
    //int li = rand() % m + 1;
    //int ri = rand() % m + 1;
    //if( li > ri ) swap( li , ri );
    printf( "%d\n" , st.query( 1 , 1 , m , li , ri ).cc );
  }
}
int main(){
  init();
  solve();
}