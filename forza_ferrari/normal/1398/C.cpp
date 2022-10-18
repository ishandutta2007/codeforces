#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define int long long
int t,n,a[100011],sum[100011],ans;
map<int,int> mp;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        mp.clear();
        scanf("%lld",&n);
        memset(a,0,sizeof a);
        memset(sum,0,sizeof sum);
        ans=0;
        for(register int i=1;i<=n;++i)
        {
            a[i]=getchar()-'0';
            while(a[i]<0||a[i]>9)
                a[i]=getchar()-'0';
            a[i]=(a[i])? a[i]-1:-1;
            sum[i]=sum[i-1]+a[i];
        }
        mp[0]=1;
        for(register int i=1;i<=n;++i)
        {
            ans+=mp[sum[i]];
            ++mp[sum[i]];
        }
        printf("%lld\n",ans);
    }
    return 0;
}