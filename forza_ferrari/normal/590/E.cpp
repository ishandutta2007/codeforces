#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int n;
bool g[751][751],tag[2001];
string s[751];
vector<int> ans;
struct ACAM
{
    int tot,ch[10000001][2],fail[10000001],top[10000001];
    vector<int> v[10000001];
    inline void insert(int x)
    {
        int node=0;
        for(auto i:s[x])
        {
            if(!ch[node][i-'a'])
                ch[node][i-'a']=++tot;
            node=ch[node][i-'a'];
        }
        if(v[node].size())
            g[x][v[node].back()]=1;
        v[node].emplace_back(x);
    }
    inline void getfail()
    {
        queue<int> q;
        for(int i=0;i<2;++i)
            if(ch[0][i])
                q.emplace(ch[0][i]);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=0;i<2;++i)
                if(ch[k][i])
                {
                    fail[ch[k][i]]=ch[fail[k]][i];
                    if(v[fail[ch[k][i]]].size())
                        top[ch[k][i]]=fail[ch[k][i]];
                    else
                        top[ch[k][i]]=top[fail[ch[k][i]]];
                    q.emplace(ch[k][i]);
                }
                else
                    ch[k][i]=ch[fail[k]][i];
        }
    }
    inline void solve()
    {
        for(int i=1;i<=n;++i)
        {
            int node=0;
            int len=0;
            for(auto j:s[i])
            {
                ++len;
                node=ch[node][j-'a'];
                if(v[top[node]].size())
                    g[i][v[top[node]].back()]=1;
                if(v[node].size()&&len!=s[i].length())
                    g[i][v[node].back()]=1;
            }
        }
    }
}ACAM;
struct flow
{
    struct edge
    {
        int nxt,to,weight;
    }e[100001<<3];
    int tot=1,s,t,h[2001],dep[2001],cur[2001],ans;
    bool vis[2001];
    inline void add(int x,int y,int w)
    {
        e[++tot]={h[x],y,w};
        h[x]=tot;
    }
    inline bool bfs()
    {
        queue<int> q;
        for(int i=0;i<=t;++i)
        {
            vis[i]=0;
            dep[i]=0x3f3f3f3f;
            cur[i]=h[i];
        }
        dep[s]=0;
        q.emplace(s);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            vis[k]=0;
            for(int i=h[k];i;i=e[i].nxt)
                if(e[i].weight&&dep[e[i].to]>dep[k]+1)
                {
                    dep[e[i].to]=dep[k]+1;
                    if(!vis[e[i].to])
                    {
                        vis[e[i].to]=1;
                        q.emplace(e[i].to);
                    }
                }
        }
        return dep[t]^dep[0];
    }
    inline int dfs(int k,int f)
    {
        if(k==t)
        {
            ans+=f;
            return f;
        }
        int r=0,used=0;
        for(int i=cur[k];i;i=e[i].nxt)
        {
            cur[k]=i;
            if(e[i].weight&&dep[e[i].to]==dep[k]+1)
                if((r=dfs(e[i].to,min(e[i].weight,f-used))))
                {
                    e[i].weight-=r;
                    e[i^1].weight+=r;
                    used+=r;
                    if(f==used)
                        break;
                }
        }
        return used;
    }
    inline void dinic()
    {
        while(bfs())
            dfs(s,1<<30);
    }
    inline void solve(int k)
    {
        if(tag[k])
            return;
        tag[k]=1;
        for(int i=h[k];i;i=e[i].nxt)
            if(e[i].weight)
                solve(e[i].to);
    }
}flow;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        ACAM.insert(i);
    }
    ACAM.getfail();
    ACAM.solve();
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            if(i^k)
                for(int j=1;j<=n;++j)
                    if(i!=j&&j!=k)
                        g[i][j]|=g[i][k]&g[k][j];
    flow.s=n+n+1;
    flow.t=flow.s+1;
    for(int i=1;i<=n;++i)
    {
        flow.add(flow.s,i,1);
        flow.add(i,flow.s,0);
        flow.add(i+n,flow.t,1);
        flow.add(flow.t,i+n,0);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j&&g[i][j])
            {
                flow.add(i,j+n,1);
                flow.add(j+n,i,0);
            }
    flow.dinic();
    flow.solve(flow.s);
    for(int i=1;i<=n;++i)
        if(tag[i]&&!tag[i+n])
            ans.emplace_back(i);
    cout<<ans.size()<<'\n';
    for(int i:ans)
        cout<<i<<" ";
    cout<<'\n';
    return 0;
}