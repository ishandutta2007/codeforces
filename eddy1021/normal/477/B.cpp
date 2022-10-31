#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define mod 1000000007
#define ll long long
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
    printf( "%d\n" , ( n * 6 - 1 ) * k );
    int base = 1;
    for( int i = 0 ; i < n ; i ++ ){
        printf( "%d %d %d %d\n" , base * k ,
                                ( base + 1 ) * k ,
                                ( base + 2 ) * k ,
                                ( base + 4 ) * k );
        base += 6;
    }
}
int main(){
    init();
    solve();
}