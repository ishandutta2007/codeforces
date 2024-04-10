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
#define SZ(x) (int)(x).size()
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
#define N 100010
int n;
char ans[ N ];
bool got[ N ];
vector<int> v[ N ];
int dps[ N ] , dp[ N ];
void build(){

}
void init(){
    n = getint();
    for( int i = 1 ; i < n ; i ++ ){
        int a , b;
        a = getint();
        b = getint();
        v[ a ].PB( b );
        v[ b ].PB( a );
    }
}
int cen , tsz , tn;
void DP( int now , int pt ){
    dps[ now ] = 1;
    dp[ now ] = 0;
    tn ++;
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ] != pt && !got[ v[ now ][ i ] ] ){
            DP( v[ now ][ i ] , now );
            dp[ now ] = max( dp[ now ] , dps[ v[ now ][ i ] ] );
            dps[ now ] += dps[ v[ now ][ i ] ];
        }
}
void DP2( int now , int pt ){
    dp[ now ] = max( dp[ now ] , tn - dps[ now ] );
    if( dp[ now ] < tsz )
        cen = now , tsz = dp[ now ];
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ] != pt && !got[ v[ now ][ i ] ] )
            DP2( v[ now ][ i ] , now );
}
void find_c( int now ){
    tn = 0;
    DP( now , -1 );
    cen = now; tsz = n + n;
    DP2( now , -1 );
}
void DFS( int now , int nrank ){
    find_c( now );
    got[ cen ] = true;
    ans[ cen ] = nrank + 'A';
    int ncen = cen;
    for( int i = 0 ; i < (int)v[ ncen ].size() ; i ++ )
        if( !got[ v[ ncen ][ i ] ] )
            DFS( v[ ncen ][ i ] , nrank + 1 );
}
void solve(){
    DFS( 1 , 0 );
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%c%c" , ans[ i ] , " \n"[i==n] );
}
int main(){

    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}