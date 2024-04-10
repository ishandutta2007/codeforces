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
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 60
int n , m;
char c[ N ][ N ];
bool flag , vst[ N ][ N ];
void build(){

}
bool in( int tn , int tm ){
    return tn >= 1 && tn <= n && tm >= 1 && tm <= m;
}
int dn[]={0,0,1,-1};
int dm[]={1,-1,0,0};
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
}
void DFS( int pn , int pm , int tn , int tm ){
    vst[ tn ][ tm ] = true;
    for( int i = 0 ; i < 4 ; i ++ ){
        int nxtn = tn + dn[ i ] , nxtm = tm + dm[ i ];
        if( nxtn == pn && nxtm == pm ) continue;
        if( in( nxtn , nxtm ) && c[ tn ][ tm ] == c[ nxtn ][ nxtm ] ){
            if( !vst[ nxtn ][ nxtm ] )
                DFS( tn , tm , nxtn , nxtm );
            else flag = true;
        }
    }
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( !vst[ i ][ j ] )
                DFS( -1 , -1 , i , j );
    puts( flag ? "Yes" : "No" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}