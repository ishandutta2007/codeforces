#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int L = 30;

struct Trie {
	struct Node {
		array<int, 2> to;

		Node(): to({-1, -1}) {}
	};

	vector<Node> a;

	Trie(): a(1) {}

	int new_node() {
		a.push_back(Node());
		return (int)a.size() - 1;
	}

	void add(int x) {
		int v = 0;
		for (int i = L - 1; i >= 0; --i) {
			int b = !!(x & (1 << i));
			if (!~a[v].to[b]) {
				int x = new_node();
				a[v].to[b] = x;
			}
			v = a[v].to[b];
		}
	}

	int best(int x) const {
		int res = 0;
		int v = 0;
		for (int i = L - 1; i >= 0; --i) {
			int b = !!(x & (1 << i));
			b ^= 1;
			if (!~a[v].to[b]) {
				b ^= 1;
			}
			v = a[v].to[b];
			res |= b << i;
		}
		return res;
	}
};

void solve() {
	int n = nxt(), k = nxt();
	if (k == 0) {
		if (n == 1) {
			cout << "-1\n";
			return;
		}
		cout << n << "\n";
		for (int i = 0; i < n; ++i) {
			cout << i + 1 << " ";
		}
		cout << "\n";
		return;
	}
	map<int, int> idx;
	const int b = 1 << (31 - __builtin_clz(k));
	map<int, vector<int>> M;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		M[x / b / 2].push_back(x);
		idx[x] = i;
	}
	vector<int> ans;
	for (const auto& p : M) {
		const auto& vec = p.second;
		vector<int> by_bit[2];
		for (int x : vec) {
			by_bit[!!(x & b)].push_back(x);
		}
		if (by_bit[0].empty()) {
			ans.push_back(by_bit[1][0]);
		} else if (by_bit[1].empty()) {
			ans.push_back(by_bit[0][0]);
		} else {
			Trie trie;
			for (int x : by_bit[0]) {
				trie.add(x);
			}
			bool ok = false;
			for (int x : by_bit[1]) {
				int y = trie.best(x);
				if ((x ^ y) >= k) {
					ok = true;
					ans.push_back(x);
					ans.push_back(y);
					break;
				}
			}
			if (!ok) {
				ans.push_back(by_bit[0][0]);
			}
		}
	}
	if ((int)ans.size() <= 1) {
		cout << "-1\n";
		return;
	}
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << idx[x] + 1 << " ";
	}
	cout << "\n";
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}