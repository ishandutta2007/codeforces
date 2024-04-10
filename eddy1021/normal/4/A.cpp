#include <stdio.h>
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int n;
int main(){
    n=getint(); puts(n>2&&!((n-2)&1)?"YES":"NO");
    return 0;
}