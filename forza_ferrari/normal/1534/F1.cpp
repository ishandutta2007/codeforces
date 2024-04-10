#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int n,m,bin[400001],d[400001],ans,dfn[400001],low[400001],cnt,col[400001],num;
vector<char> v[400001];
vector<int> g[400001];
stack<int> t;
bool vis[400001],inq[400001];
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline int id(int x,int y)
{
    return (x-1)*m+y;
}
inline void tarjan(int k)
{
    low[k]=dfn[k]=++cnt;
    vis[k]=inq[k]=1;
    t.emplace(k);
    for(auto i:g[k])
        if(!dfn[i])
        {
            tarjan(i);
            low[k]=min(low[k],low[i]);
        }
        else
            if(inq[i])
                low[k]=min(low[k],dfn[i]);
    if(low[k]==dfn[k])
    {
        col[k]=++num;
        inq[k]=0;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=num;
            inq[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
int main()
{
    cin>>n>>m;
    v[0].resize(m+2);
    for(int i=1;i<=n;++i)
    {
        v[i].resize(m+2);
        for(int j=1;j<=m;++j)
        {
            cin>>v[i][j];
            if(v[i][j]=='#')
            {
                if(v[i-1][j]=='#')
                    link(id(i-1,j),id(i,j));
                if(v[i][j-1]=='#')
                    link(id(i,j-1),id(i,j));
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        int x=-1,y=-1,z=-1;
        for(int j=n;j>=1;--j)
        {
            if(v[j][i]=='#')
            {
                int val=anc(id(j,i));
                if((~x)&&x!=val)
                    g[val].emplace_back(x);
                if((~y)&&y!=val)
                    g[val].emplace_back(y);
                if((~z)&&z!=val)
                    g[val].emplace_back(z);
            }
            if(v[j][i-1]=='#')
                x=anc(id(j,i-1));
            if(v[j][i]=='#')
                y=anc(id(j,i));
            if(v[j][i+1]=='#')
                z=anc(id(j,i+1));
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(v[i][j]=='#'&&anc(id(i,j))==id(i,j)&&!vis[id(i,j)])
                tarjan(id(i,j));
    for(int i=1;i<=n*m;++i)
        for(auto j:g[i])
            if(col[i]!=col[j])
                ++d[col[j]];
    for(int i=1;i<=num;++i)
        if(!d[i])
            ++ans;
    cout<<ans<<'\n';
    return 0;
}