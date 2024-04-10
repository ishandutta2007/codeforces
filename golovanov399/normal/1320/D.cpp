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
	scanf("%d", &x);
	return x;
}

struct State {
	int len;
	int link;
	array<int, 2> to;

	State(): len(0), link(-1) {
		to.fill(-1);
	}

	State(int _len, int _link): len(_len), link(_link) {
		to.fill(-1);
	}

	bool has(int c) const {
		return to[c] > -1;
	}
};

struct SA {
	vector<State> a;
	int cur;

	SA(): a(1), cur(0) {}

	void add(int c) {
		int nw = a.size();
		a.emplace_back(a[cur].len + 1, -1);
		while (cur >= 0) {
			if (!a[cur].has(c)) {
				a[cur].to[c] = nw;
				cur = a[cur].link;
			} else {
				break;
			}
		}
		if (cur == -1) {
			a[nw].link = 0;
			cur = nw;
			return;
		}

		int by_c = a[cur].to[c];
		if (a[by_c].len == a[cur].len + 1) {
			a[nw].link = by_c;
		} else {
			int clone = a.size();
			auto st = a[by_c];
			a.push_back(st);
			a[clone].len = a[cur].len + 1;
			a[by_c].link = clone;
			a[nw].link = clone;
			while (cur > -1 && a[cur].to[c] == by_c) {
				a[cur].to[c] = clone;
				cur = a[cur].link;
			}
		}
		cur = nw;
	}

	void add(const vector<int>& v) {
		for (int c : v) {
			add(c);
		}
	}

	void show() {
		for (int i = 0; i < (int)a.size(); ++i) {
			cerr << "State #" << i << ": len = " << a[i].len << ", link = " << a[i].link << ";";
			for (int c : {0, 1}) {
				if (a[i].to[c] > -1) {
					cerr << " transition to " << a[i].to[c] << " by " << c << ",";
				}
			}
			cerr << "\n";
		}
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	string s;
	cin >> s;
	vector<int> zeroes;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			zeroes.push_back(i);
		}
	}
	vector<int> normal, flipped;
	for (int i : zeroes) {
		normal.push_back(i % 2);
		flipped.push_back((i + 1) % 2);
	}
	vector<int> a = normal;
	a.insert(a.end(), all(flipped));
	SA sa;
	sa.add(a);
	// sa.show();
	n = (int)a.size();

	int sz = sa.a.size();
	vector<vector<int>> sons(sz);
	vector<vector<int>> par(sz);
	for (int i = 1; i < sz; ++i) {
		sons[sa.a[i].link].push_back(i);
		par[i].push_back(sa.a[i].link);
	}
	for (int i = 0;; ++i) {
		bool changed = false;
		for (int v = 0; v < sz; ++v) {
			if ((int)par[v].size() <= i) {
				continue;
			}
			if ((int)par[par[v][i]].size() <= i) {
				continue;
			}
			changed = true;
			int nw = par[par[v][i]][i];
			par[v].push_back(nw);
		}
		if (!changed) {
			break;
		}
	}
	vector<int> tin(sz), tout(sz);
	int timer = 0;
	function<void(int)> dfs = [&](int v) {
		tin[v] = timer++;
		for (int x : sons[v]) {
			dfs(x);
		}
		tout[v] = timer;
	};
	dfs(0);

	auto isPar = [&](int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	vector<int> nth_suf(n + 1);
	for (int i = 0; i < n; ++i) {
		nth_suf[i + 1] = sa.a[nth_suf[i]].to[a[i]];
	}

	auto lca = [&](int u, int v) {
		if (isPar(v, u)) {
			return v;
		}
		for (int i = (int)par[v].size() - 1; i >= 0; --i) {
			if (i >= (int)par[v].size()) {
				continue;
			}
			if (!isPar(par[v][i], u)) {
				v = par[v][i];
			}
		}
		return par[v][0];
	};

	int q = nxt();
	while (q--) {
		int l1 = nxt() - 1, l2 = nxt() - 1, len = nxt();
		int real_l1 = lower_bound(all(zeroes), l1) - zeroes.begin();
		int real_r1 = lower_bound(all(zeroes), l1 + len) - zeroes.begin();
		int real_l2 = lower_bound(all(zeroes), l2) - zeroes.begin();
		int real_r2 = lower_bound(all(zeroes), l2 + len) - zeroes.begin();
		len = real_r1 - real_l1;
		if (len != real_r2 - real_l2) {
			puts("No");
			continue;
		}
		if (len == 0) {
			puts("Yes");
			continue;
		}
		real_l1 += l1 % 2 * (int)zeroes.size();
		real_l2 += l2 % 2 * (int)zeroes.size();
		// cerr << real_l1 << " " << real_r1 << " " << real_l2 << " " << real_r2 << "\n";
		int u = nth_suf[real_l1 + len];
		int v = nth_suf[real_l2 + len];
		int l = lca(u, v);
		puts(sa.a[l].len >= len ? "Yes" : "No");
	}

	return 0;
}