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
#define N 1000010
int n , m , z[ N ] , len;
char c[ N ];
void Zvalue(){
    int l = 0 , r = 0;
    for( int i = 1 ; i < len ; i ++ )
        if( i > r ){
            l = r = i;
            while( r < len && c[ r-l ] == c[ r ] ) r ++;
            z[ i ] = r - l; r --;
        }else{
            int k = i - l;
            if( z[ k ] < r - i + 1 ) z[ i ] = z[ k ];
            else{
                l = i;
                while( r < len && c[ r - l ] == c[ r ] ) r ++;
                z[ i ] = r - l; r --;
            }
        }
}
void build(){

}
vector<int> v;
void init(){
    n = getint(); m = getint();
    scanf( "%s" , c );
    len = strlen( c );
    Zvalue();
    for( int i = 0 ; i < m ; i ++ )
        v.PB( getint() );
}
ll cal(){
    ll nd = 0;
    if( m == 0 ) return mypow( 26ll , (ll)n , mod7 );
    if( v[ 0 ] > 1 ) nd += v[ 0 ] - 1ll;
    int pre = v[ 0 ];
    for( int i = 1 ; i < m ; i ++ ){
        int now = v[ i ];
        if( now >= pre + len ){
            nd += now - ( pre + len );
        }else{
            int dlt = now - pre;
            int tvl = z[ dlt ];
            int tnd = len - dlt;
            if( tvl < tnd ) return 0ll;
        }
        pre = now;
    }
    pre += len - 1;
    nd += n - pre;
    return mypow( 26ll , nd , mod7 );
}
void solve(){
    printf( "%I64d\n" , cal() );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}