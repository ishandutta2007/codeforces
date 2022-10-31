#include <map>
#include <set>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1010
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll n , m , k , p , dr , dc , sumr[ N ] , sumc[ N ];
priority_queue<ll> heapr , heapc;
void init(){
    n = getint(); m = getint(); k = getint(); p = getint();
    for( ll i = 1 ; i <= n ; i ++ )
        for( ll j = 1 ; j <= m ; j ++ ){
            ll tmp = getint();
            sumr[ i ] += tmp;
            sumc[ j ] += tmp;
        }
    for( ll i = 1 ; i <= n ; i ++ )
        heapr.push( sumr[ i ] );
    for( ll i = 1 ; i <= m ; i ++ )
        heapc.push( sumc[ i ] );
}
ll dpr[ N * N ] , dpc[ N * N ];
void solve(){
    for( ll i = 1 ; i <= k ; i ++ ){
        dpr[ i ] = heapr.top();
        heapr.pop();
        heapr.push( dpr[ i ] - m * p );
        dpr[ i ] += dpr[ i - 1 ];
    }
    for( ll i = 1 ; i <= k ; i ++ ){
        dpc[ i ] = heapc.top();
        heapc.pop();
        heapc.push( dpc[ i ] - n * p );
        dpc[ i ] += dpc[ i - 1 ];
    }
    ll ans = dpr[ k ];
    for( ll i = 1 ; i <= k ; i ++ )
        if( dpc[ i ] + dpr[ k - i ] - i * ( k - i ) * p > ans )
            ans = dpc[ i ] + dpr[ k - i ] - i * ( k - i ) * p;
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}