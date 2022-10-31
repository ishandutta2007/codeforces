#include <stdio.h>
#define N 1000010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int max( int x , int y ){ return x>y?x:y; }
int n , p[ N ] , a[ N ] , m1[ N ] , m2[ N ];
void solve(){
    n = getint(); a[ 1 ] = 0;
    for( int i = 2 ; i <= n + 1 ; i ++ ){
        p[ i ] = getint(); a[ i ] = 1;
        int now = i;
        while( 1 ){
            if( a[ now ] == m1[ p[ now ] ] + 1 ) m1[ p[ now ] ] ++;
            else if( a[ now ] == m2[ p[ now ] ] + 1 ) m2[ p[ now ] ] ++;
            else break;
            if( a[ p[ now ] ] < max( m1[ p[ now ] ] , m2[ p[ now ] ] + 1 ) )
                a[ p[ now ] ] = max( m1[ p[ now ] ] , m2[ p[ now ] ] + 1 );
            else break;
            if( p[ now ] == 1 ) break;
            now = p[ now ];
        }
        printf( "%d%c" , m1[ 1 ] , i == n + 1 ? '\n' : ' ' );
    }
}
int main(){
    solve();
}