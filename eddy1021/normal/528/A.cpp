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
#define N 200010
int w , h , n;
multiset<int> Sh , Sw;
set<int> H , W;
typedef set<int>::iterator si;
void build(){

}
void init(){
    w = getint(); h = getint();
    n = getint();
    Sh.insert( h );
    Sw.insert( w );
    H.insert( 0 );
    H.insert( h );
    W.insert( 0 );
    W.insert( w );
}
void modify_h( int dlt ){
    H.insert( dlt );
    si it = H.find( dlt );
    int l , r;
    --it; l = *it;
    ++it; ++it; r = *it;
    Sh.erase( Sh.find( r - l ) );
    Sh.insert( r - dlt );
    Sh.insert( dlt - l );
//    printf( "%d %d\n" , l , r );
}
void modify_w( int dlt ){
    W.insert( dlt );
    si it = W.find( dlt );
    int l , r;
    --it; l = *it;
    ++it; ++it; r = *it;
    Sw.erase( Sw.find( r - l ) );
    Sw.insert( r - dlt );
    Sw.insert( dlt - l );
//    printf( "%d %d\n" , l , r );
}
ll ans(){
    ll tmp = (ll)(*--Sh.end());
    tmp *= (ll)(*--Sw.end());
    return tmp;
}
void solve(){
    while( n -- ){
        char c[ 2 ]; int k;
        scanf( "%s" , c ); k = getint();
        if( c[ 0 ] == 'H' ) modify_h( k );
        else if( c[ 0 ] == 'V' ) modify_w( k );
        printf( "%I64d\n" , ans() );
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