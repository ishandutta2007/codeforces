#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
int n,p[100005];
vector<int>edge[100005];
vector<int>ans;
vector<int>ord;
int dep[100005],num[100005];
multiset<P>dp[100005];
int lazy[100005];
int last[100005];
void dfs(int v,int u){
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	int sz = -1;
	int to = -1;
	int sum = 0;
	for(int i=0;i<edge[v].size();i++){
		dfs(edge[v][i],v);
		if(sz < (int)dp[edge[v][i]].size()){
			sz = (int)dp[edge[v][i]].size();
			to = edge[v][i];
		}
		sum += (*dp[edge[v][i]].begin()).fi + lazy[edge[v][i]];
	}
	if(sz == -1){
		dp[v].insert(P(dep[v],v));
		return;
	}
	lazy[to] = lazy[to]+sum-(*dp[to].begin()).fi-lazy[to];
	map<int,int>M;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == to) continue;
		int sum2 = sum - (*dp[edge[v][i]].begin()).fi - lazy[edge[v][i]];
		for(auto A:dp[edge[v][i]]){
			int val = A.fi+lazy[edge[v][i]]+sum2;
			int ver = A.sc;
			M[ver] = edge[v][i];
			dp[to].insert(P(val-lazy[to],ver));
		}
	}
	swap(dp[v],dp[to]);
	swap(lazy[v],lazy[to]);
	int las = (*dp[v].begin()).sc;
	if(M.find(las) == M.end()) last[v] = to;
	else last[v] = M[las];
	return;
}
bool L[100005];
void make(int v){
	while(v != 0){
		L[v] = 1;
		v = p[v];
	}
}
void dfs1(int v,int u){
	num[v] = ord.size(); ord.pb(v);
	bool ex = 0;
	for(int i=0;i<edge[v].size();i++){
		if(L[edge[v][i]]) ex = 1;
	}
	if(ex){
		for(int i=0;i<edge[v].size();i++){
			if(!L[edge[v][i]]) dfs1(edge[v][i],v);
		}
		for(int i=0;i<edge[v].size();i++){
			if(L[edge[v][i]]) dfs1(edge[v][i],v);
		}
	}
	else{
		for(int i=0;i<edge[v].size();i++){
			if(last[v] == edge[v][i]) continue;
			dfs1(edge[v][i],v);
		}
		if(last[v] != -1) dfs1(last[v],v);
	}
}
void dfs2(int v,int u){
	bool ex = 0;
	for(int i=0;i<edge[v].size();i++){
		if(L[edge[v][i]]) ex = 1;
	}
	if(ex){
		for(int i=0;i<edge[v].size();i++){
			if(!L[edge[v][i]]){
				dfs2(edge[v][i],v);
				int x = ord[num[edge[v][i]]-1];
				rep(C,dep[x]-dep[v]) ans.pb(edge[v][i]);
			}
		}
		for(int i=0;i<edge[v].size();i++){
			if(L[edge[v][i]]) {
				dfs2(edge[v][i],v);
				int x = ord[num[edge[v][i]]-1];
				rep(C,dep[x]-dep[v]) ans.pb(edge[v][i]);
			}
		}
	}
	else{
		for(int i=0;i<edge[v].size();i++){
			if(last[v] == edge[v][i]) continue;
			{
				dfs2(edge[v][i],v);
				int x = ord[num[edge[v][i]]-1];
				rep(C,dep[x]-dep[v]) ans.pb(edge[v][i]);
			}
		}
		if(last[v] != -1) {
			dfs2(last[v],v);
			int x = ord[num[last[v]]-1];
			rep(C,dep[x]-dep[v]) ans.pb(last[v]);
		}
	}
}
int main(){
	memset(last,-1,sizeof(last));
	cin >> n;
	rep(i,n-1){
		int x; cin >> x;
		edge[x].pb(i+1);
		p[i+1] = x;
	}
	dfs(0,-1);
	int mx = 10000000; int L = -1;
	set<int>S;
	for(auto A:dp[0]){
		S.insert(A.fi);
		if(mx > A.fi-dep[A.sc]){ mx = A.fi-dep[A.sc]; L = A.sc;}
	}
	assert(S.size() == 1);
	make(L);
	dfs1(0,-1);
	dfs2(0,-1);
	rep(i,n) cout << ord[i] << '\n';
	cout << ans.size() << '\n';
	rep(i,ans.size()) cout << ans[i] << '\n';
}