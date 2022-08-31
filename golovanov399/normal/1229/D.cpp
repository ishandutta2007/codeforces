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

vector<int> permApply(const vector<int>& p, const vector<int>& q) {
	vector<int> res(p.size());
	for (int i = 0; i < (int)p.size(); ++i) {
		res[i] = q[p[i]];
	}
	return res;
}

const int N = 120;
using Bs = bitset<N>;
int mult[N][N];

// void add(Bs& a, int x) {
// 	if (a[x]) {
// 		return;
// 	}
// 	for (int i = 0; i < N; ++i) {
// 		if (a[i]) {
// 			for (int j = mult[i][x]; !a[j]; j = mult[j][x]) {
// 				a.set(j, 1);
// 			}
// 		}
// 	}
// }

struct Subgroup {
	Bs can;
	vector<int> generators;

	Subgroup() {
		can = {};
		can.flip(0);
	}

	void add(int x) {
		if (!can[x]) {
			generators.push_back(x);
			vector<int> st;
			for (int i = 0; i < N; ++i) {
				if (can[i]) {
					st.push_back(i);
				}
				while (!st.empty()) {
					int v = st.back();
					st.pop_back();
					for (int y : generators) {
						if (!can[mult[v][y]]) {
							can.flip(mult[v][y]);
							st.push_back(mult[v][y]);
						}
					}
				}
			}
			// ::add(can, x);
		}
	}
};

Subgroup concat(const Subgroup& a, const Subgroup& b) {
	Subgroup res = a;
	for (int x : b.generators) {
		res.add(x);
	}
	return res;
}

struct State {
	long long ans;
	vector<pair<Subgroup, int>> pr, sf;

	State() {}
	State(int x) {
		Subgroup g;
		g.add(x);
		ans = g.can.count();
		pr = sf = {{g, 1}};
	}

	State(long long _ans, const vector<pair<Subgroup, int>>& _pr, const vector<pair<Subgroup, int>>& _sf): ans(_ans), pr(_pr), sf(_sf) {}
};

State unite(const State& left, const State& right) {
	long long ans = left.ans + right.ans;
	for (int i = 0; i < (int)left.sf.size(); ++i) {
		Subgroup g = left.sf[i].first;
		int lst = 0;
		for (int j = 0; j < (int)right.pr.size(); ++j) {
			while (lst < (int)right.pr[j].first.generators.size()) {
				g.add(right.pr[j].first.generators[lst++]);
			}
			ans += 1ll * left.sf[i].second * right.pr[j].second * (int)g.can.count();
		}
	}
	auto pr = left.pr;
	Subgroup g = pr.back().first;
	{
		int cnt = g.can.count();
		int lst = 0;
		for (int j = 0; j < (int)right.pr.size(); ++j) {
			while (lst < (int)right.pr[j].first.generators.size()) {
				g.add(right.pr[j].first.generators[lst++]);
			}
			if (cnt == (int)g.can.count()) {
				pr.back().second += right.pr[j].second;
			} else {
				pr.push_back({g, right.pr[j].second});
				cnt = g.can.count();
			}
		}
	}
	auto sf = right.sf;
	g = sf.back().first;
	{
		int cnt = g.can.count();
		int lst = 0;
		for (int j = 0; j < (int)left.sf.size(); ++j) {
			while (lst < (int)left.sf[j].first.generators.size()) {
				g.add(left.sf[j].first.generators[lst++]);
			}
			if (cnt == (int)g.can.count()) {
				sf.back().second += left.sf[j].second;
			} else {
				cnt = g.can.count();
				sf.push_back({g, left.sf[j].second});
			}
		}
	}

	return {ans, pr, sf};
}

State get(const vector<int>& a, int l, int r) {
	State res;
	if (r == l + 1) {
		res = State(a[l]);
	} else {
		int mid = (l + r) / 2;
		res = unite(get(a, l, mid), get(a, mid, r));
	}
	// cerr << "[" << l << ", " << r << "): " << res.ans << "\n";
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	int k = nxt();

	int fact = vector{1, 1, 2, 6, 24, 120}[k];
	vector<vector<int>> perms(fact);
	perms[0].resize(k);
	iota(all(perms[0]), 0);
	for (int i = 1; i < fact; ++i) {
		perms[i] = perms[i - 1];
		assert(next_permutation(all(perms[i])));
	}
	for (int i = 0; i < fact; ++i) {
		for (int j = 0; j < fact; ++j) {
			mult[i][j] = lower_bound(all(perms), permApply(perms[i], perms[j])) - perms.begin();
		}
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		vector<int> perm(k);
		for (int j = 0; j < k; ++j) {
			perm[j] = nxt() - 1;
		}
		a[i] = lower_bound(all(perms), perm) - perms.begin();
	}

	cout << get(a, 0, n).ans << "\n";

	return 0;
}