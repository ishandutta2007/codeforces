#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
vector<int> v[ N ] , tans;
int n , ans , s[ N ] , t[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i < n ; i ++ ){
        int a , b;
        a = getint(); b = getint();
        v[ a ].push_back( b );
        v[ b ].push_back( a );
    }
    for( int i = 1 ; i <= n ; i ++ )
        s[ i ] = getint();
    for( int i = 1 ; i <= n ; i ++ )
        t[ i ] = getint();
}
void DFS( int now , int tn , int x1 , int x2 , int p ){
    if( now & 1 ){
        if( s[ tn ] ^ x1 != t[ tn ] ){
            x1 ^= 1 , ans ++;
            tans.push_back( tn );
        }
    }else{
        if( s[ tn ] ^ x2 != t[ tn ] ){
            x2 ^= 1 , ans ++;
            tans.push_back( tn );
        }
    }
    for( int i = v[ tn ].size() - 1 ; i >= 0 ; i -- )
        if( v[ tn ][ i ] != p )
            DFS( 1 - now , v[ tn ][ i ] , x1 , x2 , tn );
}
void solve(){
    DFS( 1 , 1 , 0 , 0 , -1 );
    printf( "%d\n" , ans );
    for( int i = 0 ; i < tans.size() ; i ++ )
        printf( "%d\n" , tans[ i ] );
}
int main(){
    init();
    solve();
}