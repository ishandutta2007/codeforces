// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009int
#define mod7 1000000007int 
#define INF 1023456789int
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
    if( _x == 0 ) return 1;
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
int r , s , p;
typedef pair< D,pair<D,D> > po;
#define R FI
#define S SE.FI
#define P SE.SE
void build(){

}
void init(){
    r = getint(); s = getint(); p = getint();
}
#define N 110
po dp[ N ][ N ][ N ];
bool vst[ N ][ N ][ N ];
po DP( int tr , int ts , int tp ){
    if( ts == 0 && tp == 0 ) return MP( 1.0 , MP( 0.0 , 0.0 ) );
    if( tr == 0 && tp == 0 ) return MP( 0.0 , MP( 1.0 , 0.0 ) );
    if( ts == 0 && tr == 0 ) return MP( 0.0 , MP( 0.0 , 1.0 ) );
    if( vst[ tr ][ ts ][ tp ] ) return dp[ tr ][ ts ][ tp ];
    vst[ tr ][ ts ][ tp ] = true;
    D pr = 0.0 , ps = 0.0 , pp = 0.0;
    int total = tr * ts + ts * tp + tr * tp;
    if( tr && ts ){
        int pot = tr * ts;
        D tmpp = (D)pot / (D)total;
        po tmp = DP( tr , ts - 1 , tp );
        pr += tmp.R * tmpp;
        ps += tmp.S * tmpp;
        pp += tmp.P * tmpp;
    }
    if( tr && tp ){
        int pot = tr * tp;
        D tmpp = (D)pot / (D)total;
        po tmp = DP( tr - 1 , ts , tp );
        pr += tmp.R * tmpp;
        ps += tmp.S * tmpp;
        pp += tmp.P * tmpp;
    }
    if( ts && tp ){
        int pot = ts * tp;
        D tmpp = (D)pot / (D)total;
        po tmp = DP( tr , ts , tp - 1 );
        pr += tmp.R * tmpp;
        ps += tmp.S * tmpp;
        pp += tmp.P * tmpp;
    }
    return dp[ tr ][ ts ][ tp ] = MP( pr , MP( ps , pp ) );
}
void solve(){
    po tp = DP( r , s , p );
    printf( "%.12f %.12f %.12f\n" , tp.R , tp.S , tp.P );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}