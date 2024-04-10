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
#define N 100010
int n , m , deg[ N ];
multiset<int> S[ N ];
typedef multiset<int>::iterator si;
vector<int> odd;
void build(){

}
void init(){
    n = getint(); m = getint();
    while( m -- ){
        int u , v;
        u = getint(); v = getint();
        S[ u ].insert( v );
        S[ v ].insert( u );
        deg[ u ] ++;
        deg[ v ] ++;
    }
    for( int i = 1 ; i <= n ; i ++ )
        if( deg[ i ] % 2 )
            odd.PB( i );
    if( (int)odd.size() % 2 ) assert( 1 == 0 );
    for( int i = 0 , j = (int)odd.size() - 1 ; i < j ; i ++ , j -- ){
        S[ odd[ i ] ].insert( odd[ j ] );
        S[ odd[ j ] ].insert( odd[ i ] );
    }
}
vector<PII> ans;
int got;
void DFS( int now ){
    while( S[ now ].size() ){
        si it = S[ now ].begin();
        int des = *it;
        S[ now ].erase( S[ now ].find( des ) );
        S[ des ].erase( S[ des ].find( now ) );
        DFS( des );
        got ++;
        if( got % 2 ) ans.PB( MP( des , now ) );
        else ans.PB( MP( now , des ) );
    } 
}
void find_circle(){
    for( int i = 1 ; i <= n ; i ++ )
        while( (int)S[ i ].size() > 0 ){
            got = 0;
            DFS( i );
            if( got % 2 ) ans.PB( MP( i , i ) );
        }
}
void solve(){
    find_circle();
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d\n" , ans[ i ].FI , ans[ i ].SE );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}