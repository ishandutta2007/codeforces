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
#define N 131073
#define M 6
int n , m , k , a[ N ][ M ];
int st[ M ][ N << 1 ];
#define L(x) (x<<1)
#define R(x) (1+(x<<1))
void build(){

}
void build_st( int no , int l , int r ){
    if( l == r ){
        for( int j = 1 ; j <= m ; j ++ )
            st[ j ][ no ] = a[ l ][ j ];
        return;
    }
    int mid = ( l + r ) >> 1;
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
    for( int j = 1 ; j <= m ; j ++ )
        st[ j ][ no ] = max( st[ j ][ L( no ) ] , st[ j ][ R( no ) ] );
}
int query_max( int idx , int no , int l , int r , int ql , int qr ){
    if( l == ql && r == qr ) return st[ idx ][ no ];
    int mid = ( l + r ) >> 1;
    if( qr <= mid ) return query_max( idx , L( no ) , l , mid , ql , qr );
    if( mid < ql ) return query_max( idx , R( no ) , mid + 1 , r , ql , qr );
    return max( query_max( idx , L( no ) , l , mid , ql , mid ) ,
                query_max( idx , R( no ) , mid + 1 , r , mid + 1 , qr ) );
}
ll query_sum( int ql , int qr ){
    if( ql > qr ) return 0ll;
    ll tsum = 0;
    for( int j = 1 ; j <= m ; j ++ )
        tsum += (ll)query_max( j , 1 , 1 , n , ql , qr );
    return tsum;
}
void init(){
    n = getint(); m = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            a[ i ][ j ] = getint();
    build_st( 1 , 1 , n );
}
int ansl , ans[ M ];
void update_ans( int ql , int qr ){
    if( qr - ql + 1 <= ansl ) return;
    ansl = qr - ql + 1;
    for( int j = 1 ; j <= m ; j ++ )
        ans[ j ] = query_max( j , 1 , 1 , n , ql , qr );
}
void solve(){
    int ptrl = 1;
    for( int i = 1 ; i <= n ; i ++ ){
        while( ptrl <= i && query_sum( ptrl , i ) > (ll)k ) ptrl ++;
        if( ptrl <= i ) update_ans( ptrl , i );
    }
    for( int j = 1 ; j <= m ; j ++ )
        printf( "%d " , ans[ j ] );
    puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}