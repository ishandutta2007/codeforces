#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 19
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int num,ans,n,a[MAXN];
vector<int> indices[MAXN];
vector<int> save[MAXN];
int prime[MAXN],sz[MAXN];
bool is_prime[MAXN];
bool mark[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<int> G[MAXN];
vector<P> vt[MAXN];
int parent[MAXLOGN][MAXN];
int depth[MAXN],dfn[MAXN],dis[MAXN],st[MAXN];
int tot;
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
void dfs(int v,int p,int d)
{
    dfn[v]=++tot;
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=n;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAXLOGN;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int get_dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void add_edge(int from,int to)
{
    int cost=get_dis(from,to);
    vt[from].push_back(P(to,cost));
}
int build_vtree(vector<int> &a)
{
    sort(a.begin(),a.end(),cmp);
    a.erase(unique(a.begin(),a.end()),a.end());
    assert(a.size()>0);
    int t=0;
    st[t++]=a[0];
    vector<int> newly;newly.clear();
    for(int i=1;i<(int)a.size();i++)
    {
        if(t==0) {st[t++]=a[i]; continue;}
        int l=lca(a[i],st[t-1]);
        while(t>1&&dfn[st[t-2]]>=dfn[l]) add_edge(st[t-2],st[t-1]),t--;
        if(l!=st[t-1]) {add_edge(l,st[t-1]),st[t-1]=l; newly.push_back(l);}
        st[t++]=a[i];
    }
    while(t>1) add_edge(st[t-2],st[t-1]),t--;
    for(auto it:newly) a.push_back(it);
    return st[0];
}
void dfs_dp(int v)
{
    sz[v]=(mark[v]?1:0);
    for(auto p:vt[v])
    {
        dfs_dp(p.F);
        sz[v]+=sz[p.F];
        add(ans,1LL*p.S*sz[p.F]%MOD*(num-sz[p.F])%MOD);
    }
}
int solve(vector<int> &v)
{
    if(v.size()<=2) return 0;
    for(auto x:v) mark[x]=true;
    auto tmp=v;
    int root=build_vtree(tmp);
    ans=0; num=(int)v.size();
    dfs_dp(root);
    for(auto x:v) mark[x]=false;
    ans=1LL*ans*(num-2)%MOD*INV%MOD;
   // for(auto x:v) printf("%d ",x);
    for(auto x:tmp) vt[x].clear();
   // printf("ans=%d\n",ans);
    return ans;
}
int main()
{
    int p=sieve(200000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); indices[a[i]].push_back(i);}
    for(int i=0;i<p;i++)
        for(int j=prime[i];j<=200000;j+=prime[i])
            if(indices[j].size()) 
                for(auto x:indices[j]) save[i].push_back(x);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    init(n);
    int res=0;
    for(int i=0;i<p;i++) add(res,solve(save[i]));
    printf("%d\n",res);
    return 0;
}