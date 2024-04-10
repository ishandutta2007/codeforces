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
#define N 100010
#define NN 131073
int st[ NN << 1 ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void init_st( int no , int l , int r ){
    st[ no ] = 0;
    if( l == r ) return;
    int mid = ( l + r ) >> 1;
    init_st( L( no ) , l , mid );
    init_st( R( no ) , mid + 1 , r );
}
void modify( int no , int l , int r , int pos , int dlt ){
    if( l == r ){
        st[ no ] = dlt;
        return;
    }
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) modify( L( no ) , l , mid , pos , dlt );
    else modify( R( no ) , mid + 1 , r , pos , dlt );
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
int n , m , k , q , ans[ N << 1 ];
vector<int> c[ N ] , r[ N ];
vector< pair<pair<PII,PII>,int> > rec1 , rec2;
#define A FI.FI.FI
#define B FI.FI.SE
#define C FI.SE.FI
#define D FI.SE.SE
#define ID SE
void build(){

}
void init(){
    n = getint(); m = getint(); k = getint(); q = getint();
    while( k -- ){
        int tmpn , tmpm;
        tmpn = getint();
        tmpm = getint();
        c[ tmpm ].PB( tmpn );
        r[ tmpn ].PB( tmpm );
    }
    for( int i = 1 ; i <= q ; i ++ ){
        int x , y , x2 , y2;
        x = getint(); y = getint();
        x2 = getint(); y2 = getint();
        rec1.PB( MP( MP( MP( y2 , x2 ) , MP( y , x ) ) , i ) );
        rec2.PB( MP( MP( MP( x2 , y2 ) , MP( x , y ) ) , i ) );
    }
    sort( rec1.begin() , rec1.end() );
    sort( rec2.begin() , rec2.end() );
}
void solve1(){
    int now = 0;
    for( int i = 0 ; i < q ; i ++ ){
        while( now < rec1[ i ].A ){
            now ++;
            for( int j = 0 ; j < (int)c[ now ].size() ; j ++ )
                modify( 1 , 1 , n , c[ now ][ j ] , now );
        }
        int mnt = query( 1 , 1 , n , rec1[ i ].D , rec1[ i ].B );
        if( mnt >= rec1[ i ].C ) ans[ rec1[ i ].ID ] ++;
    }
}
void solve2(){
    int now = 0;
    init_st( 1 , 1 , m );
    for( int i = 0 ; i < q ; i ++ ){
        while( now < rec2[ i ].A ){
            now ++;
            for( int j = 0 ; j < (int)r[ now ].size() ; j ++ )
                modify( 1 , 1 , m , r[ now ][ j ] , now );
        }
        int mnt = query( 1 , 1 , m , rec2[ i ].D , rec2[ i ].B );
        if( mnt >= rec2[ i ].C ) ans[ rec2[ i ].ID ] ++;
    }
}
void solve(){
    solve1();
    solve2();
    for( int i = 1 ; i <= q ; i ++ )
        puts( ans[ i ] >= 1 ? "YES" : "NO" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}