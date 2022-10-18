#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
#define int long long
set<int> s[500001];
map<set<int>,int> mp;
int t,n,m,c[500001],ans;
bool vis[500001];
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        mp.clear();
        for(register int i=1;i<=n;++i)
        {
            s[i].clear();
            scanf("%lld",&c[i]);
            vis[i]=0;
        }
        for(register int i=1;i<=m;++i)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            s[y].insert(x);
        }
        for(register int i=1;i<=n;++i)
        {
            if(s[i].empty())
            {
                vis[i]=1;
                continue;
            }
            if(mp[s[i]])
            {
                c[mp[s[i]]]+=c[i];
                vis[i]=1;
            }
            else
                mp[s[i]]=i;
        }
        ans=0;
        for(register int i=1;i<=n;++i)
            if(!vis[i])
                if(!ans)
                    ans=c[i];
                else
                    ans=gcd(ans,c[i]);
        printf("%lld\n",ans);
    }
    return 0;
}