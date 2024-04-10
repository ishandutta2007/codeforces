#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Comp {
	vector<int> ids;
	bool flipped;
	int total;
	bool is_fixed;
};

struct Dsu {
	int n;
	vector<Comp> by_color;
	vector<int> color;
	vector<int> st;
	int ans;

	Dsu(int _n): n(_n), color(_n), st(_n) {
		iota(all(color), 0);
		by_color.resize(n);
		for (int i = 0; i < n; ++i) {
			by_color[i] = {{i}, false, 0, false};
		}
		ans = 0;
	}

	void merge(int u, int v, int diff) {
		if (color[u] == color[v]) {
			assert(!(st[u] ^ st[v] ^ diff));
			return;
		}

		int cu = color[u];
		int cv = color[v];
		if (by_color[cu].ids.size() < by_color[cv].ids.size()) {
			swap(u, v);
			swap(cu, cv);
		}
		ans -= by_color[cu].total;
		ans -= by_color[cv].total;

		if (st[u] ^ st[v] ^ diff ^ by_color[cu].flipped ^ by_color[cv].flipped) {
			int ans_inc_u = (int)by_color[cu].ids.size() - 2 * by_color[cu].total;
			int ans_inc_v = (int)by_color[cv].ids.size() - 2 * by_color[cv].total;
			assert(!by_color[cu].is_fixed || !by_color[cv].is_fixed);
			if (by_color[cu].is_fixed) {
				by_color[cv].is_fixed = true;
				for (int x : by_color[cv].ids) {
					st[x] ^= 1;
				}
				by_color[cv].total = (int)by_color[cv].ids.size() - by_color[cv].total;
			} else if (by_color[cv].is_fixed) {
				by_color[cu].is_fixed = true;
				by_color[cu].flipped ^= 1;
				by_color[cu].total = (int)by_color[cu].ids.size() - by_color[cu].total;
			} else {
				if (ans_inc_v < ans_inc_u) {
					for (int x : by_color[cv].ids) {
						st[x] ^= 1;
					}
					by_color[cv].total = (int)by_color[cv].ids.size() - by_color[cv].total;
				} else {
					by_color[cu].flipped ^= 1;
					by_color[cu].total = (int)by_color[cu].ids.size() - by_color[cu].total;
				}
			}
		} else {
			if (by_color[cu].is_fixed || by_color[cv].is_fixed) {
				by_color[cu].is_fixed = by_color[cv].is_fixed = true;
			}
		}

		for (int x : by_color[cv].ids) {
			if (by_color[cu].flipped != by_color[cv].flipped) {
				st[x] ^= 1;
			}
			color[x] = cu;
			by_color[cu].ids.push_back(x);
		}
		by_color[cu].total += by_color[cv].total;
		by_color[cv].ids.clear();
		by_color[cv].ids.shrink_to_fit();

		ans += by_color[cu].total;
	}

	void colour(int v, int x) {
		int col = color[v];
		if (st[v] ^ x ^ by_color[col].flipped) {
			ans -= by_color[col].total;
			by_color[col].flipped ^= 1;
			by_color[col].total = (int)by_color[col].ids.size() - by_color[col].total;
			ans += by_color[col].total;
		}
		by_color[col].is_fixed = true;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	vector<char> state(n);
	for (int i = 0; i < n; ++i) {
		state[i] = s[i] - '0' ? 0 : 1;
	}
	vector<vector<int>> a(n);
	for (int i = 0; i < k; ++i) {
		int c = nxt();
		while (c--) {
			a[nxt() - 1].push_back(i);
		}
	}

	Dsu dsu(k);
	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() == 1) {
			dsu.colour(a[i][0], state[i]);
		} else if ((int)a[i].size() == 2) {
			dsu.merge(a[i][0], a[i][1], state[i]);
		}
		cout << dsu.ans << "\n";
	}

	return 0;
}