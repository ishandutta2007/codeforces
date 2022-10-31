#include <stdio.h>
#define N 1010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int min( int x , int y ){ return x<y?x:y; }
int n , m , q , a[ N ][ N ] , l[ N ][ N ] , r[ N ][ N ];
int u[ N ][ N ] , d[ N ][ N ];
void init(){
    n = getint(); m = getint(); q = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ )
            a[ i ][ j ] = getint();
}
void pre_build(){
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 1 ; j <= m ; j ++ )
            if( a[ i ][ j ] ) l[ i ][ j ] = l[ i ][ j - 1 ] + 1;
            else l[ i ][ j ] = 0;
        for( int j = m ; j >= 1 ; j -- )
            if( a[ i ][ j ] ) r[ i ][ j ] = r[ i ][ j + 1 ] + 1;
            else r[ i ][ j ] = 0;
    }
    for( int j = 1 ; j <= m ; j ++ ){
        for( int i = 1 ; i <= n ; i ++ )
            if( a[ i ][ j ] ) u[ i ][ j ] = u[ i - 1 ][ j ] + 1;
            else u[ i ][ j ] = 0;
        for( int i = n ; i >= 1 ; i -- )
            if( a[ i ][ j ] ) d[ i ][ j ] = d[ i + 1 ][ j ] + 1;
            else d[ i ][ j ] = 0;
    }
}
void change( int tn , int tm ){
    a[ tn ][ tm ] = 1 - a[ tn ][ tm ];
    for( int j = 1 ; j <= m ; j ++ )
        if( a[ tn ][ j ] ) l[ tn ][ j ] = l[ tn ][ j - 1 ] + 1;
        else l[ tn ][ j ] = 0;
    for( int j = m ; j >= 1 ; j -- )
        if( a[ tn ][ j ] ) r[ tn ][ j ] = r[ tn ][ j + 1 ] + 1;
        else r[ tn ][ j ] = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if( a[ i ][ tm ] ) u[ i ][ tm ] = u[ i - 1 ][ tm ] + 1;
        else u[ i ][ tm ] = 0;
    for( int i = n ; i >= 1 ; i -- )
        if( a[ i ][ tm ] ) d[ i ][ tm ] = d[ i + 1 ][ tm ] + 1;
        else d[ i ][ tm ] = 0;
}
int query( int tn , int tm ){
    if( !a[ tn ][ tm ] ) return 0;
    int ans = 0;
    int xl = l[ tn ][ tm ] , xr = r[ tn ][ tm ];
    for( int h = 1 , xn = tn ; xn >= 1 ; xn -- , h ++ ){
        if( !a[ xn ][ tm ] ) break;
        xl = min( xl , l[ xn ][ tm ] );
        xr = min( xr , r[ xn ][ tm ] );
        if( ( xl + xr - 1 ) * h > ans )
            ans = ( xl + xr - 1 ) * h;
    }
    xl = l[ tn ][ tm ]; xr = r[ tn ][ tm ];
    for( int h = 1 , xn = tn ; xn <= n ; xn ++ , h ++ ){
        if( !a[ xn ][ tm ] ) break;
        xl = min( xl , l[ xn ][ tm ] );
        xr = min( xr , r[ xn ][ tm ] );
        if( ( xl + xr - 1 ) * h > ans )
            ans = ( xl + xr - 1 ) * h;
    }
    int xu = u[ tn ][ tm ] , xd = d[ tn ][ tm ];
    for( int h = 1 , xm = tm ; xm >= 1 ; xm -- , h ++ ){
        if( !a[ tn ][ xm ] ) break;
        xu = min( xu , u[ tn ][ xm ] );
        xd = min( xd , d[ tn ][ xm ] );
        if( ( xu + xd - 1 ) * h > ans )
            ans = ( xu + xd - 1 ) * h;
    }
    xu = u[ tn ][ tm ]; xd = d[ tn ][ tm ];
    for( int h = 1 , xm = tm ; xm <= m ; xm ++ , h ++ ){
        if( !a[ tn ][ xm ] ) break;
        xu = min( xu , u[ tn ][ xm ] );
        xd = min( xd , d[ tn ][ xm ] );
        if( ( xu + xd - 1 ) * h > ans )
            ans = ( xu + xd - 1 ) * h;
    }
    return ans;
}
void solve(){
    int op , tn , tm;
    while( q -- ){
        op = getint(); tn = getint(); tm = getint();
        if( op == 1 ) change( tn , tm );
        else printf( "%d\n" , query( tn , tm ) );
    }
}
int main(){
    init();
    pre_build();
    solve();
}