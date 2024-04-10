#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 101010
struct Nd{
  int bst;
  Nd *tl , *tr;
  Nd(){
    bst = 0;
    tl = tr = NULL;
  }
};
#define mid ((l+r)>>1)
int Bst( Nd* now ){  return now ? now->bst : 0;}
void modify( Nd* now , int l , int r , int p , int v ){
  if( l == r ){
    now->bst = max( now->bst , v );
    return;
  }
  if( p <= mid ){
    if( !now->tl ) now->tl = new Nd();
    modify( now->tl , l , mid , p , v );
  }else{
    if( !now->tr ) now->tr = new Nd();
    modify( now->tr , mid + 1 , r , p , v );
  }
  now->bst = max( Bst( now->tl ) , Bst( now->tr ) );
}
int query( Nd* now , int l , int r , int ql , int qr ){
  if( !now or r < ql or l > qr or ql > qr ) return 0;
  if( ql <= l and r <= qr ) return now->bst;
  return max( query( now->tl , l , mid , ql , qr ) ,
              query( now->tr , mid + 1 , r , ql , qr ) );
}
int n , m;
Nd *root[ N ];
const int inf = 1e5;
int main(){
  scanf( "%d%d" , &n , &m );
  for( int i = 1 ; i <= n ; i ++ )
    root[ i ] = new Nd();
  int ans = 0;
  while( m -- ){
    int ai , bi , wi;
    scanf( "%d%d%d" , &ai , &bi , &wi );
    int ret = query( root[ ai ] , 0 , inf , 0 , wi - 1 ) + 1;
    ans = max( ans , ret );
    modify( root[ bi ] , 0 , inf , wi , ret );
  }
  printf( "%d\n" , ans );
}