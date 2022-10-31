#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define N 1010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a[ N ] , ans , tans;
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        if( i > 1 )
            tans = max( tans , a[ i ] - a[ i - 1 ] );
    }
    ans = 10010;
}
void solve(){
    for( int i = 2 ; i < n ; i ++ )
        ans = min( ans , max( tans , a[ i + 1 ] - a[ i - 1 ] ) );
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}