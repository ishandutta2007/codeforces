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
int dis[211],nxt[211];
int n,mx;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll dfs(int x)
{
	if(dis[nxt[x]]>0)
	{
		mx=max(mx,dis[nxt[x]]);
		return dis[x]+1-dis[nxt[x]];
	}
	dis[nxt[x]]=dis[x]+1;
	return dfs(nxt[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		nxt[i]=x;
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		memset(dis,0,sizeof(dis));
		ll t=dfs(i);
		ans=ans/gcd(ans,t)*t;
	}
	ans=ans*((mx-1)/ans+1);
	cout<<ans<<endl;
	return 0;
}