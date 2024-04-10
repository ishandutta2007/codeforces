#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,pair<double,double> > P2;
typedef pair<pair<double,double>,P> P3;
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
ll dp[105][105][105],c[105][105],ans[105],DP[105][105];
int n;
vector<int>edge[105];
int sub[105],curr;
void dfs(int v,int u){
	sub[v] = 1;
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
		sub[v] += sub[edge[v][i]];
	}
	ll t[105][105][2]={};
	int cur = 0,nxt = 1;
	t[1][0][0] = 1;
	int c = 1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		int to = edge[v][i];
		rep(j,sub[to]+c+1)rep(k,curr+1) t[j][k][nxt] = 0;
		repn(j,c){int e=min(curr,c-j);rep(k,e+1){
			if(!t[j][k][cur]) continue;
			rep(b,sub[to]+1){
				t[j][k+b+1][nxt] += t[j][k][cur]*DP[to][b]%mod;
				rep(a,sub[to]+1){
					if(!dp[to][a][b]) continue;
					ll x = t[j][k][cur] * dp[to][a][b] % mod;
					//cut
					//t[j][k+b+1][nxt] += x * a;
					//not cut
					t[j+a][k+b][nxt] += x ;
				}
			}
		}}
		c += sub[edge[v][i]];
		repn(j,c){int e=min(curr,c-j);rep(k,e+1) if(t[j][k][nxt] >= mod) t[j][k][nxt] %= mod;}
		swap(cur,nxt);
	}
	rep(i,105)rep(j,105){
		dp[v][i][j] = t[i][j][cur];
		DP[v][j] = (DP[v][j]+dp[v][i][j]*1LL*i%mod)%mod;
	}
}
//I was just stupid. Sorry.
int main(){
	scanf("%d",&n); curr=n;
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	rep(i,105)rep(j,i+1){
		if(j==0 || j==i) c[i][j]=1;
		else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	dfs(1,-1);
	ans[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(dp[1][j][n-i-1] == 0) continue;
			ll sum = 1LL*j*dp[1][j][n-i-1]%mod;
			ans[i] += sum;
		}
		ans[i] %= mod;
		for(int j=0;j<(n-i-2);j++) ans[i] = ans[i]*n%mod;
		for(int j=i+1;j<=n-1;j++){
			ans[i] = (ans[i]+mod-ans[j]*c[j][i]%mod)%mod;
		}
	}
	for(int i=0;i<n;i++) printf("%lld ",ans[i]);
	puts("");
}