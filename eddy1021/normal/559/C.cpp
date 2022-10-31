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
#define N 200010
ll lvl[ N ] , inv[ N ];
void build(){
    lvl[ 0 ] = 1;
    for( ll i = 1 ; i < N ; i ++ )
        lvl[ i ] = ( lvl[ i - 1 ] * i ) % mod7; 
    inv[ 0 ] = 1ll;
    for( ll i = 1 ; i < N ; i ++ )
        inv[ i ] = mypow( lvl[ i ] , mod7 - 2 , mod7 );
}
ll C( ll a , ll b ){
    return ( lvl[ a ] * ( ( inv[ b ] * inv[ a - b ] ) % mod7 ) ) % mod7;
}
ll h , w , n;
vector< pair<ll,ll> > v;
void init(){
    h = getint(); w = getint(); n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        ll r = getint();
        ll c = getint();
        v.PB( MP( r , c ) );
    }
    sort( v.begin() , v.end() );
}
ll dp[ N ][ 2 ];
// 1 + 0 -
void solve(){
    ll ans = C( h + w - 2 , h - 1 );
//    cout << ans << endl;
    for( int i = 0 ; i < n ; i ++ ){
        ll tr = v[ i ].FI;
        ll tc = v[ i ].SE;
        dp[ i ][ 1 ] = C( tr + tc - 2 , tr - 1 );
        for( int j = 0 ; j < i ; j ++ )
            if( v[ j ].SE <= v[ i ].SE ){
                ll dltr = v[ i ].FI - v[ j ].FI;
                ll dltc = v[ i ].SE - v[ j ].SE;
                ll dlt = C( dltr + dltc , dltc );
                for( int k = 0 ; k < 2 ; k ++ ){
                    ll tmp = ( dlt * dp[ j ][ k ] ) % mod7;
                    dp[ i ][ 1 - k ] = ( dp[ i ][ 1 - k ] + tmp ) % mod7;
                }
            }
        ll tmp2 = C( h - tr + w - tc , h - tr );
        ans = ( ans - ( dp[ i ][ 1 ] * tmp2 ) % mod7 + mod7 ) % mod7;
        ans = ( ans + ( dp[ i ][ 0 ] * tmp2 ) % mod7 ) % mod7;
//        cout << dp[ i ][ 1 ] << " " << dp[ i ][ 0 ] << endl;
//        cout << ans << endl;
    }
    cout << ans << endl;
}
int main(){
    build();
    //__ = getint();
    while( __ -- ){
        init();
        solve();
    }  
}