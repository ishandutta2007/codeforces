#include<cstdio>
#include<map>
using namespace std;
int n,q,t,a[300005],b[300005],cnt[1000005];
map<int,bool> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=2;j*j<=a[i];j++)
            {
                while(a[i]%(j*j)==0) a[i]/=j*j;
            }
            cnt[a[i]]++;
            mp[a[i]]=true;
        }
        int ans0=0,ans1=0,tmpEven=0;
        for(auto p=mp.begin();p!=mp.end();p++)
        {
            int x=(*p).first;
            if(cnt[x]%2==0 || x==1) tmpEven+=cnt[x];
            ans0=max(ans0,cnt[x]);
            ans1=max(ans1,cnt[x]);
        }
        ans1=max(ans1,tmpEven);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            long long x;
            scanf("%lld",&x);
            if(x>=1) printf("%d\n",ans1);
            else printf("%d\n",ans0);
        }
        for(auto p=mp.begin();p!=mp.end();p++)
        {
            int x=(*p).first;
            cnt[x]=0;
        }
    }
}