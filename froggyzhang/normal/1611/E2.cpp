#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,k,ff[N][19],f[N],a[N],l[N],r[N],cnt,dep[N];
vector<int> G[N];
void dfs(int u){
	ff[u][0]=f[u];
	dep[u]=dep[f[u]]+1;
	for(int i=1;i<=18;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	if(u^1&&G[u].size()==1){
		l[u]=r[u]=++cnt;
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dfs(v);
		l[u]=min(l[u],l[v]);
		r[u]=max(r[u],r[v]); 
	}
}
int Jump(int u,int t){
	for(int i=0;i<=18;++i){
		if(t>>i&1)u=ff[u][i];
	}
	return u;	
}
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		l[i]=n+1,r[i]=0;
		G[i].clear();
	}
	cnt=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	dfs(1);
	vector<pair<int,int> > Range;
	for(int i=1;i<=k;++i){
		int u=Jump(a[i],(dep[a[i]]-1)/2);
		Range.emplace_back(l[u],r[u]);
	}
	sort(Range.begin(),Range.end());
	int now=1,ri=-1,ans=0;
	for(int i=0;i<(int)Range.size();++i){
		auto [l,r]=Range[i];
		if(l>now)now=ri+1,++ans;
		if(l>now){
			cout<<"-1\n";
			return;
		}
		ri=max(ri,r);
	}
	if(now<=cnt)++ans;
	if(ri<cnt){
		cout<<"-1\n";
	}
	else{
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}