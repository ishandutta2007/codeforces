#include <bits/stdc++.h>
using namespace std;
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
struct XD{
    int l , r , q;
}a[ N ];
int n , m , ST[ N << 2 ] , tag[ N << 2 ];
void insert( int no , int l , int r , int ql , int qr , int tq ){
    int mid = ( l + r ) >> 1;
    if( l == ql && r == qr ){
        ST[ no ] |= tq;
        tag[ no ] |= tq;
        return;
    }
    if( qr <= mid ) insert( no << 1 , l , mid , ql , qr , tq );
    else if( mid < ql ) insert( ( no << 1 ) + 1 , mid + 1 , r , ql , qr , tq );
    else{
        insert( no << 1 , l , mid , ql , mid , tq );
        insert( ( no << 1 ) + 1 , mid + 1 , r , mid + 1 , qr , tq );
    }
    ST[ no ] = ST[ ( no << 1 ) ] & ST[ ( no << 1 ) + 1 ];
}
int query( int no , int l , int r , int ql , int qr ){
    int mid = ( l + r ) >> 1;
    if( tag[ no ] > 0 ){
        ST[ no ] |= tag[ no ];
        if( l != r ){
            insert( no << 1 , l , mid , l , mid , tag[ no ] );
            insert( ( no << 1 ) + 1 , mid + 1 , r , mid + 1 , r , tag[ no ] );
        }
        tag[ no ] = 0;
    }
    if( l == ql && r == qr ) return ST[ no ];
    if( qr <= mid ) return query( no << 1 , l , mid , ql , qr );
    if( mid < ql ) return query( ( no << 1 ) + 1 , mid + 1 , r , ql , qr );
    return query( no << 1 , l , mid , ql , mid ) &
                query( ( no << 1 ) + 1 , mid + 1 , r , mid + 1 , qr );
}
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        a[ i ].l = getint();
        a[ i ].r = getint();
        a[ i ].q = getint();
        insert( 1 , 1 , n  , a[ i ].l , a[ i ].r , a[ i ].q );
    }
}
void solve(){
    for( int i = 0 ; i < m ; i ++ ){
        int tq = query( 1 , 1 , n , a[ i ].l , a[ i ].r );
        if( tq != a[ i ].q ){
            puts( "NO" );
            return;    
        }
    }
    puts( "YES" );
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%d%c" , query( 1 , 1 , n , i , i ) , i == n ? '\n' : ' ' );
}
int main(){
    init();
    solve();
}