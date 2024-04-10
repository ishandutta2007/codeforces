#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const ll INF = 1e15;
vector<int> adj[200020];
int dp[200020][2];
ll dp2[200020][2];

void dfs(int now, int par){
	int c0 = 0, c1 = 1;
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs(nxt, now);
		c0 += max(dp[nxt][0], dp[nxt][1]);
		c1 += dp[nxt][0];
	}
	dp[now][0] = c0; dp[now][1] = c1;
	//cout << "DP " << now << " = " << dp[now][0] << ' ' << dp[now][1] << endl;
}

void dfs2(int now, int par){
	ll s0 = 1, s1 = adj[now].size();
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs2(nxt, now);
		ll val;
		if (dp[nxt][0] > dp[nxt][1]){ val = dp2[nxt][0]; }
		else if (dp[nxt][0] < dp[nxt][1]){ val = dp2[nxt][1]; }
		else{ val = min(dp2[nxt][0], dp2[nxt][1]); }
		s0 += val;
		s1 += dp2[nxt][0];
	}
	dp2[now][0] = s0; dp2[now][1] = s1;
	//cout << "DP2 " << now << " = " << dp2[now][0] << ' ' << dp2[now][1] << endl;
}

int ans[200020];
void dfs3(int now, bool chk, int par){
	if (chk == 0){ ans[now] = 1; }
	else if (dp[now][0] > dp[now][1]){ ans[now] = 1; }
	else if (dp[now][0] < dp[now][1]){ ans[now] = adj[now].size(); }
	else{
		if (dp2[now][0] < dp2[now][1]){ ans[now] = 1; }
		else{ ans[now] = adj[now].size(); }
	}
	bool c = ans[now] != adj[now].size();
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs3(nxt, c, now);
	}
}

void Main(){
	int n; cin >> n;
	if (n == 2){ cout << 2 << ' ' << 2 << endl << 1 << ' ' << 1 << endl; return; }
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1); dfs2(1, -1);
	ll val;
	if (dp[1][0] > dp[1][1]){ val = dp2[1][0]; }
	else if (dp[1][0] < dp[1][1]){ val = dp2[1][1]; }
	else{ val = min(dp2[1][0], dp2[1][1]); }
	cout << max(dp[1][0], dp[1][1]) << ' ' << val << endl;
	dfs3(1, 1, -1);
	for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}