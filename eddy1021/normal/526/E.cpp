// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1000010
int n , q;
ll a[ N * 2 ] , sum[ N * 2 ];
void build(){

}
void init(){
    n = getint(); q = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ n + i ] = a[ i ] = getint();
    for( int i = 1 ; i <= 2 * n ; i ++ )
        sum[ i ] = sum[ i - 1 ] + a[ i ];
}
int lst[ N * 2 ];
ll cal( ll tk ){
    int pt = 2 * n;
    lst[ 2 * n ] = 2 * n;
    for( int i = 2 * n - 1 ; i >= 1 ; i -- ){
        while( sum[ pt ] - sum[ i - 1 ] > tk ) pt --;
        lst[ i ] = pt;
    }
    ll bst = 1;
    for( int i = 2 ; i <= n ; i ++ )
        if( lst[ i ] - i < lst[ bst ] - bst )
            bst = i;
    ll tans = n;
    for( int j = bst ; j <= lst[ bst ] + 1 ; j ++ ){
        int i = j;
        if( i > n ) i -= n;
        ll cnt = 0 , now = i;
        while( now < i + n ){
            cnt ++;
            now = lst[ now ] + 1;
        }
        tans = min( tans , cnt );
    }
    return tans;
}
void solve(){
    while( q -- ){
        ll k = getint();
        printf( "%I64d\n" , cal( k ) );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}