#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const int B = 100000;

namespace MCMF {
	int head[760], to[100000], nxt[100000], W[100000], F[100000], TOT;
	int dist[760], lst[760], pth[760], inq[760];
	void Init() {memset(head, -1, sizeof(head)), TOT = 0;}
	void AddEdge(int x, int y, int w, int f) {
		to[TOT] = y, W[TOT] = w, F[TOT] = f, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, W[TOT] = 0, F[TOT] = -f, nxt[TOT] = head[y], head[y] = TOT++;
	}
	void spfa(int S, int T) {
		static queue <int> q;
		memset(dist, 0x3f, sizeof(dist)), dist[S] = 0, q.push(S), inq[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int e = head[x]; ~e; e = nxt[e]) {
				int v = to[e], w = W[e], f = F[e];
				if (!w) continue;
				if (dist[v] > dist[x] + f) {
					dist[v] = dist[x] + f, lst[v] = x, pth[v] = e;
					if (!inq[v]) q.push(v);
				}
			}
		}
	}
	int MCMF(int S, int T, int turn) {
		int ans = 0;
		while (turn--) {
			spfa(S, T);
			ans += dist[T];
			int cur = T; while (cur != S) W[pth[cur]]--, W[pth[cur] ^ 1]++, cur = lst[cur];
		}
		return ans;
	}
	vector <int> path;
	int vis[760];
	bool dfs(int x, int S) {
		path.push_back(x), vis[x] = 1;
		if (x == S) return 1;
		for (int e = head[x]; ~e; e = nxt[e]) {
			int v = to[e], w = W[e], f = F[e];
			if (e % 2 == 0 || !w || vis[v]) continue;
			if (dfs(v, S)) {
				W[e]--;
				return 1;
			}
		}
		path.pop_back();
		return 0;
	}
	vector <vector <int> > GetPath(int S, int T, int turn) {
		vector <vector <int> > ans;
		while (turn--) {
			path.clear(), memset(vis, 0, sizeof(vis));
			assert(dfs(T, S));
			reverse(path.begin(), path.end());
			// cerr << "   path:"; for (auto x : path) cerr << " " << x; cerr << endl;
			ans.push_back(path);
		}
		return ans;
	}
}

int main() {
	MCMF :: Init();
	int n, m; scanf("%d%d", &n, &m);
	static int a[260], c[260];
	auto PopCount = [&](int x) -> int {int ans = 0; while (x) ans++, x -= x & -x; return ans;};
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[i] = PopCount(a[i]);
	}
	for (int i = 0; i < n; i++) {
		MCMF :: AddEdge(n * 2 + i, n * 2 + i + 1, INF, 0);
		MCMF :: AddEdge(n * 2 + i, i, INF, c[i]);
		MCMF :: AddEdge(i, n + i, 1, -B);
		MCMF :: AddEdge(n + i, n * 2 + i + 1, INF, 0);
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				MCMF :: AddEdge(n + i, j, INF, 0);
				break;
			}
		}
	}
	int ans = MCMF :: MCMF(n * 2, n * 3, m) + n * B;
	vector <vector <int> > path = MCMF :: GetPath(n * 2, n * 3, m);
	static vector <string> output[260];
	auto CharToString = [&](char c) -> string {return string(1, c);};
	auto IntToString = [&](int x) -> string {stringstream ss; ss << x; string s; ss >> s; return s;};
	int tot = 0;
	for (int i = 0; i < path.size(); i++) {
		for (int j = 0; j + 1 < path[i].size(); j++) {
			int x = path[i][j], y = path[i][j + 1];
			if (x / n == 2 && y / n == 0) {
				output[x % n].push_back(CharToString('a' + i) + "=" + IntToString(a[x % n])), tot++;
			}
			if (x / n == 0 && y / n == 1) {
				output[x % n].push_back("print(" + CharToString('a' + i) + ")"), tot++;
			}
		}
	}
	printf("%d %d\n", tot, ans);
	for (int i = 0; i < n; i++) {
		for (auto &it : output[i]) {
			printf("%s\n", it.c_str());
		}
	}
	return 0;
}