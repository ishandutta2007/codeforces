#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
int a[ 10 ];
void build(){

}
void init(){
    for( int i = 1 ; i < 7 ; i ++ )
        a[ i ] = getint();
}
ll ans;
void solve(){
    if( a[ 5 ] > a[ 3 ] ){
        swap( a[ 1 ] , a[ 4 ] );
        swap( a[ 2 ] , a[ 5 ] );
        swap( a[ 3 ] , a[ 6 ] );
    }
    for( int i = 0 , j = a[ 4 ] * 2 + 1 ; i < a[ 5 ] ; i ++ , j += 2 )
        ans += j;
    int tmp = a[ 4 ] + a[ 5 ];
    int dlt = a[ 3 ] - a[ 5 ];
    ans += tmp * dlt * 2;
    for( int i = 0 , j = a[ 1 ] * 2 + 1 ; i < a[ 2 ] ; i ++ , j += 2 )
        ans += j;
    cout << ans << endl;
}
int main(){
    build();
    //__ = getint();
    while( __ -- ){
        init();
        solve();
    }  
}