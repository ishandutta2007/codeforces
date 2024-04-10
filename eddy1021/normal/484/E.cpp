#include <bits/stdc++.h>
using namespace std;
#define N 101010
struct Nd{
  Nd *lc , *rc;
  int l , r , m;
  Nd(){
    l = r = m = 0;
    lc = rc = NULL;
  }
};
Nd* copy( const Nd* x ){
  Nd* td = new Nd();
  if( x ){
    td->lc = x->lc;
    td->rc = x->rc;
    td->l = x->l;
    td->r = x->r;
    td->m = x->m;
  }
  return td;
}
#define mid ((l+r)>>1)
void pull( Nd* now , int l , int r ){
  now->l = 0;
  if( now->lc ){
    now->l = now->lc->l;
    if( now->rc && now->lc->l == mid - l + 1 )
      now->l = now->lc->l + now->rc->l;
  }
  now->r = 0;
  if( now->rc ){
    now->r = now->rc->r;
    if( now->lc && now->rc->r == r - mid )
      now->r = now->lc->r + now->rc->r;
  }
  now->m = 0;
  if( now->lc ) now->m = max( now->m , now->lc->m );
  if( now->rc ) now->m = max( now->m , now->rc->m );
  if( now->lc && now->rc )
    now->m = max( now->m , now->lc->r + now->rc->l );
}
void modify( Nd* now , int l , int r , int pos ){
  if( l == r ){
    now->l = now->r = now->m = 1;
    return;
  }
  if( pos <= mid ){
    now->lc = copy( now->lc );
    modify( now->lc , l , mid , pos );
  }else{
    now->rc = copy( now->rc );
    modify( now->rc , mid + 1 , r , pos );
  }
  pull( now , l , r );
}
#define L(X) get<0>(X)
#define R(X) get<1>(X)
#define M(X) get<2>(X)
tuple<int,int,int> query( Nd* now , int l , int r , int ql , int qr ){
  if( !now ) return make_tuple( 0 , 0 , 0 );
  if( l == ql && r == qr ) return make_tuple( now->l , now->r , now->m );
  if( qr <= mid ) return query( now->lc , l , mid , ql , qr );
  if( mid < ql ) return query( now->rc , mid + 1 , r , ql , qr );
  tuple<int,int,int> tl = query( now->lc , l , mid , ql , mid );
  tuple<int,int,int> tr = query( now->rc , mid + 1 , r , mid + 1 , qr );
  tuple<int,int,int> ti = make_tuple( 0 , 0 , 0 );
  L(ti) = L(tl) + ( L(tl) == mid - l + 1 ? L(tr) : 0 );
  R(ti) = R(tr) + ( R(tr) == r - mid ? R(tl) : 0 );
  M(ti) = max( max( M(tl) , M(tr) ) , R(tl) + L(tr) );
  return ti;
}
int n;
vector< pair<int,int> > v;
void init(){
  scanf( "%d" , &n );
  for( int i = 1 ; i <= n ; i ++ ){
    int hi; scanf( "%d" , &hi );
    v.push_back( { hi , i } );
  }
  sort( v.begin() , v.end() );
  reverse( v.begin() , v.end() );
}
Nd* root[ N ];
void solve(){
  for( int i = 1 ; i <= n ; i ++ ){
    root[ i ] = copy( root[ i - 1 ] );
    modify( root[ i ] , 1 , n , v[ i - 1 ].second );
  }
  int qry; scanf( "%d" , &qry ); while( qry -- ){
    int ql , qr , qw; scanf( "%d%d%d" , &ql , &qr , &qw );
    int bl = 1 , br = n , ba = n;
    while( bl <= br ){
      int bmid = ( bl + br ) >> 1;
      if( M( query( root[ bmid ] , 1 , n , ql , qr ) ) >= qw )
        ba = bmid , br = bmid - 1;
      else
        bl = bmid + 1;
    }
    printf( "%d\n" , v[ ba - 1 ].first );
  }
}
int main(){
  init();
  solve();
}