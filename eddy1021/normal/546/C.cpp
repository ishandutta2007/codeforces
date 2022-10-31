// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define LLINF 10000000000000000ll
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
#define N 11
int n , k1,  k2;
deque<int> d1 , d2;
ll value( deque<int> d ){
    ll tv = 0;
    for( size_t i = 0 ; i < d.size() ; i ++ )
        tv = ( tv * ( n + 1 ) + d[ i ] );
    return tv;
}
void build(){

}
void init(){
    n = getint();
    k1 = getint();
    for( int i = 0 ; i < k1 ; i ++ )
        d1.PB( getint() );
    k2 = getint();
    for( int i = 0 ; i < k2 ; i ++ )
        d2.PB( getint() );
}
set< pair<ll,ll> > S;
void solve(){
    int cnt = 0;
    ll vl1 = value( d1 );
    ll vl2 = value( d2 );
    S.insert( MP( vl1 , vl2 ) );
    S.insert( MP( vl2 , vl1 ) );
    while( k1 && k2 ){
        int v1 = d1.front(); d1.pop_front();
        int v2 = d2.front(); d2.pop_front();
        if( v1 > v2 ){
            k1 ++; k2 --;
            d1.PB( v2 ); d1.PB( v1 );
        }else{
            k2 ++; k1 --;
            d2.PB( v1 ); d2.PB( v2 );
        }
        vl1 = value( d1 );
        vl2 = value( d2 );
        if( S.count( MP( vl1 , vl2 ) ) || S.count( MP( vl2 , vl1 ) ) ){
            puts( "-1" );
            return;
        }
        S.insert( MP( vl1 , vl2 ) );
        S.insert( MP( vl2 , vl1 ) );
        cnt ++;
    }
    if( k1 ) printf( "%d 1\n" , cnt );
    else printf( "%d 2\n" , cnt );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}