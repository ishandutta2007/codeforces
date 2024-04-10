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
const ll mod=1e9+7;
int n;
ll ans[200111],pl[200111],pr[200111],dp[200111];
vector<pair<int,ll> >con[200111];
void dfs(int x,int pre)
{
    for(int i=0;i<con[x].size();i++)
        if(con[x][i].FF!=pre)
            dfs(con[x][i].FF,x);
    ll tmp=1;
    for(int i=0;i<con[x].size();i++)
    {
        if(i==0)pl[i]=1;else pl[i]=pl[i-1];
        if(con[x][i].FF!=pre)
            pl[i]=pl[i]*(dp[con[x][i].FF]+1)%mod;
    }
    for(int i=int(con[x].size())-1;i>=0;i--)
    {
        if(i==int(con[x].size())-1)pr[i]=1;else pr[i]=pr[i+1];
        if(con[x][i].FF!=pre)
            pr[i]=pr[i]*(dp[con[x][i].FF]+1)%mod;
    }
    for(int i=0;i<con[x].size();i++)
        if(con[x][i].FF!=pre)
            con[x][i].SS=((i==0?1:pl[i-1])*(i==int(con[x].size())-1?1:pr[i+1]))%mod;
    dp[x]=pr[0];
}
void dfsans(int x,int pre,ll cur)
{
    if(x==1)ans[x]=dp[x];
    for(int i=0;i<con[x].size();i++)
    {
        if(con[x][i].FF!=pre)
        {
            ans[con[x][i].FF]=(cur*con[x][i].SS+1)%mod*dp[con[x][i].FF]%mod;
            dfsans(con[x][i].FF,x,(cur*con[x][i].SS+1)%mod);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int x;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        con[i].PB(MP(x,0));
        con[x].PB(MP(i,0));
    }
    dfs(1,-1);
    dfsans(1,-1,1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}