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
#define N 510
int n , m;
char c[ N ][ N ];
int r1 , c1 , r2 , c2;
void build(){

}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    r1 = getint(); c1 = getint();
    r2 = getint(); c2 = getint();
}
bool vst[ N ][ N ];
bool in( int tr , int tc ){
    return 1 <= tr && tr <= n && 1 <= tc && tc <= m;
}
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
queue< PII >Q;
bool can(){
    vst[ r1 ][ c1 ] = true;
    Q.push( MP( r1 , c1 ) );
    while( Q.size() ){
        PII tp = Q.front(); Q.pop();
        int nr = tp.FI , nc = tp.SE;
        for( int i = 0 ; i < 4 ; i ++ ){
            int nxtr = nr + dr[ i ];
            int nxtc = nc + dc[ i ];
            if( in( nxtr , nxtc ) ){
                if( nxtr == r2 && nxtc == c2 ){
                    if( c[ r2 ][ c2 ] == 'X' ) return true;
                    int cnt = 0;
                    for( int j = 0 ; j < 4 ; j ++ )
                        if( in( r2 + dr[ j ] , c2 + dc[ j ] ) &&
                            ( c[ r2 + dr[ j ] ][ c2 + dc[ j ] ] == '.' ||
                              ( r2 + dr[ j ] == r1 && c2 + dc[ j ] == c1 ) ) )
                            cnt ++;
                    return cnt > 1;
                }
                if( !vst[ nxtr ][ nxtc ] && c[ nxtr ][ nxtc ] == '.' ){
                    Q.push( MP( nxtr , nxtc ) );
                    vst[ nxtr ][ nxtc ] = true;
                }
            }
        }
    }
    return false;
}
void solve(){
    if( can() ) puts( "YES" );
    else puts( "NO" );
}
int main(){
    build();  
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}