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
#define ALL(x) (x).begin(), (x).end()
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
#define K 5010
int n , k , a[ N ];
ll dp[ K ][ K ];
bool got[ K ][ K ];
int a1 , a2 , n1 , n2;
void build(){

}
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
    sort( a + 1 , a + n + 1 );
    a1 = n / k + ( n % k != 0 );
    a2 = n / k;
    n1 = n % k;
    n2 = k - n % k;
}
ll DP( int tk , int tk1 , int tn ){
    if( tk == 0 ) return 0;
    if( got[ tk ][ tk1 ] ) return dp[ tk ][ tk1 ];
    got[ tk ][ tk1 ] = true;
    ll tans = 2147483647;
    if( tk1 != 0 )
        tans = min( tans , a[ tn ] - a[ tn - a1 + 1 ] + DP( tk - 1 , tk1 - 1 , tn - a1 ) );
    if( tk > tk1 )
        tans = min( tans , a[ tn ] - a[ tn - a2 + 1 ] + DP( tk - 1 , tk1 , tn - a2 ) );
    return dp[ tk ][ tk1 ] = tans;
}
void solve(){
    cout << DP( k , n1 , n ) << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}