#include <bits/stdc++.h>
using namespace std;
#define N 202020
struct Nd{
  int vl;
  Nd *tl , *tr;
  Nd(){
    vl = 0;
    tl = tr = NULL;
  }
};
#define mid ((l+r)>>1)
Nd* copy( Nd* x ){
  Nd* ret = new Nd();
  if( x ) *ret = *x;
  return ret;
}
int Val( Nd *x ){
  return x ? x->vl : 0;
}
void modify( Nd* now , int l , int r , int p , int v ){
  now->vl = max( now->vl , v );
  if( l == r ) return;
  if( p <= mid ){
    now->tl = copy( now->tl );
    modify( now->tl , l , mid , p , v );
  }else{
    now->tr = copy( now->tr );
    modify( now->tr , mid + 1 , r , p , v );
  }
}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now or r < ql or l > qr or ql > qr ) return 0;
  if( ql <= l and r <= qr ) return now->vl;
  return max( query( now->tl , l , mid , ql , qr ) ,
              query( now->tr , mid + 1 , r , ql , qr ) );
}
int n , a[ N ];
Nd* root[ N ] , *root2[ N ];
vector<int> li;
int main(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    scanf( "%d" , &a[ i ] );
    a[ i ] -= i;
    li.push_back( a[ i ] );
    li.push_back( a[ i ] + 1 );
  }
  sort( li.begin() , li.end() );
  li.resize( unique( li.begin() , li.end() ) - li.begin() );
  int lsz = (int)li.size();
  int bst = 1;
  for( int i = 1 ; i <= n ; i ++ ){
    int ai = lower_bound( li.begin() , li.end() , a[ i ] ) - li.begin();
    root[ i ] = copy( root[ i - 1 ] );
    int rr = query( root[ i ] , 0 , lsz , 0 , ai ) + 1;
    bst = max( bst , rr );
    modify( root[ i ] , 0 , lsz , ai , rr );
  }
  for( int i = n ; i >= 2 ; i -- ){
    int ai = lower_bound( li.begin() , li.end() , a[ i ] + 1 ) - li.begin();
    root2[ i ] = copy( root2[ i + 1 ] );
    int rr = query( root2[ i ] , 0 , lsz , ai , lsz ) + 1;
    modify( root2[ i ] , 0 , lsz , ai , rr );
    bst = max( bst , rr + query( root[ i - 2 ] , 0 , lsz , 0 , ai ) );
  }
  printf( "%d\n" , max( 0 , n - 1 - bst ) );
}