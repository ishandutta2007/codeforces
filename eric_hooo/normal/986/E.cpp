#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007, N = 10000000, B = 3162;

int D[100010];
int fa[100010][17];
int dep[100010];
int minp[10000010], mine[10000010], vis[10000010], prime[10000010], tot;
vector <int> from[100010], qry[100010];
int a[100010];

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

void get_pre() {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, minp[i] = i, mine[i] = 1;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, minp[i * prime[j]] = prime[j], mine[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				mine[i * prime[j]] += mine[i];
				break;
			}
		}
	}
}

void dfs(int x, int last) {
	fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x);
	}
}

void calc_fa(int n) {
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	} 
}

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 16; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

long long ans[100010];

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long inv(long long x) {return power(x, mod - 2);}

struct BIT {
	int T[30], S[30];
	int n, tot;
	void init(int _n) {
		n = _n, tot = 0;
		for (int i = 1; i <= n; i++) {
			T[i] = S[i] = 0;
		}
	}
	void modify(int x, int val) {
		int id = x * val; tot += val;
		while (x <= n) T[x] += val, S[x] += id, x += x & -x;
	}
	int queryT(int x) {
		int res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}
	int queryS(int x) {
		int res = 0;
		while (x) res += S[x], x -= x & -x;
		return res;
	}
	int query(int x) {
		int spe = tot - queryT(x);
		return spe * x + queryS(x);
	}
};

struct Data {
	int CNT[10000010];
	BIT bit[3200];
	void init() {
		for (int i = 2; i <= B; i++) {
			long long cur = 1; int pw = 0;
			while (cur <= N) cur *= i, pw++;
			pw--;
			bit[i].init(pw);
		}
		memset(CNT, 0, sizeof(CNT));
	}
	void Modify(int p, int cnt, int val) {
		if (p > B) CNT[p] += val;
		else bit[p].modify(cnt, val);
	}
	long long Query(int p, int cnt) {
		if (p > B) return CNT[p];
		return bit[p].query(cnt);
	}
}data;

void Modify(int x, int val) {
	while (x != 1) {
		int p = minp[x], cnt = mine[x];
		x /= power(p, cnt);
		data.Modify(p, cnt, val);
	}
}

long long Query(int x) {
	long long ans = 1;
	while (x != 1) {
		int p = minp[x], cnt = mine[x];
		x /= power(p, cnt);
		ans = ans * power(p, data.Query(p, cnt)) % mod;
	}
	return ans;
}

void get_ans(int x, int last) {
	Modify(a[x], 1);
	for (int i = 0; i < qry[x].size(); i++) {
		int id = qry[x][i];
		if (id > 0) ans[id] = ans[id] * Query(D[id]) % mod;
		else ans[-id] = ans[-id] * inv(power(Query(D[-id]), 2)) % mod;
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		get_ans(v, x);
	}
	Modify(a[x], -1);
}

int main () {
	get_pre();
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dep[1] = 0, dfs(1, 1), calc_fa(n);
	int Q; scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int x, y; scanf("%d%d%d", &x, &y, &D[i]);
		qry[x].push_back(i), qry[y].push_back(i);
		int lca = get_lca(x, y);
		qry[lca].push_back(-i);
		ans[i] = gcd(a[lca], D[i]);
	}
	data.init(), get_ans(1, 1);
	for (int i = 1; i <= Q; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}