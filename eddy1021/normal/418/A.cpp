#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , k;
void init(){
    n = getint(); k = getint();
}
void solve(){
    int sum = n * ( n - 1 ) / 2;
    if( k > sum / n ){
        puts( "-1" );
        return ;
    }
    printf( "%d\n" , n * k );
    for( int i = 0 ; i < n ; i ++ )
        for( int j = 1 ; j <= k ; j ++ )
            printf( "%d %d\n" , i + 1 , ( i + j ) % n + 1 );
}
int main(){
    init();
    solve();
}