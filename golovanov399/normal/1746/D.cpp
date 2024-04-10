#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<vector<int>> a(n);
	for (int i = 1; i < n; ++i) {
		a[nxt() - 1].push_back(i);
	}
	vector<int> mn(n);
	vector<int> mx(n);
	mn[0] = mx[0] = k;
	function<void(int)> rec = [&](int v) {
		assert(mn[v] + 1 >= mx[v]);
		if (a[v].empty()) {
			return;
		}
		for (int x : a[v]) {
			mn[x] = mn[v] / a[v].size();
			mx[x] = (mx[v] + (int)a[v].size() - 1) / a[v].size();
			rec(x);
		}
	};
	rec(0);
	vector<long long> s(n);
	generate(all(s), nxt);
	vector<long long> dpmn(n), dpmx(n);
	function<void(int)> subsolve = [&](int v) {
		dpmn[v] = mn[v] * s[v];
		dpmx[v] = mx[v] * s[v];
		if ((int)a[v].empty()) {
			return;
		}
		for (int x : a[v]) {
			subsolve(x);
		}

		vector<long long> can_inc;
		long long tot = 0;
		for (int x : a[v]) {
			tot += dpmn[x];
			can_inc.push_back(dpmx[x] - dpmn[x]);
		}
		sort(all(can_inc));
		reverse(all(can_inc));

		if (mn[v] % (int)a[v].size() == 0) {
			for (int x : a[v]) {
				dpmn[v] += dpmn[x];
			}
		} else {
			int cnt = mn[v] % a[v].size();
			dpmn[v] += tot + accumulate(can_inc.begin(), can_inc.begin() + cnt, 0ll);
		}
		if (mx[v] % (int)a[v].size() == 0) {
			for (int x : a[v]) {
				dpmx[v] += dpmx[x];
			}
		} else {
			int cnt = mx[v] % a[v].size();
			dpmx[v] += tot + accumulate(can_inc.begin(), can_inc.begin() + cnt, 0ll);
		}
	};
	subsolve(0);
	cout << dpmx[0] << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}