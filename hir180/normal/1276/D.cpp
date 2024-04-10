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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
const ll mod = 998244353;

ll dp[200005][4];
int n;
vector<int>edge[200005];
map<P,int>M;

ll dfs(int v,int u){
	bool bottom = 1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		bottom = 0;
	}
	if(bottom){
		dp[v][0] = dp[v][1] = dp[v][3] = 1;
		return 0;
	}
	dp[v][0] = dp[v][1] = 1;
	int X = M[P(min(u,v),max(u,v))];
	ll t[2][2]={}; int cur=0,nxt=1; t[0][0]=1;
	ll s[2][2]={}; int C=0,N=1; s[0][0] = 1;
	if(v == 1){
		rep(i,edge[v].size()){
			if(edge[v][i] == u) continue;
			t[nxt][0] = (t[cur][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			t[nxt][1] = (t[cur][1]*(dp[edge[v][i]][2]+dp[edge[v][i]][3])+t[cur][0]*dp[edge[v][i]][0])%mod;
			swap(cur,nxt);
		}
		return (t[cur][0]+t[cur][1])%mod;
	}
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		int Y = M[P(min(edge[v][i],v),max(edge[v][i],v))];
		if(Y < X){
			dp[v][0] = (dp[v][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			dp[v][1] = (dp[v][1]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			rep(k,2) s[N][k] = 0;
			s[N][0] = (s[C][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			s[N][1] = (s[C][0]*dp[edge[v][i]][0]+s[C][1]*(dp[edge[v][i]][2]+dp[edge[v][i]][3]))%mod;
			swap(C,N);
		}
		else{
			rep(k,2) t[nxt][k] = 0;
			t[nxt][0] = (t[cur][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			t[nxt][1] = (t[cur][1]*(dp[edge[v][i]][2]+dp[edge[v][i]][3])+t[cur][0]*dp[edge[v][i]][0])%mod;
			swap(cur,nxt);
			dp[v][1] = (dp[v][1]*(dp[edge[v][i]][3]+dp[edge[v][i]][2]))%mod;
		}
	}
	dp[v][0] = dp[v][0]*(t[cur][0]+t[cur][1])%mod;
	
	rep(a,2)rep(b,2)t[a][b]=0; t[cur][0] = s[C][0];
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		int Y = M[P(min(edge[v][i],v),max(edge[v][i],v))];
		if(Y < X){
		}
		else{
			rep(k,2) t[nxt][k] = 0;
			t[nxt][0] = (t[cur][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			t[nxt][1] = (t[cur][1]*(dp[edge[v][i]][2]+dp[edge[v][i]][3])+t[cur][0]*dp[edge[v][i]][0])%mod;
			swap(cur,nxt);
		}
	}
	dp[v][3] = (t[cur][0]+t[cur][1])%mod;
	
	rep(a,2)rep(b,2)t[a][b]=0; t[cur][1] = s[C][1];
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		int Y = M[P(min(edge[v][i],v),max(edge[v][i],v))];
		if(Y < X){
		}
		else{
			rep(k,2) t[nxt][k] = 0;
			t[nxt][0] = (t[cur][0]*(dp[edge[v][i]][1]+dp[edge[v][i]][2]))%mod;
			t[nxt][1] = (t[cur][1]*(dp[edge[v][i]][2]+dp[edge[v][i]][3])+t[cur][0]*dp[edge[v][i]][0])%mod;
			swap(cur,nxt);
		}
	}
	dp[v][2] = (t[cur][0]+t[cur][1])%mod;
	//cout << v << endl;
	//rep(i,4) cout << dp[v][i] << " "; cout << endl;
	return 0;
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		if(a > b) swap(a,b);
		M[P(a,b)] = i+1;
	}
	cout << dfs(1,-1) << endl;
}