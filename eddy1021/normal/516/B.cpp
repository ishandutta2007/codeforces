// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x , D _y ){
    return _x > _y - eps && _x < _y + eps;
}
D mypow( D _x , ll _a ){
    if( _a == 0 ) return 1.0;
    D _tmp = mypow( _x , _a / 2 );
    _tmp *= _tmp;
    if( _a & 1ll ) _tmp *= _x;
    return _tmp;
}
ll mypow( ll _x , ll _a , ll _mod ){
    if( _a == 0 ) return 1ll;
    ll _tmp = mypow( _x , _a / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _a & 1ll ) _tmp = ( _tmp * _x ) % _mod;
    return _tmp;
}
int __ = 1 , cs;
/***   default ***/
#define N 2010
int n , m , ndput;
char c[ N ][ N ];
void build(){

}
deque< PII > d;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool in( int ti , int tj ){
    return 1 <= ti && ti <= n && 1 <= tj && tj <= m;
}
bool lonely( int ti , int tj ){
    if( c[ ti ][ tj ] != '.' ) return false;
    int cnt = 0;
    for( int i = 0 ; i < 4 ; i ++ )
        if( in( ti + dx[ i ] , tj + dy[ i ] ) &&
            c[ ti + dx[ i ] ][ tj + dy[ i ] ] == '.' )
            cnt ++;
    return cnt == 1;
}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            if( c[ i ][ j ] == '.' ){
                ndput ++;
                if( lonely( i , j ) )
                    d.PB( MP( i , j ) );
            }
        }
}
void solve(){
    while( d.size() ){
        PII tp = d.front(); d.pop_front();
        int ni = tp.FI , nj = tp.SE;
        if( !lonely( ni , nj ) ) continue;
        for( int i = 0 ; i < 4 ; i ++ ){
            int nxti = ni + dx[ i ];
            int nxtj = nj + dy[ i ];
            if( in( nxti , nxtj ) && c[ nxti ][ nxtj ] == '.' ){
                ndput -= 2;
                if( i == 0 ){
                    c[ ni ][ nj ] = '<';
                    c[ nxti ][ nxtj ] = '>';
                }else if( i == 1 ){
                    c[ ni ][ nj ] = '>';
                    c[ nxti ][ nxtj ] = '<';
                }else if( i == 2 ){
                    c[ ni ][ nj ] = '^';
                    c[ nxti ][ nxtj ] = 'v';
                }else{
                    c[ ni ][ nj ] = 'v';
                    c[ nxti ][ nxtj ] = '^';
                }
                for( int j = 0 ; j < 4 ; j ++ ){
                    int cni = nxti + dx[ j ];
                    int cnj = nxtj + dy[ j ];
                    if( in( cni , cnj ) && lonely( cni , cnj ) )
                        d.PB( MP( cni , cnj ) );
                }
                break;
            }
        }
    }
    if( ndput != 0 ) puts( "Not unique" );
    else{
        for( int i = 1 ; i <= n ; i ++ )
            puts( c[ i ] + 1 );
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