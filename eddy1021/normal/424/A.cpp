#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 210
using namespace std;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n; char c[ N ];
void init(){
    scanf( "%d%s" , &n , c );
}
int cnta , cntb;
void solve(){
    for( int i = 0 ; i < n ; i ++ )
        if( c[ i ] == 'x' ) cnta ++;
        else cntb ++;
    if( cnta > cntb ){
        n /= 2;
//        if( n - cntb > 0 ) puts( "1" );
//        else puts( "0" );
        printf( "%d\n" , n - cntb );
        for( int i = 0 ; i < n ; i ++ )
            if( c[ i ] == 'x' && cnta > n ) c[ i ] = 'X' , cnta --;
        puts( c );
    }else{
        n /= 2;
//        if( n - cnta > 0 ) puts( "1" );
//        else puts( "0" );
        printf( "%d\n" , n - cnta );
        for( int i = 0 ; i < n ; i ++ )
            if( c[ i ] == 'X' && cntb > n ) c[ i ] = 'x' , cntb --;
        puts( c );
    }
}
int main(){
    init();
    solve();
}