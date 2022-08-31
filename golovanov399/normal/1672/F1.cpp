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
	int n = nxt();
	vector<int> a(n);
	vector<vector<int>> ps(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
		ps[a[i]].push_back(i);
	}
	sort(all(ps), [](const vector<int>& u, const vector<int>& v) {
		return u.size() > v.size();
	});
	int off = ps[0].size();
	vector<int> positions;
	for (const auto& v : ps) {
		positions.insert(positions.end(), all(v));
	}
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[positions[(i + off) % n]] = a[positions[i]] + 1;
	}
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}