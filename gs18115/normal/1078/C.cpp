#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const int MAXN=3e5+10;
const int R=0;
vector<int>adj[MAXN];
LL dp[MAXN][3];
LL N1[MAXN],N2[MAXN];
void dfs(int x,int p)
{
    if(p!=-1&&adj[x].size()==1)
    {
        dp[x][0]=1;
        return;
    }
    int i;
    for(i=0;i<adj[x].size();i++)
        if(adj[x][i]!=p)
            dfs(adj[x][i],x);
    N1[0]=1;
    N2[adj[x].size()]=1;
    for(i=0;i<adj[x].size();i++)
    {
        N1[i+1]=N1[i];
        if(adj[x][i]!=p)
            N1[i+1]=N1[i+1]*(dp[adj[x][i]][0]+dp[adj[x][i]][1]*2)%MOD;
    }
    for(i=adj[x].size();i-->0;)
    {
        N2[i]=N2[i+1];
        if(adj[x][i]!=p)
            N2[i]=N2[i]*(dp[adj[x][i]][0]+dp[adj[x][i]][1]*2)%MOD;
    }
    dp[x][0]=1;
    for(i=0;i<adj[x].size();i++)
        if(adj[x][i]!=p)
            dp[x][0]=dp[x][0]*(dp[adj[x][i]][0]+dp[adj[x][i]][1])%MOD;
    for(i=0;i<adj[x].size();i++)
        if(adj[x][i]!=p)
            dp[x][1]=(dp[x][1]+(dp[adj[x][i]][0]+dp[adj[x][i]][2])*N1[i]%MOD*N2[i+1])%MOD;
    dp[x][2]=(N2[0]-dp[x][0]+MOD)%MOD;
    return;
}
int N,i;
int u,v;
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
    dfs(R,-1);
    cout<<(dp[R][0]+dp[R][1])%MOD<<endl;
    return 0;
}