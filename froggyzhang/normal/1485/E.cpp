#include<bits/stdc++.h>
using namespace std;
#define N 200010
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,f[N],T,mx[N],mn[N],dep[N],a[N];
vector<int> G[N],p[N];
ll dp[N],t[N];
void dfs(int u){
	dep[u]=dep[f[u]]+1;
	mx[dep[u]]=max(mx[dep[u]],a[u]);
	mn[dep[u]]=min(mn[dep[u]],a[u]);
	p[dep[u]].push_back(u);
	for(auto v:G[u])dfs(v);
}
ll Solve(){
	dfs(1);
	for(int i=n;;--i){
		for(auto u:p[i]){
			dp[u]=0;
			for(auto v:G[u]){
				dp[u]=max(dp[u],dp[v]);
			}
			t[u]=dp[u];
		}
		if(!i)break;
		sort(p[i].begin(),p[i].end(),[&](int i,int j){return a[i]<a[j];});
		ll l=-2e18,r=-2e18;
		for(auto u:p[i]){
			l=max(l,t[u]-a[u]);
			dp[u]=max(dp[u],l+a[u]);
		}
		reverse(p[i].begin(),p[i].end());
		for(auto u:p[i]){
			r=max(r,t[u]+a[u]);
			dp[u]=max(dp[u],r-a[u]);
		}
		for(auto u:p[i]){
			dp[u]=max(dp[u],t[u]+max(a[u]-mn[i],mx[i]-a[u]));
		}
	}
	return dp[1];
}
int main(){
	T=read();
	dep[0]=-1;
	while(T--){
		n=read();
		for(int i=0;i<=n;++i){
			G[i].clear();
			p[i].clear();
			mx[i]=-inf,mn[i]=inf;
		}
		for(int i=2;i<=n;++i){
			f[i]=read();
			G[f[i]].push_back(i);
		}
		for(int i=2;i<=n;++i){
			a[i]=read();
		}
		printf("%lld\n",Solve());
	}
	return 0;
}