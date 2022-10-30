#include <stdio.h>
#include <string.h>
#define N 110
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
bool lck2[ N ];
int n , m , k , a[ N ][ N ] , lck[ N ];
void init(){
    n = getint(); m = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            a[ i ][ j ] = getint();
}
void solve(){
    for( int i = 1 ; i <= m ; i ++ ){
        bool got[ N ] = {};
        for( int j = 1 ; j <= n ; j ++ )
            if( !lck[ j ] && a[ j ][ i ] ){
                if( !got[ a[ j ][ i ] ] ) got[ a[ j ][ i ] ] = true;
                else lck2[ a[ j ][ i ] ] = true;
            }
        for( int j = 1 ; j <= n ; j ++ )
            if( !lck[ j ] && lck2[ a[ j ][ i ] ] )
                lck[ j ] = i;
    }
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%d\n" , lck[ i ] );
}
int main(){
    init();
    solve();
}