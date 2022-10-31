// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
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
#define P 1000010
bool p[ P ];
vector<int> pset;
void build(){
    p[ 0 ] = p[ 1 ] = true;
    for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
        pset.PB( i );
        for( int j = P / i ; j >= i ; j -- )
            p[ i * j ] = true;
    }
}
bool is_prime( ll tmp ){
    if( tmp < P ) return !p[ tmp ];
    ll bdr = (ll)sqrt( tmp );
    for( int i = 0 ; i < (int)pset.size() && pset[ i ] <= bdr ; i ++ )
        if( tmp % pset[ i ] == 0 )
            return false;
    return true;
}
ll a;
vector< pair<ll,int> > fac;
vector<ll> divs;
vector<ll> posp;
vector<ll> pospp[ 9999 ];
int p_no( ll tmp ){
    return lower_bound( posp.begin() , posp.end() , tmp ) - posp.begin();
}
void factor( ll tmp ){
    for( int i = 0 ; i < (int)pset.size() && tmp > 1 ; i ++ )
        if( tmp % pset[ i ] == 0 ){
            int cnt = 0;
            while( tmp % pset[ i ] == 0 ){
                cnt ++;
                tmp /= pset[ i ];
            }
            fac.PB( MP( pset[ i ] , cnt ) );
        }
    if( tmp > 1 ) fac.PB( MP( tmp , 1 ) );
}
void DFS( int now , ll pt ){
    if( now == (int)fac.size() ){
        divs.PB( pt );
        return;
    }
    ll tmp = 1;
    for( int i = 0 ; i <= fac[ now ].SE ; i ++ ){
        DFS( now + 1,  pt * tmp );
        tmp *= fac[ now ].FI;
    }
}
void init(){
    a = getint();
    factor( a );
    DFS( 0 , 1 );
    sort( divs.begin() , divs.end() );
}
void Insert( ll now ){
    if( now <= 1 ) return;
    if( is_prime( now ) ) posp.PB( now );
    else{
        ll bdr = (ll)sqrt( now ) , tmp = now;
        for( int i = 0 ; i < (int)pset.size() && pset[ i ] <= bdr ; i ++ )
            if( tmp % pset[ i ] == 0 ){
                while( tmp % pset[ i ] == 0 )
                    tmp /= pset[ i ];
                if( tmp == 1 ) posp.PB( pset[ i ] );
                return;
            }
        posp.PB( now );
        assert( 1 == 0 );
    }
}
void Insert2( ll now ){
    if( now <= 1 ) return;
    if( is_prime( now ) ) pospp[ p_no( now ) ].PB( now + 1 );
    else{
        ll bdr = (ll)sqrt( now ) , tmp = now;
        for( int i = 0 ; i < (int)pset.size() && pset[ i ] <= bdr ; i ++ )
            if( tmp % pset[ i ] == 0 ){
                while( tmp % pset[ i ] == 0 )
                    tmp /= pset[ i ];
                if( tmp == 1 ) pospp[ p_no( pset[ i ] ) ].PB( now + 1 );
                return;
            }
        pospp[ p_no( now ) ].PB( now + 1 );
        assert( 1 == 0 );
    }
}
void pre_solve(){
    for( int i = 0 ; i < (int)divs.size() ; i ++ )
        Insert( divs[ i ] - 1 );
    sort( posp.begin() , posp.end() );
    posp.resize( unique( posp.begin() , posp.end() ) - posp.begin() );
    for( int i = 0 ; i < (int)divs.size() ; i ++ )
        Insert2( divs[ i ] - 1 );
/*    for( int i = 0 ; i < (int)divs.size() ; i ++ )
        cout << divs[ i ] << " "; puts( "" );
    for( int i = 0 ; i < (int)posp.size() ; i ++ ){
        printf( "%I64d\n   " , posp[ i ] );
        for( int j = 0 ; j < (int)pospp[ i ].size() ; j ++ )
            printf( "%I64d " , pospp[ i ][ j ] ); puts( "" );
    }*/
}
ll dp[ 2 ][ 9999 ];
void solve(){
    pre_solve();
    dp[ 1 ][ 0 ] = 1;
    for( int i = 0 ; i < (int)posp.size() ; i ++ ){
        int now = i & 1 , pre = 1 - now;
        for( int j = 0 ; j < (int)divs.size() ; j ++ ) dp[ now ][ j ] = dp[ pre ][ j ];
        for( int j = 0 ; j < (int)pospp[ i ].size() ; j ++ )
            for( int k = 0 ; k < (int)divs.size() ; k ++ )
                if( ( a / divs[ k ] ) % pospp[ i ][ j ] == 0 ){
                    ll nxt = divs[ k ] * pospp[ i ][ j ];
                    ll no = lower_bound( divs.begin() , divs.end() , nxt ) - divs.begin();
                    dp[ now ][ no ] += dp[ pre ][ k ];
                }
//        printf( "%I64d\n" , posp[ i ] );
//        for( int j = 0 ; j < (int)divs.size() ; j ++ )
//            cout << dp[ now ][ j ] << " "; puts( "" );
    }
    ll now = ( (int)posp.size() - 1 ) & 1;
    cout << dp[ now ][ (int)divs.size() - 1 ] << endl;
}
int main(){
    build();  
    //  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}