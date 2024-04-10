/********************************************************/
/*             _      _          _   __      __      _  */
/*            ( )    ( )       /' )/' _`\  /'__`\  /' ) */
/*    __     _| |   _| | _   _(_, || ( ) |(_)  ) )(_, | */
/*  /'__`\ /'_` | /'_` |( ) ( ) | || | | |   /' /   | | */
/* (  ___/( (_| |( (_| || (_) | | || (_) | /' /( )  | | */
/* `\____)`\__,_)`\__,_)`\__, | (_)`\___/'(_____/'  (_) */
/*                      ( )_| |                         */
/*                      `\___/'                         */
/*                                                      */
/********************************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
struct Treap{
	int sz , val , pri , tag;
	Treap *l , *r;
	Treap( int _val ){
		val = _val; sz = 1;
		pri = rand(); l = r = NULL; tag = 0;
	}
};
void push( Treap * a ){
	if( a->tag ){
		Treap *swp = a->l; a->l = a->r; a->r = swp;
		if( a->l ) a->l->tag ^= 1;
		if( a->r ) a->r->tag ^= 1;
		a->tag = 0;
	}
}
int Size( Treap * a ){ return a ? a->sz : 0; }
void pull( Treap * a ){
	a->sz = Size( a->l ) + Size( a->r ) + 1;
}
Treap* merge( Treap *a , Treap *b ){
	if( !a || !b ) return a ? a : b;
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
#define N 202020
int n , q , m , b[ N ];
int main(){
  srand( 0x514 );
  Treap *t = NULL , *tl = NULL , *tr = NULL;
  scanf( "%d%d%d" , &n , &q , &m );
  for( int i = 1 , ai ; i <= n ; i ++ ){
    scanf( "%d" , &ai );
    t = merge( t , new Treap( ai ) );
  }
  while( q -- ){
    int cmd , li , ri;
    scanf( "%d%d%d" , &cmd , &li , &ri );
    if( cmd == 1 ){
      if( li < ri ){
        split( t , li - 1 , tl , t );
        split( t , ri - li + 1 , t , tr );
        Treap* tmp;
        split( t , ri - li , t , tmp );
        t = merge( tmp , t );
        t = merge( tl , t );
        t = merge( t , tr );
      }
    }else{
      split( t , li - 1 , tl , t );
      split( t , ri - li + 1 , t , tr );
      t->tag ^= 1;
      t = merge( tl , t );
      t = merge( t , tr );
    }
  }
  for( int i = 1 ; i <= n ; i ++ ){
    split( t , 1 , tl , t );
    b[ i ] = tl->val;
  }
  for( int i = 1 , ai ; i <= m ; i ++ ){
    scanf( "%d" , &ai );
    printf( "%d%c" , b[ ai ] , " \n"[ i == m ] );
  }
}