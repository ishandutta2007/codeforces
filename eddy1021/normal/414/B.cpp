#include <vector>
#include <stdio.h>
using namespace std;
#define N 2010
#define mod 1000000007
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , k , dp[ 2 ][ N ];
vector<int> V[ N ];
void init(){
    n = getint(); k = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= i ; j ++ )
            if( !( i % j ) )
                V[ i ].push_back( j );
}
void process(){
    for( int i = 1 ; i <= n ; i ++ )
        dp[ 1 ][ i ] = 1;
    for( int i = 2 ; i <= k ; i ++ )
        for( int j = 1 ; j <= n ; j ++ ){
            dp[ i & 1 ][ j ] = 0;
            for( int k = V[ j ].size() - 1 ; k >= 0 ; k -- )
                dp[ i & 1 ][ j ] = ( dp[ i & 1 ][ j ] +
                            dp[ ( i + 1 ) & 1 ][ V[ j ][ k ] ] ) % mod;
        }
    int ans = 0;
    for( int i = 1 ; i <= n ; i ++ )
        ans = ( ans + dp[ k & 1 ][ i ] ) % mod;
    printf( "%d\n" , ans );
}
int main(){
    init();
    process();
}