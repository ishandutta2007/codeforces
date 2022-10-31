#include <bits/stdc++.h>
using namespace std;
#define N 5010
#define D double
#define ll long long
#define mod 1000000007
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a , b , k , dp[ N ][ N ] , sum[ N ][ N ];
void init(){
    n = getint(); a = getint();
    b = getint(); k = getint();
}
void solve(){
    dp[ 0 ][ a ] = 1;
    for( int i = 1 ; i <= n ; i ++ )
        sum[ 0 ][ i ] = sum[ 0 ][ i - 1 ] + dp[ 0 ][ i ];
    for( int i = 1 ; i <= k ; i ++ ){
        for( int j = 1 ; j <= n ; j ++ ){
            if( j == b ) continue;
            if( j < b ){
                int dst = b - j;
                int x = ( dst - 1 ) / 2;
                int st = j + x;
                dp[ i ][ j ] = sum[ i - 1 ][ st ] - dp[ i - 1 ][ j ];
                if( dp[ i ][ j ] < 0 ) dp[ i ][ j ] += mod;
            }else{
                int dst = j - b;
                int x = ( dst - 1 ) / 2;
                int st = j - x;
                int tsum = sum[ i - 1 ][ n ] - sum[ i - 1 ][ st - 1 ];
                if( tsum < 0 ) tsum += mod;
                dp[ i ][ j ] = tsum - dp[ i - 1 ][ j ];
                if( dp[ i ][ j ] < 0 ) dp[ i ][ j ] += mod;
            }
        }
        for( int j = 1 ; j <= n ; j ++ ){
            sum[ i ][ j ] = sum[ i ][ j - 1 ] + dp[ i ][ j ];
            sum[ i ][ j ] %= mod;
        }
    }
    printf( "%d\n" , sum[ k ][ n ] );    
}
int main(){
    init();
    solve();
}