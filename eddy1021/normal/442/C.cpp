#include <stdio.h>
#include <algorithm>
#define ll long long
#define N 500010
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
ll min( ll x , ll y ){ return x<y?x:y; }
ll n , a[ N ] , l[ N ] , r[ N ] , b[ N ];
bool cmp( ll x , ll y ){ return a[ x ] < a[ y ]; }
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        l[ i ] = i - 1;
        r[ i ] = i + 1;
        b[ i ] = i;
    }
    std::sort( b + 1 , b + n + 1 , cmp );
}
void solve(){
    ll ans = 0;
    for( int i = 1 ; i < n - 1 ; i ++ )
        if( l[ b[ i ] ] == 0 ){
            ans += a[ b[ i ] ];
            l[ r[ b[ i ] ] ] = l[ b[ i ] ];
        }else if( r[ b[ i ] ] == n + 1 ){
            ans += a[ b[ i ] ];
            r[ l[ b[ i ] ] ] = r[ b[ i ] ];
        }else{
            ans += min( a[ l[ b[ i ] ] ] , a[ r[ b[ i ] ] ] );
            ll nl = l[ b[ i ] ] , nr = r[ b[ i ] ];
            l[ nr ] = nl; r[ nl ] = nr;
        }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}