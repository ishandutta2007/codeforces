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

struct Node {
	int mx[2];
	int to[2];

	Node() {
		memset(mx, 0, sizeof(mx));
		memset(to, -1, sizeof(to));
	}
};

void remax(int& x, int y) {
	x = (x > y) ? x : y;
}

const int L = 30;

struct Trie {
	vector<Node> a;

	Trie(): a(1) {}

	void update(int x, int idx, int val) {
		int v = 0;
		for (int i = L - 1; i >= 0; --i) {
			int b = !!(x & (1 << i));
			if (a[v].to[b] == -1) {
				a[v].to[b] = a.size();
				a.emplace_back();
			}
			v = a[v].to[b];
			remax(a[v].mx[!!(idx & (1 << i))], val);
		}
	}

	int get(int x, int idx) const {
		int res = 0;
		int v = 0;
		for (int i = L - 1; i >= 0; --i) {
			int b = !!(x & (1 << i));
			if (a[v].to[!b] != -1) {
				remax(res, a[a[v].to[!b]].mx[!((x ^ idx) & (1 << i))]);
			}
			if (a[v].to[b] == -1) {
				break;
			}
			v = a[v].to[b];
		}
		return res;
	}
};

void solve() {
	int n = nxt();
	int ans = 0;
	Trie trie;
	for (int i = 0; i < n; ++i) {
		int x = nxt() ^ i;
		int val = trie.get(x, i) + 1;
		remax(ans, val);
		trie.update(x, i, val);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}