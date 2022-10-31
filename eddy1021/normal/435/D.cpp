#include <stdio.h>
#include <string.h>
#define N 410
char c[ N ][ N ];
int n , m , dpl[ N ][ N ] , dpu[ N ][ N ] , ans;
void init(){
    scanf( "%d%d" , &n , &m );
    for( int i = 1 ; i <= n ; i ++ )
        scanf( "%s" , c[ i ] + 1 );
}
void pre_build(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            dpl[ i ][ j ] = dpl[ i ][ j - 1 ] + c[ i ][ j ] - '0';
            dpu[ i ][ j ] = dpu[ i - 1 ][ j ] + c[ i ][ j ] - '0';
        }
}
void test1( int idxi , int idxj ){
    for( int div = 1 ; idxi + div <= n && idxj + div <= m ; div ++ ){
        if( c[ idxi ][ idxj + div ] == '1' ) return;
        if( c[ idxi + div ][ idxj + div ] == '1' ) return;
        if( dpu[ idxi + div ][ idxj + div ] - dpu[ idxi - 1 ][ idxj + div ] == 0 ) ans ++;
    }
}
void test2( int idxi , int idxj ){
    for( int div = 1 ; idxi + div <= n && idxj + div <= m ; div ++ ){
        if( c[ idxi + div ][ idxj ] == '1' ) return;
        if( c[ idxi + div ][ idxj + div ] == '1' ) return;
        if( dpl[ idxi + div ][ idxj + div ] - dpl[ idxi + div ][ idxj - 1 ] == 0 ) ans ++;
    }
}
void test3( int idxi , int idxj ){
    for( int div = 1 ; idxi + div <= n && idxj - div > 0 ; div ++ ){
        if( c[ idxi ][ idxj - div ] == '1' ) return;
        if( c[ idxi + div ][ idxj - div ] == '1' ) return;
        if( dpu[ idxi + div ][ idxj - div ] - dpu[ idxi - 1 ][ idxj - div ] == 0 ) ans ++;
    }
}
void test4( int idxi , int idxj ){
    for( int div = 1 ; idxi + div <= n && idxj - div > 0 ; div ++ ){
        if( c[ idxi + div ][ idxj ] == '1' ) return;
        if( c[ idxi + div ][ idxj - div ] == '1' ) return;
        if( dpl[ idxi + div ][ idxj ] - dpl[ idxi + div ][ idxj - div - 1 ] == 0 ) ans ++;
    }
}
void test5( int idxi , int idxj ){
    for( int div = 1 ; idxi - div > 0 && idxj - div > 0 && idxj + div <= m ; div ++ ){
        if( c[ idxi - div ][ idxj - div ] == '1' ) return;
        if( c[ idxi - div ][ idxj + div ] == '1' ) return;
        if( dpl[ idxi - div ][ idxj + div ] - dpl[ idxi - div ][ idxj - div - 1 ] == 0 )
            ans ++;
    }
}
void test6( int idxi , int idxj ){
    for( int div = 1 ; idxi + div <= n && idxj - div > 0 && idxj + div <= m ; div ++ ){
        if( c[ idxi + div ][ idxj - div ] == '1' ) return;
        if( c[ idxi + div ][ idxj + div ] == '1' ) return;
        if( dpl[ idxi + div ][ idxj + div ] - dpl[ idxi + div ][ idxj - div - 1 ] == 0 )
            ans ++;
    }
}
void test7( int idxi , int idxj ){
    for( int div = 1 ; idxj - div > 0 && idxi - div > 0 && idxi + div <= n ; div ++ ){
        if( c[ idxi - div ][ idxj - div ] == '1' ) return;
        if( c[ idxi + div ][ idxj - div ] == '1' ) return;
        if( dpu[ idxi + div ][ idxj - div ] - dpu[ idxi - div - 1 ][ idxj - div ] == 0 )
            ans ++;
    }
}
void test8( int idxi , int idxj ){
    for( int div = 1 ; idxj + div <= m && idxi - div > 0 && idxi + div <= n ; div ++ ){
        if( c[ idxi - div ][ idxj + div ] == '1' ) return;
        if( c[ idxi + div ][ idxj + div ] == '1' ) return;
        if( dpu[ idxi + div ][ idxj + div ] - dpu[ idxi - div - 1 ][ idxj + div ] == 0 )
            ans ++;
    }
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            if( c[ i ][ j ] == '0' ){
                test1( i , j ); test2( i , j );
                test3( i , j ); test4( i , j );
                test5( i , j ); test6( i , j );
                test7( i , j ); test8( i , j );
            }
}
int main(){
    init();
    pre_build();
    solve();
    printf( "%d\n" , ans );
}