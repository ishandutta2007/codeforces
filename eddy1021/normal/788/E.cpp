#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 102110
const int mod = 1000000007;
inline int add( int a , int b ){
  a += b;
  return a >= mod ? a - mod : a;
}
inline int sub( int a , int b ){
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int mul( LL a , LL b ){
  a *= b;
  return a >= mod ? a % mod : a;
}
struct Mat{
  int a[ 4 ][ 4 ];
  Mat( int def = 1 ){
    for( int i = 0 ; i < 4 ; i ++ )
      for( int j = 0 ; j < 4 ; j ++ )
        a[ i ][ j ] = ( i == j ? def : 0 );
  }
  Mat operator*( const Mat& rhs ) const{
    Mat res( 0 );
    for( int i = 0 ; i < 4 ; i ++ )
      for( int j = 0 ; j < 4 ; j ++ )
        for( int k = 0 ; k < 4 ; k ++ )
          res.a[ i ][ j ] = add( res.a[ i ][ j ],
                                 mul( a[ i ][ k ] , rhs.a[ k ][ j ] ) );
    return res;
  }
};
struct SegT{
  vector<Mat> st;
  int sz;
  void init( int _sz ){
    sz = _sz;
    st.resize( _sz << 2 );
  }
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
  void modify( int no , int l , int r , int p , int ls , int ms , int rs ){
    if( l == r ){
      st[ no ].a[ 0 ][ 1 ] = ls;
      st[ no ].a[ 1 ][ 2 ] = ms;
      st[ no ].a[ 2 ][ 3 ] = rs;
      return;
    }
    if( p <= mid ) modify( L( no ) , l , mid , p , ls , ms , rs );
    else modify( R( no ) , mid + 1 , r , p , ls , ms , rs );
    st[ no ] = st[ L( no ) ] * st[ R( no ) ];
  }
  void modify( int p , int ls , int ms , int rs ){
    modify( 1 , 0 , sz - 1 , p , ls , ms , rs );
  }
  int query(){
    return st[ 1 ].a[ 0 ][ 3 ];
  }
} st[ N ];
int BIT[ N ];
int n , a[ N ] , lc[ N ] , rc[ N ];
inline int lb( int x ){ return x & (-x); }
void modify( int p ){
  for( int i = p ; i <= n ; i += lb( i ) )
    BIT[ i ] ++;
}
int query( int p ){
  int ret = 0;
  for( int i = p ; i ; i -= lb( i ) )
    ret += BIT[ i ];
  return ret;
}
vector<int> who[ N ];
int pos[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  vector<int> li;
  for( int i = 1 ; i <= n ; i ++ )
    li.push_back( a[ i ] );
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  for( int i = 1 ; i <= n ; i ++ )
    a[ i ] = lower_bound( li.begin() , li.end() , a[ i ] ) - li.begin();
  for( int i = 1 ; i <= n ; i ++ ){
    lc[ i ] = query( a[ i ] + 1 );
    modify( a[ i ] + 1 );
  }
  for( int i = 1 ; i <= n ; i ++ )
    rc[ i ] = query( a[ i ] + 1 ) - lc[ i ] - 1;
  for( int i = 1 ; i <= n ; i ++ ){
    pos[ i ] = who[ a[ i ] ].size();
    who[ a[ i ] ].push_back( i );
  }
  for( int i = 0 ; i < n ; i ++ ){
    if( who[ i ].empty() ) continue;
    st[ i ].init( who[ i ].size() );
    for( int id : who[ i ] )
      st[ i ].modify( pos[ id ] , lc[ id ] , 1 , rc[ id ] );
  }
}
void solve(){
  int ans = 0;
  for( int i = 0 ; i < n ; i ++ ){
    if( who[ i ].empty() ) continue;
    ans = add( ans , st[ i ].query() );
  }
  int qry; scanf( "%d" , &qry ); while( qry -- ){
    int ti , xi; scanf( "%d%d" , &ti , &xi );
    ans = sub( ans , st[ a[ xi ] ].query() );
    if( ti == 1 )
      st[ a[ xi ] ].modify( pos[ xi ] , 0 , 0 , 0 );
    else
      st[ a[ xi ] ].modify( pos[ xi ] , lc[ xi ] , 1 , rc[ xi ] );
    ans = add( ans , st[ a[ xi ] ].query() );
    printf( "%d\n" , ans );
  }
}
int main(){
  init();
  solve();
}