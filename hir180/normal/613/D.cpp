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
void dmp(vector<int>&a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
}
#define SZ 100005
vector<int>edge[SZ];
P ar[SZ*2]={};
int pos[SZ]={},id=0,up[SZ],dep[SZ];
P mn[20][SZ*2]={};
int sz[SZ*2]={};
struct LCA{
	//SZ
	//edge[]
	
	void dfs(int v,int u,int d){
		pos[v] = id; up[v] = u; dep[v] = d;
		ar[id++] = mp(d,v);
		for(int i=0;i<edge[v].size();i++){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i],v,d+1);
			ar[id++] = mp(d,v);
		}
	}
	void prepare(){
		dfs(1,-1,0);
		for(int i=0;i<id;i++) mn[0][i] = ar[i];
		for(int j=0;j<19;j++){
			for(int i=0;i<id;i++){
				if(i+(1<<j) >= id) mn[j+1][i] = mn[j][i];
				else mn[j+1][i] = min(mn[j][i], mn[j][i+(1<<j)]);
			}
		}
		for(int i=1;i<SZ*2;i++){
			for(int j=0;j<20;j++){
				if((1<<j) <= i && i <= (2<<j)){
					sz[i] = j;
					break;
				}
			}
		}
	}
	int get(int a,int b){
		int len = max(pos[a],pos[b]) - min(pos[a],pos[b]) + 1;
		int ty = sz[len];
		P p = min(mn[ty][min(pos[a],pos[b])], mn[ty][max(pos[a],pos[b])-(1<<ty)+1]);
		return p.second;
	}
}kaede;
//
// -> dfslca
int mapp[200005],mrev[200005];
bool cmp(const int&a, const int&b){
	return pos[a] < pos[b];
}
vector<vector<P>>G;
//impsubtree
//G[v] <- ()
//imp.size() log
void compress_tree(vector<int>imp){
	sort(imp.begin(),imp.end(),cmp);
	ERASE(imp);
	int sz = imp.size();
	rep(i,sz-1){
		imp.pb(kaede.get(imp[i], imp[i+1]));
	}
	sort(imp.begin(),imp.end(),cmp);
	ERASE(imp);
	
	int nxt = 0;
	//dmp(imp);
	for(auto a:imp){
		mrev[nxt] = a;
		mapp[a] = nxt++;
	}
	G.clear();
	G.resize(nxt, vector<P>());
	for(int i=1;i<nxt;i++){
		int par = kaede.get(imp[i-1],imp[i]);
		G[mapp[par]].pb(mp(mapp[imp[i]], dep[imp[i]] - dep[par]));
		G[mapp[imp[i]]].pb(mp(mapp[par], dep[imp[i]] - dep[par]));
	}
	return;
}
int dp[2][100005];
bool alw[100005];

void calc_dp(int v,int u){
	int t[2][3];
	rep(i,2)rep(j,3) t[i][j] = INF;
	t[0][0] = 0;
	int cur = 0,nxt = 1;
	
	rep(i,G[v].size()){
		if(G[v][i].fi == u) continue;
		int to = G[v][i].fi;
		int cs = G[v][i].sc;
		calc_dp(to,v);
		t[nxt][0] = t[nxt][1] = t[nxt][2] = INF;
		rep(j,3){
			if(t[cur][j] > INF/2) continue;
			t[nxt][j] = min(t[nxt][j], t[cur][j]+dp[0][to]);
			t[nxt][min(2,j+1)] = min(t[nxt][min(2,j+1)], t[cur][j]+dp[1][to]);
			if(cs > 1){
				t[nxt][j] = min(t[nxt][j], t[cur][j]+dp[1][to]+1);
			}
		}
		swap(cur,nxt);
	}
	if(!alw[mrev[v]]){
    	dp[0][v] = t[cur][0];
        dp[0][v] = min(dp[0][v],min(t[cur][1],t[cur][2])+1);
    	dp[1][v] = t[cur][1];
	}
	else{
	    dp[0][v] = INF;
    	dp[1][v] = t[cur][0];
	}
}
int n,q;
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	kaede.prepare();
	repn(i,n) mapp[i] = i;
	scanf("%d",&q);
	rep(w,q){
		int k;
		vector<int>imp;
		scanf("%d",&k);
		rep(i,k){
			int a; scanf("%d",&a); alw[a]=1;
			imp.pb(a);
		}
		compress_tree(imp);
		
		int sz = G.size();
		rep(i,2)rep(j,sz) dp[i][j] = INF;
		calc_dp(0,-1);
		int ans = min(dp[0][0], dp[1][0]);
		if(ans > 5e8) puts("-1");
		else printf("%d\n",ans);
		for(auto a:imp) alw[a] = 0;
	}
	return 0;
}