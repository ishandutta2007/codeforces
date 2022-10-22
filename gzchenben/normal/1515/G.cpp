#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
long long gcd(long long x,long long y)
{
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int dfn[200005],low[200005],color[200005],points,colors;
bool In[200005];
stack<int> st;
vector<pair<int,long long> > vec[200005];//pair<To,Val>
void tarjan(int x)
{
    In[x]=true;
    st.push(x);
    dfn[x]=low[x]=++points;
    for(int i=0;i<vec[x].size();i++)
    {
        int y=vec[x][i].first;
        if(!dfn[y]) 
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(In[y]) 
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(low[x]==dfn[x])
    {
        colors++;
        int cur=0;
        while(cur!=x)
        {
            cur=st.top();
            In[cur]=false;
            color[cur]=colors;
            st.pop();
        }
    }
}
int n,m,k,u[200005],v[200005];
long long w[200005],val[200005],G[200005];
bool vis[200005];
void dfs(int x)
{
    vis[x]=true;
    for(int i=0;i<vec[x].size();i++)
    {
        int y=vec[x][i].first;
        if(vis[y] || color[y]!=color[x]) continue;
        val[y]=val[x]+vec[x][i].second;
        dfs(y);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lld",&u[i],&v[i],&w[i]);
        vec[u[i]].push_back(make_pair(v[i],w[i]));
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(color[u[i]]==color[v[i]]) G[color[u[i]]]=gcd(G[color[u[i]]],val[u[i]]-val[v[i]]+w[i]);
    }
//    for(int i=1;i<=colors;i++) printf("G[%d]=%lld\n",i,G[i]);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int p;
        long long res,mod;
        scanf("%d%lld%lld",&p,&res,&mod);
        if(gcd(res,mod)%gcd(G[color[p]],mod)==0) printf("YES\n");
        else printf("NO\n");
    }
}