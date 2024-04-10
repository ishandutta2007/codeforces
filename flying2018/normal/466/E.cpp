#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int f[N];
int wf[N],wg[N],wt;
vector<P >q[N];
bool vis[N];
int find(int x){return f[x]==x?f[x]:(f[x]=find(f[x]));}
int tot[N];
void dfs(int u,int p)
{
    vis[u]=true;
    for(int i=head[u];i;i=nxt[i]) dfs(to[i],u);
    for(auto a:q[u]) if(vis[a.fi]) tot[a.se]++;
    vis[u]=false;
}
int main()
{
    int n,m,k=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int opt,x,y;
        scanf("%d%d",&opt,&x);
        if(opt==1)
        {
            scanf("%d",&y);
            add(y,x);f[x]=y;
        }
        else if(opt==2) wf[++wt]=find(x),wg[wt]=x;
        else
        {
            scanf("%d",&y);++k;
            q[x].push_back(MP(wf[y],k));
            q[wg[y]].push_back(MP(x,k));
        }
    }
    for(int i=1;i<=n;i++)
    if(find(i)==i) dfs(i,0);
    for(int i=1;i<=k;i++) puts(tot[i]==2?"YES":"NO");
    return 0;
}