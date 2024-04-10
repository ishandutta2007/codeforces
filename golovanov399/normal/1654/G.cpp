#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 202'222;
vector<int> a[N];
int h[N];

vector<int> same[N];
vector<int> up[N];
bool good[N];

int lowest[N];
int could[N];

void remin(int& x, int y) {
	x = (x < y) ? x : y;
}

void dfs(int v, int cur, int dest) {
	if (cur == 0) {
		remin(lowest[v], h[dest]);
	}
	if (h[dest] > lowest[v]) {
		return;
	}
	if (cur >= could[v]) {
		return;
	}
	could[v] = cur;
	for (int x : same[v]) {
		dfs(x, cur + 1, dest);
	}
	for (int x : up[v]) {
		dfs(x, cur ? cur - 1 : 0, dest);
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		h[i] = nxt() - 1;
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (~h[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int x : a[v]) {
			if (h[x] == -1) {
				h[x] = h[v] + 1;
				q.push(x);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		good[i] = false;
		for (int x : a[i]) {
			if (h[i] == h[x]) {
				same[i].push_back(x);
				good[i] = true;
			} else if (h[x] > h[i]) {
				up[i].push_back(x);
			}
		}
	}

	vector<int> all_good;
	for (int i = 0; i < n; ++i) {
		if (good[i]) {
			all_good.push_back(i);
		}
	}
	sort(all(all_good), [&](int x, int y) {
		return h[x] < h[y];
	});

	for (int i = 0; i < n; ++i) {
		lowest[i] = 1e9;
		could[i] = 1e9;
	}

	for (int v : all_good) {
		dfs(v, 0, v);
	}

	for (int i = 0; i < n; ++i) {
		int ans = h[i];
		if (lowest[i] < 1e8) {
			ans = max(ans, 2 * h[i] - lowest[i]);
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}