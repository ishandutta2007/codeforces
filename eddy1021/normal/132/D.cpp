#include <bits/stdc++.h>
using namespace std;
#define N 1000010
char c[ N ];
int len , x[ N ];
void init(){
    scanf( "%s" , c );
    len = strlen( c );
    reverse( c , c + len );
}
void solve(){
    for( int i = 0 ; i < len ; i ++ )
        if( c[ i ] == '1' ){
            if( x[ i ] == 1 ){
                x[ i ] = 0;
                x[ i + 1 ] = 1;
            }else if( i && x[ i - 1 ] == 1 ){
                x[ i - 1 ] = -1;
                x[ i + 1 ] = 1;
            }else x[ i ] = 1;
        }
    int cnt = 0;
    for( int i = N - 1 ; i >= 0 ; i -- )
        if( x[ i ] != 0 )
            cnt ++;
    printf( "%d\n" , cnt );
    for( int i = N - 1 ; i >= 0 ; i -- )
        if( x[ i ] == 1 ) printf( "+2^%d\n" , i );
        else if( x[ i ] == -1 ) printf( "-2^%d\n" , i );
}
int main(){
    init();
    solve();
}