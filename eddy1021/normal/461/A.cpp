#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 300010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , m , a[ N ];
long long sum[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
    std::sort( a + 1 , a + n + 1 );
}
void solve(){
    for( int i = n ; i >= 1 ; i -- ){
        sum[ i ] = sum[ i + 1 ] + (long long)a[ i ];
    }
    long long ans = sum[ 1 ];
    for( int i = 1 ; i < n ; i ++ )
        ans += sum[ i ];
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}