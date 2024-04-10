#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int n, k;
int P[110], C[110], L[110], seq[110];
int prime[200010], vis[200010], tot;

bool IsPrime(int x) {
	return !vis[x];
}

void PreCalc(int n) {
	vis[0] = vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) prime[tot++] = i;
		for (int j = 0; j < tot && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

struct Dinic {
	int head[110], to[100010], nxt[100010], W[100010], TOT;
	int dep[110], cur[110];
	queue <int> q;
	void clear() {
		memset(head, -1, sizeof(head)), TOT = 0;
	}
	void AddEdge(int x, int y, int w) {
		to[TOT] = y, W[TOT] = w, nxt[TOT] = head[x], head[x] = TOT++;
		to[TOT] = x, W[TOT] = 0, nxt[TOT] = head[y], head[y] = TOT++;
	}
	bool bfs(int S, int T) {
		while (!q.empty()) q.pop();
		memset(dep, -1, sizeof(dep)), dep[S] = 0, q.push(S);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			if (dep[T] != -1 && dep[x] >= dep[T]) return 1;
			for (int i = head[x]; ~i; i = nxt[i]) {
				int v = to[i], w = W[i];
				if (w && dep[v] == -1) dep[v] = dep[x] + 1, q.push(v);
			}
		}
		return dep[T] != -1;
	}
	int dfs(int x, int T, int flow) {
		if (x == T) return flow;
		int res = 0;
		for (int &i = cur[x]; ~i; i = nxt[i]) {
			int v = to[i], w = W[i];
			if (dep[v] != dep[x] + 1 || !w) continue;
			int tmp = dfs(v, T, min(flow, w));
			W[i] -= tmp, W[i ^ 1] += tmp, flow -= tmp, res += tmp;
			if (!flow) break;
		}
		return res;
	}
	int MaxFlow(int S, int T) {
		int ans = 0;
		while (bfs(S, T)) {
			memcpy(cur, head, sizeof(head));
			ans += dfs(S, T, INF);
		}
		return ans;
	}
}mf;

vector <pii> a;

bool Check(int mid) {
	mf.clear();
	int S = n, T = n + 1;
	a.clear();
	for (int i = 0; i <= mid; i++) {
		a.push_back(mp(C[seq[i]], P[seq[i]]));
	}
	sort(a.begin(), a.end());
	while (a.size() >= 2 && a[0].fi == 1 && a[1].fi == 1) a.erase(a.begin());
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int x = a[i].fi, w = a[i].se;
		ans += w;
		if (x & 1) mf.AddEdge(S, i, w);
		else mf.AddEdge(i, T, w);
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if ((a[i].fi & 1) && IsPrime(a[i].fi + a[j].fi)) {
				mf.AddEdge(i, j, INF);
			}
		}
	}
	return ans - mf.MaxFlow(S, T) >= k;
}

int main() {
	PreCalc(200000);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &P[i], &C[i], &L[i]);
		seq[i] = i;
	}
	sort(seq, seq + n, [](const int &x, const int &y) {return L[x] < L[y];});
	int l = 0, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (Check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == n) printf("-1\n");
	else printf("%d\n", L[seq[l]]);
	return 0;
}