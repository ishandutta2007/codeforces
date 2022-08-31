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

struct Dsu {
	int n;
	vector<int> p, rk, cool;

	Dsu(int _n): n(_n), p(_n), rk(_n), cool(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool is_cool(int v) {
		return cool[get(v)];
	}

	void make_cool(int v) {
		cool[get(v)] = 1;
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v || (cool[u] && cool[v])) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		cool[u] |= cool[v];
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	Dsu dsu(m);
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		if (k == 1) {
			int v = nxt() - 1;
			if (!dsu.is_cool(v)) {
				ans.push_back(i + 1);
				dsu.make_cool(v);
			}
		} else {
			int u = nxt() - 1, v = nxt() - 1;
			if (dsu.merge(u, v)) {
				ans.push_back(i + 1);
			}
		}
	}
	int cn = 1;
	for ([[maybe_unused]] auto _ : ans) {
		cn = cn * 2 % 1'000'000'007;
	}
	cout << cn << " " << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}