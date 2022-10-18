#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define int long long
int n,m,t[100001],f[100001],d[100001],val[100001];
multiset<int> ans,s[100001];
bool vis[100001];
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
inline int calc(int x)
{
    return val[x]+t[x]-(d[x]+1)*(t[x]/(d[x]+2));
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        t[i]=read();
    for(int i=1;i<=n;++i)
        ++d[f[i]=read()];
    for(int i=1;i<=n;++i)
        val[f[i]]+=t[i]/(d[i]+2);
    for(int i=1;i<=n;++i)
        s[f[i]].emplace(calc(i));
    for(int i=1;i<=n;++i)
        if(s[i].size())
        {
            ans.emplace(*s[i].begin()+t[i]/(d[i]+2));
            if(s[i].size()>1)
                ans.emplace(*--s[i].end()+t[i]/(d[i]+2));
        }
    while(m--)
    {
        int opt=read();
        if(opt==1)
        {
            int x=read(),y=read();
            set<int> tmp;
            tmp.emplace(f[x]);
            tmp.emplace(f[f[x]]);
            tmp.emplace(f[f[f[x]]]);
            tmp.emplace(y);
            tmp.emplace(f[y]);
            tmp.emplace(f[f[y]]);
            for(int i:tmp)
                if(s[i].size())
                {
                    ans.erase(ans.find(*s[i].begin()+t[i]/(d[i]+2)));
                    if(s[i].size()>1)
                        ans.erase(ans.find(*--s[i].end()+t[i]/(d[i]+2)));
                }
            s[f[f[f[x]]]].erase(s[f[f[f[x]]]].find(calc(f[f[x]])));
            vis[f[f[x]]]=1;
            if(!vis[f[x]])
            {
                s[f[f[x]]].erase(s[f[f[x]]].find(calc(f[x])));
                vis[f[x]]=1;
            }
            if(!vis[x])
            {
                s[f[x]].erase(s[f[x]].find(calc(x)));
                vis[x]=1;
            }
            if(!vis[f[y]])
            {
                s[f[f[y]]].erase(s[f[f[y]]].find(calc(f[y])));
                vis[f[y]]=1;
            }
            if(!vis[y])
            {
                s[f[y]].erase(s[f[y]].find(calc(y)));
                vis[y]=1;
            }
            vis[f[f[x]]]=vis[f[x]]=vis[x]=vis[f[y]]=vis[y]=0;
            val[f[f[x]]]-=t[f[x]]/(d[f[x]]+2);
            --d[f[x]];
            val[f[f[x]]]+=t[f[x]]/(d[f[x]]+2);
            val[f[x]]-=t[x]/(d[x]+2);
            val[f[y]]-=t[y]/(d[y]+2);
            ++d[y];
            val[f[y]]+=t[y]/(d[y]+2);
            val[y]+=t[x]/(d[x]+2);
            s[f[f[f[x]]]].emplace(calc(f[f[x]]));
            vis[f[f[x]]]=1;
            if(!vis[f[x]])
            {
                s[f[f[x]]].emplace(calc(f[x]));
                vis[f[x]]=1;
            }
            if(!vis[f[y]])
            {
                s[f[f[y]]].emplace(calc(f[y]));
                vis[f[y]]=1;
            }
            if(!vis[y])
            {
                s[f[y]].emplace(calc(y));
                vis[y]=1;
            }
            if(!vis[x])
            {
                s[y].emplace(calc(x));
                vis[x]=1;
            }
            vis[f[f[x]]]=vis[f[x]]=vis[f[y]]=vis[y]=vis[x]=0;
            for(int i:tmp)
                if(s[i].size())
                {
                    ans.emplace(*s[i].begin()+t[i]/(d[i]+2));
                    if(s[i].size()>1)
                        ans.emplace(*--s[i].end()+t[i]/(d[i]+2));
                }
            f[x]=y;
        }
        if(opt==2)
        {
            int x=read();
            cout<<calc(x)+t[f[x]]/(d[f[x]]+2)<<'\n';
        }
        if(opt==3)
            cout<<*ans.begin()<<" "<<*--ans.end()<<'\n';
    }
    return 0;
}