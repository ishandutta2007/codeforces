#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],ans,dp[100001],pre[100001],b[100001];
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]^a[i-1])
            b[++m]=a[i];
    }
    for(register int i=1;i<=m;++i)
    {
        dp[i]=dp[i-1]+1;
        if(pre[b[i]])
        {
            dp[i]=min(dp[i],dp[pre[b[i]]]+i-pre[b[i]]-1);
            dp[i]=min(dp[i],dp[pre[b[i]]+1]+(i-pre[b[i]]-2));
        }
        pre[b[i]]=i;
    }
    printf("%d\n",dp[m]);
    return 0;
}