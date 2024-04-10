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
	int n = nxt(), l = nxt(), r = nxt();
	int ans = abs(r - l) / 2;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	if (l > r) {
		swap(l, r);
		reverse(all(a));
	}
	map<int, int> M;
	for (int i = 0; i < l; ++i) {
		M[a[i]] += 1;
	}
	ans += l;
	map<int, int> rem;
	for (int i = l; i < n; ++i) {
		if (auto it = M.find(a[i]); it != M.end()) {
			it->second -= 1;
			if (it->second == 0) {
				M.erase(it);
			}
			--ans;
		} else {
			rem[a[i]] += 1;
		}
	}
	int cnt = (r - l) / 2;
	for (auto p : rem) {
		cnt = max(0, cnt - p.second / 2);
	}
	ans += cnt;
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}