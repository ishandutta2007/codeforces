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

struct Node {
	long long sum;
	long long max_pref;
	long long max_suf;
	long long max_subseg;
};

Node merge(const Node& a, const Node& b) {
	return {
		a.sum + b.sum,
		max(a.max_pref, a.sum + b.max_pref),
		max(a.max_suf + b.sum, b.max_suf),
		max({a.max_subseg, b.max_subseg, a.max_suf + b.max_pref}),
	};
}

void solve() {
	int n = nxt();
	const int nn = 1 << n;
	vector<int> a(nn);
	generate(all(a), nxt);
	vector<Node> nodes(nn);
	for (int i = 0; i < nn; ++i) {
		nodes[i] = {a[i], max(0, a[i]), max(0, a[i]), max(0, a[i])};
	}
	for (int len = 1; len < nn; len *= 2) {
		for (int start = 0; start < nn; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				auto a = nodes[start + i], b = nodes[start + len + i];
				nodes[start + i] = merge(a, b);
				nodes[start + len + i] = merge(b, a);
			}
		}
	}
	int x = 0;
	int q = nxt();
	while (q --> 0) {
		x ^= 1 << nxt();
		cout << nodes[x].max_subseg << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}