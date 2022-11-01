#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

const int MOD = 1e9 + 9;

mt19937 rnd(time(nullptr));

vector<int> dsu;

int get(int v) {
	if (v == dsu[v]) {
		return v;
	} else {
		return dsu[v] = get(dsu[v]);
	}
}

bool merge(int u, int v) {
	u = get(u);
	v = get(v);
	dsu[u] = v;
	return u == v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	dsu.resize(n);
	iota(dsu.begin(), dsu.end(), 0);
	int ans = 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (merge(u, v)) {
			ans *= 2;
		}
		ans %= MOD;
		cout << (ans + MOD - 1) % MOD << '\n';
	}
	return 0;
}