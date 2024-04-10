#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n;
int fib[nax];
int f[60];
set<int> V[nax];
int dp[nax], par[nax];
vi vis = {};

void dfs(int x, int p) {
	dp[x] = 1;
	par[x] = p;
	vis.PB(x);
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
		dp[x] += dp[nbh];
	}
}

bool isf(int x) {
	vis.clear();
	dfs(x, 0);
	if(dp[x] == 1) return true;
	if(fib[dp[x]] == 0) return false;
	int ver = -1;
	for(int y : vis) {
		if(y != x && fib[dp[y]] != 0 && fib[(int)vis.size() - dp[y]] != 0) {
			ver = y;
		}
	}
	if(ver == -1) return false;
	V[ver].erase(par[ver]);
	V[par[ver]].erase(ver);
	int y = par[ver];
	return isf(ver) && isf(y);
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		V[a].insert(b);
		V[b].insert(a);
	}
	fib[1] = 1;
	f[0] = f[1] = 1;
	for(int i = 2; f[i - 1] + f[i - 2] <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		fib[f[i]] = i;
	}
	if(isf(1)) cout << "YES";
	else cout << "NO";
}