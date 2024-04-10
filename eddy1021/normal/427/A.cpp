#include <stdio.h>
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a , x , s;
void solve(){
    while( n -- ){
        x = getint();
        if( x < 0 ){
            if( s > 0 ) s --;
            else a ++;
        }else s += x;
    }
    printf( "%d\n" , a );
}
int main(){
    n = getint();
    solve();
}