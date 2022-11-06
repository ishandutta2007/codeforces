#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define ll long long
using namespace std;
ll num[N],ans[N];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]),sum+=num[i];
    ll r=1ll*n*(n-1)/2,p=sum-r-(sum-r)/n*n;
    for(int i=1;i<=n;i++) ans[i]=(sum-r)/n+i-1;
    for(int i=1;i<=n;i++)
    {
        if(i<=p) printf("%lld\n",ans[i]+1);
        else printf("%lld\n",ans[i]);
    }
    return 0;
}