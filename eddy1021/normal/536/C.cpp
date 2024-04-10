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
unordered_set<int> S;
void build(){

}
vector<PII> a , v;
int n , s[ N ] , r[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        s[ i ] = getint(); r[ i ] = getint();
        a.PB( MP( s[ i ] , r[ i ] ) );
    }
    sort( a.begin() , a.end() );
    for( int i = 0 ; i < n ; i ++ ){
        while( v.size() && a[ i ].SE >= v.back().SE ) v.pop_back();
        v.push_back( a[ i ] );
    }
}
int sz;
bool can( int idx ){
    int tmaxp = 0 , tmaxq = 1;
    int tminp = N , tminq = 1;
    for( int i = 0 ; i < idx ; i ++ ){
        int tmpp = llabs( v[ idx ].FI - v[ i ].FI ) * (ll)v[ i ].SE;
        int tmpq = llabs( v[ idx ].SE - v[ i ].SE ) * (ll)v[ i ].FI;
        if( (ll)tmpp * (ll)tminq < (ll)tmpq * (ll)tminp )
            tminp = tmpp , tminq = tmpq;
    }
    for( int i = idx + 1 ; i < sz ; i ++ ){
        int tmpp = llabs( v[ idx ].FI - v[ i ].FI ) * (ll)v[ i ].SE;
        int tmpq = llabs( v[ idx ].SE - v[ i ].SE ) * (ll)v[ i ].FI;
        if( (ll)tmpp * (ll)tmaxq > (ll)tmpq * (ll)tmaxp )
            tmaxp = tmpp , tmaxq = tmpq;
    }
//    cout << tmaxp << "/" << tmaxq << endl;
//    cout << tminp << "/" << tminq << endl;
    return (ll)tmaxp * (ll)tminq <= (ll)tmaxq * (ll)tminp;
}
void solve(){
    sz = (int)v.size();
    for( int i = 0 ; i < sz ; i ++ )
        if( i == 0 || i == sz - 1 || can( i ) )
            S.insert( v[ i ].FI * 100000 + v[ i ].SE );
    for( int i = 0 ; i < n ; i ++ )
        if( S.count( s[ i ] * 100000 + r[ i ] ) > 0 )
            printf( "%d " , i + 1 );
    puts( "" );
}
int main(){
    srand( time( 0 ) );
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}