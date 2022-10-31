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
#define N 500010
vector<int> v[ N ];
vector<int> v2[ N ];
vector<PII> q[ N ];
int n , m , p[ N ] , d[ N ] , in[ N ] , out[ N ] , maxd;
int st[ N << 2 ];
char c[ N ];
bool ans[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void modify( int no , int l , int r , int pos , int num ){
    if( l == r ){
        st[ no ] ^= num;
        return;
    }
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) modify( L( no ) , l , mid , pos , num );
    else modify( R( no ) , mid + 1 , r , pos , num );
    st[ no ] = st[ L( no ) ] ^ st[ R( no ) ];
}
int query( int no , int l , int r , int ql , int qr ){
    if( l == ql && r == qr ) return st[ no ];
    int mid = ( l + r ) >> 1;
    if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
    if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
    return query( L( no ) , l , mid , ql , mid ) ^
            query( R( no ) , mid + 1 , r , mid + 1 , qr );
}
void build(){

}
int dcnt;
void DFS( int now , int td ){
    d[ now ] = td;
    v2[ td ].PB( now );
    maxd = max( maxd , td );
    in[ now ] = ++ dcnt;
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        DFS( v[ now ][ i ] , td + 1 );
    out[ now ] = dcnt;
}
void init(){
    n = getint(); m = getint();
    for( int i = 2 ; i <= n ; i ++ ){
        p[ i ] = getint();
        v[ p[ i ] ].PB( i );
    }
    scanf( "%s" , c + 1 );
    DFS( 1 , 1 );
    for( int i = 0 ; i < m ; i ++ ){
        int vi = getint();
        int hi = getint();
        q[ hi ].PB( MP( vi , i ) );
    }
}
void solve(){
    for( int nd = maxd ; nd >= 1 ; nd -- ){
//        printf( "%d :\n" , nd );
        for( int i = 0 ; i < (int)v2[ nd ].size() ; i ++ ){
            modify( 1 , 1 , n , in[ v2[ nd ][ i ] ] , ( 1 << ( c[ v2[ nd ][ i ] ] - 'a' ) ) );
//            printf( "%d %d %d\n" , v2[ nd ][ i ] , in[ v2[ nd ][ i ] ] , ( 1 << ( c[ v2[ nd ][ i ] ] - 'a' ) )  );
        }
        for( int i = 0 ; i < (int)q[ nd ].size() ; i ++ ){
            int tans = query( 1 , 1 , n , in[ q[ nd ][ i ].FI ] , out[ q[ nd ][ i ].FI ] );
//            printf( "%d %d (%d,%d) %d\n" , q[ nd ][ i ].FI , q[ nd ][ i ].SE ,
//                                           in[ q[ nd ][ i ].FI ] , out[ q[ nd ][ i ].FI ] , tans );
            if( tans == 0 || ( tans == ( tans & ( -tans ) ) ) ) ans[ q[ nd ][ i ].SE ] = false;
            else ans[ q[ nd ][ i ].SE ] = true;
        }
        for( int i = 0 ; i < (int)v2[ nd ].size() ; i ++ )
            modify( 1 , 1 , n , in[ v2[ nd ][ i ] ] , ( 1 << ( c[ v2[ nd ][ i ] ] - 'a' ) ) );
    }
    for( int i = 0 ; i < m ; i ++ )
        puts( ans[ i ] ? "No" : "Yes" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}