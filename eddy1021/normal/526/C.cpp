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
ll c , hr , hb , wr , wb;
void build(){

}
void init(){
    c = getint();
    hr = getint();
    hb = getint();
    wr = getint();
    wb = getint();
}
ll cal2( ll x ){
    ll tk = x / wr;
    ll tk2 = ( c - x ) / wb;
    return tk * hr + tk2 * hb;
}
ll cal(){
    ll l = 0 , r = c , mid1 , mid2 , ans = 0;
    while( l <= r ){
        if( r - l < 5 ){
            for( ll i = l ; i <= r ; i ++ )
                ans = max( ans , cal2( i ) );
            break;
        }
        mid1 = l + ( r - l ) / 3;
        mid2 = r - ( r - l ) / 3;
        ll tans1 = cal2( mid1 );
        ll tans2 = cal2( mid2 );
//        printf( "%I64d %I64d\n" , mid1 , tans1 );
//        printf( "%I64d %I64d\n" , mid2 , tans1 );
        if( tans1 <= tans2 ){
            ans = max( ans , tans2 );
            l = mid1 + 1;
        }else{
            ans = max( ans , tans1 );
            r = mid2 - 1;
        }
    }
    return ans;
}
void solve(){
    ll ans = 0;
    for( ll i = 0 ; i < 1000000 ; i ++ ){
        if( i * wr <= c ){
            ll tk = ( c - i * wr ) / wb;
            ans = max( ans , i * hr + tk * hb );
        }
        if( i * wb <= c ){
            ll tk = ( c - i * wb ) / wr;
            ans = max( ans , i * hb + tk * hr );
        }
        if( i * wr > c && i * wb > c ) break;
    }
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