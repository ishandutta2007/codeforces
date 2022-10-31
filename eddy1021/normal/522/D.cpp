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
#define N 500010
#define NN 1048577
int n , m , a[ N ] , idx[ N ] , ans[ N ];
vector<int> v;
void build(){

}
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
int st[ NN ];
void build_st( int no , int l , int r ){
    st[ no ] = NN;
    if( l == r ) return;
    int mid = ( l + r ) >> 1;
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
    st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
void insert( int no , int l , int r , int pos , int dlt ){
    if( l == r ){
        st[ no ] = min( st[ no ] , dlt );
        return;
    }
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) insert( L( no ) , l , mid , pos , dlt );
    else insert( R( no ) , mid + 1 , r , pos , dlt );
    st[ no ] = min( st[ L( no ) ] , st[ R( no ) ] );
}
int query( int no , int l , int r , int ql , int qr ){
    if( l == ql && r == qr ) return st[ no ];
    int mid = ( l + r ) >> 1;
    if( qr <= mid ) return query( L( no ) , l , mid , ql , qr );
    if( mid < ql ) return query( R( no ) , mid + 1 , r , ql , qr );
    return min( query( L( no ) , l , mid , ql , mid ) ,
                query( R( no ) , mid + 1 , r , mid + 1 , qr ) );
}
vector< pair<PII,int> > Q;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        v.PB( a[ i ] );
    }
    sort( v.begin() , v.end() );
    v.resize( unique( v.begin() , v.end() ) - v.begin() );
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = lower_bound( v.begin() , v.end() , a[ i ] ) - v.begin();
    for( int i = 0 ; i < m ; i ++ ){
        int ql , qr;
        ql = getint(); qr = getint();
        Q.PB( MP( MP( qr , ql ) , i ) );
    }
    sort( Q.begin() , Q.end() );
}
void solve(){
    int nr = 0;
    build_st( 1 , 1 , n );
    for( int i = 0 ; i < m ; i ++ ){
        while( nr < Q[ i ].FI.FI ){
            ++ nr;
            if( idx[ a[ nr ] ] )
                insert( 1 , 1 , n , idx[ a[ nr ] ] , nr - idx[ a[ nr ] ] );
            idx[ a[ nr ] ] = nr;
        }
        int tans = query( 1 , 1 , n , Q[ i ].FI.SE , Q[ i ].FI.FI );
        if( tans == NN ) ans[ Q[ i ].SE ] = -1;
        else ans[ Q[ i ].SE ] = tans;
    }
    for( int i = 0 ; i < m ; i ++ )
        printf( "%d\n" , ans[ i ] );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}