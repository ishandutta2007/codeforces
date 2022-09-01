#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define at(i,x) for(auto i:x)
#define pot(x) cout << x.fi << " " << x.sc << endl
int n,m;
vector<int>G[2505];
vector<int>edge[2505];
int up[2505],dep[2505];
bool used[2505];
int cnt[2505];
vector<P>ctr;
void dfs(int v,int u){
	up[v] = u; used[v] = 1;
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	rep(i,G[v].size()){
		if(G[v][i] == u) continue;
		if(used[G[v][i]]){
			if(dep[v] < dep[G[v][i]]){
				cnt[G[v][i]]++; cnt[v]--;
				ctr.pb(P(G[v][i],v));
			}
		}
		else{
			dfs(G[v][i],v);
			edge[v].pb(G[v][i]);
		}
	}
}
void dfs2(int v,int u){
	rep(i,edge[v].size()){
		dfs2(edge[v][i],v);
		cnt[v] += cnt[edge[v][i]];
	}
	if(cnt[v] == 0 && u != -1){
		ctr.pb(P(v,u));
	}
}
vector<vector<int>>cyc;
vector<P>belong[2505];
vector<vector<int>>calc(int c,int v){
	//0...jill
	//1...jack
	//2...empty
	vector<vector<int>>ret; rep(i,3) ret.pb(vector<int>(1,0));
	//cout << c << " " << v << endl;
	rep(i,belong[v].size()){
		int cnum = belong[v][i].fi, pos = belong[v][i].sc;
		if(cnum == c) continue;
		int sz = cyc[cnum].size();
		vector<int>dp[2][3][3];
		rep(i,3) dp[0][i][i].pb(0);
		int cur = 0, nxt = 1;
		repn(go,sz-1){
			rep(a,3)rep(b,3) dp[nxt][a][b].clear();
			int ver = cyc[cnum][(pos+go)%sz];
			auto x = calc(cnum,ver);
			rep(a,3)rep(b,3)rep(d,3){
				if(b==2||d==2||b==d){
					if(dp[nxt][a][d].size() < dp[cur][a][b].size()+x[d].size()-1) dp[nxt][a][d].resize(dp[cur][a][b].size()+x[d].size()-1);
					rep(p,dp[cur][a][b].size()) rep(q,x[d].size()){
						dp[nxt][a][d][p+q] = max(dp[nxt][a][d][p+q],dp[cur][a][b][p]+x[d][q]);
					}
				}
			}
			swap(cur,nxt);
		}
		rep(a,3) rep(b,3){
			if(a==2||b==2||a==b){
				if(dp[cur][a][a].size() < dp[cur][a][b].size()) dp[cur][a][a].resize(dp[cur][a][b].size());
				rep(i,dp[cur][a][b].size()) dp[cur][a][a][i] = max(dp[cur][a][a][i], dp[cur][a][b][i]);
			}
		}
		rep(a,3){
			int sz = ret[a].size();
			ret[a].resize(ret[a].size()+dp[cur][a][a].size()-1);
			for(int b=sz-1;b>=0;b--) for(int c=dp[cur][a][a].size()-1;c>=0;c--){
				ret[a][b+c] = max(ret[a][b+c],ret[a][b]+dp[cur][a][a][c]);
			}
		}
	}
	reverse(ret[0].begin(),ret[0].end()); ret[0].pb(-INF); reverse(ret[0].begin(),ret[0].end()); 
	rep(i,ret[1].size()) ret[1][i]++;
	//cout << ret[0].size() << " " << ret[1].size() << " " << ret[2].size() << endl;
	//cout << c << " " << v << endl;
	return ret;
}
int main(){
	cin >> n >> m;
	rep(i,m){
		int a,b; cin >> a >> b;
		G[a].pb(b); G[b].pb(a);
	}
	dfs(1,-1);
	dfs2(1,-1);
	at(i,ctr){
		int x = i.fi, y = i.sc;
		vector<int>vi;
		while(1){
			vi.pb(x);
			if(x == y) break;
			x = up[x];
		}
		cyc.pb(vi);
	}
	rep(i,cyc.size()) rep(j,cyc[i].size()) belong[cyc[i][j]].pb(mp(i,j));
	//repn(i,n) rep(j,belong[i].size()) cout << belong[i][j].fi << " " << belong[i][j].sc << " " << j << endl;
	auto ans = calc(-1,1);
	vector<int>ret(n+1,-INF);
	rep(i,3)rep(j,ans[i].size()) ret[j] = max(ret[j],ans[i][j]);
	rep(i,n+1) cout << ret[i] << endl;
}