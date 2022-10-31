#include <bits/stdc++.h>
using namespace std;
#define N 202020
struct Seg{
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
  multiset<int> s[ N << 2 ];
  int st[ N << 2 ];
  void init( int no , int l , int r ){
    s[ no ].clear();
    st[ no ] = 0;
    if( l == r ) return;
    init( L( no ) , l , mid );
    init( R( no ) , mid + 1 , r );
  }
  void modify( int no , int l , int r , int p , int x , bool add ){
    if( l == r ){
      if( add ) s[ no ].insert( x );
      else s[ no ].erase( s[ no ].find( x ) );
      st[ no ] = s[ no ].empty() ? 0 : *--s[ no ].end();
      return;
    }
    if( p <= mid ) modify( L( no ) , l , mid , p , x , add );
    else modify( R( no ) , mid + 1 , r , p , x , add );
    st[ no ] = max( st[ L( no ) ] , st[ R( no ) ] );
  }
  int query( int no , int l , int r , int ql , int qr ){
    if( qr < l || ql > r || ql > qr ) return 0;
    if( ql <= l && r <= qr ) return st[ no ];
    return max( query( L( no ) , l , mid , ql , qr ),
                query( R( no ) , mid + 1 , r , ql , qr ) );
  }
} xst, yst;
int n , m , cmd[ N ] , p[ N ] , h[ N ] , sz;
void init(){
  vector< int > li;
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= m ; i ++ ){
    scanf( "%d%d" , &cmd[ i ] , &p[ i ] );
    if( cmd[ i ] == 1 ){
      scanf( "%d" , &h[ i ] );
      h[ i ] -= i;
      li.push_back( h[ i ] );
    }
  }
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  for( int i = 1 ; i <= m ; i ++ )
    if( cmd[ i ] == 1 )
      h[ i ] = lower_bound( li.begin() , li.end() , h[ i ] ) - li.begin() + 1;
  sz = (int)li.size();
}
typedef tuple<int,int,int> tiii;
set< tiii > xy , yx;
void Erase( tiii tp ){
  xy.erase( tp );
  yx.erase( make_tuple( get<1>( tp ) , get<0>( tp ) , get<2>( tp ) ) );
  xst.modify( 1 , 1 , n + 1  , get<0>( tp ) , get<2>( tp ) , false );
  yst.modify( 1 , 1 , sz + 1 , get<1>( tp ) , get<2>( tp ) , false );
}
void Add( tiii tp ){
  xy.insert( tp );
  yx.insert( make_tuple( get<1>( tp ) , get<0>( tp ) , get<2>( tp ) ) );
  xst.modify( 1 , 1 , n + 1  , get<0>( tp ) , get<2>( tp ) , true );
  yst.modify( 1 , 1 , sz + 1 , get<1>( tp ) , get<2>( tp ) , true );
}
void solve(){
  xst.init( 1 , 1 , n + 1 );
  yst.init( 1 , 1 , sz + 1 );
  for( int i = 1 ; i <= m ; i ++ ){
    if( cmd[ i ] == 1 ){
      vector< pair<int,int> > wt;
      while( yx.size() && get<0>( *yx.begin() ) < h[ i ] ){
        tiii tp = *yx.begin();
        swap( get<0>( tp ) , get<1>( tp ) );
        Erase( tp );
        wt.push_back( { get<0>( tp ) , get<1>( tp ) } );
      }
      wt.push_back( { p[ i ] , h[ i ] } );
      reverse( wt.begin() , wt.end() );
      for( size_t l = 0 , r = 0 ; l < wt.size() ; l = r ){
        while( r < wt.size() && wt[ l ].second == wt[ r ].second ) r ++;
        vector< int > tans;
        for( size_t j = l ; j < r ; j ++ )
          tans.push_back( 1 + xst.query( 1 , 1 , n + 1 , wt[ j ].first + 1 , n + 1 ) );
        for( size_t j = l ; j < r ; j ++ )
          Add( make_tuple( wt[ j ].first , wt[ j ].second , tans[ j - l ] ) );
      }
    }else{
      vector< pair<int,int> > wt;
      for( int j = 1 ; j < p[ i ] ; j ++ ){
        tiii tp = *xy.begin();
        Erase( tp );
        wt.push_back( { get<0>( tp ) , get<1>( tp ) } );
      }
      Erase( *xy.begin() );
      reverse( wt.begin() , wt.end() );
      for( pair<int,int> tp : wt ){
        int tans = yst.query( 1 , 1 , sz + 1 , tp.second + 1 , sz + 1 );
        Add( make_tuple( tp.first , tp.second , tans + 1 ) );
      }
    }
    printf( "%d\n" , xst.st[ 1 ] );
  }
}
int main(){
  init();
  solve();
}