#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar(); 
    return x;
}
int n , m , dx , dy , y[ N ] , ans[ N ];
void init(){
    n = getint(); m = getint();
    dx = getint(); dy = getint();
    y[ 0 ] = 0;
    int nx = 0 , ny = 0;
    for( int i = 1 ; i < n ; i ++ ){
        nx = ( nx + dx ) % n;
        ny = ( ny + dy ) % n;
        y[ nx ] = ny;
    }
}
void solve(){
    int tx , ty , ap = 0 , tans = -1;
    while( m -- ){
        tx = getint(); ty = getint();
        ans[ ( ty - y[ tx ] + n ) % n ] ++;
    }
    for( int i = 0 ; i < n ; i ++ )
        if( ans[ i ] > tans )
            tans = ans[ i ] , ap = i;
    printf( "0 %d\n" , ap );
}
int main(){
    init();
    solve();
}