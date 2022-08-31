#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> p(n);
	generate(all(p), nxt);
	p.insert(p.begin(), n + 1);
	p.insert(p.begin(), 0);
	map<pair<int, int>, int> M;
	function<int(int, int)> f = [&](int last_incr, int last_decr) {
		int i = max(last_incr, last_decr) + 1;
		if (i == (int)p.size()) {
			return i;
		}
		if (p[i] < p[last_incr] && p[i] > p[last_decr]) {
			return i;
		}
		if (auto it = M.find({last_incr, last_decr}); it != M.end()) {
			return it->second;
		}
		if (p[i] > p[last_incr] && p[i] < p[last_decr]) {
			if (i + 1 == (int)p.size()) {
				return i + 1;
			} else {
				return M[{last_incr, last_decr}] = (p[i + 1] > p[i]) ? f(i, last_decr) : f(last_incr, i);
			}
		}
		if (p[i] > p[last_incr]) {
			return M[{last_incr, last_decr}] = f(i, last_decr);
		} else {
			return M[{last_incr, last_decr}] = f(last_incr, i);
		}
	};
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			ans += 1;
		} else if (p[i + 2] < p[i + 3]) {
			ans += f(i + 2, 1) - (i + 2);
		} else {
			ans += f(0, i + 2) - (i + 2);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}