#include<iostream>
#include<cstdio>
using namespace std;
int n,mod,ans[4000001],dp[4000001];
inline void update(register int x,register int val)
{
    for(;x<=n;x+=x&-x)
    {
        ans[x]+=val;
        if(ans[x]>=mod)
            ans[x]-=mod;
    }
}
inline int query(register int x)
{
    register int res=0;
    for(;x;x-=x&-x)
    {
        res+=ans[x];
        if(res>=mod)
            res-=mod;
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&mod);
    dp[n]=1;
    update(n,1);
    for(register int i=n-1;i;--i)
    {
        dp[i]=query(n)-query(i);
        if(dp[i]>=mod)
            dp[i]-=mod;
        if(dp[i]<0)
            dp[i]+=mod;
        for(register int j=2;j<=n;++j)
        {
            if(i*j>n)
                break;
            if((i+1)*j-1<=n)
                dp[i]=dp[i]+query((i+1)*j-1)-query(i*j-1);
            else
                dp[i]=dp[i]+query(n)-query(i*j-1);
            if(dp[i]>=mod)
                dp[i]-=mod;
            if(dp[i]<0)
                dp[i]+=mod;
        }
        update(i,dp[i]);
    }
    printf("%d\n",dp[1]);
    return 0;
}