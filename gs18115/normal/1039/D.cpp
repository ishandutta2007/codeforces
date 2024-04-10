#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef int LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
vector<LL>adj[100010];
LL dp[100010],maxd[100010];
void dfs(LL x,LL d)
{
    dp[x]=0;
    LL m1,m2;
    m1=m2=0;
    for(LL i:adj[x])
    {
        dfs(i,d);
        if(maxd[i]>m1)
        {
            m2=m1;
            m1=maxd[i];
        }
        else if(maxd[i]>m2)
            m2=maxd[i];
        dp[x]+=dp[i];
    }
    if(1+m1+m2>=d)
    {
        dp[x]++;
        maxd[x]=0;
    }
    else
        maxd[x]=1+m1;
    return;
}
void dfs1(LL x,LL p)
{
    LL it;
    for(LL i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==p)
        {
            it=i;
            continue;
        }
        dfs1(adj[x][i],x);
    }
    if(p>=0)
        adj[x].erase(adj[x].begin()+it);
    return;
}
LL D[100010];
inline LL getans(LL x)
{
    if(D[x]>0)
        return D[x];
    dfs(0,x);
    return dp[0];
}
void dnc(LL s,LL e,LL l,LL r)
{
    if(s>e)
        return;
    if(l==r)
    {
        fill(D+s,D+e+1,l);
        return;
    }
    LL m=s+e>>1;
    D[m]=getans(m);
    dnc(s,m-1,D[m],r);
    dnc(m+1,e,l,D[m]);
    return;
}
LL N,M,i,u,v,s,e,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=1;i<N;i++)
    {
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    dfs1(0,-1);
    dnc(1,N,0,N);
    for(i=1;i<=N;i++)
        cout<<D[i]<<'\n';
    cout<<endl;
    return 0;
}