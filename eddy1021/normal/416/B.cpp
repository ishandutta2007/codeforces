#include <stdio.h>
#define N 50010
#define M 6
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int max( int x , int y ){ return x>y?x:y; }
int t[ N ][ M ] , dp[ N ][ M ] , n , m;
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 0 ; j < m ; j ++ )
            t[ i ][ j ] = getint();
}
void process(){
    dp[ 0 ][ 0 ] = t[ 0 ][ 0 ];
    for( int i = 1 ; i < n ; i ++ )
        dp[ i ][ 0 ] = dp[ i - 1 ][ 0 ] + t[ i ][ 0 ];
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 1 ; j < m ; j ++ )
            dp[ i ][ j ] = max( dp[ i - 1 ][ j ] , dp[ i ][ j - 1 ] ) + t[ i ][ j ];
    for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , dp[ i ][ m - 1 ] , i == n - 1 ? '\n' : ' ' );
}
int main(){
    init();
    process();
}