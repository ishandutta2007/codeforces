#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
#define N 310
#define mod9 1000000009
#define mod7 1000000007
#define INF 1023456789
TYPE getint(){
    TYPE x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int p[ N ];
int find_p( int x ){
    return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
    x = find_p( x ); y = find_p( y );
    p[ x ] = y;
}
TYPE t = 1 , n , m , a[ N ];
char c[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        p[ i ] = i;
    }
    for( int i = 1 ; i <= n ; i ++ ){
        scanf( "%s" , c + 1 );
        for( int j = 1 ; j <= n ; j ++ )
            if( c[ j ] == '1' )
                Union( i , j );
    }
}
void solve(){
    for( int i = 1 ; i < n ; i ++ ){
        int idx = i;
        for( int j = i + 1 ; j <= n ; j ++ )
            if( find_p( i ) == find_p( j ) && a[ j ] < a[ idx ] )
                idx = j;
        swap( a[ idx ] , a[ i ] );
    }
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%d " , a[ i ] );
}
int main(){
//    t = getint();
    while( t -- ){
        init();
        solve();
    }
}