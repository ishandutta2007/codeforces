//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
int n;
ll a[2111],d;
bool vis[2111];
vector<int>con[2111];
ll dfs(int x,int y)
{
	ll res=1;
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(vis[u]||a[u]<a[y]||a[u]>a[y]+d||a[u]==a[y]&&u<y)continue;
		res=res*(dfs(u,y)+1)%mod;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>d>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		con[x].PB(y);
		con[y].PB(x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=(ans+dfs(i,i))%mod;
	}
	cout<<ans<<endl;
	return 0;
}