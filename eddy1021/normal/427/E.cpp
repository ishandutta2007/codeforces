#include <vector>
#include <stdio.h>
using namespace std;
#define N 1000010
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll n , m , a[ N ] , ans = -1;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void test( ll md ){
    ll tans = 0;
    for( int i = 1 ; i < md ; i += m )
        tans += ( a[ md ] - a[ i ] ) * 2;
    for( int i = n ; i > md ; i -= m )
        tans += ( a[ i ] - a[ md ] ) * 2;
    if( ans == -1 || tans < ans )
        ans = tans;
}
void solve(){
    test( n / 2 + 1 );
    if( !( n & 1 ) ) test( n / 2 );
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}