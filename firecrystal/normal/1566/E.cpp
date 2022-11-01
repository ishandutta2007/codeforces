// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, d[N], cnt, o;

vector<int> g[N];

void inline clear() {
	for (int i = 1; i <= n; i++) g[i].clear(), d[i] = 0;
}

int dfs(int u, int fa) {
	int t = 0;
	for (int v: g[u]) {
		if (v == fa) continue;
		t += dfs(v, u);
	}
	if (!t) return 1;
	else {
		if (!cnt) cnt += t;
		else cnt += t - 1;
		return 0;
	}
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n); o = 0;
		for (int i = 1; i < n; i++) {
			int u, v; read(u), read(v);
			g[u].pb(v), g[v].pb(u);
			d[u] ++, d[v]++;
		}
		cnt = 0;
		int pp = 0;
		for (int v: g[1]) {
			if (d[v] == 1) ++pp;
		}
		for (int v: g[1]) {
			if (d[v] != 1) {
				pp += dfs(v, 1);
			}
		}
		if (cnt) pp = max(pp - 1, 0);
		cnt += pp;
		printf("%d\n", cnt);
		clear();
	}
	return 0;
}