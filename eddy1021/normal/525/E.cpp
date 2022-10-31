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
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x , D _y ){
    return _x > _y - eps && _x < _y + eps;
}
D mypow( D _x , ll _a ){
    if( _a == 0 ) return 1.0;
    D _tmp = mypow( _x , _a / 2 );
    _tmp *= _tmp;
    if( _a & 1ll ) _tmp *= _x;
    return _tmp;
}
ll mypow( ll _x , ll _a , ll _mod ){
    if( _a == 0 ) return 1ll;
    ll _tmp = mypow( _x , _a / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _a & 1ll ) _tmp = ( _tmp * _x ) % _mod;
    return _tmp;
}
int __ = 1 , cs;
/***   default ***/
#define K 30
ll lv[ K ] , n , k , s , a[ K ];
map<ll,ll> cnt[ K ];
vector<ll> a1 , a2;
ll ans;
void build(){
    lv[ 0 ] = 1;
    for( ll i = 1 ; i < 19 ; i ++ )
        lv[ i ] = lv[ i - 1 ] * i;
//    for( int i = 1 ; i < 19 ; i ++ )
//        printf( "%d! : %I64d\n" , i , lv[ i ] );
}
void init(){
    n = getint(); k = getint(); s = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
    sort( a , a + n );
    ll hf = n / 2;
    for( int i = 0 ; i < hf ; i ++ ) a1.PB( a[ i ] );
    for( int i = hf ; i < n ; i ++ ) a2.PB( a[ i ] );
}
void DFS1( ll now , ll tk , ll tsum ){
    if( tk > k || tsum > s ) return;
    if( now == (int)a1.size() ){
        if( tsum == s ) ans ++;
        else cnt[ tk ][ tsum ] ++;
        return;
    }
    DFS1( now + 1 , tk , tsum );
    DFS1( now + 1 , tk , tsum + a1[ now ] );
    if( a1[ now ] < 19 )
        DFS1( now + 1 , tk + 1 , tsum + lv[ a1[ now ] ] );
}
void DFS2( ll now , ll tk , ll tsum ){
    if( tk > k || tsum > s ) return;
    if( now == (int)a2.size() ){
        if( tsum == 0 ) return;
        for( int i = 0 ; i + tk <= k ; i ++ )
            if( cnt[ i ].count( s - tsum ) )
                ans += cnt[ i ][ s - tsum ];
        return;
    }
    DFS2( now + 1 , tk , tsum );
    DFS2( now + 1 , tk , tsum + a2[ now ] );
    if( a2[ now ] < 19 )
        DFS2( now + 1 , tk + 1 , tsum + lv[ a2[ now ] ] );
}
void solve(){
    DFS1( 0 , 0 , 0 );
    DFS2( 0 , 0 , 0 );
    printf( "%I64d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}