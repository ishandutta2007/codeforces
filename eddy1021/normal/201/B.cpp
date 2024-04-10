#include <stdio.h>
#define N 1010
#define ll long long
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
ll n , m , sx[ N ] , sy[ N ];
int main(){
    n = getint(); m = getint();
    ll ans1 = -1 , ans2 = -1 , an = 0 , am = 0;
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            ll t = getint();
            sx[ i ] += t;
            sy[ j ] += t;
        }
    for( ll i = 0 ; i <= n ; i ++ ){
        ll tans = 0;
        for( ll j = 1 ; j <= n ; j ++ ){
            tans += sx[ j ] * ( i * 4 - ( j - 1 ) * 4 - 2 ) * ( i * 4 - ( j - 1 ) * 4 - 2 );
        }
        if( ans1 == -1 || tans < ans1 ) ans1 = tans , an = i;
    }
    for( ll i = 0 ; i <= m ; i ++ ){
        ll tans = 0;
        for( int j = 1 ; j <= m ; j ++ )
            tans += sy[ j ] * ( i * 4 - ( j - 1 ) * 4 - 2 ) * ( i * 4 - ( j - 1 ) * 4 - 2 );
        if( ans2 == -1 || tans < ans2 ) ans2 = tans , am = i;
    }
    printf( "%I64d\n%I64d %I64d\n" , ans1 + ans2 , an , am );
}