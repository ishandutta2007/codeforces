#include <bits/stdc++.h>
using namespace std;
#define N 100
char c[ 2 ][ N ];
struct XD{
    int tt , tn;
    char team[ N ] , cd[ N ];
}a[ N ];
bool cmp( XD x , XD y ){
    return x.tt < y.tt;
}
int n , call[ N ] , t[ N ] , nm[ N ];
int got[ 2 ][ N ];
void init(){
    scanf( "%s%s" , c[ 0 ] , c[ 1 ] );
    scanf( "%d" , &n );
    for( int i = 0 ; i < n ; i ++ )
        scanf( "%d%s%d%s" , &a[ i ].tt , a[ i ].team , &a[ i ].tn , a[ i ].cd );
    sort( a , a + n , cmp );
}
void solve(){
    for( int i = 0 ; i < n ; i ++ )
        if( a[ i ].team[ 0 ] == 'a' ){
            if( a[ i ].cd[ 0 ] == 'r' && got[ 1 ][ a[ i ].tn ] < 2 ){
                got[ 1 ][ a[ i ].tn ] = 2;
                call[ a[ i ].tt ] = 1;
                t[ a[ i ].tt ] = 1;
                nm[ a[ i ].tt ] = a[ i ].tn;
            }else if( a[ i ].cd[ 0 ] == 'y' && got[ 1 ][ a[ i ].tn ] == 1 ){
                got[ 1 ][ a[ i ].tn ] = 2;
                call[ a[ i ].tt ] = 1;
                t[ a[ i ].tt ] = 1;
                nm[ a[ i ].tt ] = a[ i ].tn;                
            }else if( a[ i ].cd[ 0 ] == 'y' && got[ 1 ][ a[ i ].tn ] == 0 )
                got[ 1 ][ a[ i ].tn ] = 1;
        }else{
            if( a[ i ].cd[ 0 ] == 'r' && got[ 0 ][ a[ i ].tn ] < 2 ){
                got[ 0 ][ a[ i ].tn ] = 2;
                call[ a[ i ].tt ] = 1;
                t[ a[ i ].tt ] = 0;
                nm[ a[ i ].tt ] = a[ i ].tn;
            }else if( a[ i ].cd[ 0 ] == 'y' && got[ 0 ][ a[ i ].tn ] == 1 ){
                got[ 0 ][ a[ i ].tn ] = 2;
                call[ a[ i ].tt ] = 1;
                t[ a[ i ].tt ] = 0;
                nm[ a[ i ].tt ] = a[ i ].tn;                
            }else if( a[ i ].cd[ 0 ] == 'y' && got[ 0 ][ a[ i ].tn ] == 0 )
                got[ 0 ][ a[ i ].tn ] = 1;
        }
}
void print_ans(){
    for( int i = 0 ; i < N ; i ++ )
        if( call[ i ] )
            printf( "%s %d %d\n" , c[ t[ i ] ] , nm[ i ] , i );
}
int main(){
    init();
    solve();
    print_ans();
}