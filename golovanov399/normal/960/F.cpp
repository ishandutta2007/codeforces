#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int from;
	int to;
	int w;
	int id;

	bool operator <(const Edge& ot) const {
		return w < ot.w;
	}
};

const int N = 111111;
vector<Edge> a[N];

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n = 0): n(_n), a(_n) {}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res = max(res, a[pos]);
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	void chg(int pos, int x) {
		while (pos < n) {
			a[pos] = max(a[pos], x);
			pos |= pos + 1;
		}
	}
};

Fenwick fws[N];

int main() {
	int n = nxt(), m = nxt();
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[v].push_back({u, v, w, i});
		edges.push_back(a[v].back());
	}

	for (int i = 0; i < n; ++i) {
		sort(all(a[i]));
		fws[i] = Fenwick(a[i].size());
	}

	for (auto e : edges) {
		int u = e.from, v = e.to;
		auto it = lower_bound(all(a[u]), e);
		int to_relax = fws[u].get((int)(it - a[u].begin()) - 1) + 1;
		int pos = lower_bound(all(a[v]), e) - a[v].begin();
		fws[v].chg(pos, to_relax);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, fws[i].get(fws[i].n - 1));
	}

	printf("%d\n", ans);

	return 0;
}