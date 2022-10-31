#include <stdio.h>
#include <string.h>
#define N 30
int n , m;
char c1[ N ] , c2[ N ];
void init(){
    scanf( "%d%d" , &n , &m );
    scanf( "%s%s" , c1 , c2 );
}
bool flag , tag[ N ][ N ];
bool in( int ti , int tj ){
    if( ti < 0 || tj < 0 || ti >= n || tj >= m )
        return false;
    return true;
}
void DFS( int ti , int tj ){
    tag[ ti ][ tj ] = true;
    if( c1[ ti ] == '<' && in( ti , tj - 1 ) && !tag[ ti ][ tj - 1 ] )
        DFS( ti , tj - 1 );
    if( c1[ ti ] == '>' && in( ti , tj + 1 ) && !tag[ ti ][ tj + 1 ] )
        DFS( ti , tj + 1 );
    if( c2[ tj ] == '^' && in( ti - 1 , tj ) && !tag[ ti - 1 ][ tj ] )
        DFS( ti - 1 , tj );
    if( c2[ tj ] == 'v' && in( ti + 1 , tj ) && !tag[ ti + 1 ][ tj ] )
        DFS( ti + 1 , tj );
}
void check( int ti , int tj ){
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            tag[ i ][ j ] = false;
    DFS( ti , tj );
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            if( !tag[ i ][ j ] )
                flag = false;
}
void solve(){
    flag = true;
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            check( i , j ); 
    puts( flag ? "YES" : "NO" );
}
int main(){
    init();
    solve();
}