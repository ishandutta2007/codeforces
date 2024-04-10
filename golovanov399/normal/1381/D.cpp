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

const int N = 111111;
vector<int> a[N];
vector<int> dp[N];
const int L = 20;
int par[N][L];

int d[N];
void mark_d(int v, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		d[x] = d[v] + 1;
		mark_d(x, v);
	}
}

int dfsDown(int v) {
	int res = 0;
	for (int i = 1; i < L; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v][0]) {
			continue;
		}
		par[to][0] = v;
		res = max(res, dp[v][i] = 1 + dfsDown(to));
	}
	return res;
}

void dfsUp(int v, int to_parent = 0) {
	vector<int> pref, suf;
	pref.reserve(a[v].size());
	suf.reserve(a[v].size());
	int j = 0;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v][0]) {
			dp[v][i] = to_parent;
			continue;
		}
		pref.push_back(j ? max(pref[j - 1], dp[v][i]) : dp[v][i]);
		++j;
	}
	j = 0;
	for (int i = (int)a[v].size() - 1; i >= 0; --i) {
		int to = a[v][i];
		if (to == par[v][0]) {
			continue;
		}
		suf.push_back(j ? max(dp[v][i], suf[j - 1]) : dp[v][i]);
		++j;
	}
	reverse(all(suf));

	j = 0;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		int to = a[v][i];
		if (to == par[v][0]) {
			continue;
		}
		int new_to_parent = to_parent;
		if (j > 0) {
			new_to_parent = max(pref[j - 1], new_to_parent);
		}
		if (j < (int)suf.size() - 1) {
			new_to_parent = max(new_to_parent, suf[j + 1]);
		}
		dfsUp(to, new_to_parent + 1);
		++j;
	}
}

int tin[N], tout[N];
int timer;

void tindfs(int v, int p = -1) {
	tin[v] = timer++;
	for (int i = 1; i < L; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for (int x : a[v]) {
		if (x != p) {
			par[x][0] = v;
			tindfs(x, v);
		}
	}
	tout[v] = timer;
}

int goup(int v, int l) {
	while (l) {
		v = par[v][__builtin_ctz(l)];
		l &= l - 1;
	}
	return v;
}

inline bool isPar(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair<int, int> deepest[N];
void deepdfs(int v, int p = -1) {
	deepest[v] = {0, v};
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		deepdfs(x, v);
		deepest[v] = max(deepest[v], {deepest[x].first + 1, deepest[x].second});
	}
}

void solve() {
	int n = nxt(), s = nxt() - 1, t = nxt() - 1;
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	memset(d, 0, sizeof(int) * n);
	mark_d(s);
	int len = d[t];

	for (int i = 0; i < n; ++i) {
		dp[i].assign(a[i].size(), 0);
	}
	dfsDown(0);
	dfsUp(0);

	int root = 0;
	while (root < n) {
		int cnt = 0;
		for (int x : dp[root]) {
			if (x >= len) {
				++cnt;
			}
		}
		if (cnt >= 3) {
			break;
		}
		++root;
	}
	if (root == n) {
		puts("NO");
		return;
	}

	for (int i = 0; i < L; ++i) {
		par[root][i] = root;
	}
	timer = 0;
	tindfs(root);
	deepdfs(root);

	while (true) {
		int cur_s = s;
		int depth = deepest[s].first;
		s = deepest[s].second;
		t = goup(t, depth);
		if (isPar(t, s)) {
			puts("YES");
			return;
		}
		depth = deepest[t].first;
		t = deepest[t].second;
		s = goup(s, depth);
		if (isPar(s, t)) {
			puts("YES");
			return;
		}
		if (s == cur_s) {
			puts("NO");
			return;
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}