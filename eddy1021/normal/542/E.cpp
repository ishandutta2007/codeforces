// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
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
#define N 1010
#define M 100010
int n , m , ans;
vector<int> v[ N ];
void build(){

}
void init(){
    n = getint(); m = getint();
    while( m -- ){
        int a , b;
        a = getint(); b = getint();
        v[ a ].PB( b );
        v[ b ].PB( a );
    }
}
int tag[ N ] , tans , ti;
int lvl[ N ]; bool flag;
queue<int> Q;
vector<int> inq;
void BFSp( int now ){
    while( Q.size() ) Q.pop();
    tag[ now ] = ti;
    Q.push( now );
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        inq.PB( tn );
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( !tag[ v[ tn ][ i ] ] ){
                tag[ v[ tn ][ i ] ] = ti;
                Q.push( v[ tn ][ i ] );
            }
    }
}
void BFS( int now ){
    for( int i = 1 ; i <= n ; i ++ ) lvl[ i ] = 0;
    while( Q.size() ) Q.pop();
    Q.push( now ); lvl[ now ] = 1;
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( !lvl[ v[ tn ][ i ] ] ){
                lvl[ v[ tn ][ i ] ] = lvl[ tn ] + 1;
                tans = max( tans , lvl[ v[ tn ][ i ] ] - 1 );
                Q.push( v[ tn ][ i ] );
            }else if( lvl[ tn ] == lvl[ v[ tn ][ i ] ] ){
                flag = false;
                return;
            }
    }
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ) if( !tag[ i ] ){
        inq.clear();
        ++ ti; BFSp( i ); tans = 0;
        for( int j = 0 ; j < (int)inq.size() ; j ++ ){
            flag = true;
            BFS( inq[ j ] );
            if( !flag ){
                puts( "-1" );
                return;
            }
        }
        ans += tans;
    }
    printf( "%d\n" , ans );
}
int main(){
    build();
    //  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}