#include<iostream>
#include<cstdio>
#include<cmath>
#define N 100010
#define ll long long
using namespace std;
ll num[N],sum[N],s1[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,k,z;
        scanf("%d%d%d",&n,&k,&z);
        for(int i=1;i<=n;i++) sum[i]=0;
        for(int i=1;i<=n;i++) scanf("%lld",&num[i]),sum[i]=max(sum[i-1],num[i]+num[i-1]),s1[i]=s1[i-1]+num[i];
        ll ans=0,maxn=0,res;
        k++;
        ans=sum[k];
        for(int i=0;i<=2*z;i++)
        {
            if(i>k) break;
            if(i&1) res=s1[k-i]+num[k-i-1]+sum[k-i]*((i-1)/2);
            else res=s1[k-i]+sum[k-i]*i/2;
            ans=max(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}