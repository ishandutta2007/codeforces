//https://codeforces.com/contest/461/submission/97151346
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n, dp[nax];
bool c[nax];
vi V[nax];
int ans[nax];

void dfs(int x, int p) {
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
		dp[x] += max(0, dp[nbh]);
	}
	if(!c[x]) dp[x]--;
	else dp[x]++;
}

void dfs2(int x, int p) {
	dp[x] = 0;
	//~ cout << x << ": \n";
	for(int nbh : V[x]) {
		dp[x] += max(dp[nbh], 0);
		//~ cout << nbh << " - " << dp[nbh] << "\n";
	}
	if(!c[x]) dp[x]--;
	else dp[x]++;
	ans[x] = dp[x];
	for(int nbh : V[x]) if(nbh != p) {
		int s = dp[x], w = dp[nbh];
		dp[x] -= max(0, dp[nbh]);
		dfs2(nbh, x);
		dp[nbh] = w;
		dp[x] = s;
	}
}

int main() {_
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
}