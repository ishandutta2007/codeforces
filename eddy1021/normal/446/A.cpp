#include <map>
#include <set>
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
int n , a[ N ] , l[ N ] , r[ N ] , ans;
void init(){
    n = getint(); ans = 1;
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void solve(){
    l[ 1 ] = 1; r[ n ] = 1;
    for( int i = 2 ; i <= n ; i ++ ){
        if( a[ i ] > a[ i - 1 ] )
            l[ i ] = l[ i - 1 ] + 1;
        else l[ i ] = 1;
        if( l[ i ] > ans ) ans = l[ i ];
    }
    for( int i = n - 1 ; i >= 1 ; i -- ){
        if( a[ i ] < a[ i + 1 ] )
            r[ i ] = r[ i + 1 ] + 1;
        else r[ i ] = 1;
        if( r[ i ] > ans ) ans = r[ i ];
    }
    for( int i = 2 ; i <= n ; i ++ )
        if( r[ i ] + 1 > ans )
            ans = r[ i ] + 1;
    for( int i = 1 ; i < n ; i ++ )
        if( l[ i ] + 1 > ans )
            ans = l[ i ] + 1;
    for( int i = 2 ; i < n ; i ++ )
        if( a[ i - 1 ] < a[ i + 1 ] - 1 ){
            if( l[ i - 1 ] + r[ i + 1 ] + 1 > ans )
                ans = l[ i - 1 ] + r[ i + 1 ] + 1;
        }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}