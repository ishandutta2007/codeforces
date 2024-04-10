// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
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
#define L 600010
#define N 300010
int n , m;
ll p = 4ll , bs[ L ];
void build(){
    bs[ 0 ] = 1ll;
    for( int i = 1 ; i < L ; i ++ )
        bs[ i ] = ( bs[ i - 1 ] * p ) % mod7;
}
set<ll> S[ N ];
string ts;
ll hv(){
    int len = ts.length();
    ll hvl = 0;
    for( int i = 0 ; i < len ; i ++ ){
        ll dlt = ( ( ts[ i ] - 'a' + 1 ) * bs[ i ] ) % mod7;
        hvl = ( hvl + dlt ) % mod7;
    }
    return hvl;
}
vector<int> v;
set<int> LEN;
int len[ N ] , tn;
ll nvl[ N ];
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < n ; i ++ ){
        cin >> ts;
        len[ i ] = ts.length();
        v.PB( len[ i ] );
        nvl[ i ] = hv();
        LEN.insert( len[ i ] );
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
    for( int i = 0 ; i < n ; i ++ )
        S[ lower_bound( v.begin() , v.end() , len[ i ] ) - v.begin() ].insert( nvl[ i ] );
}
void solve(){
    while( m -- ){
        cin >> ts;
        int tlen = ts.length();
        if( LEN.count( tlen ) == 0 ){
            puts( "NO" );
            continue;
        }
        int idx = lower_bound( v.begin() , v.end() , tlen ) - v.begin();
        ll tvl = hv();
        bool flag = false;
        for( int i = 0 ; i < tlen ; i ++ ){
            for( char j = 'a' ; j <= 'c' ; j ++ )
                if( ts[ i ] != j ){
                    tvl = ( tvl - ( bs[ i ] * ( ts[ i ] - 'a' + 1 ) ) % mod7 + mod7 ) % mod7;
                    tvl = ( tvl + ( bs[ i ] * ( j - 'a' + 1 ) ) % mod7 ) % mod7;
                    if( S[ idx ].count( tvl ) ){
                        flag = true;
                        break;
                    }
                    tvl = ( tvl + ( bs[ i ] * ( ts[ i ] - 'a' + 1 ) ) % mod7 ) % mod7;
                    tvl = ( tvl - ( bs[ i ] * ( j - 'a' + 1 ) ) % mod7 + mod7 ) % mod7;
                }
            if( flag ) break;
        }
        puts( flag ? "YES" : "NO" );
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}