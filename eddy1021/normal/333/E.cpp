#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 60
#define N 3010
#define d double
#define ll unsigned long long
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , x[ N ] , y[ N ] , bidx;
int dist( int idxi , int idxj ){
    return ( x[ idxi ] - x[ idxj ] ) * ( x[ idxi ] - x[ idxj ] ) +
                ( y[ idxi ] - y[ idxj ] ) * ( y[ idxi ] - y[ idxj ] );
}
struct XD{
    int ti , tj , r;
}v[ N * N ];
bool cmp( XD x , XD y ){
    return x.r > y.r;
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        x[ i ] = getint();
        y[ i ] = getint();
    }
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = i + 1 ; j <= n ; j ++ ){
            v[ bidx ].ti = i;
            v[ bidx ].tj = j;
            v[ bidx ++ ].r = dist( i , j );
        }
    sort( v , v + bidx , cmp );
}
ll bitmsk[ N ][ N / M + 1 ];
bool link( int idxi , int idxj ){
    for( int i = n / M ; i >= 0 ; i -- )
        if( ( bitmsk[ idxi ][ i ] & bitmsk[ idxj ][ i ] ) > 0llu )
            return true;
    return false;
}
void solve(){
    for( int i = 0 ; i < bidx ; i ++ ){
//        printf( "%d %d %.10lf\n" , v[ i ].ti , v[ i ].tj , v[ i ].r );
        if( link( v[ i ].ti , v[ i ].tj ) ){
            printf( "%.20lf\n" , sqrt( (d)v[ i ].r ) / 2.0 );
            return;
        }else{
            bitmsk[ v[ i ].ti ][ v[ i ].tj >> 6 ] |= ( 1llu << ( v[ i ].tj & 63 ) );
            bitmsk[ v[ i ].tj ][ v[ i ].ti >> 6 ] |= ( 1llu << ( v[ i ].ti & 63 ) );
        }
    }
}
int main(){
    init();
    solve();
}