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

const int nax = 100 * 1000 + 10, mod = 1e9 + 7;
int n, dp[nax][2];
bool c[nax];
vi V[nax];
int suf[nax], pref[nax];

void dfs(int x) {
	for(int nbh : V[x]) {
		dfs(nbh);
	}
	if(c[x] == 1) {
		dp[x][0] = 0;
		dp[x][1] = 1;
		for(int nbh : V[x]) {
			dp[x][1] = (1LL * dp[x][1] * (dp[nbh][1] + dp[nbh][0])) % mod;
		}
	} else {
		dp[x][0] = 1;
		dp[x][1] = 0;
		int w = 1;
		pref[0] = 1;
		for(int nbh : V[x]) {
			dp[x][0] = (1LL * dp[x][0] * (dp[nbh][1] + dp[nbh][0])) % mod;
			pref[w++] = dp[x][0];
		}
		//cout << dp[x][0] << "\n";
		ll cur = 1;
		for(int i = (int)V[x].size() - 1; i >= 0; --i) {
			dp[x][1] = (dp[x][1] + (ll)((ll)pref[i] * cur % mod) * dp[V[x][i]][1]) % mod;
			cur = (cur * (dp[V[x][i]][1] + dp[V[x][i]][0])) % mod;
		}
	}
}

int main() {_
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		V[a].PB(i);
	}
	for(int i = 0; i < n; ++i) cin >> c[i];
	dfs(0);
	cout << dp[0][1];
}