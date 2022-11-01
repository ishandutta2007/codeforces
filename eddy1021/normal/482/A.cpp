#include <bits/stdc++.h>
using namespace std;
#define N 1010
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
void solve(){
    for( int i = n ; i > k + 1 ; i -- ) printf( "%d " , i );
    printf( "%d " , k + 1 );
    int l = 1 , r = k;
    for( int i = 1 ; i <= k ; i ++ )
        if( i & 1 ){
            printf( "%d " , l );
            l ++;
        }else{
            printf( "%d " , r );
            r --;
        }
}
int main(){
    init();
    solve();
}