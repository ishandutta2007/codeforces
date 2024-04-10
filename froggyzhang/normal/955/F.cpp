#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define N 300030
typedef long long ll;
int n,maxdep[N],dp[N],now,f[N],g[N];
vector<int> G[N],c[N];
tree<pair<int,int>,null_type,greater<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> T[N];
multiset<int> s[N];
ll ans;
void dfs(int u){
	maxdep[u]=1;
	int son=0;
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs(v);
		s[u].insert(dp[v]);
		T[u].insert(make_pair(g[v],v));
		maxdep[u]=max(maxdep[v]+1,maxdep[u]);
		++son;
	}	
	g[u]=son>=2?T[u].find_by_order(1)->first+1:1;
	dp[u]=max(s[u].empty()?0:*s[u].rbegin(),g[u]);
	now+=dp[u];
	ans+=maxdep[u]+dp[u];
	for(int i=3;i<=son+8;++i){
		c[i].push_back(u);
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int k=3;k<=n;++k){
		for(auto u:c[k]){
			for(int x=u;x;x=f[x]){
				int nw=T[x].size()<k?1:T[x].find_by_order(k-1)->first+1;
				int las=now,lasg=g[x];
				now-=dp[x];
				if(f[x]){
					T[f[x]].erase(make_pair(g[x],x));
					s[f[x]].erase(s[f[x]].find(dp[x]));	
				}
				dp[x]=max(s[u].empty()?0:*s[u].rbegin(),nw);
				g[x]=nw;
				if(f[x]){
					T[f[x]].insert(make_pair(g[x],x));
					s[f[x]].insert(dp[x]);	
				}
				now+=dp[x];
				if(las==now&&lasg==nw)break;
			}	
		}	
		ans+=now;
	}
	cout<<ans<<'\n';
	return 0;
}