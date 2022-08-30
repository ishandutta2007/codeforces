#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define repn(i, n) for(int i=1;i<=n;i++)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vector<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
const int INF = 1000000000;

vector<int>edge[100005];
int n, dp[2][100005], ans;
void dfs(int v, int u){
	dp[0][v] = si(edge[v]) - 2;
	dp[1][v] = 1;
	priority_queue<int, vector<int>, greater<int>>que[2];
	int add0 = -INF, add1 = -INF;
	rep(i, edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i], v);
		int S = si(edge[edge[v][i]]) - 1;
		int Z = dp[0][edge[v][i]];
		int O = dp[1][edge[v][i]];
		chmax(add0, max(S, max(Z, O)));
		chmax(add1, max(S, Z));
		
		que[0].push(max(S, max(Z, O)));
		que[1].push(max(S, Z));
		if(que[0].size() == 3) que[0].pop();
		if(que[1].size() == 3) que[1].pop();
	}
	dp[0][v] += add0;
	dp[1][v] += add1;
	chmax(ans, dp[0][v] + 1);
	
	rep(j, 2){
		if(que[j].size() != 2) continue;
		int vv = 0;
		while(que[j].size()){
			vv += que[j].top(); que[j].pop();
		}
		if(j == 0) vv += si(edge[v]) - 2;
		else vv += 1;
		chmax(ans, vv);
	}
	
	//cout << v << " " << dp[0][v] << " " << dp[1][v] << endl;
}
void solve(){
	cin >> n;
	rep(i, n-1){
		int a, b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1, -1);
	rng(i, 1, n+1) chmax(ans, si(edge[i]));
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	solve();
}