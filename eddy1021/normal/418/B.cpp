#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 21
#define N 110
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll min( ll x , ll y ){ return x<y?x:y; }
ll max( ll x , ll y ){ return x>y?x:y; }
struct XD{
    ll tag , a , m;
}bx[ N ];
bool cmp( XD x , XD y ){
    return x.m < y.m;
}
ll n , xm , b;
void init(){
    n = getint(); xm = getint(); b = getint();
    for( ll i = 1 ; i <= n ; i ++ ){
        bx[ i ].a = getint();
        bx[ i ].m = getint();
        ll tmp = getint(); while( tmp -- )
            bx[ i ].tag |= ( 1 << ( getint() - 1 ) );
    }
    std::sort( bx + 1 , bx + n + 1 , cmp );
}
ll dp[ 2 ][ 1ll << M ] , ans;
void DP(){
    ans = -1;
    for( ll j = 0ll ; j < ( 1ll << xm ) ; j ++ )
        dp[ 0ll ][ j ] = -1;
    dp[ 0 ][ 0 ] = 0ll;
    for( ll i = 0ll ; i < n ; i ++ ){
        for( ll j = 0 ; j < ( 1ll << xm ) ; j ++ )
            dp[ ( i + 1 ) % 2 ][ j ] = dp[ i % 2 ][ j ];
        if( dp[ ( i + 1 ) % 2 ][ bx[ i + 1 ].tag ] == -1 ||
            bx[ i + 1 ].a < dp[ ( i + 1 ) % 2 ][ bx[ i + 1 ].tag ] )
                dp[ ( i + 1 ) % 2 ][ bx[ i + 1 ].tag ] = bx[ i + 1 ].a;
        for( ll j = 0 ; j < ( 1ll << xm ) ; j ++ ){
            if( dp[ i % 2 ][ j ] != -1 ){
                if( dp[ ( i + 1 ) % 2 ][ j | bx[ i + 1 ].tag ] == -1 ||
                        dp[ ( i + 1 ) % 2 ][ j | bx[ i + 1 ].tag ] >
                                    dp[ i % 2 ][ j ] + bx[ i + 1 ].a ){
                    dp[ ( i + 1 ) % 2 ][ j | bx[ i + 1 ].tag ] = dp[ i % 2 ][ j ] + bx[ i + 1 ].a;
                }
            }
        }
        if( dp[ ( i + 1 ) % 2 ][ ( 1ll << xm ) - 1 ] != -1 &&
                ( ans == -1 || dp[ ( i + 1 ) % 2 ][ ( 1ll << xm ) - 1 ] + bx[ i + 1 ].m * b < ans ) )
            ans = dp[ ( i + 1 ) % 2 ][ ( 1ll << xm ) - 1 ] + bx[ i + 1 ].m * b;
    }
}
void solve(){
    DP();
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}