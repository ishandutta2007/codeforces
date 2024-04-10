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
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
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
/*** default ***/
#define N 3010
int n , m;
vector<int> v[ N ];
int s1 , t1 , l1;
int s2 , t2 , l2;
int ans;
void build(){

}
void init(){
    n = getint(); m = getint(); ans = m + 1;
    for( int i = 0 ; i < m ; i ++ ){
        int a , b;
        a = getint(); b = getint();
        v[ a ].PB( b );
        v[ b ].PB( a );
    }
    s1 = getint(); t1 = getint(); l1 = getint();
    s2 = getint(); t2 = getint(); l2 = getint();
}
int dst[ N ][ N ];
bool vst[ N ];
queue<int> Q;
void BFS( int now ){
    for( int i = 1 ; i <= n ; i ++ ) vst[ i ] = 0;
    while( Q.size() ) Q.pop();
    dst[ now ][ now ] = 0; vst[ now ] = true;
    Q.push( now ); while( Q.size() ){
        int tn = Q.front(); Q.pop();
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ )
            if( !vst[ v[ tn ][ i ] ] ){
                dst[ now ][ v[ tn ][ i ] ] = dst[ now ][ tn ] + 1;
                vst[ v[ tn ][ i ] ] = true;
                Q.push( v[ tn ][ i ] );
            }
    }
}
void update( int tans ){
    if( tans < ans ) ans = tans;
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        BFS( i );
    if( dst[ s1 ][ t1 ] <= l1 && dst[ s2 ][ t2 ] <= l2 )
        update( dst[ s1 ][ t1 ] + dst[ s2 ][ t2 ] );
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= n ; j ++ ){
            if( dst[ s1 ][ i ] + dst[ i ][ j ] + dst[ j ][ t1 ] <= l1 &&
                dst[ s2 ][ i ] + dst[ i ][ j ] + dst[ j ][ t2 ] <= l2 )
                    update( dst[ s1 ][ i ] + dst[ i ][ j ] + dst[ j ][ t1 ] + dst[ s2 ][ i ] + dst[ j ][ t2 ] );
            if( dst[ s1 ][ i ] + dst[ i ][ j ] + dst[ j ][ t1 ] <= l1 &&
                dst[ t2 ][ i ] + dst[ i ][ j ] + dst[ j ][ s2 ] <= l2 )
                    update( dst[ s1 ][ i ] + dst[ i ][ j ] + dst[ j ][ t1 ] + dst[ t2 ][ i ] + dst[ j ][ s2 ] );
        }
    cout << m - ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}