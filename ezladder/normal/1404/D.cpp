#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int c[1000007];

struct TwoSATSolver {
	// !a or b
	// 1, a, 0, b
	void add_or(int na, int a, int nb, int b) {
		int v1 = a * 2 + na;
		int v2 = b * 2 + nb;
		n = max(n, 2 * max(a + 1, b + 1));
		// while (g.size() < n) g.emplace_back(), gt.emplace_back();
		add_edge(v1 ^ 1, v2);
		add_edge(v2 ^ 1, v1);
	}

	vector<int> solve() {
		used.assign(n, false);
		for (int i = 0; i < n; ++i)
			if (!used[i])
				dfs1(i);

		comp.assign(n, -1);
		for (int i = 0, j = 0; i < n; ++i) {
			int v = order[n - i - 1];
			if (comp[v] == -1)
				dfs2(v, j++);
		}

		for (int i = 0; i < n; ++i)
			if (comp[i] == comp[i ^ 1]) {
				return {};
			}

		vector<int> res;
		for (int i = 0; i < n; i += 2) {
			int ans = comp[i] > comp[i ^ 1] ? 1 : 0;
			res.pb(ans);
		}
		return res;
	}

private:
	void add_edge(int a, int b) {
		g[a].pb(b);
		gt[b].pb(a);
	}

	int n = 0;
	vector<int> g[3000007], gt[3000007];
	vector<bool> used;
	vector<int> order, comp;

	void dfs1 (int v) {
		used[v] = true;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to])
				dfs1(to);
		}
		order.push_back(v);
	}

	void dfs2 (int v, int cl) {
		comp[v] = cl;
		for (size_t i = 0; i < gt[v].size(); ++i) {
			int to = gt[v][i];
			if (comp[to] == -1)
				dfs2(to, cl);
		}
	}
};
	TwoSATSolver kek;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "First" << endl;
		for (int i = 1; i <= 2 * n; ++i) {
			int x = i;
			if (x > n) x -= n;
			cout << x << ' ';
		}
		cout << endl;
		int x; cin >> x;
		exit(0);
	}

	cout << "Second" << endl;
	vector<vector<int>> g(n + 2);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> c[i];
		g[c[i] - 1].pb(i);
	}


	for (int i = 0; i < n; ++i) {
		kek.add_or(0, i, 0, i + n);
		kek.add_or(1, i, 1, i + n);
	}

	for (int i = 0; i < n; ++i) {
		kek.add_or(0, g[i][0], 0, g[i][1]);
		kek.add_or(1, g[i][0], 1, g[i][1]);
	}

	auto now = kek.solve();

	if (now.size() == 0) assert(0);

	ll sum = 0;
	for (int i = 0; i < now.size(); ++i) if (now[i]) sum += i + 1;
	if (sum % (2 * n) != 0) {
		for (int& x : now) x ^= 1;
	}
	for (int i = 0; i < now.size(); ++i) if (now[i]) cout << i + 1 << ' ';
	cout << endl;
	int x; cin >> x;
}