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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[105][25][25];
int n,a;
vector<int>edge[105];
void dfs(int v,int u){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
	}
	ll DP[2][25][25]={};
	DP[0][a+1][0] = 1; DP[0][0][a+1] = 1;
	int cur = 0,nxt = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		rep(j,25) rep(k,25) DP[nxt][j][k] = 0;
		rep(j,25){ rep(k,25){
			if(j>a+1 || k>a+1) continue;
			rep(p,25){ rep(q,25){
				if(p>a+1 || (q>a+1||q==a)) continue;
				//DP[cur][j][k] + dp[edge[v][i]][p][q]
				int c1 = min(a+1,min(j,p+1));
				int c2 = a+1;
				if(q != a+1 && q+1+j > a){
					c2 = q+1;
				}
				if(k != a+1 && p+1+k > a){
					if(c2 == a+1) c2 = k;
					else c2 = max(c2,k);
				}
				DP[nxt][c1][c2] += DP[cur][j][k]*dp[edge[v][i]][p][q]%mod;
				DP[nxt][c1][c2] %= mod;
			}}
		}}
		swap(cur,nxt);
	}
	rep(j,25) rep(k,25) dp[v][j][k] = DP[cur][j][k];
//cout << dp[v][0][0] << " " << dp[v][0][1] << " " << dp[v][1][0] << " " << dp[v][1][1] << endl;
}
int main(){
	cin >> n >> a;
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	ll ret = 0;
	for(int i=0;i<25;i++) ret = (ret+dp[1][i][a+1])%mod;
	cout << ret << endl;
}