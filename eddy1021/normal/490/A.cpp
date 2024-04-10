#include <bits/stdc++.h>
using namespace std;
vector<int> v[ 4 ];
int t , n;
void init(){
    scanf( "%d" , &t );
    for( int i = 1 ; i <= t ; i ++ ){
        scanf( "%d" , &n );
        v[ n ].push_back( i );
    }
}
void solve(){
    int ans = min( (int)v[ 1 ].size() , min( (int)v[ 2 ].size() , (int)v[ 3 ].size() ) );
    printf( "%d\n" , ans );
    for( int i = 0 ; i < ans ; i ++ )
        printf( "%d %d %d\n" , v[ 1 ][ i ] , v[ 2 ][ i ] , v[ 3 ][ i ] );
}
int main(){
    init();
    solve();
}