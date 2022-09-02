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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[5005][5005][2],b,c[5005],d[5005];
int n,sub[5005];
vector<int>edge[5005];
void dfs(int v,int u){
	sub[v] = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]== u) continue;
		dfs(edge[v][i],v);
		sub[v] += sub[edge[v][i]];
	}
	for(int i=0;i<5005;i++){
		dp[v][i][0] = dp[v][i][1] = 1e18;
	}
	dp[v][0][0] = 0LL; dp[v][1][0] = c[v]; dp[v][1][1] = c[v]-d[v];
	int sum = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]==u) continue;
		//dp[v][][0] no koushin
		for(int j=sum+sub[edge[v][i]];j>=0;j--){
			for(int k=max(0,j-sum);k<=sub[edge[v][i]];k++){
				if(k>j) break;
				dp[v][j][0] = min(dp[v][j][0],dp[v][j-k][0]+dp[edge[v][i]][k][0]);
			}
		}
		//dp[v][][1] no koushin
		for(int j=sum+sub[edge[v][i]];j>=0;j--){
			for(int k=max(0,j-sum);k<=sub[edge[v][i]];k++){
				if(k>j) break;
				dp[v][j][1] = min(dp[v][j][1],dp[v][j-k][1]+min(dp[edge[v][i]][k][0],dp[edge[v][i]][k][1]));
			}
		}
		sum += sub[edge[v][i]];
	}//for(int i=0;i<=5;i++) cout << v << " " << dp[v][i][1] << endl;
}
int main(){
	scanf("%d%lld",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&c[i],&d[i]);
		if(i>1){
			int x; scanf("%d",&x);
			edge[x].pb(i);
			edge[i].pb(x);
		}
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		if(dp[1][i][0] > b && dp[1][i][1] > b){
			printf("%d\n",i-1);
			return 0;
		}
	}
	cout << n << endl;
}