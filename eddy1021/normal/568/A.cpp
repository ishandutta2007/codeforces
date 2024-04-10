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
#define N 2000010
int pi[ N ] , rub[ N ];
bool p[ N + N ];
bool palin( int x ){
    vector<int> tv;
    while( x ){
        tv.PB( x % 10 );
        x /= 10;
    }
    int tn = (int)tv.size();
    for( int i = 0 ; i < tn ; i ++ )
        if( tv[ i ] != tv[ tn - i - 1 ] )
            return false;
    return true;
}
void build(){
    for( int i = 2 ; i < N ; i ++ ) if( !p[ i ] ){
        pi[ i ] = 1;
        for( int j = N / i ; j >= i ; j -- )
            p[ i * j ] = true;
    }
    for( int i = 1 ; i < N ; i ++ )
        if( palin( i ) )
            rub[ i ] = 1;
    for( int i = 1 ; i < N ; i ++ )
        pi[ i ] += pi[ i - 1 ],
        rub[ i ] += rub[ i - 1 ];
//    printf( "%d %d\b" , pi[ N - 1 ] , rub[ N - 1 ] );
}
ll tp , tq;
void init(){
    tp = getint();
    tq = getint();
}
void solve(){
    int a = 0;
    for( int i = 1 ; i < N ; i ++ )
        if( tq * (ll)pi[ i ] <= tp * (ll)rub[ i ] )
            a = i;
//    for( int i = 1 ; i < 50 ; i ++ )
//        cout << i << " " << pi[ i ] << " " << rub[ i ] << endl;
    cout << a << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}