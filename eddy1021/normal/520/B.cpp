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
#define N 200010
int dst[ N ];
void build(){

}
int n , m;
void init(){
    n = getint();
    m = getint();
    
}
bool inq[ N ];
queue<int> Q;
void SPFA(){
    for( int i = 0 ; i < N ; i ++ ) dst[ i ] = INF;
    dst[ n ] = 0; Q.push( n );
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); inq[ tn ] = false;
        if( tn * 2 < N && dst[ tn ] + 1 < dst[ tn * 2 ] ){
            dst[ tn * 2 ] = dst[ tn ] + 1;
            if( !inq[ tn * 2 ] ){
                inq[ tn * 2 ] = true;
                Q.push( tn * 2 );
            }
        }
        if( tn - 1 > 0 && dst[ tn ] + 1 < dst[ tn - 1 ] ){
            dst[ tn - 1 ] = dst[ tn ] + 1;
            if( !inq[ tn - 1 ] ){
                inq[ tn - 1 ] = true;
                Q.push( tn - 1 );
            }
        }
    }
}
void solve(){
    SPFA();
    printf( "%d\n" , dst[ m ] );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}