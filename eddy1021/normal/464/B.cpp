#include <stdio.h>
#define N 9
#define M 4
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
bool flag;
ll a[ N ][ M ];
void init(){
    for( int i =  1 ; i < N ; i ++ )
        for( int j = 1 ; j < M ; j ++ )
            a[ i ][ j ] = getint();
}
ll sqr( ll x ){ return x * x; }
ll dis( ll x , ll y ){
    return sqr( a[ x ][ 1 ] - a[ y ][ 1 ] ) +
            sqr( a[ x ][ 2 ] - a[ y ][ 2 ] ) +
            sqr( a[ x ][ 3 ] - a[ y ][ 3 ] );
}
void SWAP( int i , int x , int y ){
    int Swap = a[ i ][ x ];
    a[ i ][ x ] = a[ i ][ y ];
    a[ i ][ y ] = Swap; 
}
int swapx[]={1,2};
int swapy[]={2,3};
void DFS( int now ){
    if( flag ) return;
    if( now == N ){
        ll dist[ N ][ N ];
        for( int i = 1 ; i < N ; i ++ ){
            for( int j = 1 ; j < N ; j ++ )
                dist[ i ][ j ] = dis( i , j );
            ll mn = i == 1 ? dist[ i ][ 2 ] : dist[ i ][ 1 ];
            for( int j = 1 ; j < N ; j ++ )
                if( i != j && dist[ i ][ j ] < mn )
                    mn = dist[ i ][ j ];
            ll cnt[ M ] = {};
            if( mn == 0 ) return;
            for( int j = 1 ; j < N ; j ++ )
                if( i != j ){
                    if( dist[ i ][ j ] % mn ) return;
                    if( dist[ i ][ j ] / mn > 3 ) return;
                    cnt[ dist[ i ][ j ] / mn ] ++;
                }
            if( cnt[ 1 ] != 3 || cnt[ 2 ] != 3 || cnt[ 3 ] != 1 )
                return;
        }
        puts( "YES" ); flag = true;
        for( int i = 1 ; i < N ; i ++ )
            for( int j = 1 ; j < M ; j ++ )
                printf( "%I64d%c" , a[ i ][ j ] , j == M - 1 ? '\n' : ' ' );
        return;
    }
    DFS( now + 1 );
    for( int i = 0 ; i < 5 && !flag ; i ++ ){
        SWAP( now , swapx[ i & 1 ] , swapy[ i & 1 ] );
        DFS( now + 1 );
    }
}
void solve(){
    DFS( 1 );
    if( !flag ) puts( "NO" );
}
int main(){
    init();
    solve();
}