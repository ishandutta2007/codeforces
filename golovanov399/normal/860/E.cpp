#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

struct Linear {
	long long a, b;

	long long get(long long x) const {
		return a * x + b;
	}

	void operator +=(const Linear& l) {
		a += l.a;
		b += l.b;
	}
};

ostream& operator <<(ostream& ostr, const Linear& l) {
	ostr << l.a << " * x + " << l.b;
	return ostr;
}

struct Fenwick {
	int n;
	vector<Linear> a;

	Fenwick(int _n = 0): n(_n) {
		a.resize(n);
	}

	void add(int pos, const Linear& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	Linear get(int pos) {
		Linear res = {0, 0};
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

const int N = 555555;
vector<int> a[N];
int size[N];
int level[N];
int tin[N];
int tout[N];
int timer = 0;

void dfs(int v) {
	size[v] = 1;
	tin[v] = timer++;
	for (int x : a[v]) {
		level[x] = level[v] + 1;
		dfs(x);
		size[v] += size[x];
	}
	tout[v] = timer++;
}

int main() {
	int n = nxt();
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int p = nxt() - 1;
		if (p > -1) {
			a[p].push_back(i);
		} else {
			root = i;
		}
	}

	dfs(root);

	vector<int> ppr(n, -1);
	vector<int> pr(n, -1);
	vector<int> p(n, -1);
	vector<int> st = {root};
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		ppr[v] = (pr[v] == -1 ? v : ppr[pr[v]]);
		pair<int, int> mx = {0, -1};
		for (int x : a[v]) {
			p[x] = v;
			st.push_back(x);
			mx = max(mx, make_pair(size[x], x));
		}
		if (mx.second >= 0) {
			pr[mx.second] = v;
		}
	}

	vector<int> ml(n);
	for (int i = 0; i < n; ++i) {
		ml[ppr[i]] = max(ml[ppr[i]], level[i] - level[ppr[i]] + 1);
	}

	vector<Fenwick> f(n);
	for (int i = 0; i < n; ++i) {
		if (pr[i] == -1) {
			f[i] = Fenwick(ml[i]);
		}
	}

	vector<vector<int>> levels;
	for (int i = 0; i < n; ++i) {
		while ((int)levels.size() <= level[i]) {
			levels.emplace_back();
		}
		levels[level[i]].push_back(i);
	}

	vector<long long> ans(n);
	for (int l = 0; l < (int)levels.size(); ++l) {
		for (int v : levels[l]) {
			while (v > -1) {
				int w = ppr[v];
				f[w].add(0, {1, 1 - level[w]});
				f[w].add(level[v] - level[w] + 1, {-1, level[v]});
				// cerr << "add 1 * x + " << 1 - level[w] << " to " << w << "-th (" << 0 << ")\n";
				// cerr << "add -1 * x + " << level[w] - 1 << " to " << w << "-th (" << level[v] - level[w] + 1 << ")\n";
				v = p[w];
			}
		}
		// for (auto l : f[0].a) {
		// 	cerr << "(" << l << ") ";
		// }
		// cerr << "\n";
		for (int v : levels[l]) {
			// cerr << v << ": ";
			// int vv = v;
			long long& res = ans[v] = -level[v] - 1;
			while (v > -1) {
				int w = ppr[v];
				// cerr << w << " " << v << " (";
				auto add = f[w].get(level[v] - level[w]);
				// cerr << add << "), ";
				res += add.get(level[v]);
				v = p[w];
			}
			// cerr << "\n";
		}
		// cerr << "\n";
	}

	for (auto x : ans) {
		printf("%lld ", x);
	}
	printf("\n");

	return 0;
}