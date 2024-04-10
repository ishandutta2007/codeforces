#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Dsu {
	int n;
	vector<int> a, color;
	vector<vector<int>> vers;

	Dsu(int _n): n(_n), a(_n), color(_n), vers(_n) {
		for (int i = 0; i < n; ++i) {
			vers[i] = {i};
			color[i] = i;
		}
	}

	bool merge(int u, int v, int x) {
		int c_u = color[u];
		int c_v = color[v];
		if (c_u == c_v) {
			return false;
		}

		if (vers[c_u].size() < vers[c_v].size()) {
			swap(u, v);
			swap(c_u, c_v);
		}

		int y = a[u] ^ a[v] ^ x;
		for (int ver : vers[c_v]) {
			vers[c_u].push_back(ver);
			a[ver] ^= y;
			color[ver] = c_u;
		}
		vers[c_v].clear();
		return true;
	}

	int get(int u, int v) {
		if (color[u] != color[v]) {
			return -1;
		} else {
			return a[u] ^ a[v];
		}
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int q = nxt();
	map<int, int> enc;
	auto getEnc = [&](int x) {
		auto it = enc.find(x);
		if (it != enc.end()) {
			return it->second;
		} else {
			int sz = enc.size();
			return enc[x] = sz;
		}
	};
	Dsu dsu(2 * q);
	int last = 0;
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int l = nxt(), r = nxt(), x = nxt();
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r) {
				swap(l, r);
			}
			r += 1;
			l = getEnc(l);
			r = getEnc(r);
			dsu.merge(l, r, x);
		} else {
			int l = nxt(), r = nxt();
			l ^= last;
			r ^= last;
			if (l > r) {
				swap(l, r);
			}
			r += 1;
			l = getEnc(l);
			r = getEnc(r);
			last = dsu.get(l, r);
			printf("%d\n", last);
			if (last == -1) {
				last = 1;
			}
		}
	}

	return 0;
}