#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 2010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
char c[ N ][ N ];
int n , sum , a[ N ] , ymax , ymin;
int posy( int ty ){
    return ty + 1000;
}
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        a[ i ] = getint();
        sum += a[ i ];
    }
}
void solve(){
    int nowx = 0 , nowy = 0;
    for( int i = 1 ; i <= n ; i ++ )
        if( i & 1 ){
            for( int j = 0 ; j < a[ i ] ; j ++ ){
                c[ nowx ][ posy( nowy ) ] = '/';
                if( nowy > ymax ) ymax = nowy;
                if( nowy < ymin ) ymin = nowy;
                nowx ++; nowy ++;
            }
        }else{
            nowy --;
            for( int j = 0 ; j < a[ i ] ; j ++ ){
                c[ nowx ][ posy( nowy ) ] = '\\';
                if( nowy > ymax ) ymax = nowy;
                if( nowy < ymin ) ymin = nowy;
                nowx ++; nowy --;
            }
            nowy ++;
        }
}
void print(){
    for( int j = ymax ; j >= ymin ; j -- ){
        int nj = posy( j );
        for( int i = 0 ; i < sum ; i ++ )
            if( !c[ i ][ nj ] ) putchar( ' ' );
            else putchar( c[ i ][ nj ] );
        puts( "" );
    }
}
int main(){
    init();
    solve();
    print();
}