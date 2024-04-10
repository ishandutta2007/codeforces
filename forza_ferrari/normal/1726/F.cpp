#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n,t,sum,ans,g[200001],c[200001];
map<int,int> mp;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
signed main()
{
    n=read(),t=read();
    for(int i=1;i<=n;++i)
        g[i]=read(),c[i]=read();
    for(int i=2;i<=n;++i)
        c[i]=(c[i]+(sum+=read())%t)%t;
    mp[0]=0;
    for(int i=1;i<=n;++i)
        mp[(g[i]-c[i]-1+t)%t]=mp[(t-c[i])%t]=0;
    for(int i=1;i<=n;++i)
    {
        int pos=(t-c[i])%t,w=1e18;
        auto it=mp.lower_bound((g[i]-c[i]+t)%t);
        while(it!=mp.end()&&(it->first+c[i])%t>=g[i])
        {
            w=min(w,it->second+(pos-it->first+t)%t);
            it=mp.erase(it);
        }
        it=mp.begin();
        while(it!=mp.end()&&(it->first+c[i])%t>=g[i])
        {
            w=min(w,it->second+(pos-it->first+t)%t);
            it=mp.erase(it);
        }
        if(w<1e18)
            if(!mp.count(pos))
                mp[pos]=w;
            else
                mp[pos]=min(mp[pos],w);
    }
    ans=1e18;
    for(auto i:mp)
        ans=min(ans,i.second);
    cout<<ans+sum<<'\n';
    return 0;
}