#include <bits/stdc++.h>
using namespace std;
#define N 303030
struct Treap{
	int sz , val , pri , tag;
	Treap *l , *r;
	Treap( int _val ){
		val = _val; sz = 1;
		pri = rand();
    l = r = NULL; tag = 0;
	}
};
void push( Treap * a ){
	if( a->tag == 0 ) return;
  if( a->l ){
    a->l->val += a->tag;
    a->l->tag += a->tag;
  }
  if( a->r ){
    a->r->val += a->tag;
    a->r->tag += a->tag;
  }
  a->tag = 0;
}
int Size( Treap * a ){ return a ? a->sz : 0; }
void pull( Treap * a ){
	a->sz = Size( a->l ) + Size( a->r ) + 1;
}
Treap* merge( Treap *a , Treap *b ){
	if( !a or !b ) return a ? a : b;
	if( a->pri > b->pri ){
		push( a );
		a->r = merge( a->r , b );
		pull( a );
		return a;
	}else{
		push( b );
		b->l = merge( a , b->l );
		pull( b );
		return b;
	}
}
void split( Treap *t , int k , Treap*&a , Treap*&b ){
	if( !t ){ a = b = NULL; return; }
	push( t );
	if( Size( t->l ) + 1 <= k ){
		a = t;
		split( t->r , k - Size( t->l ) - 1 , a->r , b );
		pull( a );
	}else{
		b = t;
		split( t->l , k , a , b->l );
		pull( b );
	}
}
int n;
int pos( Treap* t , int bdr ){
  if( !t ) return 0;
  push( t );
  if( t->val < bdr )
    return Size( t->l ) + 1 + pos( t->r , bdr );
  return pos( t->l , bdr );
}
void print( Treap* t ){
  if( !t ) return;
  push( t );
  print( t->l );
  printf( "%d " , t->val );
  print( t->r );
}
const int inf = 1000000010;
Treap *t , *tl , *tr , *dump;
void init(){
  scanf( "%d" , &n );
  //n = 300000;
  t = NULL;
  for( int i = 0 ; i <= n ; i ++ )
    t = merge( t , new Treap( i == 0 ? 0 : inf + i ) );
}
void solve(){
  for( int i = 0 ; i < n ; i ++ ){
    int ql , qr;
    scanf( "%d%d" , &ql , &qr );
    //ql = qr = i + 1;
    int posl = pos( t , ql );
    int posr = pos( t , qr );
    //printf( "%d %d : %d %d\n" , ql , qr , posl , posr );
    split( t , posr , t , tr );
    split( tr , 1 , dump , tr );
    split( t , posl , tl , t );
    if( t ){
      t->val ++;
      t->tag ++;
    }
    t = merge( new Treap( ql ) , t );
    t = merge( tl , t );
    t = merge( t , tr );
    //print( t ); puts( "" );
  }
  printf( "%d\n" , pos( t , inf ) - 1 );
}
int main(){
  init();
  solve();
}