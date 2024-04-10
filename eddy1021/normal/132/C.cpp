#include <bits/stdc++.h>
using namespace std;
#define N 110
#define T 60
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
char c[ N ];
bool tag[ 4 ][ N ][ T ];
int dp[ 4 ][ N ][ T ] , len , k;
// 0 for left min
// 1 for left max
// 2 for right min
// 3 for right max
void init(){
    scanf( "%s%d" , c + 1 , &k );
    len = strlen( c + 1 );
}
void solve(){
    tag[ 2 ][ 0 ][ 0 ] = true;
    tag[ 3 ][ 0 ][ 0 ] = true;
    for( int i = 1 ; i <= len ; i ++ )
        for( int j = 0 ; j <= i && j <= k ; j ++ )
            if( c[ i ] == 'F' ){
                if( tag[ 0 ][ i - 1 ][ j ] )
                    dp[ 0 ][ i ][ j ] = dp[ 0 ][ i - 1 ][ j ] - 1 , tag[ 0 ][ i ][ j ] = true;
                if( tag[ 1 ][ i - 1 ][ j ] )
                    dp[ 1 ][ i ][ j ] = dp[ 1 ][ i - 1 ][ j ] - 1 , tag[ 1 ][ i ][ j ] = true;
                if( tag[ 2 ][ i - 1 ][ j ] )
                    dp[ 2 ][ i ][ j ] = dp[ 2 ][ i - 1 ][ j ] + 1 , tag[ 2 ][ i ][ j ] = true;
                if( tag[ 3 ][ i - 1 ][ j ] )
                    dp[ 3 ][ i ][ j ] = dp[ 3 ][ i - 1 ][ j ] + 1 , tag[ 3 ][ i ][ j ] = true;
                if( j ){
                    if( tag[ 2 ][ i - 1 ][ j - 1 ] )
                        dp[ 0 ][ i ][ j ] = min( dp[ 0 ][ i ][ j ] , dp[ 2 ][ i - 1 ][ j - 1 ] ) ,
                                            tag[ 0 ][ i ][ j ] = true;
                    if( tag[ 3 ][ i - 1 ][ j - 1 ] )
                        dp[ 1 ][ i ][ j ] = max( dp[ 1 ][ i ][ j ] , dp[ 3 ][ i - 1 ][ j - 1 ] ) ,
                                            tag[ 1 ][ i ][ j ] = true;
                    if( tag[ 0 ][ i - 1 ][ j - 1 ] )
                        dp[ 2 ][ i ][ j ] = min( dp[ 2 ][ i ][ j ] , dp[ 0 ][ i - 1 ][ j - 1 ] ) ,
                                            tag[ 2 ][ i ][ j ] = true;
                    if( tag[ 1 ][ i - 1 ][ j - 1 ] )
                        dp[ 3 ][ i ][ j ] = max( dp[ 3 ][ i ][ j ] , dp[ 1 ][ i - 1 ][ j - 1 ] ) ,
                                            tag[ 3 ][ i ][ j ] = true;
                }
            }else{
                if( tag[ 2 ][ i - 1 ][ j ] )
                    dp[ 0 ][ i ][ j ] = dp[ 2 ][ i - 1 ][ j ] , tag[ 0 ][ i ][ j ] = true;
                if( tag[ 3 ][ i - 1 ][ j ] )
                    dp[ 1 ][ i ][ j ] = dp[ 3 ][ i - 1 ][ j ] , tag[ 1 ][ i ][ j ] = true;
                if( tag[ 0 ][ i - 1 ][ j ] )
                    dp[ 2 ][ i ][ j ] = dp[ 0 ][ i - 1 ][ j ] , tag[ 2 ][ i ][ j ] = true;
                if( tag[ 1 ][ i - 1 ][ j ] )  
                    dp[ 3 ][ i ][ j ] = dp[ 1 ][ i - 1 ][ j ] , tag[ 3 ][ i ][ j ] = true;
                if( j ){
                    if( tag[ 0 ][ i - 1 ][ j - 1 ] )
                        dp[ 0 ][ i ][ j ] = min( dp[ 0 ][ i ][ j ] , dp[ 0 ][ i - 1 ][ j - 1 ] - 1 ) , 
                            tag[ 0 ][ i ][ j ] = true;
                    if( tag[ 1 ][ i - 1 ][ j - 1 ] )
                        dp[ 1 ][ i ][ j ] = max( dp[ 1 ][ i ][ j ] , dp[ 1 ][ i - 1 ][ j - 1 ] - 1 ) ,
                            tag[ 1 ][ i ][ j ] = true;
                    if( tag[ 2 ][ i - 1 ][ j - 1 ] )
                        dp[ 2 ][ i ][ j ] = min( dp[ 2 ][ i ][ j ] , dp[ 2 ][ i - 1 ][ j - 1 ] + 1 ) ,
                            tag[ 2 ][ i ][ j ] = true;
                    if( tag[ 3 ][ i - 1 ][ j - 1 ] )    
                        dp[ 3 ][ i ][ j ] = max( dp[ 3 ][ i ][ j ] , dp[ 3 ][ i - 1 ][ j - 1 ] + 1 ) ,
                            tag[ 3 ][ i ][ j ] = true;
                }
            }
    int ans = 0;
    while( k >= 0 ){
        /*printf( "%d\n" , k );
        for( int i = 0 ; i < 4 ; i ++ )
            printf( "%d " , dp[ i ][ len ][ k ] );
        puts( "" );*/
        if( tag[ 0 ][ len ][ k ] );
        ans = max( ans , abs( dp[ 0 ][ len ][ k ] ) );
        if( tag[ 1 ][ len ][ k ] );
        ans = max( ans , abs( dp[ 1 ][ len ][ k ] ) );
        if( tag[ 2 ][ len ][ k ] );
        ans = max( ans , abs( dp[ 2 ][ len ][ k ] ) );
        if( tag[ 3 ][ len ][ k ] );
        ans = max( ans , abs( dp[ 3 ][ len ][ k ] ) );
        k -= 2;
    }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}