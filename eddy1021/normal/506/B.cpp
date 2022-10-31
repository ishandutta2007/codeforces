#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
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
#define N 100010
int n , m , ans , cnt , deg[ N ];
vector<int> v[ N ] , rv[ N ];
bool vst[ N ] , flag;
void build(){

}
void init(){
    n = getint(); m = getint();
    while( m -- ){
        int a , b;
        a = getint(); b = getint();
        v[ a ].PB( b );
        rv[ b ].PB( a );
        deg[ b ] ++;
    }
}
queue<int> Q;
void DFS( int now ){
    vst[ now ] = true; cnt ++;
    if( deg[ now ] == 0 ) Q.push( now );
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( !vst[ v[ now ][ i ] ] )
            DFS( v[ now ][ i ] );
    for( int i = 0 ; i < (int)rv[ now ].size() ; i ++ )
        if( !vst[ rv[ now ][ i ] ] )
            DFS( rv[ now ][ i ] );
}
void count( int idx ){
    while( Q.size() ) Q.pop();
    cnt = 0; int got = 0;
    DFS( idx );
    while( Q.size() ){
        int tn = Q.front(); Q.pop(); got ++;
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ ){
            deg[ v[ tn ][ i ] ] --;
            if( deg[ v[ tn ][ i ] ] == 0 )
               Q.push( v[ tn ][ i ] ); 
        }
    }
    if( got != cnt ) ans += cnt;
    else ans += ( cnt - 1 );
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ) if( !vst[ i ] )
        count( i );
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