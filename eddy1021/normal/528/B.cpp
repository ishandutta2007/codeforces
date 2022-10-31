// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
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
#define N 200010
int n , w1[ N ] , w2[ N ];
vector<PII> v;
vector<int> sv;
int BIT[ N << 1 ] , sn;
int lb( int x ){ return x & (-x); }
void insert( int pos , int dlt ){
    while( pos <= sn ){
        BIT[ pos ] = max( BIT[ pos ] , dlt );
        pos += lb( pos );
    }
}
int query( int pos ){
    int tans = 0;
    while( pos ){
        tans = max( BIT[ pos ] , tans );
        pos -= lb( pos );
    }
    return tans;
}
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int tx , tw;
        tx = getint(); tw = getint();
        v.PB( MP( tx , tw ) );
    }
    sort( v.begin() , v.end() );
    for( int i = 0 ; i < n ; i ++ ){
        w1[ i ] = v[ i ].FI - v[ i ].SE;
        w2[ i ] = v[ i ].FI + v[ i ].SE;
        sv.PB( w1[ i ] );
        sv.PB( w2[ i ] );
    }
    sort( sv.begin() , sv.end() );
    sv.resize( unique( sv.begin() , sv.end() ) - sv.begin() );
    sn = (int)sv.size();
    for( int i = 0 ; i < n ; i ++ ){
        w1[ i ] = lower_bound( sv.begin() , sv.end() , w1[ i ] ) - sv.begin();
        w2[ i ] = lower_bound( sv.begin() , sv.end() , w2[ i ] ) - sv.begin();
        w1[ i ] ++; w2[ i ] ++;
    }
}
int ans;
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        int tans = query( w1[ i ] );
        ans = max( ans , tans + 1 );
        insert( w2[ i ] , tans + 1 );
    }
    printf( "%d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}