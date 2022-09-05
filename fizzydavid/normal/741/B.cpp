//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,w;
ll dp[1011],a[1011],b[1011];
ll suma,sumb;
vector<int>con[1011];
vector<pair<ll,ll> >g[1011];
int gtot;
bool vis[1011];
void dfs(int x)
{
	vis[x]=1;
	suma+=a[x];
	sumb+=b[x];
	g[gtot].PB(MP(a[x],b[x]));
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(vis[u])continue;
		dfs(u);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		b[i]=x;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		suma=0;sumb=0;
		gtot++;
		dfs(i);
		g[gtot].PB(MP(suma,sumb));
	}
	dp[0]=0;
	for(int i=1;i<=w;i++)dp[i]=-(1ll<<60);
	for(int i=1;i<=gtot;i++)
	{
		for(int j=w;j>=0;j--)
		{
			for(int k=0;k<g[i].size();k++)
			{
				if(g[i][k].FF<=j)
				{
					dp[j]=max(dp[j],dp[j-g[i][k].FF]+g[i][k].SS);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=w;i++)ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}