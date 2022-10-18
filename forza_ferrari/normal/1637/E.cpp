#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m,a[300001],s[300001],node[300001],cnt,p[300001],tot;
long long ans;
vector<int> v[300001];
set<int> st[300001];
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
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
            node[i]=a[i]=read();
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=cnt;++i)
        {
            v[i].clear();
            s[i]=0;
        }
        for(int i=1;i<=n;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            ++s[a[i]];
        }
        for(int i=1;i<=m;++i)
        {
            int x=read(),y=read();
            if(node[lower_bound(node+1,node+cnt+1,x)-node]!=x||node[lower_bound(node+1,node+cnt+1,y)-node]!=y)
                continue;
            x=lower_bound(node+1,node+cnt+1,x)-node;
            y=lower_bound(node+1,node+cnt+1,y)-node;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        tot=0;
        for(int i=1;i<=cnt;++i)
            if(s[i])
                p[++tot]=s[i];
        sort(p+1,p+tot+1);
        tot=unique(p+1,p+tot+1)-p-1;
        for(int i=1;i<=tot;++i)
            st[i].clear();
        for(int i=1;i<=cnt;++i)
        {
            s[i]=lower_bound(p+1,p+tot+1,s[i])-p;
            st[s[i]].insert(node[i]);
        }
        ans=0;
        for(int i=1;i<=cnt;++i)
        {
            for(auto j:v[i])
                st[s[j]].erase(node[j]);
            st[s[i]].erase(node[i]);
            for(int j=1;j<=tot;++j)
                if(!st[j].empty())
                    ans=max(ans,1ll*(p[s[i]]+p[j])*(*--st[j].end()+node[i]));
            for(auto j:v[i])
                st[s[j]].insert(node[j]);
            st[s[i]].insert(node[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}