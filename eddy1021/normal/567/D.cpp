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
void build(){

}
int n , k , a , mx;
set< PII > S;
void init(){
    n = getint();
    k = getint();
    a = getint();
    S.insert( MP( 1 , n ) );
    S.insert( MP( 2 * n , 2 * n ) );
    mx = ( n + 1 ) / ( a + 1 );
}
void solve(){
    int m = getint();
    for( int i = 1 ; i <= m ; i ++ ){
        int x = getint();
        PII tp = *--S.upper_bound( MP( x , n + n ) );
        mx -= ( tp.SE - tp.FI + 2 ) / ( a + 1 );
        S.erase( S.find( tp ) );
        if( tp.FI != x ){
            S.insert( MP( tp.FI , x - 1 ) );
            mx += ( x - tp.FI + 1 ) / ( a + 1 );
        }
        if( tp.SE != x ){
            S.insert( MP( x + 1 , tp.SE ) );
            mx += ( tp.SE - x + 1 ) / ( a + 1 );
        }
        if( mx < k ){
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}