#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
ll bin[300005];
vector<int>edge[300005];
vector<int>num[300005];
int id[300005],nxt,mn[300005];
int sum[300005];
int col[300005];
int rev[300005];
int up[300005][20];
int dep[300005];
void dfs(int v,int u){
	rev[nxt] = v;
	id[v] = nxt++;
	if(col[v]) sum[v] = 1;
	up[v][0] = u;
	if(u==-1) dep[v] = 0; else dep[v] = dep[u]+1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		sum[v] += sum[edge[v][i]];
	}
}

set<int>ss[300005];

bool cmp(const int&a,const int&b){
	return id[a] < id[b];
}
int lca(int a,int b){
	if(dep[a] > dep[b]) swap(a,b);
	int D = dep[b]-dep[a];
	for(int i=19;i>=0;i--){
		if(D >= (1<<i)){
			D -= (1<<i);
			b = up[b][i];
		}
	}
	if(a == b) return a;
	for(int i=19;i>=0;i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}
vector<int>G[600005];
ll dp[600005][2];
void calc(int v,int u){
	bool is_leaf = true;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i] == u) continue;
		is_leaf = 0;
		calc(G[v][i],v);
	}
	if(is_leaf){
		if(v > 300002){
			dp[v][1] = 1;
		}
		else{
			dp[v][0] = 1;
		}
		return;
	}
	else if(v > 300002){
		dp[v][1] = 1;
		for(int i=0;i<G[v].size();i++){
			if(G[v][i] == u) continue;
			dp[v][1] *= (dp[G[v][i]][0]+dp[G[v][i]][1])%mod;
			dp[v][1] %= mod;
		}
	}
	else{
		dp[v][0] = 1;
		ll gg[2][2] = {};
		gg[0][0] = 1; gg[0][1] = 0;
		int cur = 0,nxt = 1;
		for(int i=0;i<G[v].size();i++){
			if(G[v][i] == u) continue;
			rep(w,2) gg[nxt][w] = 0;
			dp[v][0] *= (dp[G[v][i]][0]+dp[G[v][i]][1])%mod;
			dp[v][0] %= mod;
			gg[nxt][0] = (gg[cur][0]*((dp[G[v][i]][0]+dp[G[v][i]][1])%mod))%mod;
			gg[nxt][1] = (gg[cur][1]*((dp[G[v][i]][0]+dp[G[v][i]][1])%mod))%mod;
			gg[nxt][1] += (gg[cur][0]*((0+dp[G[v][i]][1])%mod))%mod;
			gg[nxt][1] %= mod;
			swap(cur,nxt);
		}
		dp[v][1] = gg[cur][1];
	}
}
struct u{
int par[600005],ran[600005];
void init(){ for(int i=0;i<600005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
}kaede;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a); col[i] = a;
		if(a){
			num[a].pb(i);
		}
	}
	for(int i=0;i<n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	int root = num[1][0];
	dfs(root,-1);
	ll ans = 1;
	for(int j=0;j<19;j++){
		for(int i=1;i<=n;i++){
			if(up[i][j] == -1) up[i][j+1] = -1;
			else up[i][j+1] = up[up[i][j]][j];
		}
	}
	for(int i=1;i<=k;i++){
		sort(num[i].begin(),num[i].end(),cmp);
		mn[i] = num[i][0];
		for(int j=1;j<num[i].size();j++){
		    if(id[mn[i]] > id[num[i][j]]){
		        mn[i] = num[i][j];
		    }
			int L = lca(num[i][j-1],num[i][j]);
			if(id[mn[i]] > id[L]){
				mn[i] = L;
			}
		}
		for(int j=0;j<num[i].size();j++){
			int cur = num[i][j]; 
			while(1){
				if(ss[cur].find(i) != ss[cur].end()) break;
				ss[cur].insert(i);
				if(ss[cur].size() >= 2){
					puts("0");
					return 0;
				}
				if(cur == mn[i]) break;
				
				cur = up[cur][0];
			}
		}
	}
	int C = 0; kaede.init();
	for(int i=1;i<=n;i++){
		if(up[i][0] == -1) continue;
		int j = up[i][0]; 
		int ii = i, jj = j;
		if(ss[j].size()) j = *ss[j].begin() + 300002;
		if(ss[i].size()) i = *ss[i].begin() + 300002;
		if(j == i) {i = ii;continue;}
		G[j].pb(i); kaede.unite(i,j);
		C++;
		i = ii;
	}
	for(int i=1;i<=n;i++){
		if(up[i][0] == -1) continue;
		int j = up[i][0]; 
		int ii = i, jj = j;
		if(ss[j].size()) j = *ss[j].begin() + 300002;
		if(ss[i].size()) i = *ss[i].begin() + 300002;
		if(j == i) {i = ii;continue;}
		assert(kaede.same(300003,i));
				assert(kaede.same(300003,j));
		i = ii;
	}
	calc(300003,-1);
	cout << (dp[300003][1]%mod+mod)%mod << endl;
}