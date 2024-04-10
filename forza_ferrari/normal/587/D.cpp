#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct edge
{
    int x,y,col,val;
}e[50001];
int n,m,tot,dfn[500001],low[500001],col[500001],cnt,num;
stack<int> t;
vector<int> v[500001];
vector<pair<int,int> > g[500001];
bool vis[500001];
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
inline void tarjan(int k)
{
    vis[k]=1;
    dfn[k]=low[k]=++cnt;
    t.emplace(k);
    for(int i:v[k])
        if(!dfn[i])
        {
            tarjan(i);
            low[k]=min(low[k],low[i]);
        }
        else if(vis[i])
            low[k]=min(low[k],dfn[i]);
    if(dfn[k]==low[k])
    {
        col[k]=++num;
        vis[k]=0;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=num;
            vis[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
inline bool check(int mid)
{
    for(int i=1;i<=m;++i)
        if(e[i].val>mid)
            v[i].emplace_back(i+m);
    for(int i=1;i<=tot;++i)
        col[i]=dfn[i]=low[i]=0;
    cnt=num=0;
    for(int i=1;i<=tot;++i)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=m;++i)
        if(e[i].val>mid)
            v[i].pop_back();
    for(int i=1;i<=m;++i)
        if(col[i]==col[i+m])
            return 0;
    return 1;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        e[i].x=read(),e[i].y=read(),e[i].col=read(),e[i].val=read();
        g[e[i].x].emplace_back(e[i].col,i);
        g[e[i].y].emplace_back(e[i].col,i);
    }
    tot=m+m;
    for(int i=1;i<=n;++i)
    {
        sort(g[i].begin(),g[i].end());
        int t1=0,t2=0;
        for(auto j:g[i])
        {
            //cout<<j.second<<" ";
            int x=j.second,y=j.second+m,s1=++tot,s2=++tot;
            v[x].emplace_back(s1);
            v[s2].emplace_back(y);
            if(t1&&t2)
            {
                v[t1].emplace_back(s1);
                v[s2].emplace_back(t2);
                v[t1].emplace_back(y);
                v[x].emplace_back(t2);
            }
            t1=s1;
            t2=s2;
        }
        //cout<<'\n';
        vector<pair<int,int> > tmp;
        for(auto j:g[i])
        {
            if(!tmp.empty()&&j.first!=tmp.back().first)
            {
                t1=t2=0;
                for(auto k:tmp)
                {
                    //cout<<k.second<<" ";
                    int x=k.second,y=k.second+m,s1=++tot,s2=++tot;
                    v[s1].emplace_back(x);
                    v[y].emplace_back(s2);
                    if(t1&&t2)
                    {
                        v[s1].emplace_back(t1);
                        v[t2].emplace_back(s2);
                        v[y].emplace_back(t1);
                        v[t2].emplace_back(x);
                    }
                    t1=s1;
                    t2=s2;
                }
                //cout<<'\n';
                tmp.clear();
            }
            tmp.emplace_back(j);
        }
        t1=t2=0;
        if(!tmp.empty())
        {
            for(auto j:tmp)
            {
                //cout<<j.second<<" ";
                int x=j.second,y=j.second+m,s1=++tot,s2=++tot;
                v[s1].emplace_back(x);
                v[y].emplace_back(s2);
                if(t1&&t2)
                {
                    v[s1].emplace_back(t1);
                    v[t2].emplace_back(s2);
                    v[y].emplace_back(t1);
                    v[t2].emplace_back(x);
                }
                t1=s1;
                t2=s2;
            }
            //cout<<'\n';
        }
    }
    int l=0,r=1e9,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(ans==-1)
    {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    check(ans);
    vector<int> res;
    for(int i=1;i<=m;++i)
        if(col[i]<col[i+m])
            res.emplace_back(i);
    cout<<ans<<" "<<res.size()<<'\n';
    for(int i:res)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}