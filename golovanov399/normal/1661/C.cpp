#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<long long> a(n);
	generate(all(a), nxt);

	auto can = [&](long long d) {
		for (int par : {0, 1}) {
			long long num_odd = (d + 1) / 2;
			long long num_even = d / 2;
			long long mx = 0;
			for (auto x : a) {
				if (x % 2 != par) {
					--num_odd;
					++x;
				}
				mx = max(mx, x);
			}
			for (auto x : a) {
				long long need = mx - (x + (x % 2 != par));
				long long tmp = min(num_even, need / 2);
				need -= 2 * tmp;
				num_even -= tmp;
				num_odd -= need;
			}
			if (num_even >= 0 && num_odd >= 0) {
				return true;
			}
		}
		return false;
	};

	long long l = -1, r = 1e18;
	while (r > l + 1) {
		auto m = (l + r) / 2;
		(can(m) ? r : l) = m;
	}
	cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}