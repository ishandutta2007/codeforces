#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 998244353;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

int vis[200010], prime[200010], tot, minp[200010];
vector <pip> G[200010];
long long inv[200010];
int used[200010];

void PreCalc(int N) {
	for (int i = 1; i <= N; i++) {
		inv[i] = power(i, mod - 2);
	}
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, minp[i] = i;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

int cur[200010];
long long val, sum;
int minj[200010];
vector <int> useful;

void Apply(int x, int coef) {
	val = val * (coef == 1 ? x : inv[x]) % mod;
	while (x > 1) {
		int p = minp[x];
		if (!used[p]) used[p] = 1, useful.push_back(p);
		cur[p] += coef;
		minj[p] = min(minj[p], cur[p]);
		x /= p;
	}
}

void dfs(int x, int last) {
	sum = (sum + val) % mod;
	for (auto it : G[x]) {
		int v = it.fi, p = it.se.fi, q = it.se.se;
		if (v == last) continue;
		Apply(q, 1), Apply(p, -1);
		dfs(v, x);
		Apply(p, 1), Apply(q, -1);
	}
}

int main() {
	PreCalc(200000);
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		useful.clear();
		for (int i = 1; i < n; i++) {
			int x, y, p, q; scanf("%d%d%d%d", &x, &y, &p, &q);
			G[x].push_back(mp(y, mp(p, q)));
			G[y].push_back(mp(x, mp(q, p)));
		}
		val = 1, sum = 0, dfs(1, 1);
		long long k = 1;
		for (auto it : useful) {
			k = k * power(it, -minj[it]) % mod;
			used[it] = 0, minj[it] = 0, cur[it] = 0;
		}
		printf("%lld\n", sum * k % mod);
	}
	return 0;
}