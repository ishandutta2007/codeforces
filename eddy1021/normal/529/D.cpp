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
#define N 20010
int n , m , t;
vector<int> v;
deque<PII> d;
int idx , ans[ N ];
bool got;
void build(){

}
void init(){
    n = getint(); m = getint(); t = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int th , tm , ts;
        th = getint(); tm = getint(); ts = getint();
        v.PB( th * 3600 + tm * 60 + ts );
    }
}
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        while( d.size() && d.front().FI <= v[ i ] - t )
            d.pop_front();
        if( (int)d.size() == m ){
            ans[ i ] = d.back().SE;
            d.pop_back();
        }else ans[ i ] = ++ idx;
        d.push_back( MP( v[ i ] , ans[ i ] ) );
        if( (int)d.size() == m ) got = true;
    }
    if( !got ){
        puts( "No solution" );
    }else{
        printf( "%d\n" , idx );
        for( int i = 0 ; i < n ; i ++ )
            printf( "%d\n" , ans[ i ] );
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