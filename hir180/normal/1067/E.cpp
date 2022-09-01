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
ll dp[500005];;
ll bin[500005];
int n;
vector<int>edge[500005];
int cnt[500005];
ll ans;
void dfs(int v,int u){
	cnt[v] = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
		cnt[v] += cnt[edge[v][i]];
	}
	dp[v] = 1;
	int cur = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]==u) continue;
		int sz = cnt[edge[v][i]];
		cur += sz;
		ans += dp[v]*dp[edge[v][i]]%mod*bin[n-cur]%mod;
		dp[v] *= bin[sz]-dp[edge[v][i]];
		dp[v] %= mod;
	}
}
int main(){
	bin[0] = 1;
	for(int i=1;i<500005;i++) bin[i]=bin[i-1]*2LL%mod;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	cout<<(2LL*ans%mod+mod)%mod<<endl;
}