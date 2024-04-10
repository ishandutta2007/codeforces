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
#define N 262145
#define INFLL 100000000000000000ll
int n , m , h[ N ];
ll d[ N ] , dd[ N ];
ll stmin[ N << 1 ] , stmax[ N << 1 ];
ll ans[ N << 1 ];
void build(){

}
#define L(x) (x<<1)
#define R(x) (1+(x<<1))
void build_st( int no , int l , int r ){
    if( l == r ){
        stmin[ no ] = -2ll * (ll)h[ l ] + d[ l ];
        stmax[ no ] = 2ll * (ll)h[ l ] + d[ l ];
        ans[ no ] = -INFLL;
        return;
    }
    int mid = ( l + r ) >> 1;
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
    stmin[ no ] = min( stmin[ L( no ) ] , stmin[ R( no ) ] );
    stmax[ no ] = max( stmax[ L( no ) ] , stmax[ R( no ) ] );
    ans[ no ] = max( ans[ L( no ) ] , ans[ R( no ) ] );
    ans[ no ] = max( ans[ no ] ,
            stmax[ R( no ) ] - stmin[ L( no ) ] );
}
pair< ll,pair<ll,ll> > query( int no , int l , int r , int ql , int qr ){
    if( l == ql && r == qr ) return MP( ans[ no ] ,
                                    MP( stmin[ no ] , stmax[ no ] ) );
    int mid = ( l + r ) >> 1;
    if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
    if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
    pair< ll , pair<ll,ll> > tp1 = query( L( no ) , l , mid , ql , mid );
    pair< ll , pair<ll,ll> > tp2 = query( R( no ) , mid + 1 , r , mid + 1 , qr );
    ll tans = max( tp1.FI , tp2.FI );
    tans = max( tans , tp2.SE.SE - tp1.SE.FI );
    ll tmin = min( tp1.SE.FI , tp2.SE.FI );
    ll tmax = max( tp1.SE.SE , tp2.SE.SE );
    return MP( tans , MP( tmin , tmax ) );
}
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        dd[ n + i ] = dd[ i ] = getint();
    for( int i = 1 ; i <= n ; i ++ )
        h[ n + i ] = h[ i ] = getint();
    n <<= 1;
    d[ 1 ] = 0;
    for( int i = 2 ; i <= n ; i ++ )
        d[ i ] = d[ i - 1 ] + dd[ i - 1 ];
//    for( int i = 1 ; i <= n ; i ++ )
//        printf( "%lld %d\n" , d[ i ] , h[ i ] );
    build_st( 1 , 1 , n );
}
void solve(){
    while( m -- ){
        int ql , qr , nql , nqr;
        ql = getint(); qr = getint();
        if( ql <= qr ){
            nql = qr + 1;
            nqr = ql + n / 2 - 1;
        }else{
            nql = qr + 1;
            nqr = ql - 1;
        }
        //printf( " => %d %d\n" , nql , nqr );
        pair< ll , pair<ll,ll> > pans = query( 1 , 1 , n , nql , nqr );
        printf( "%I64d\n" , pans.FI );
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