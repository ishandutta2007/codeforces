#include <stdio.h>
#include <algorithm>
#define N 100010
#define inf 2000000001
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int min( int x , int y ){ return x<y?x:y; }
int max( int x , int y ){ return x>y?x:y; }
struct XD{
    int v , no;
}a[ N ];
bool cmp( XD x , XD y ){ return x.v < y.v; }
int n , h , ans , anst[ N ] , aidx;
void init(){
    n = getint(); h = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ].v = getint();
        a[ i ].no = i;
    }
    std::sort( a + 1 , a + n + 1 , cmp );
}
void solve(){
    int tmin = a[ 1 ].v + a[ 2 ].v , tmax = a[ n ].v + a[ n - 1 ].v;
    ans = tmax - tmin; aidx = n;
    for( int i = 1 ; i < n ; i ++ ){
        int ttmin = inf , ttmax = -inf;
        if( i > 1 ){
            ttmin = min( ttmin , a[ 1 ].v + a[ 2 ].v );
            ttmax = max( ttmax , a[ i ].v + a[ i - 1 ].v );
        }
        if( i < n - 1 ){
            ttmin = min( ttmin , a[ i + 1 ].v + a[ i + 2 ].v );
            ttmax = max( ttmax , a[ n ].v + a[ n - 1 ].v );
        }
        ttmin = min( ttmin , a[ 1 ].v + a[ i + 1 ].v + h );
        ttmax = max( ttmax , a[ i ].v + a[ n ].v + h );
        if( ttmax - ttmin < ans ){
            ans = ttmax - ttmin , aidx = i;
        }
    }
}
void print(){
    printf( "%d\n" , ans );
    for( int i = 1 ; i <= aidx ; i ++ )
        anst[ a[ i ].no ] = 1;
    for( int i = aidx + 1 ; i <= n ; i ++ )
        anst[ a[ i ].no ] = 2;
    for( int i = 1 ; i <= n ; i ++ )
        printf( "%d%c" , anst[ i ] , i == n ? '\n' : ' ' );
}
int main(){
    init();
    solve();
    print();
}