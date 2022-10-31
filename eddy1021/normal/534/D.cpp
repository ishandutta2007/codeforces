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
void build(){

}
#define N 200010
multiset<PII> S[ 3 ];
typedef multiset<PII>::iterator si;
vector<int> ans;
int n , a[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < 3 ; i ++ ){
        S[ i ].insert( MP( -N , -1 ) );
        S[ i ].insert( MP( N  , -1 ) );
    }
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        S[ a[ i ] % 3 ].insert( MP( a[ i ] , i ) );
    }
}
bool can(){
    int now = 0;
    for( int i = 0 ; i < n ; i ++ ){
        int nd = now % 3;
        if( S[ nd ].size() == 2 ) return false;
        si it = S[ nd ].begin(); it ++;
        if( it->first > now ) return false;
        it = S[ nd ].upper_bound( MP( now , N ) ); it --;
        if( it->first > now ) return false;
        if( it->second == -1 ) return false;
        now = ( it->first ) + 1;
        int idx = it->second;
        ans.PB( idx );
        S[ nd ].erase( S[ nd ].find( MP( now - 1 , idx ) ) );
    }
    return true;
}
void solve(){
    if( can() ){
        puts( "Possible" );
        for( int i = 0 ; i < n ; i ++ ){
            printf( "%d" , ans[ i ] );
            putchar( i == n - 1 ? '\n' : ' ' );
        }
    }else puts( "Impossible" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}