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

const int nax = 1e5 + 10;
int t, n;
vi V[nax];
int val[nax][2];
ll dp[nax][2];

void dfs(int x, int p) {
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
	}
	for(int opt : {0, 1}) {
		dp[x][opt] = 0;
		for(int nbh : V[x]) if(nbh != p) {
			ll w = 0;
			for(int opt2 : {0, 1}) {
				w = max(w, dp[nbh][opt2] + abs(val[x][opt] - val[nbh][opt2]));
			}
			dp[x][opt] += w;
		}
	}
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) V[i].clear();
	for(int i = 1; i <= n; ++i) {
		cin >> val[i][0] >> val[i][1];
	}
	for(int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << "\n";
}
	

int main() {_
	cin >> t;
	while(t--) {
		solve();
	}
	
}