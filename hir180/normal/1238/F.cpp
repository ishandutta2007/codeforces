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
int q,n;
vector<int>edge[300005];
int dp[300005],ans;
void dfs(int v,int u){
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
	}
	priority_queue<int,vector<int>,greater<int>>que;
	dp[v] = -INF;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dp[v] = max(dp[v],dp[edge[v][i]]);
		que.push(dp[edge[v][i]]);
		if(que.size() == 3) que.pop();
	}
	if(dp[v] >= 0){
		dp[v] += edge[v].size(); if(v != 1) dp[v]--;
	}
	else{
		dp[v] = 1;
	}
	//cout << v << " " << dp[v] << endl;
	ans = max(ans,dp[v]);
	if(que.size() == 2){
		int sum = que.top(); que.pop(); sum += que.top(); que.pop();
		sum += edge[v].size()-1;
		//cout << sum << " " << v << endl;
		ans = max(ans,sum);
	}
	return;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		repn(i,n){ edge[i].clear(); dp[i] = 0; }
		rep(i,n-1){
			int a,b; scanf("%d%d",&a,&b);
			edge[a].pb(b);
			edge[b].pb(a);
		}
		ans = 0;
		dfs(1,-1);
		printf("%d\n",ans);
	}
}