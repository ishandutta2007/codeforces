//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,ans;
vector<int>con[100111],rev[100111],arr;
int vis[100111],cycle;
void dfs1(int x)
{
    arr.PB(x);
    vis[x]=1;
    for(int i=0;i<con[x].size();i++)
    {
        int u=con[x][i];
        if(vis[u])continue;
        dfs1(u);
    }
    for(int i=0;i<rev[x].size();i++)
    {
        int u=rev[x][i];
        if(vis[u])continue;
        dfs1(u);
    }
}
void dfs2(int x)
{
    vis[x]=3;
    for(int i=0;i<con[x].size();i++)
    {
        int u=con[x][i];
        if(vis[u]==2)continue;
        if(vis[u]==3){cycle=1;continue;}
        dfs2(u);
    }
    vis[x]=2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        con[x].PB(y);
        rev[y].PB(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            arr.clear();cycle=0;
            dfs1(i);
            for(int j=0;j<arr.size();j++)if(vis[arr[j]]==1)dfs2(arr[j]);
            if(cycle)ans+=arr.size();else ans+=arr.size()-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}