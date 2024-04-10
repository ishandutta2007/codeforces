#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define T 10
#define N 100010
#define mod 1000000007
#define ll long long
char c[ N ] , ctmp[ N ];
ll n;
pair<ll,string> p[ N ];
void init(){
    scanf( "%s" , c );
    scanf( "%I64d" , &n );
    for( int i = 0 ; i < n ; i ++ ){
        ll ntmp; int tlen;
        scanf( "%I64d->" , &ntmp );
        gets( ctmp );
        string stmp; tlen = strlen( ctmp );
        for( int j = 0 ; j < tlen ; j ++ )
            stmp += ctmp[ j ];
        p[ i ] = make_pair( ntmp , stmp );
    }
}
void solve(){
    ll value[ T ] , base[ T ];
    for( ll i = 0 ; i < T ; i ++ )
        value[ i ] = i , base[ i ] = 10;
    for( int i = n - 1 ; i >= 0 ; i -- ){
        ll tvalue = 0 , tbase = 1; int tlen = p[ i ].second.length();
        for( int j = tlen - 1 ; j >= 0 ; j -- ){
            tvalue = ( tvalue + ( value[ p[ i ].second[ j ] - '0' ] * tbase ) % mod ) % mod;
            tbase = ( tbase * base[ p[ i ].second[ j ] - '0' ] ) % mod; 
        }
        value[ p[ i ].first ] = tvalue;
        base[ p[ i ].first ] = tbase;
//        printf( "%I64d %I64d\n" , value[ p[ i ].first ] , base[ p[ i ].first ] );
    }
    ll ans = 0 , tbase = 1; int len = strlen( c );
    for( int i = len - 1 ; i >= 0 ; i -- ){
        ans = ( ans + ( value[ c[ i ] - '0' ] * tbase ) % mod ) % mod;
        tbase = ( tbase * base[ c[ i ] - '0' ] ) % mod;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}