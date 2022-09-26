#include <bits/stdc++.h>
#define N 250010
typedef long long ll;
using namespace std;
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
int n,wf[N],d[N],f[N],dep[N],vis[N],cnt[N],rk[N];
set<pair<int,int> > G[N];
set<pair<int,int> > all;
vector<pair<ll,int> > s[N],t[N];
int K;
void dfs1(int u){
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		++cnt[u];
		f[v]=u;
		wf[v]=w;
		dep[v]=dep[u]+1;
		dfs1(v);
		s[u].emplace_back(w,v);
	}
	sort(s[u].begin(),s[u].end());
	t[u]=s[u];
	for(int i=1;i<(int)s[u].size();++i){
		s[u][i].first+=s[u][i-1].first;
	}
	for(int i=0;i<(int)s[u].size();++i){
		rk[s[u][i].second]=i;	
	}
} 
ll dp[N][2];
void dfs2(int u){
	vis[u]=1;
	vector<int> vec;
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		dfs2(v);
		dp[u][0]+=dp[v][0];
		dp[u][1]+=dp[v][0];
		vec.push_back(v);
	}
	sort(vec.begin(),vec.end(),[&](int i,int j){return rk[i]<rk[j];});
	int lim=max(0,cnt[u]-K+1)-1;
	static int hh[N];
	ll red=0;
	for(auto v:vec){
		if(rk[v]<=lim)++lim,red+=wf[v],hh[rk[v]]=1;
	}
	sort(vec.begin(),vec.end(),[&](int i,int j){return dp[i][1]-dp[i][0]<dp[j][1]-dp[j][0];});
	for(auto v:vec){
		ll w=dp[v][1]-dp[v][0];
		if(lim>=0&&(lim>=(int)t[u].size()||w<t[u][lim].first)){
			--lim;
			red-=w;
			while(lim>=0&&lim<(int)t[u].size()&&hh[lim])red-=t[u][lim].first,--lim;
		}	
		else if(w<0)red-=w;
	}
	dp[u][0]+=lim>=0?s[u][lim].first-red:-red;
	for(auto v:vec){
		hh[rk[v]]=0;
	}
	lim=max(0,cnt[u]-K)-1;
	red=0;
	for(auto v:vec){
		if(rk[v]<=lim)++lim,red+=wf[v],hh[rk[v]]=1;
	}
	sort(vec.begin(),vec.end(),[&](int i,int j){return dp[i][1]-dp[i][0]<dp[j][1]-dp[j][0];});
	for(auto v:vec){
		ll w=dp[v][1]-dp[v][0];
		if(lim>=0&&(lim>=(int)t[u].size()||w<t[u][lim].first)){
			--lim;
			red-=w;
			while(lim>=0&&lim<(int)t[u].size()&&hh[lim])red-=t[u][lim].first,--lim;
		}
		else if(w<0)red-=w;
	}
	dp[u][1]+=lim>=0?s[u][lim].first-red:-red;
	for(auto v:vec){
		hh[rk[v]]=0;
	}
	dp[u][1]+=wf[u];
}

int main(){
	n=read();
	ll wtot=0;
	for(int i=0;i<n-1;++i){
		int u=read(),v=read(),w=read();
		G[u].insert(make_pair(v,w));
		G[v].insert(make_pair(u,w));
		++d[u],++d[v];
		wtot+=w;
	}
	for(int i=1;i<=n;++i){
		all.insert(make_pair(d[i],i));
	}
	dfs1(1);
	vector<ll> ans(1,wtot);
	for(int i=1;i<n;++i){
		K=i;
		while(!all.empty()&&all.begin()->first <= i){
			int u=all.begin()->second;
			all.erase(all.begin());
			for(auto [v,w]:G[u]){
				G[v].erase(make_pair(u,w));	
			}
			G[u].clear();
		}
		static vector<int> nd;
		nd.clear();
		for(auto [p,u]:all){
			nd.push_back(u);
		}
		sort(nd.begin(),nd.end(),[&](int i,int j){return dep[i]<dep[j];});
		ll res=0;
		for(auto u:nd){
			if(!vis[u]){
				dfs2(u);
				res+=min(dp[u][0],dp[u][1]);
			}
		}
		ans.push_back(res);
		for(auto u:nd)vis[u]=dp[u][0]=dp[u][1]=0;
	}
	for(auto x:ans){
		printf("%lld ",x);
	}
	return 0;
}