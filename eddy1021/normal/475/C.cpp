#include <stdio.h>
#include <string.h>
#define N 1010
int n , m , sn , sm , ans;
char c[ N ][ N ];
bool tag[ N ][ N ];
void init(){
    scanf( "%d%d" , &n , &m );
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%s" , c[ i ] );
}
void test( int tsn , int ttn , int tsm , int ttm ){
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            tag[ i ][ j ] = false;
    for( int i = tsn ; i <= ttn ; i ++ )
        for( int j = tsm ; j <= ttm ; j ++ )
            if( c[ i ][ j ] == 'X' ) tag[ i ][ j ] = true;
            else return;
    while( ttn < n && ttm < m ){
        bool down = false , right = false;
        if( ttn + 1 < n && c[ ttn + 1 ][ tsm ] == 'X' ) down = true;
        if( ttm + 1 < m && c[ tsn ][ ttm + 1 ] == 'X'  ) right = true;
        if( down && right ) return;
        if( !down && !right ) break;
        if( down ){
            for( int i = tsm ; i <= ttm ; i ++ )
                if( c[ ttn + 1 ][ i ] == 'X' ) tag[ ttn + 1 ][ i ] = true;
                else return;
            tsn ++; ttn ++;
        }else{
            for( int i = tsn ; i <= ttn ; i ++ )
                if( c[ i ][ ttm + 1 ] == 'X' ) tag[ i ][ ttm + 1 ] = true;
                else return;
            tsm ++; ttm ++;
        }
    }
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            if( tag[ i ][ j ] && c[ i ][ j ] != 'X' ) return;
            else if( !tag[ i ][ j ] && c[ i ][ j ] == 'X' ) return;
    if( ans == -1 || ( ttn - tsn + 1 ) * ( ttm - tsm + 1 ) < ans )
        ans = ( ttn - tsn + 1 ) * ( ttm - tsm + 1 );
}
void test1(){
    int tm = sm;
    for( int i = sm ; i < m ; i ++ )
        if( c[ sn ][ i ] == 'X' ) tm = i;
        else break;
    int len = 1;
    if( tm + 1 < m ){
        bool flag = false;
        int xn1 = tm , xn2 = tm;
        for( int i = sn ; i < n ; i ++ )
            if( c[ i ][ tm + 1 ] == 'X' ){
                xn1 = i; flag = true; break;
            }
        if( flag ){
            for( int i = sn ; i < n ; i ++ )
                if( c[ i ][ sm ] == 'X' ) xn2 = i;
                else break;
            len = xn2 - xn1 + 1;
        }
    }
    test( sn , sn + len - 1 , sm , tm );
}
void test2(){
    int tn = sn;
    for( int i = sn ; i < n ; i ++ )
        if( c[ i ][ sm ] == 'X' ) tn = i;
        else break;
    int len = 1;
    if( tn + 1 < n ){
        bool flag = false;
        int xm1 = tn , xm2 = tn;
        for( int i = sm ; i < m ; i ++ )
            if( c[ tn + 1 ][ i ] == 'X' ){
                xm1 = i; flag = true; break;
            }
        if( flag ){
            for( int i = sm ; i < m ; i ++ )
                if( c[ sn ][ i ] == 'X' ) xm2 = i;
                else break;
            len = xm2 - xm1 + 1;
        }
    }
    test( sn , tn , sm , sm + len - 1 );
}
void solve(){
    ans = sn = -1;
    for( int i = 0 ; i < n && sn == -1 ; i ++ )
        for( int j = 0 ; j < m && sn == -1 ; j ++ )
            if( c[ i ][ j ] == 'X' )
                sn = i , sm = j;
    test1();
    test2();
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}