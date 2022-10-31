// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define INF16 10000000000000000ll
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
#define N 1010
char c[ N ];
int n , k;
void init(){
    scanf( "%s" , c + 1 );
    n = strlen( c + 1 );
    k = getint();
}
bool is_palin( int l , int r ){
    while( l <= r ){
        if( c[ l ] != c[ r ] )
            return false;
        l ++; r --;
    }
    return true;
}
bool okay(){
    int p = n / k;
    for( int i = 1 ; i <= n ; i += p )
        if( !is_palin( i , i + p - 1 ) )
            return false;
    return true;
}
void solve(){
    if( n % k == 0 && okay() ) puts( "YES" );
    else puts( "NO" );
}
int main(){
    init();
    solve();
}