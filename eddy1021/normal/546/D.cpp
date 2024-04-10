// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define LLINF 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
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
#define N 5000001
#define P 2310
int dp[ N ];
bool p[ P ];
vector<int> pset;
int cal( int tmp ){
    int bdr = sqrt( tmp ) , cnt = 0;
    for( int i = 0 ; i < (int)pset.size() && pset[ i ] <= bdr ; i ++ )
        if( !( tmp % pset[ i ] ) ){
            while( !( tmp % pset[ i ] ) ){
                tmp /= pset[ i ];
                cnt ++;
            }
            bdr = sqrt( tmp );
        }
    if( tmp > 1 ) cnt ++;
    return cnt;
}
void build(){
    for( int i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
        pset.PB( i );
        for( int j = P / i ; j >= i ; j -- )
            p[ i * j ] = true;
    }
    for( int i = 2 ; i < N ; i ++ )
        dp[ i ] = dp[ i - 1 ] + cal( i );
}
int a , b;
void init(){
    a = getint(); b = getint();
}
void solve(){
    printf( "%d\n" , dp[ a ] - dp[ b ] );
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}