#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const long long inf = 1e18;

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n = 0): n(_n) {
		a.resize(n);
	}

	void add(int pos, int x = 1) {
		while (pos < n) {
			a[pos] += x;
			pos |= (pos + 1);
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		return get(r - 1) - get(l - 1);
	}
};

struct Shit {
	set<pair<long long, pair<int, int>>> remins;
	Fenwick used;

	Shit(int n, int s) {
		used = Fenwick(n);
		remins.insert({0, {s, s + 1}});
	}

	void forbid(int pos) {
		used.add(pos);
	}

	void remin(int l, int r, long long what) {
		remins.insert({what, {l, r}});
	}

	pair<long long, int> getmin() {
		while (!remins.empty()) {
			auto it = remins.begin();
			if (used.get(it->second.first, it->second.second) == it->second.second - it->second.first) {
				remins.erase(it);
			} else {
				int l = it->second.first, r = it->second.second;
				while (r > l + 1) {
					int mid = (l + r) / 2;
					if (used.get(l, mid) == mid - l) {
						l = mid;
					} else {
						r = mid;
					}
				}
				return {it->first, l};
			}
		}
		return {-1, -1};
	}
};

struct PlanCollection {
	int n;
	vector<set<int>> tree;

	PlanCollection(int nn) {
		n = 1;
		while (n < nn) {
			n *= 2;
		}
		tree.resize(n + n);
	}

	void _add(int v, int l1, int r1, int l, int r, int num) {
		if (l1 >= r || l >= r1) {
			return;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			tree[v].insert(num);
			return;
		}

		int mid = (l1 + r1) / 2;
		_add(v + v, l1, mid, l, r, num);
		_add(v + v + 1, mid, r1, l, r, num);
	}

	void add(int l, int r, int num) {
		_add(1, 0, n, l, r, num);
	}

	void _remove(int v, int l1, int r1, int l, int r, int num) {
		if (l1 >= r || l >= r1) {
			return;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			tree[v].erase(num);
			return;
		}

		int mid = (l1 + r1) / 2;
		_remove(v + v, l1, mid, l, r, num);
		_remove(v + v + 1, mid, r1, l, r, num);
	}

	void remove(int l, int r, int num) {
		_remove(1, 0, n, l, r, num);
	}

	vector<int> getnums(int v) {
		v += n;
		vector<int> res;
		while (v > 0) {
			for (int x : tree[v]) {
				res.push_back(x);
			}
			v /= 2;
		}
		return res;
	}
};

int main() {
	int n = nxt(), q = nxt(), s = nxt() - 1;
	PlanCollection coll(n);
	vector<vector<int>> plans;
	vector<vector<int>> planlist(n);
	for (int i = 0; i < q; ++i) {
		int t = nxt();
		if (t == 1) {
			int v = nxt() - 1, u = nxt() - 1, w = nxt();
			plans.push_back({t, v, u, w});
			// coll.add(v, v + 1, i);
			planlist[v].push_back(i);
		} else if (t == 2) {
			int v = nxt() - 1, l = nxt() - 1, r = nxt(), w = nxt();
			plans.push_back({t, v, l, r, w});
			// coll.add(v, v + 1, i);
			planlist[v].push_back(i);
		} else {
			int v = nxt() - 1, l = nxt() - 1, r = nxt(), w = nxt();
			plans.push_back({t, l, r, v, w});
			coll.add(l, r, i);
		}
	}

	Shit shit(n, s);
	vector<long long> dist(n, inf);

	while (true) {
		auto p = shit.getmin();
		if (p.second == -1) {
			break;
		}

		int v = p.second;
		dist[v] = p.first;
		shit.forbid(v);
		for (int pl : planlist[v]) {
			auto plan = plans[pl];
			if (plan[0] == 1) {
				shit.remin(plan[2], plan[2] + 1, dist[v] + plan[3]);
			} else {
				shit.remin(plan[2], plan[3], dist[v] + plan[4]);
			}
		}

		auto badplans = coll.getnums(v);
		for (int x : badplans) {
			auto plan = plans[x];
			shit.remin(plan[3], plan[3] + 1, dist[v] + plan[4]);
			coll.remove(plan[1], plan[2], x);
		}
	}

	cout.sync_with_stdio(0);
	for (long long x : dist) {
		if (x == inf) {
			cout << -1 << " ";
		} else {
			cout << x << " ";
		}
	}
	cout << "\n";

	return 0;
}