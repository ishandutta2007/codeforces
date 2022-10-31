#include <stdio.h>
#include <string.h>
#define N 2010
char c[ N ][ N ];
int n , m , k;
void init(){
    scanf( "%d%d%d" , &n , &m , &k );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
}
bool in( int tn , int tm ){
    if( tn < 1 || tn > n || tm < 1 || tm > m )
        return false;
    return true;
}
void solve(){
    for( int j = 1 ; j <= m ; j ++ ){
        int cnt = 0;
        for( int i = 1 , t = 0 ; i <= n ; i ++ , t ++ ){
            if( in( i , j - t ) && c[ i ][ j - t ] == 'R' ) cnt ++;
            if( in( i , j + t ) && c[ i ][ j + t ] == 'L' ) cnt ++;
            if( in( i - t , j ) && c[ i - t ][ j ] == 'D' ) cnt ++;
            if( in( i + t , j ) && c[ i + t ][ j ] == 'U' ) cnt ++;
        }
        printf( "%d%c" , cnt , j == m ? '\n' : ' ' );
    }
}
int main(){
    init();
    solve();
}