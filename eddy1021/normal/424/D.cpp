#include <map>
#include <set>
#include <stdio.h>
using namespace std;
#define N 310
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int abs( int x ){ return x<0?-x:x; }
int n , m , t , c[ 3 ] , x[ N ][ N ];
int l[ N ][ N ] , r[ N ][ N ] , u[ N ][ N ] , d[ N ][ N ];
int step( int from , int to ){
    if( from == to ) return c[ 0 ];
    if( from < to ) return c[ 1 ];
    return c[ 2 ];
}
void init(){
    n = getint(); m = getint(); t = getint();
    for( int i = 0 ; i < 3 ; i ++ )
        c[ i ] = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            x[ i ][ j ] = getint();
}
void build(){
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 2 ; j <= m ; j ++ )
            l[ i ][ j ] = l[ i ][ j - 1 ] + step( x[ i ][ j - 1 ] , x[ i ][ j ] );
        for( int j = m - 1 ; j >= 1 ; j -- )
            r[ i ][ j ] = r[ i ][ j + 1 ] + step( x[ i ][ j + 1 ] , x[ i ][ j ] );
    }
    for( int j = 1 ; j <= m ; j ++ ){
        for( int i = 2 ; i <= n ; i ++ )
            u[ i ][ j ] = u[ i - 1 ][ j ] + step( x[ i - 1 ][ j ] , x[ i ][ j ] );
        for( int i = n - 1 ; i >= 1 ; i -- )
            d[ i ][ j ] = d[ i + 1 ][ j ] + step( x[ i + 1 ][ j ] , x[ i ][ j ] );
    }
}
int value( int n1 , int n2 , int m1 ){
    return d[ n1 ][ m1 ] - d[ n2 ][ m1 ] - l[ n1 ][ m1 ] - ( r[ n2 ][ 1 ] - r[ n2 ][ m1 ] );
}
int value2( int n1 , int n2 , int m1 ){
    return l[ n1 ][ m1 ] + u[ n2 ][ m1 ] - u[ n1 ][ m1 ] + r[ n2 ][ 1 ] - r[ n2 ][ m1 ];
}
typedef set<int>::iterator si;
int ans = (int)1e9 , xn , xm , yn , ym;
void test( int tcst , int txn , int txm , int tyn , int tym ){
    if( abs( tcst ) < ans ){
        ans = abs( tcst );
        xn = txn; xm = txm;
        yn = tyn; ym = tym;
    }
}
void solve(){
    for( int i1 = 1 ; i1 <= n ; i1 ++ )
        for( int i2 = i1 + 2 ; i2 <= n ; i2 ++ ){
            set<int> S; map<int,int> M;
            for( int k = 3 ; k <= m ; k ++ ){
                S.insert( value( i1 , i2 , k - 2 ) );
                M[ value( i1 , i2 , k - 2 ) ] = k - 2;
                int tnow = value2( i1 , i2 , k );
                si it = S.lower_bound( t - tnow );
                if( it == S.begin() )
                    test( (*it) + tnow - t , i1 , M[ *it ] , i2 , k );
                else if( it == S.end() ){
                    it --;
                    test( (*it) + tnow - t , i1 , M[ *it ] , i2 , k );
                }else{
                    test( (*it) + tnow - t , i1 , M[ *it ] , i2 , k );
                    it --;
                    test( (*it) + tnow - t , i1 , M[ *it ] , i2 , k );
                }
            }
        }
    printf( "%d %d %d %d\n" , xn , xm , yn , ym );
}
int main(){
    init();
    build();
    solve();
}