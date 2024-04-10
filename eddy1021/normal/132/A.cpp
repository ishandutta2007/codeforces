#include <bits/stdc++.h>
using namespace std;
#define N 110
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
char c[ N ];
int len;
void solve(){
    int pre = 0;
    for( int i = 0 ; i < len ; i ++ ){
        int now = (int)c[ i ] , rev = 0;
        for( int j = 0 ; j < 8 ; j ++ ){
            rev <<= 1;
            rev += now % 2;
            now >>= 1;
        }
        now = rev;
        int ans = pre - now;
        ans %= 256;
        if( ans < 0 ) ans += 256;
        printf( "%d\n" , ans );
        pre = now;
/*        int trev = 0;
        for( int j = 0 ; j < 8 ; j ++ ){
            trev <<= 1;
            trev += pre % 2;
            pre >>= 1;
        }
        pre = trev;*/
    }
}
int main(){
    gets( c ); len = strlen( c );
    solve();
}