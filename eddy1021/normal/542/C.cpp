// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
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
#define N 210
ll n , a[ N ] , ans , tmin;
ll gcd( ll ta , ll tb ){
    ll tr;
    while( tb ){
        tr = ta % tb;
        ta = tb;
        tb = tr;
    }
    return ta;
}
ll lcm( ll ta , ll tb ){
    ll tmp = gcd( ta , tb );
    return ( ta / tmp ) * tb;
}
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
    ans = 1;
}
int tag[ N ];
void DFS( int now , int ttag ){
    tag[ now ] = ttag;
    if( tag[ a[ now ] ] ){
        ll cyc = ttag + 1 - tag[ a[ now ] ];
        tmin = max( tmin , (ll)tag[ a[ now ] ] - 1 );
//        ll tmp = ( ( tag[ a[ now ] ] - 1 ) / cyc ) +
//            ( ( tag[ a[ now ] ] - 1 ) % cyc != 0 );
        //printf( "%d %I64d %I64d\n" , now , cyc , tmp );
//        ll tans = tmp * cyc;
        ans = lcm( ans , cyc );
    }else DFS( a[ now ] , ttag + 1 );
}
void solve(){
    tmin = 0;
    for( int i = 1 ; i <= n ; i ++ ){
        if( a[ i ] == i ) continue;
        memset( tag , 0 , sizeof( tag ) );
        DFS( i , 1 );
    }
    ll ttt = ( tmin / ans ) + ( tmin % ans != 0 );
    if( ttt == 0 ) ttt = 1;
    ans *= ttt;
    cout << ans << endl;
}
int main(){
    build();  
    //  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}