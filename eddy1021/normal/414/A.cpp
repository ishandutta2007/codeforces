#include <stdio.h>
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , k;
void init(){
    n = getint(); k = getint();
}
void process(){
    if( n == 1 ){
        if( k == 0 ) puts( "1" );
        else puts( "-1" );
        return ;
    }
    if( k < n / 2 ){
        puts( "-1" );
        return;
    }
    int bonus = k - n / 2 , tmp;
    printf( "%d %d " , bonus + 1 , ( bonus + 1 ) * 2 );
    n -= 2; tmp = ( bonus + 1 ) * 2 + 1;
    for( int i = 1 ; i <= n ; i ++ , tmp ++ )
        printf( "%d%c" , tmp , i == n ? '\n' : ' ' );
}
int main(){
    init();
    process();
}