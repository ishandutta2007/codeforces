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

struct Node {
	int sum, mi;
};

const int nax = 1e5 + 10;
int t, n, m;
Node T[(1 << 18)];
int R;
int val[nax];
vi g[nax];
ll s[nax];

void add(int a, int x) {
	a = 100000 - a;
	a += R;
	T[a].sum += x;
	T[a].mi = min(0, T[a].sum);
	while(a > 1) {
		a /= 2;
		T[a].sum = T[a<<1].sum + T[a << 1 | 1].sum;
		T[a].mi = min(T[a << 1].mi, T[a << 1].sum + T[a << 1 | 1].mi);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	R = (1 << 17);
	while(t--) {
		cin >> n >> m;
		for(int i = 0; i < n; ++i) {
			cin >> val[i];
			add(val[i], 1);
		}
		for(int i = 0; i < m; ++i) {
			s[i] = 0;
			g[i].clear();
			int k;
			cin >> k;
			for(int j = 0; j < k; ++j) {
				int x;
				cin >> x;
				g[i].PB(x);
				s[i] += x;
			}
			add((s[i] - 1) / k + 1, -1);
		}
		for(int i = 0; i < m; ++i) {
			int k = (int)g[i].size();
			add((s[i]-1) / k + 1, 1);
			for(int j = 0; j < k; ++j) {
				add((s[i] - g[i][j] - 1) / (k - 1) + 1, -1);
				if(T[1].mi >= 0) {
					cout << "1";
				} else {
					cout << "0";
				}
				add((s[i] - g[i][j] - 1) / (k - 1) + 1, 1);
			}
			add((s[i] - 1) / k + 1, -1);
		}
		for(int i = 0; i < m; ++i) {
			add((s[i] - 1) / (int)g[i].size() + 1, 1);
		}
		for(int i = 0; i < n; ++i) {
			add(val[i], -1);
		}
		cout << "\n";
	}
}