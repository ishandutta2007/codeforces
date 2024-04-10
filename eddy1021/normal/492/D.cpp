#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar(); 
    return x;
}
ll a , n , x , y , tlcm , nx , ny;
void init(){
    n = getint(); x = getint(); y = getint();
    tlcm = ( x / __gcd( x , y ) ) * y;
    nx = tlcm / x; ny = tlcm / y;    
}
void test(){
//    printf( "%I64d\n" , a );
    ll l = 1ll , m , r = tlcm , ta = -1ll;
    while( l <= r ){
        m = ( l + r ) / 2ll;
        ll th = ( m / nx ) + ( m / ny );
        if( th >= a ) ta = m , r = m - 1;
        else l = m + 1;
    }
//    printf( "%I64d\n" , ta );
    ll tb = tlcm / __gcd( tlcm , ta );
//    printf( "%I64d\n" , tb );
    if( x % tb == 0 && y % tb == 0 ) puts( "Both" );
    else if( x % tb == 0 ) puts( "Vanya" );
    else puts( "Vova" );
}
void solve(){
    while( n -- ){
        a = getint() % ( x + y );
        if( a == 0 ) puts( "Both" );
        else test();
    }
}
int main(){
    init();
    solve();
}