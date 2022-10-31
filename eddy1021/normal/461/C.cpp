#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int ST[ N << 2 ] , n , q , base , flag;
void build( int no , int l , int r ){
    if( l == r ){ ST[ no ] = 1; return; }
    int m = ( l + r ) >> 1;
    build( no << 1 , l , m );
    build( ( no << 1 ) + 1 , m + 1 , r );
    ST[ no ] = ST[ no << 1 ] + ST[ ( no << 1 ) + 1 ];
}
void modify( int no , int l , int r , int ql , int num ){
    if( l == r ){ ST[ no ] = num; return; }
    int m = ( l + r ) >> 1;
    if( ql <= m ) modify( no << 1 , l , m , ql , num );
    else modify( ( no << 1 ) + 1 , m + 1 , r , ql , num );
    ST[ no ] = ST[ no << 1 ] + ST[ ( no << 1 ) + 1 ];
}
int query( int no , int l , int r , int ql , int qr ){
    if( ql > qr ) return 0;
    if( ql == l && qr == r ) return ST[ no ];
    int m = ( l + r ) >> 1;
    if( qr <= m ) return query( no << 1 , l , m , ql , qr );
    if( m < ql ) return query( ( no << 1 ) + 1 , m + 1 , r , ql , qr );
    return query( no << 1 , l , m , ql , m ) +
            query( ( no << 1 ) + 1 , m + 1 , r , m + 1 , qr );
}
int L , R;
void cover( int i , int j ){
    int num1 = query( 1 , 1 , n , i , i );
    int num2 = query( 1 , 1 , n , j , j );
    modify( 1 , 1 , n , i , 0 );
    modify( 1 , 1 , n , j , num1 + num2 );
}
void fold( int x ){
    if( flag ){
        if( R - 2 * x + 1 >= L ){
            for( int i = R , j = R - 2 * x + 1 , t = 1 ;
                t <= x ; i -- , j ++ , t ++ )
                cover( i , j );
            R = R - x;
        }else{
            flag ^= 1;
            int tx = R - L + 1 - x;
            for( int i = L , j = L + 2 * tx - 1 , t = 1 ;
                t <= tx ; i ++ , j -- , t ++ )
                cover( i , j );
            L = L + tx;
        }
    }else{
        if( L + 2 * x - 1 <= R ){
            for( int i = L , j = L + 2 * x - 1 , t = 1 ;
                    t <= x ; i ++ , j -- , t ++ )
                cover( i , j );
            L = L + x;
        }else{
            flag ^= 1;
            int tx = R - L + 1 - x;
            for( int i = R , j = R - 2 * tx + 1 , t = 1 ;
                    t <= tx ; i -- , j ++ , t ++ )
                cover( i , j );
            R = R - tx;
        }
    }
}
void ans( int a , int b ){
    if( flag )
        printf( "%d\n" , query( 1 , 1 , n , R - b + 1 , n ) -
                            query( 1 , 1 , n , R - a + 1 , n ) );
    else
        printf( "%d\n" , query( 1 , 1 , n , 1 , L + b - 1 ) -
                            query( 1 , 1 , n , 1 , L + a - 1 ) );
}
void init(){
    n = getint(); q = getint();
    build( 1 , 1 , n );
    L = 1; R = n; flag = 0;
}
void solve(){
    while( q -- ){
        int t , a , b;
        t = getint();
        if( t == 1 ){
            a = getint();
            fold( a );
        }else{
            a = getint(); b = getint();
            ans( a , b );
        }
    }
}
int main(){
    init();
    solve();
}