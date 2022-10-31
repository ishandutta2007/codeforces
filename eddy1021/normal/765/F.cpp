// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 101021
const int MX = 1000000001;
struct Seg{
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
  int a[ N << 2 ];
  void init(){
    for( int i = 0 ; i < ( N << 2 ) ; i ++ )
      a[ i ] = MX;
  }
  void modify( int no , int l , int r , int p , int x ){
    a[ no ] = min( a[ no ] , x );
    if( l == r ) return;
    if( p <= mid ) modify( L( no ) , l , mid , p , x );
    else modify( R( no ) , mid + 1 , r , p , x );
  }
  int query( int no , int l , int r , int ql , int qr ){
    if( qr < l or ql > r ) return MX;
    if( ql <= l and r <= qr ) return a[ no ];
    return min( query( L( no ) , l , mid , ql , qr ) ,
                query( R( no ) , mid + 1 , r , ql , qr ) );
  }
} st , st2;
int n , a[ N ] , q , ans[ N * 3 ];
vector< pair<int,int> > qry[ N ];
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &a[ i ] );
  scanf( "%d" , &q );
  for( int i = 0 ; i < q ; i ++ ){
    int ql , qr; scanf( "%d%d" , &ql , &qr );
    qry[ ql ].push_back( { qr , i } );
  }
}
void solve(){
  vector<int> li;
  for( int i = 1 ; i <= n ; i ++ )
    li.push_back( a[ i ] );
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  int sz = (int)li.size();
  st.init();
  st2.init();
  for( int i = n ; i >= 1 ; i -- ){
    int now = lower_bound( li.begin() , li.end() , a[ i ] ) - li.begin() + 1;
    int tar = MX + MX;
    do{
      tar >>= 1;
      int pos = upper_bound( li.begin() , li.end() , a[ i ] + tar ) - li.begin();
      int ret = st.query( 1 , 1 , sz , now , pos );
      if( ret == MX ) break;
      st2.modify( 1 , 1 , n , ret , a[ ret ] - a[ i ] );
      tar = a[ ret ] - a[ i ];
    }while( tar );
    tar = MX + MX;
    do{
      tar >>= 1;
      int pos = lower_bound( li.begin() , li.end() , a[ i ] - tar ) - li.begin() + 1;
      int ret = st.query( 1 , 1 , sz , pos , now );
      if( ret == MX ) break;
      st2.modify( 1 , 1 , n , ret , a[ i ] - a[ ret ] );
      tar = a[ i ] - a[ ret ];
    }while( tar );
    for( auto j : qry[ i ] )
      ans[ j.second ] = st2.query( 1 , 1 , n , 1 , j.first );
    st.modify( 1 , 1 , sz , now , i );
  }
  for( int i = 0 ; i < q ; i ++ )
    printf( "%d\n" , ans[ i ] );
}
int main(){
  init();
  solve();
}