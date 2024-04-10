#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v[ 2 ];
ll n , last;
ll sa , sb;
void init(){
    scanf( "%I64d" , &n );
    for( int i = 0 ; i < n ; i ++ ){
        scanf( "%I64d" , &last );
        if( last > 0 ) sa += last , v[ 0 ].push_back( last );
        else sb -= last , v[ 1 ].push_back( -last );
    }
}
bool win(){
    if( sa != sb ) return sa > sb;
    int l1 = (int)v[ 0 ].size() , l2 = (int)v[ 1 ].size();
    for( int i = 0 ; i < min( l1 , l2 ) ; i ++ )
        if( v[ 0 ][ i ] != v[ 1 ][ i ] )
            return v[ 0 ][ i ] > v[ 1 ][ i ];
    if( l1 != l2 ) return l1 > l2;
    return last > 0;
}
void solve(){
    if( win() ) puts( "first" );
    else puts( "second" );
}
int main(){
    init();
    solve();
}