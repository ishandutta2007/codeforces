#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
	}
	const int thres = n / 3;
	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		int need = (i - p[i] + n) % n;
		cnt[need] += 1;
	}
	vector<int> ans;
	for (int shift = 0; shift < n; ++shift) {
		if (cnt[shift] < thres) {
			continue;
		}
		vector<int> q(n);
		for (int i = 0; i < n; ++i) {
			q[i] = (p[i] + shift) % n;
		}
		vector<char> used(n);
		int ops = n;
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			--ops;
			for (int x = i; !used[x]; x = q[x]) {
				used[x] = 1;
			}
		}
		if (ops <= m) {
			ans.push_back(shift);
		}
	}
	cout << ans.size();
	for (int x : ans) {
		cout << " " << x;
	}
	cout << "\n";
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