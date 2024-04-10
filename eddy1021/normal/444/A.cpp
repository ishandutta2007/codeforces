#include <stdio.h>
#define N 510
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int n , m;
double v[ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        v[ i ] = getint();
}
void solve(){
    ans = 0; while( m -- ){
        int a , b; double c;
        a = getint(); b = getint(); c = getint();
        if( ( v[ a ] + v[ b ] ) / c > ans )
            ans = ( v[ a ] + v[ b ] ) / c;
    }
    printf( "%.20lf\n" , ans );
}
int main(){
    init();
    solve();
}