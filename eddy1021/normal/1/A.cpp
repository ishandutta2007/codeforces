#include <stdio.h>
#define ll long long
ll a,b,c;
ll getl(){
    ll x=0LL; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int main(){
    a=getl(); b=getl(); c=getl();
    a=(a%c!=0)+(a/c); b=(b%c!=0)+(b/c);
    printf("%I64d\n",a*b); return 0;
}