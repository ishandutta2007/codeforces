#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        ll a,b,c,p;
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        if(p%a==0 || p%b==0 || p%c==0) puts("0");
        else printf("%lld\n",min(min(a-p%a,b-p%b),c-p%c));
    }
    return 0;
}