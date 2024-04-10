#include <stdio.h>
#define N 200010
#define ll long long
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int n , a[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
}
void solve(){
    ll ans1 = 0 , ans2 = 0;
    int cnt1 = 0 , cnt2 = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( a[ i ] == 1 ) cnt1 ++;
        else ans1 += (ll)cnt1;
    for( int i = n - 1 ; i >= 0 ; i -- )
        if( a[ i ] == 0 ) cnt2 ++;
        else ans2 += (ll)cnt2;
    printf( "%I64d\n" , ans1 < ans2 ? ans1 : ans2 );
}
int main(){
    init();
    solve();
}