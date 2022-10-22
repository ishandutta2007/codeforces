#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int MAXN = 1e5 + 10;
int n, d, h1;
vector<int> g[MAXN];
vector<int> h;

void dfs(int v, int p) {
	for (auto i : g[v]) {
		if (i == p) continue;
		h[i] = h[v] + 1;
		dfs(i, v);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	cin >> n >> d >> h1;
	for (int i = 2; i <= h1 + 1; i++) {
		g[i - 1].push_back(i);
		g[i].push_back(i - 1);
		//cout << i - 1 << " " << i << "\n";
	}
	for (int i = h1 + 2; i <= d + 1; i++) {
		if (i == h1 + 2) {
		//	cout << 1 << " " << i << "\n";
			g[1].push_back(i);
			g[i].push_back(1);
		} else {
			//cout << i - 1 << " " << i << "\n";
			g[i - 1].push_back(i);
			g[i].push_back(i - 1);
		}
	}
	for (int i = d + 2; i <= n; i++) {
		//cout << 2 << " " << i << "\n";
		if (d == h1) {
			g[2].push_back(i);
			g[i].push_back(2);
		} else {
			g[1].push_back(i);
			g[i].push_back(1);
		}
	}
	h.assign(n + 1, 0);
	dfs(1, 1);
	int myH = *max_element(all(h));
	int pos = max_element(all(h)) - h.begin();
	h.assign(n + 1, 0);
	dfs(pos, pos);
	if (*max_element(all(h)) == d && myH == h1) {
		for (int i = 1; i <= n; i++) {
			for (auto j : g[i]) {
				if (i < j) {
					cout << i << " " << j << "\n";
				}
			}
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}