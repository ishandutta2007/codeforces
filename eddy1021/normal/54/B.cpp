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
#define N 22
int n , m;
char c[ N ][ N ];
int ans , aa , an , am;
void build(){

}
void init(){
    an = n = getint(); am = m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
    aa = n * m;
}
#define BS 13131
ll take_value( int sn , int tn , int sm , int tm ){
    ll vl = 0;
    for( int i = sn ; i <= tn ; i ++ )
        for( int j = sm ; j <= tm ; j ++ ){
            vl = ( vl * BS ) % mod7;
            vl = ( vl + c[ i ][ j ] ) % mod7;
        }
    return vl;
}
ll take_value2( int sn , int tn , int sm , int tm ){
    ll vl = 0;
    for( int j = sm ; j <= tm ; j ++ )
        for( int i = tn ; i >= sn ; i -- ){
            vl = ( vl * BS ) % mod7;
            vl = ( vl + c[ i ][ j ] ) % mod7;
        }
    return vl;
}
ll take_value3( int sn , int tn , int sm , int tm ){
    ll vl = 0;
    for( int i = tn ; i >= sn ; i -- )
        for( int j = tm ; j >= sm ; j -- ){
            vl = ( vl * BS ) % mod7;
            vl = ( vl + c[ i ][ j ] ) % mod7;
        }
    return vl;
}
ll take_value4( int sn , int tn , int sm , int tm ){
    ll vl = 0;
    for( int j = tm ; j >= sm ; j -- )
        for( int i = sn ; i <= tn ; i ++ ){
            vl = ( vl * BS ) % mod7;
            vl = ( vl + c[ i ][ j ] ) % mod7;
        }
    return vl;
}
void test( int ti , int tj ){
//    printf( "%d %d\n" , ti , tj );
    set<ll> s1 , s2;
    for( int i = 1 ; i <= n ; i += ti )
        for( int j = 1 ; j <= m ; j += tj ){
//            printf( "%d %d\n" , i , j );
            ll vl1 = take_value( i , i + ti - 1 , j , j + tj - 1 );
//            printf( "%d %d\n" , i , j );
            ll vl2 = take_value2( i , i + ti - 1 , j , j + tj - 1 );
            ll vl3 = take_value3( i , i + ti - 1 , j , j + tj - 1 );
            ll vl4 = take_value4( i , i + ti - 1 , j , j + tj - 1 );
//            printf( "%d %d\n" , i , j );
            if( s1.count( vl1 ) > 0 || s1.count( vl3 ) > 0 ) return;
            if( s2.count( vl2 ) > 0 || s2.count( vl4 ) > 0 ) return;
//            printf( "%d %d\n" , i , j );
            s1.insert( vl1 );
            s1.insert( vl3 );
            s2.insert( vl2 );
            s2.insert( vl4 );
            if( ti == tj ){
                s1.insert( vl2 );
                s1.insert( vl4 );
                s2.insert( vl1 );
                s2.insert( vl3 );
            }
        }
    ans ++;
    if( ti * tj < aa || ( ti * tj == aa && ti < an ) ){
        aa = ti * tj;
        an = ti;
        am = tj;
    }
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ) if( ( n % i ) == 0 )
        for( int j = 1; j  <= m ; j ++ ) if( ( m % j ) == 0 )
            test( i , j );
    printf( "%d\n%d %d\n" , ans , an , am );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}