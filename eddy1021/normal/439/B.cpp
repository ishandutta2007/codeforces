#include <stdio.h>
#include <algorithm>
#define N 100010
#define ll long long
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
ll a[ N ] , n , x , ans;
void init(){
    n = getint(); x = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
    std::sort( a , a + n );
}
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        ans += a[ i ] * x;
        if( x > 1 ) x --;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}