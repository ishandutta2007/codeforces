#include <bits/stdc++.h>
using namespace std;

struct Max_Flow {
	int head[110], nxt[100000], to[100000], w[100000], TOT, n, cur[110], dep[110];
	queue <int> q;
	void init(int N) {n = N, TOT = 0; for (int i = 0; i < n; i++) head[i] = -1;}
	void AddEdge(int x, int y, int W) {
		to[TOT] = y, w[TOT] = W, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, w[TOT] = 0, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool bfs(int S, int T) {
		for (int i = 0; i < n; i++) dep[i] = -1; dep[S] = 0, q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i];
				if (w[i] && dep[v] == -1) dep[v] = dep[x] + 1, q.push(v);
			}
		}
		return dep[T] != -1;
	}
	int dfs(int x, int T, int flow) {
		if (x == T) return flow;
		int res = 0;
		for (int &i = cur[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if (!w[i] || dep[v] != dep[x] + 1) continue;
			int tmp = dfs(v, T, min(flow, w[i]));
			w[i] -= tmp, w[i ^ 1] += tmp, flow -= tmp, res += tmp;
			if (!flow) break;
		}
		return res;
	}
	int MaxFlow(int S, int T) {
		int res = 0;
		while (bfs(S, T)) {
			for (int i = 0; i < n; i++) cur[i] = head[i];
			res += dfs(S, T, 0x3f3f3f3f);
		}
		return res;
	}
}mf;

vector <int> from[60];
vector <int> ans;
vector <int> res;
int can[60], X[60], Y[60];
long long dp[60][60];
int lst[60][60];
int n, m, k;

int GetVal() {
	int S = n * 2, T = S + 1; mf.init(T + 1);
	for (int i = 0; i < n; i++) mf.AddEdge(S, i << 1, 1), mf.AddEdge(i << 1 | 1, T, 1);
	for (int x = 0; x < n; x++) for (auto y : from[x]) if ((can[x] & 1) && (can[y] & 2)) {
		mf.AddEdge(x << 1, y << 1 | 1, 1);
	}
	return n - mf.MaxFlow(S, T);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) can[i] = 3;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y, x--, y--;
		from[x].push_back(y);
	}
	for (int i = 0; i < k; i++) cin >> X[i] >> Y[i];
	int val = GetVal();
	for (int it = val; it <= k; it++) {
		for (int i = 0; i < n; i++) {
			if (can[i] & 1) {
				can[i] ^= 1; if (GetVal() == it + 1) {ans.push_back(i + 1); break;} can[i] ^= 1;
			}
			if (can[i] & 2) {
				can[i] ^= 2; if (GetVal() == it + 1) {ans.push_back(-i - 1); break;} can[i] ^= 2;
			}
		}
		assert(GetVal() == it + 1);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][val] = 0;
	for (int i = 0; i < k; i++) for (int j = i + 1; j <= k + 1; j++) if (dp[i][j] != -1) {
		for (int t = (j == i + 1); j + t <= k + 1; t++) {
			if (dp[i + 1][j + t] < dp[i][j] + max(0ll, X[i] - 1ll * Y[i] * t)) {
				dp[i + 1][j + t] = dp[i][j] + max(0ll, X[i] - 1ll * Y[i] * t);
				lst[i + 1][j + t] = t;
			}
		}
	}
	int x = k, y = k + 1;
	while (x) {
		res.push_back(0);
		int t = lst[x][y];
		while (t--) res.push_back(ans.back()), ans.pop_back();
		y -= lst[x][y], x--;
	}
	reverse(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto x : res) cout << x << " "; cout << endl;
	return 0;
}