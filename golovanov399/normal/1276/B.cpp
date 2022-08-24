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

const int N = 222222;
vector<int> a[N];
int color[N];
char used[N];
int curc = 0;

void prepare(int n) {
	curc = 0;
	memset(used, 0, sizeof(char) * n);
}

void dfs(int v, int ban) {
	used[v] = 1;
	color[v] = curc;
	for (int x : a[v]) {
		if (x == ban || used[x]) {
			continue;
		}
		dfs(x, ban);
	}
}

void solve() {
	int n = nxt(), m = nxt();
	int vert[2];
	for (int i = 0; i < 2; ++i) {
		vert[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<array<int, 2>> colors(n);
	for (int i = 0; i < 2; ++i) {
		prepare(n);
		color[vert[i]] = -1;
		for (int j = 0; j < n; ++j) {
			if (!used[j] && j != vert[i]) {
				dfs(j, vert[i]);
				++curc;
			}
		}
		for (int j = 0; j < n; ++j) {
			colors[j][i] = color[j];
		}
	}

	// for (auto [x, y] : colors) {
	// 	cerr << "(" << x << " " << y << ")\n";
	// }
	// cerr << "\n";

	for (int i = 0; i < (int)colors.size(); ++i) {
		if (colors[i][0] == -1) {
			colors.erase(colors.begin() + i);
		}
	}
	for (int i = 0; i < (int)colors.size(); ++i) {
		if (colors[i][1] == -1) {
			colors.erase(colors.begin() + i);
		}
	}
	long long ans = 1ll * (n - 2) * (n - 3) / 2;
	for ([[maybe_unused]] char c : ")") {
		sort(all(colors));
		int cur = 0;
		for (int i = 0; i < n - 2; ++i) {
			if (i && colors[i][0] != colors[i - 1][0]) {
				cur = 0;
			}
			ans -= cur++;
		}
		for (auto& p : colors) {
			swap(p[0], p[1]);
		}
	}
	int cur = 0;
	for (int i = 0; i < n - 2; ++i) {
		if (i && colors[i] != colors[i - 1]) {
			cur = 0;
		}
		ans += cur++;
	}
	cout << ans << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}