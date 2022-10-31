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
#define N 210
int n , idx , ans , indeg[ N ] , dp[ N ];
map<string,int> M;
vector<int> v[ N ];
void build(){
    
}
string modify( string stmp ){
    int len = stmp.length();
    for( int i = 0 ; i < len ; i ++ )
        if( stmp[ i ] >= 'a' )
            stmp[ i ] -= 'a' - 'A';
    return stmp;
}
void init(){
    n = getint(); ans = 1;
    while( n -- ){
        string a , b , c;
        cin >> a >> b >> c;
        a = modify( a );
        c = modify( c );
        if( !M.count( a ) ) M[ a ] = ++ idx;
        if( !M.count( c ) ) M[ c ] = ++ idx;
        indeg[ M[ a ] ] ++;
        v[ M[ c ] ].PB( M[ a ] );
    }
}
queue<int> Q;
void solve(){
    int st = M[ "POLYCARP" ];
    dp[ st ] = 1; Q.push( st );
    while( Q.size() ){
        int tn = Q.front(); Q.pop();
        ans = max( ans , dp[ tn ] );
        for( int i = 0 ; i < (int)v[ tn ].size() ; i ++ ){
            dp[ v[ tn ][ i ] ] = max( dp[ v[ tn ][ i ] ] , dp[ tn ] + 1 );
            indeg[ v[ tn ][ i ] ] --;
            if( indeg[ v[ tn ][ i ] ] == 0 ) Q.push( v[ tn ][ i ] );
        }
    }
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