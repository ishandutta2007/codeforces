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
int n;
vi V[nax];
int dp[nax];


int fastpow(int a, int b) {
	int w = 1;
	while(b > 0) {
		if(b&1) {
			w = ((ll)w * a) % mod;
		}
		b /= 2;
		a = ((ll)a * a) % mod;
	}
	return w;
}


void dfs(int x, int p) {
	int s0 = 1;
	bool any = false;
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
		s0 = ((ll)s0 * dp[nbh]) % mod;
		any = true;
	}
	dp[x] = s0;
	if(any) dp[x] = (2 * dp[x]) % mod;
}

int ans;

void dfs2(int x, int p) {
	ans = (ans + dp[x]) % mod;
	for(int nbh : V[x]) if(nbh != p) {
		int tmp = dp[nbh], tmp2 = dp[x];
		dp[x] = ((ll)dp[x] * fastpow(tmp, mod - 2)) % mod;
		//cout << dp[x] << " " << fastpow(2, mod - 2) << "\n";
		if((int)V[x].size() == 1) {
			dp[x] = ((ll)dp[x] * fastpow(2, mod - 2)) % mod;
		}
		//cout << dp[x] << "\n";
		dp[nbh] = (ll)dp[nbh] * dp[x] % mod;
		if((int)V[nbh].size() == 1) dp[nbh] = 2 * dp[nbh] % mod;
		dfs2(nbh, x);
		dp[x] = tmp2;
		dp[nbh] = tmp;
	}
}

int main() {_
	cin >> n;
	for(int u,v,i = 1; i < n; ++i) {
		cin >> u >> v;
		V[u].PB(v);
		V[v].PB(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	cout << ans;
}