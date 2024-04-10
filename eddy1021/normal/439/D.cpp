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
ll n , m , a[ N ] , b[ N ] , tmin , tmax , ans;
void init(){
    n = getint(); m = getint();
    tmin = 1000000007; tmax = 0; ans = -1;
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ] = getint();
        if( a[ i ] < tmin ) tmin = a[ i ];
        if( a[ i ] > tmax ) tmax = a[ i ];
    }
    for( int i = 0 ; i < m ; i ++ ){
        b[ i ] = getint();
        if( b[ i ] < tmin ) tmin = b[ i ];
        if( b[ i ] > tmax ) tmax = b[ i ];
    }
    std::sort( a , a + n );
    std::sort( b , b + m );
}
ll cal( ll tidx ){
    ll tcnt = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( a[ i ] < tidx ) tcnt += tidx - a[ i ];
        else break;
    for( int i = m - 1 ; i >= 0 ; i -- )
        if( b[ i ] > tidx ) tcnt += b[ i ] - tidx;
        else break;
    if( ans == -1 || tcnt < ans ) ans = tcnt;
    return tcnt;
}
void tenary_search( ll tl , ll tr ){
    if( tr - tl < 10 ){
        for( ll i = tl ; i <= tr ; i ++ )
            cal( i );
        return;
    }
    ll div = ( tr - tl ) / 3;
    ll p1 = tl + div , p2 = tr - div;
    ll c1 = cal( p1 ) , c2 = cal( p2 );
    if( c1 < c2 ) tenary_search( tl , p2 );
    else tenary_search( p1 , tr );
}
void solve(){
    tenary_search( tmin , tmax );
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}