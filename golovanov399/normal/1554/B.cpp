#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

void add(pair<int, int>& p, int x) {
	if (x > p.first) {
		p.second = p.first;
		p.first = x;
	} else if (x > p.second) {
		p.second = x;
	}
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> val(n);
	generate(all(val), nxt);
	int nn = 1 << (32 - __builtin_clz(n + 1));
	vector<pair<int, int>> a(nn, {-1, -1});
	for (int i = 0; i < n; ++i) {
		add(a[val[i]], i + 1);
	}
	for (int l = 1; l < nn; l *= 2) {
		for (int mask = l; mask < nn; mask = (mask + 1) | l) {
			add(a[mask], a[mask ^ l].first);
			add(a[mask], a[mask ^ l].second);
		}
	}
	long long ans = LLONG_MIN;
	for (int i = 0; i < nn; ++i) {
		if (a[i].second > -1) {
			ans = max(ans, 1ll * a[i].first * a[i].second - k * i);
		}
	}
	cout << ans << "\n";
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