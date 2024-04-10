// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 510
int n , a[ N ] , dp[ N ][ N ];
void build(){
    
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
int DP( int l , int r ){
    if( l > r ) return 1;
    if( dp[ l ][ r ] ) return dp[ l ][ r ];
    if( l == r ) return dp[ l ][ r ] = 1;
    int sum = DP( l + 1 , r );
    for( int i = l + 1 ; i <= r ; i ++ )
        if( a[ i ] > a[ l ] ){
            ll tsum = ( (ll)( DP( l + 1 , i - 1 ) ) * (ll)( DP( i , r ) ) ) % mod7;
            sum = ( sum + (int)tsum ) % mod7;
        }
//    printf( "%d %d %d\n" , l , r , sum );
    return dp[ l ][ r ] = sum;
}
void solve(){
    if( n == 1 ) puts( "1" );
    else printf( "%d\n" , DP( 2 , n ) );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}