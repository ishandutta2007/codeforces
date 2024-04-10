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
int n , m;
vector<PII> v , v0 , ch;
set<PII> s;
PII operator-( const PII &p1 , const PII &p2 ){
    return MP( p1.FI - p2.FI , p1.SE - p2.SE );
}
bool cross( PII p1 , PII p2 ){
    return (ll)p1.FI * (ll)p2.SE - (ll)p1.SE * (ll)p2.FI < 0ll;
}
void build(){

}
void init(){
    n = getint(); m = getint();
    int _ = getint(); _ = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int tx = getint();
        int ty = getint();
        v.PB( MP( tx , -ty ) );
        v0.PB( MP( tx , ty ) );
    }
    for( int i = 0 ; i < m ; i ++ ){
        int tx = getint();
        int ty = getint();
        v.PB( MP( tx , -ty ) );
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
}
void solve(){
    int csz = 0;
    for( int i = 0 ; i < (int)v.size() ; i ++ ){
        v[ i ].SE = -v[ i ].SE;
        while( csz > 0 && ch[ csz - 1 ].SE < v[ i ].SE ) 
            ch.pop_back() , csz --;
        while( csz > 1 && cross( v[ i ] - ch[ csz - 2 ] , ch[ csz - 1 ] - ch[ csz - 2 ] ) )
            ch.pop_back() , csz --;
        ch.PB( v[ i ] ); csz ++;
    }
    for( int i = 0 ; i < (int)ch.size() ; i ++ )
//        printf( "%d %d\n" , ch[ i ].FI , ch[ i ].SE );
        s.insert( ch[ i ] );
    bool winner = false;
    for( int i = 0 ; i < (int)v0.size() ; i ++ )
        if( s.find( v0[ i ] ) != s.end() ){
            winner = true;
            break;
        }
    puts( winner ? "Max" : "Min" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}