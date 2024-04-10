#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
ll h , n , ans;
void build(){
    
}
void init(){
    h = (ll)getint(); scanf( "%I64d" , &n );
}
void count( ll now , ll th , ll l , ll r ){
    ll m = ( l + r ) >> 1ll;
    ans ++;
    if( l == r ) return;
    if( !now ){
        if( n > m ){
            ans += ( 1ll << ( h - th ) ) - 1ll;
            count( 0ll , th + 1ll , m + 1ll , r );
        }else count( 1ll , th + 1ll , l , m );
    }else{
        if( n > m )
            count( 0ll , th + 1ll , m + 1ll , r );
        else{
            ans += ( 1ll << ( h - th ) ) - 1ll;
            count( 1ll , th + 1ll , l , m );
        }
    }
}
void solve(){
    count( 0ll , 0ll , 1ll , ( 1ll << h ) );
    printf( "%I64d\n" , ans - 1ll );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}