// eddy1021
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
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
#define N 500010
#define K 700
ll n , q , tn , dlt[ N / K + 1 ];
vector< pair<ll,int> > v[ N / K + 1 ];
void build(){

}
void init(){
    n = getint(); q = getint();
    for( int i = 0 ; i < n ; i ++ ){
        ll tmp = getint();
        v[ i / K ].PB( MP( tmp , i ) );
    }
    tn = ( n - 1 ) / K;
    for( int i = 0 ; i <= tn ; i ++ )
        sort( v[ i ].begin() , v[ i ].end() );
}
void modify( ll l , ll r , ll x ){
    ll p1 = l / K , p2 = r / K;
    for( int i = p1 + 1 ; i < p2 ; i ++ )
        dlt[ i ] += x;
    for( int i = 0 ; i < (int)v[ p1 ].size() ; i ++ )
        if( v[ p1 ][ i ].SE >= l &&
            v[ p1 ][ i ].SE <= r ) v[ p1 ][ i ].FI += x;
    sort( v[ p1 ].begin() , v[ p1 ].end() );
    if( p1 != p2 ){
        for( int i = 0 ; i < (int)v[ p2 ].size() ; i ++ )
            if( v[ p2 ][ i ].SE >= l &&
                v[ p2 ][ i ].SE <= r ) v[ p2 ][ i ].FI += x;
        sort( v[ p2 ].begin() , v[ p2 ].end() );
    }
}
int query( ll y ){
    int tmin = n + n , tmax = -n;
    for( int i = 0 ; i <= tn ; i ++ ){
        int pos = lower_bound( v[ i ].begin() , v[ i ].end() , MP( y - dlt[ i ] , -1 ) ) - v[ i ].begin();
        if( pos < (int)v[ i ].size() && v[ i ][ pos ].FI == y - dlt[ i ] ){
            tmin = min( tmin , v[ i ][ pos ].SE );
            tmax = max( tmax , v[ i ][ pos ].SE );
        }
        pos = upper_bound( v[ i ].begin() , v[ i ].end() , MP( y - dlt[ i ] , (int)n + (int)n ) ) - v[ i ].begin();
        if( pos - 1 < (int)v[ i ].size() && pos - 1 >= 0 && v[ i ][ pos - 1 ].FI == y - dlt[ i ] ){
            tmin = min( tmin , v[ i ][ pos - 1 ].SE );
            tmax = max( tmax , v[ i ][ pos - 1 ].SE );
        }
    }
    if( tmax == -n ) return -1;
    return tmax - tmin;
}
void solve(){
    while( q -- ){
        int type = getint();
        if( type == 1 ){
            ll l , r , x;
            l = getint(); r = getint(); x = getint();
            modify( l - 1 , r - 1 , x );
        }else{
            ll y = getint();
            printf( "%d\n" , query( y ) );
        }
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