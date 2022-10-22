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
int t, n;
vi V[nax];
int h[nax];

void dfs(int x, int p) {
	h[x] = 0;
	for(auto nbh : V[x]) if(nbh != p) {
		dfs(nbh, x);
		h[x] = max(h[x], h[nbh] + 1);
	}
	if(h[x] == 1) {
		h[x] = -1;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			V[i].clear();
		}
		for(int u,v, i = 1; i < n; ++i) {
			cin >> u >> v;
			V[u].PB(v);
			V[v].PB(u);
		}
		int l = 0;
		dfs(1, 0);
		bool any = false;
		for(int nbh : V[1]) {
			if(h[nbh] != -1) {
				any = true;
			}
		}
		int cnt = 0;
		for(int i = 2; i <= n; ++i) {
			cnt += (h[i] == -1);
			l += (h[i] == 0);
		}
		//cout << "\n";
		cout << l - cnt + (1 - any) << "\n";
	}
}