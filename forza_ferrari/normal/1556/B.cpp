#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int cnt[2],a[100001],t,n,pos,ans,sum;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        cnt[0]=cnt[1]=sum=0;
        ans=1ll<<60;
        for(register int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            ++cnt[a[i]&1];
        }
        if(abs(cnt[0]-cnt[1])>1)
        {
            puts("-1");
            continue;
        }
        if(cnt[0]>=cnt[1])
        {
            pos=1;
            sum=0;
            for(register int i=1;i<=n;++i)
                if(a[i]&1^1)
                {
                    sum+=abs(pos-i);
                    pos+=2;
                }
            ans=min(ans,sum);
        }
        if(cnt[1]>=cnt[0])
        {
            pos=1;
            sum=0;
            for(register int i=1;i<=n;++i)
                if(a[i]&1)
                {
                    sum+=abs(pos-i);
                    pos+=2;
                }
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}