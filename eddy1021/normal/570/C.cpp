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
#define N 300010
int n , m , st[ N << 2 ];
bool lll[ N << 2 ] , rrr[ N << 2 ];
char c[ N ];
#define L(X) (X<<1)
#define R(X) (1+(X<<1))
void build_st( int no , int l , int r ){
    if( l == r ){
        st[ no ] = 0;
        if( c[ l ] == '.' ) lll[ no ] = rrr[ no ] = true;
        else lll[ no ] = rrr[ no ] = false;
        return;
    }
    int mid = ( l + r ) >> 1;
    build_st( L( no ) , l , mid );
    build_st( R( no ) , mid + 1 , r );
    st[ no ] = st[ L( no ) ] + st[ R( no ) ] + ( rrr[ L( no ) ] && lll[ R( no ) ] ? 1 : 0 );
    lll[ no ] = lll[ L( no ) ];
    rrr[ no ] = rrr[ R( no ) ];
}
void modify( int no , int l , int r , int pos , int dlt ){
    if( l == r ){
        st[ no ] = 0;
        if( dlt ) lll[ no ] = rrr[ no ] = true;
        else lll[ no ] = rrr[ no ] = false;
        return;
    }
    int mid = ( l + r ) >> 1;
    if( pos <= mid ) modify( L( no ) , l , mid , pos , dlt );
    else modify( R( no ) , mid + 1 , r , pos , dlt );
    st[ no ] = st[ L( no ) ] + st[ R( no ) ] + ( rrr[ L( no ) ] && lll[ R( no ) ] ? 1 : 0 );
    lll[ no ] = lll[ L( no ) ];
    rrr[ no ] = rrr[ R( no ) ];
}
void build(){

}
void init(){
    n = getint(); m = getint();
    scanf( "%s" , c + 1 );
    build_st( 1 , 1 , n );
}
void solve(){
    while( m -- ){
        int x = getint();
        char ch[ 3 ];
        scanf( "%s" , ch );
        modify( 1 , 1 , n , x , ch[ 0 ] == '.' ? 1 : 0 );
        printf( "%d\n" , st[ 1 ] );
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