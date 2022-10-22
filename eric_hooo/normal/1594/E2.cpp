#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1000000007;

long long power(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

int n, m;
char buf[20];
int to[500];
set <long long> all;
map <long long, int> col;
vector <long long> f[100];

void Insert(long long x, int val) {
	col[x] = val, all.insert(x), x >>= 1;
	while (x) all.insert(x), x >>= 1;
}

vector <long long> operator * (const vector <long long> &a, const vector <long long> &b) {
	vector <long long> c = {0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j || (i ^ 1) == j) continue;
			c[i] = (c[i] + a[i] * b[j]) % mod;
		}
	}
	return c;
}

vector <long long> dfs(long long now, int dep) {
	if (!all.count(now)) return f[dep];
	vector <long long> ans = {1, 1, 1, 1, 1, 1};
	if (col.count(now)) {
		for (int i = 0; i < 6; i++) {
			ans[i] = i == col[now];
		}
	}
	if (dep == 1) return ans;
	ans = ans * dfs(now << 1, dep - 1);
	ans = ans * dfs(now << 1 | 1, dep - 1);
	return ans;
}

signed main() {
	to['w'] = 0, to['y'] = 1, to['g'] = 2, to['b'] = 3, to['r'] = 4, to['o'] = 5;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			f[i].push_back(power(4, (1ll << i) - 2) % mod);
		}
	}
	if (m == 0) {
		printf("%lld\n", 6 * power(4, (1ll << n) - 2) % mod);
		return 0;
	}
	for (int i = 0; i < m; i++) {
		long long x; scanf("%lld%s", &x, buf);
		int id = to[buf[0]];
		Insert(x, id);
	}
	auto qwq = dfs(1, n);
	long long ans = 0;
	for (auto it : qwq) {
		ans += it;
	}
	ans %= mod;
	printf("%lld\n", ans);
	return 0;
}