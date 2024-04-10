#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100010
#define ll long long
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
ll Abs( ll x ){ return x<0?-x:x; }
queue< ll > Q;
vector< ll > v[ N ];
bool inq[ N ];
ll n , m , a[ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= m ; i ++ ){
        a[ i ] = getint();
        if( !inq[ a[ i ] ] ) Q.push( a[ i ] );
        inq[ a[ i ] ] = true;
        if( i > 1 && a[ i - 1 ] != a[ i ] ){
            v[ a[ i ] ].push_back( a[ i - 1 ] );
            v[ a[ i - 1 ] ].push_back( a[ i ] );
        }
    }
    for( int i = 2 ; i <= m ; i ++ )
        ans += Abs( a[ i ] - a[ i - 1 ] );
}
void solve(){
    ll fans = ans;
    while( Q.size() ){
        ll tn = Q.front() , md; Q.pop();
        sort( v[ tn ].begin() , v[ tn ].end() );
        md = (ll)v[ tn ].size() / 2;
        ll delta = 0;
        for( int i = 0 ; i < v[ tn ].size() ; i ++ ){
            delta += Abs( v[ tn ][ md ] - v[ tn ][ i ] );
            delta -= Abs( (ll)tn - v[ tn ][ i ] );
//            printf( "%I64d\n" , v[ tn ][ i ] );
        }
//        printf( "%I64d %I64d\n" , tn , delta );
        if( ans + delta < fans )
            fans = ans + delta;
    }
    printf( "%I64d\n" , fans );
}
int main(){
    init();
    solve();
}