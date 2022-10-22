#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int dw[1010][12], up[1010][12], bert[1010][12];
vector <int> G[1010], T[20];
int mem[1010][1 << 12], pre[1010][1 << 12];
int sz[20], maxj[20];
int fa[1010];
int tmp[1 << 12];
int son[20];
int n, m;

void Calc(int *g, int *f, int *dp) {
	for (int mask = (1 << m) - 1; mask >= 0; mask--) {
		for (int i = 0; i < m; i++) if (!(mask >> i & 1)) {
			ADD(g[mask ^ 1 << i], 1ll * f[mask] * dp[i] % mod);
		}
	}
}

void GetDw(int x, int last) {
	fa[x] = last;
	for (auto v : G[x]) if (v != last) {
		GetDw(v, x);
	}
	memset(tmp, 0, sizeof(tmp)), tmp[0] = 1;
	for (auto v : G[x]) {
		Calc(tmp, tmp, dw[v]);
	}
	for (int X = 0; X < m; X++) {
		int &res = dw[x][X] = 0;
		res = tmp[son[X]];
	}
}

void GetUp(int x, int last) {
	int *tmp = mem[x]; tmp[0] = 1;
	Calc(tmp, tmp, up[x]);
	for (auto v : G[x]) if (v != last) {
		memcpy(pre[v], tmp, sizeof(pre[v]));
		Calc(tmp, tmp, dw[v]);
	}
	for (int i = 0; i < m; i++) {
		bert[x][i] = tmp[son[i]];
	}
	memset(mem[x], 0, sizeof(mem[x])), tmp[0] = 1;
	reverse(G[x].begin(), G[x].end());
	for (auto v : G[x]) if (v != last) {
		int *f = tmp, *g = pre[v];
		for (int j = 0; j < m; j++) {
			int target = son[j];
			up[v][j] = 1ll * f[0] * g[target] % mod;
			for (int mask = target; mask; mask = mask - 1 & target) {
				ADD(up[v][j], 1ll * f[mask] * g[target ^ mask] % mod);
			}
		}
		GetUp(v, x);
		Calc(tmp, tmp, dw[v]);
	}
}

void GetSz(int x, int last) {
	sz[x] = 1, maxj[x] = 0;
	for (auto v : T[x]) if (v != last) {
		GetSz(v, x), sz[x] += sz[v], maxj[x] = max(maxj[x], sz[v]);
	}
	maxj[x] = max(maxj[x], m - sz[x]);
}

void GetSon(int x, int last) {
	son[x] = 0;
	for (auto v : T[x]) if (v != last) {
		son[x] |= 1 << v;
		GetSon(v, x);
	}
}

int GetDp(int x, int k, int y) {
	return fa[x] == y ? dw[x][k] : up[y][k];
}

map <vector <int>, int> ID;
int id[20];

int GetId(int x, int last) {
	if (~id[x]) return id[x];
	vector <int> son;
	for (auto v : T[x]) if (v != last) {
		son.push_back(GetId(v, x));
	}
	sort(son.begin(), son.end());
	if (ID.count(son)) id[x] = ID[son];
	else id[x] = ID.size(), ID[son] = id[x];
	return id[x];
}

int Work(int x, int last) {
	int ans = 1;
	vector <int> son;
	for (auto v : T[x]) if (v != last) {
		ans = 1ll * ans * Work(v, x) % mod;
		son.push_back(GetId(v, x));
	}
	sort(son.begin(), son.end());
	for (int i = 0; i < son.size(); i++) {
		int j = i; while (j < son.size() && son[i] == son[j]) j++, ans = 1ll * ans * (j - i) % mod;
		i = j - 1;
	}
	return ans;
}

int SelfSim(int X, int Y) {
	if (Y == -1) return Work(X, X);
	long long ans = 1ll * Work(X, Y) * Work(Y, X) % mod;
	GetId(X, Y), GetId(Y, X);
	if (id[X] == id[Y]) ans = ans * 2 % mod;
	return ans;
}

int main() {
	memset(id, -1, sizeof(id));
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	scanf("%d", &m);
	for (int i = 1; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		T[x].push_back(y), T[y].push_back(x);
	}
	GetSz(0, 0);
	int X = -1, Y = -1;
	for (int i = 0; i < m; i++) {
		if (maxj[i] * 2 <= m) {
			if (X == -1) X = i;
			else assert(Y == -1), Y = i;
		}
	}
	GetSon(X, Y);
	if (Y != -1) GetSon(Y, X);
	GetDw(1, 1), GetUp(1, 1);
	int ans = 0;
	if (Y == -1) {
		for (int i = 1; i <= n; i++) {
			ADD(ans, bert[i][X]);
		}
	} else {
		for (int i = 1; i <= n; i++) {
			for (auto j : G[i]) {
				ADD(ans, 1ll * GetDp(i, X, j) * GetDp(j, Y, i) % mod);
			}
		}
	}
	printf("%lld\n", ans * power(SelfSim(X, Y), mod - 2) % mod);
	return 0;
}