// eddy1021
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
#define eps 1e-9
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
#define N 200010
int n , m;
ll l[ N ] , r[ N ];
int ans[ N ];
vector< pair<ll,int> > bridge;
vector< tuple<ll,ll,int> > need;
void build(){

}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        l[ i ] = getint();
        r[ i ] = getint();
    }
    for( int i = 0 ; i < m ; i ++ ){
        ll len = getint();
        bridge.PB( MP( len , i + 1 ) );
    }
    for( int i = 1 ; i < n ; i ++ ){
        ll tmin = l[ i + 1 ] - r[ i ];
        ll tmax = r[ i + 1 ] - l[ i ];
        need.PB( MT( tmax , tmin , i ) );
    }
    sort( bridge.begin() , bridge.end() );
    sort( need.begin() , need.end() );
//    sort( tmp.begin() , tmp.end() );
//    tmp.resize( unique( tmp.begin() , tmp.end() ) - tmp.begin() );
}
set< pair<ll,int> > wait;
set< pair<ll,int> >::iterator si;
bool can(){
    int now = 0;
    for( int i = 0 ; i < n - 1 ; i ++ ){
        while( now < m && bridge[ now ].FI <= get<0>( need[ i ] ) )
            wait.insert( bridge[ now ++ ] );
        if( (int)wait.size() == 0 ) return false;
        pair<ll,int> tp = *--wait.end();
        if( tp.FI < get<1>( need[ i ] ) ) return false;
        tp = *wait.lower_bound( MP( get<1>( need[ i ] ) , -1 ) );
        wait.erase( wait.find( tp ) );
        ans[ get<2>( need[ i ] ) ] = tp.SE;
    }
    return true;
}
void solve(){
    if( can() ){
        puts( "Yes" );
        for( int i = 1 ; i < n ; i ++ )
            printf( "%d " , ans[ i ] );
        puts( "" );
    }else puts( "No" );
}
int main(){
    build();
//  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}