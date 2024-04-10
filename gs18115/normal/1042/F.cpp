#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MAXV=1e6+10;
bool vis[MAXV];
LL dp[MAXV];
LL K,ans;
vector<LL>adj[MAXV];
void dfs(LL X)
{
    vis[X]=true;
    if(adj[X].size()==1)
    {
        dp[X]=0;
        return;
    }
    vector<int>V;
    for(int i=0;i<adj[X].size();i++)
    {
        if(vis[adj[X][i]])
            continue;
        dfs(adj[X][i]);
        if(dp[adj[X][i]]!=-1)
            V.push_back(dp[adj[X][i]]+1);
    }
    sort(V.begin(),V.end());
    while(!V.empty())
    {
        if(V.back()>=K)
            V.pop_back();
        else
            break;
        ans++;
    }
    while(V.size()>1)
    {
        if(V.back()+V[V.size()-2]>K)
            V.pop_back();
        else
            break;
        ans++;
    }
    if(V.empty())
        dp[X]=-1;
    else
        dp[X]=V.back();
    return;
}
LL N,i,s,e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=1;i<N;i++)
    {
        cin>>s>>e;
        adj[s-1].push_back(e-1);
        adj[e-1].push_back(s-1);
    }
    for(i=0;i<N;i++)
        if(adj[i].size()>1)
            break;
    dfs(i);
    if(dp[i]!=-1)
        ans++;
    cout<<ans<<endl;
    return 0;
}