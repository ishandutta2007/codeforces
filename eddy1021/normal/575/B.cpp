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
#define ALL(x) (x).begin(), (x).end()
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
int n , k , a[ N * 10 ] , lca[ N * 10 ];
int p[ N ];
bool got[ N ];
ll two[ N * 10 ];
int find_p( int x ){
    return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
    p[ x ] = y;
}
vector<PII> v[ N ];
vector<PII> q[ N ];
// -1 bi 0 yes 1 no
void build(){
    two[ 0 ] = 1;
    for( int i = 1 ; i < N * 10 ; i ++ )
        two[ i ] = ( two[ i - 1 ] * 2ll ) % mod7;
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        p[ i ] = i;
    for( int i = 1 ; i < n ; i ++ ){
        int tu = getint();
        int tv = getint();
        int tc = getint();
        if( !tc ){
            v[ tu ].PB( MP( tv , -1 ) );
            v[ tv ].PB( MP( tu , -1 ) );
        }else{
            v[ tu ].PB( MP( tv , 0 ) );
            v[ tv ].PB( MP( tu , 1 ) );
        }
    }
    k = getint(); k ++;
    a[ 0 ] = 1;
    for( int i = 1 ; i < k ; i ++ ){
        a[ i ] = getint();
        q[ a[ i ] ].PB( MP( a[ i - 1 ] , i - 1 ) );
        q[ a[ i - 1 ] ].PB( MP( a[ i ] , i - 1 ) );
    }
}
void Tarjan( int now , int prt ){
    got[ now ] = true;
    for( int i = 0 ; i < (int)q[ now ].size() ; i ++ )
        if( got[ q[ now ][ i ].FI ] )
            lca[ q[ now ][ i ].SE ] = find_p( q[ now ][ i ].FI );
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ].FI != prt ){
            Tarjan( v[ now ][ i ].FI , now );
            Union( v[ now ][ i ].FI , now );
        }
}
ll ans , tag1[ N ] , tag2[ N ];
int DFS1( int now , int prt ){
    int sum = 0;
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ].FI != prt ){
            int tsum = DFS1( v[ now ][ i ].FI , now );
            if( v[ now ][ i ].SE == 0 )
                ans = ( ans + two[ tsum ] - 1 + mod7 ) % mod7;
            sum += tsum;
        }
    sum += tag1[ now ];
    return sum;
}
int DFS2( int now , int prt ){
    int sum = 0;
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ].FI != prt ){
            int tsum = DFS2( v[ now ][ i ].FI , now );
            if( v[ now ][ i ].SE == 1 )
                ans = ( ans + two[ tsum ] - 1 + mod7 ) % mod7;
            sum += tsum;
        }
    sum += tag2[ now ];
    return sum;
}
void solve(){
    Tarjan( 1 , -1 );
    for( int i = 0 ; i < k - 1 ; i ++ ){
        tag1[ a[ i ] ] ++;
        tag1[ lca[ i ] ] --;

        tag2[ a[ i + 1 ] ] ++;
        tag2[ lca[ i ] ] --;
    }
//    for( int i = 1 ; i <= n ; i ++ )
//        cout << tag1[ i ] << " " << tag2[ i ] << endl;
    DFS1( 1 , -1 );
    DFS2( 1 , -1 );
    cout << ans << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}