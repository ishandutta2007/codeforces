// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
#define N 102100
D stl[ N << 2 ] , str[ N << 2 ];
int n , q , a[ N ] , b[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
#define mid ((l+r)>>1)
inline D Lft( D ll , D lr , D rl , D rr ){
  return ( ll * rl ) / ( 1.0 + lr * ( rl - 1.0 ) );
}
inline D Rgt( D ll , D lr , D rl , D rr ){
  return rr + ( lr * rl * ( 1.0 - rr ) ) / ( 1.0 - lr * ( 1.0 - rl ) );
}
void build_st( int no , int l , int r ){
  if( l == r ){
    stl[ no ] = str[ no ] = (D)a[ l ] / b[ l ];
    return;
  }
  build_st( L( no ) , l , mid );
  build_st( R( no ) , mid + 1 , r );
  stl[ no ] = Lft( stl[ L( no ) ] , str[ L( no ) ] ,
                   stl[ R( no ) ] , str[ R( no ) ] );
  str[ no ] = Rgt( stl[ L( no ) ] , str[ L( no ) ] ,
                   stl[ R( no ) ] , str[ R( no ) ] );
}
void modify( int no , int l , int r , int p , int qa , int qb ){
  if( l == r ){
    stl[ no ] = str[ no ] = (D)qa / qb;
    return;
  }
  if( p <= mid ) modify( L( no ) , l , mid , p , qa , qb );
  else modify( R( no ) , mid + 1 , r , p , qa , qb );
  stl[ no ] = Lft( stl[ L( no ) ] , str[ L( no ) ] ,
                   stl[ R( no ) ] , str[ R( no ) ] );
  str[ no ] = Rgt( stl[ L( no ) ] , str[ L( no ) ] ,
                   stl[ R( no ) ] , str[ R( no ) ] );
}
pair<D,D> query( int no , int l , int r , int ql , int qr ){
  if( l == ql && r == qr ) return { stl[ no ] , str[ no ] };
  if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
  if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
  pair<D,D> lft = query( L( no ) , l , mid , ql , mid );
  pair<D,D> rgt = query( R( no ) , mid + 1 , r , mid + 1 , qr );
  D lv = Lft( lft.first , lft.second ,
              rgt.first , rgt.second );
  D rv = Rgt( lft.first , lft.second ,
              rgt.first , rgt.second );
  return { lv , rv };
}
void init(){
  scanf( "%d%d" , &n , &q );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d%d" , &a[ i ] , &b[ i ] );
  build_st( 1 , 1 , n );
}
void solve(){
  while( q -- ){
    int cmd , qa , qb , qi;
    scanf( "%d" , &cmd );
    if( cmd == 1 ){
      scanf( "%d%d%d" , &qi , &qa , &qb );
      modify( 1 , 1 , n , qi , qa , qb );
    }else{
      scanf( "%d%d" , &qa , &qb );
      pair<D,D> tp = query( 1 , 1 , n , qa , qb );
      printf( "%.9f\n" , tp.first );
    }
  }
}
int main(){
  init();
  solve();
}