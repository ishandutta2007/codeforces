#include <bits/stdc++.h>
using namespace std;
#define N 110
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , m , a[ N ] , b[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
    m = getint();
    for( int i = 0 ; i < m ; i ++ )
        b[ i ] = getint();
    sort( a , a + n );
    sort( b , b + m );
}
void solve(){
    int ans = 0 , ptr = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( ptr >= m ) break;
        else{
            while( ptr < m && b[ ptr ] < a[ i ] - 1 ) ptr ++;
            if( ptr < m && abs( b[ ptr ] - a[ i ] ) <= 1 ) ans ++ , ptr ++;
        }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}