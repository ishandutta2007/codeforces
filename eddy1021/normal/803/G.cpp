#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 101010
#define lgN 20
int n , k , b[ N ];
const int inf = 1000000010;
int rmq[ N ][ lgN ] , lg[ N ];
int query_rmq( int l , int r ){
  int bt = lg[ r - l + 1 ];
  return min( rmq[ l ][ bt ] ,
              rmq[ r - ( 1 << bt ) + 1 ][ bt ] );
}
int query_pre( int l , int r ){
  int ll = ( l - 1 ) / n;
  int rr = ( r - 1 ) / n;
  l = l % n; r = r % n;
  if( l == 0 ) l = n;
  if( r == 0 ) r = n;
  if( ll + 1 < rr ) return query_rmq( 1 , n );
  if( ll < rr ) return min( query_rmq( l , n ) ,
                            query_rmq( 1 , r ) );
  return query_rmq( l , r );
}
struct Nd{
  Nd *tl , *tr;
  int mn , tg;
  Nd( int vl = inf ){
    mn = vl; tg = inf;
    tl = tr = NULL;
  }
};
Nd* new_node( int l , int r ){
  return new Nd( query_pre( l , r ) );
}
#define mid ((l+r)>>1)
int Min( Nd* tn ){
  return tn ? tn->mn : inf;
}
void pull( Nd* tn ){
  tn->mn = min( Min( tn->tl ) , Min( tn->tr ) );
}
void push( Nd* tn , int l , int r ){
  if( tn->tg == inf ) return;
  if( !tn->tl ) tn->tl = new_node( l , mid );
  if( !tn->tr ) tn->tr = new_node( mid + 1 , r );
  tn->tl->mn = tn->tl->tg = 
  tn->tr->mn = tn->tr->tg = tn->tg;
  tn->tg = inf;
}
void modify( Nd* tn , int l , int r , int ql , int qr , int qd ){
  if( l == ql and r == qr ){
    tn->mn = tn->tg = qd;
    return;
  }
  push( tn , l , r );
  if( !tn->tl ) tn->tl = new_node( l , mid );
  if( !tn->tr ) tn->tr = new_node( mid + 1 , r );
  if( qr <= mid )
    modify( tn->tl , l , mid , ql , qr , qd );
  else if( mid < ql )
    modify( tn->tr , mid + 1 , r , ql , qr , qd );
  else{
    modify( tn->tl , l , mid , ql , mid , qd );
    modify( tn->tr , mid + 1 , r , mid + 1 , qr , qd );
  }
  pull( tn );
}
int query( Nd* tn , int l , int r , int ql , int qr ){
  if( !tn ) return query_pre( ql , qr );
  if( l == ql and r == qr ) return tn->mn;
  push( tn , l , r );
  if( qr <= mid ) return query( tn->tl , l , mid , ql , qr );
  if( mid < ql ) return query( tn->tr , mid + 1 , r , ql , qr );
  return min( query( tn->tl , l , mid , ql , mid ) ,
              query( tn->tr , mid + 1 , r , mid + 1 , qr ) );
}
void init(){
  scanf( "%d%d" , &n , &k );
  for( int i = 1 ; i <= n ; i ++ )
    scanf( "%d" , &b[ i ] );
  for( int i = 1 , nxt = 2 , cur = 0  ; i <= n ; i ++ ){
    lg[ i ] = cur;
    if( i == nxt ) cur ++, nxt <<= 1;
  }
  for( int i = 1 ; i <= n ; i ++ )
    rmq[ i ][ 0 ] = b[ i ];
  for( int j = 1 ; j < lgN ; j ++ )
    for( int i = 1 ; i + ( 1 << j ) - 1 <= n ; i ++ )
      rmq[ i ][ j ] = min( rmq[ i ][ j - 1 ] ,
                           rmq[ i + ( 1 << ( j - 1 ) ) ][ j - 1 ] );
}
Nd* root;
void solve(){
  int nk = n * k;
  root = new_node( 1 , nk );
  int q; scanf( "%d" , &q ); while( q -- ){
    int cmd; scanf( "%d" , &cmd );
    if( cmd == 1 ){
      int l , r , x; scanf( "%d%d%d" , &l , &r , &x );
      modify( root , 1 , nk , l , r , x );
    }else{
      int l , r; scanf( "%d%d" , &l , &r );
      printf( "%d\n" , query( root , 1 , nk , l , r ) );
    }
  }
}
int main(){
  init();
  solve();
}