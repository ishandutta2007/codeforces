#include <bits/stdc++.h>
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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[300005][2];
ll hoge[300005];
ll md[300005];
vector<int>edge[300005];
int n;
void dfs(int v,int u){
	bool in = 0;
	rep(i,edge[v].size()){
		int to = edge[v][i]; if(to == u) continue;
		dfs(to,v); in = 1;
	}
	if(!in){
		dp[v][0] = 1;
		dp[v][1] = 0;
		hoge[v] = 1;
	}
	else{
		dp[v][0] = 1;
		dp[v][1] = 0;
		ll pre = 1;
		rep(i,edge[v].size()){
			int to = edge[v][i]; if(to == u) continue;
			dp[v][0] = (dp[v][0]*(dp[to][0]+dp[to][1]))%mod;
			md[to] = pre;
			pre = pre*(dp[to][0]+2LL*dp[to][1])%mod;
		}
		pre = 1;
		for(int i=edge[v].size()-1;i>=0;i--){
			int to = edge[v][i]; if(to == u) continue;
			md[to] = md[to]*pre%mod;
			pre = pre*(dp[to][0]+2LL*dp[to][1])%mod;
		}
		rep(i,edge[v].size()){
			int to = edge[v][i]; if(to == u) continue;
			dp[v][1] += md[to]*hoge[to]%mod;
		}
		hoge[v] = 1;
		rep(i,edge[v].size()){
			int to = edge[v][i]; if(to == u) continue;
			hoge[v] = hoge[v]*(dp[to][0]+2LL*dp[to][1])%mod;
		}
		rep(i,2) dp[v][i] = (dp[v][i]%mod+mod)%mod;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}