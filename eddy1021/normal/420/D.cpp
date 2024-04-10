#include <stdio.h>
#include <stdlib.h>
#define N 1000010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
struct Treap{
    int val , pri , sz , pos;
    Treap *l , *r;
    Treap( int _val , int _pos ){
        val = _val; pos = _pos; pri = rand();
        l = r = NULL; sz = 1;
    }
};
int size( Treap * t ){ return t ? t->sz : 0; }
void pull( Treap * t ){
    t->sz = size( t->l ) + size( t->r ) + 1;
}
Treap *merge( Treap * a , Treap * b ){
    if( !a || !b ) return a ? a : b;
    if( a->pri > b->pri ){
        a->r = merge( a->r , b );
        pull( a );
        return a;
    }else{
        b->l = merge( a , b->l );
        pull( b );
        return b;
    }
}
void split( Treap *t , int k , Treap *&a , Treap *&b ){
    if( !t ) a = b = NULL;
    else if( size( t->l ) + 1 <= k ){
        a = t;
        split( t->r , k - size( t->l ) - 1 , a->r , b );
        pull( a );
    }else{
        b = t;
        split( t->l , k , a , b->l );
        pull( b );
    }
}
int n , m , xi , yi , ans[ N ];
bool got[ N ];
bool solve(){
    Treap *t = NULL , *tl , *tr;
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        t = merge( t , new Treap( 0 , i ) );
    while( m -- ){
        xi = getint(); yi = getint();
        split( t , yi - 1 , tl , t );
        split( t , 1 , t , tr );
        if( t->val ){
            if( t->val != xi )
                return false;
        }else{
            if( got[ xi ] )
                return false;
            ans[ t->pos ] = xi;
            t->val = xi; got[ xi ] = true;
        }
        t = merge( t , tl );
        t = merge( t , tr );
    }
    int gidx = 1;
    for( int i = 1 ; i <= n ; i ++ ){
        if( ans[ i ] ) printf( "%d" , ans[ i ] );
        else{
            while( got[ gidx ] ) gidx ++;
            printf( "%d" , gidx ); gidx ++;
        }
        putchar( i == n ? '\n' : ' ' );
    }
    return true;
}
int main(){
    if( !solve() ) puts( "-1" );
}