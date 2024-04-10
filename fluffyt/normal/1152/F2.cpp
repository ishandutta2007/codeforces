#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
ll cc[105][15];
ll modpow(ll a, int b) {
	ll res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}
int dis[20], arr[20], K, n, m;
ll f[4100][12];
vector<int> bt[4100];
struct HashMap {
	static const int N = 1 << 20, B = N - 1;
	ll key[N], sz; bool vis[N];
	ll val[N];
	int hash(ll x) { return (x << 16 ^ x >> 6 ^ x << 1) & B; }
	int khash(ll x) { return (x << 15 ^ x >> 5 ^ x << 2) & B; }
	void ins(ll x, int y) {
		int t = hash(x), s = khash(x) | 1;
		while (vis[t]) {
			if (key[t] == x) { val[t] += y; return; }
			t = (t + s) & B;
		}
		vis[t] = true, key[t] = x, ++sz, val[t] = y;
	}
	int query(ll x) {
		int t = hash(x), s = khash(x) | 1;
		while (vis[t]) {
			if (key[t] == x) return val[t];
			t = (t + s) & B;
		}
		return 0;
	}
} hm, hn;
void dfs(int k) {
	if (dis[k] >= K) return;
	if (k == n) {
		int mul = 0, cnt = 1;
		for (int i = 1; i < k; i++) {
			int f = 0;
			for (int j = i + 1; j <= k; j++)
				if (dis[j] - dis[i] <= m) f = j - i;
				else break;
			mul = mul * (m + 1) + f;
			if (dis[i + 1] - dis[i] > m) ++cnt;
		}
		hm.ins(mul, cc[dis[k] + 1 - cnt][cnt]);
		return;
	}
	for (int i = 1; i <= m + 1; i++) {
		dis[k + 1] = dis[k] + i;
		dfs(k + 1);
	}
}
int brr[20];
int calc(int n) {
	if (n == 1) return 1;
	int nn = (1 << n) - 1;
	for (int i = 1; i <= nn; i++)
	for (int j : bt[i]) f[i][j] = 0;
	for (int i = 0; i < n; i++) f[1 << i][i] = 1;
	for (int i = 1; i < nn; i++)
	for (int j : bt[i]) if (f[i][j])
	for (int k : bt[nn ^ i]) {
		if (k > j + brr[j]) break;
		f[i | 1 << k][k] += f[i][j];
	}
	ll res = 0;
	for (int i = 0; i < n; i++) res += f[nn][i];
	return res % MOD;
}
int main() {
	scanf("%d%d%d", &K, &n, &m);
	for (int i = 0; i <= K && i <= 100; i++) {
		int nn = K - i;
		cc[i][0] = 1;
		for (int j = 1; j <= nn && j <= n; j++)
			cc[i][j] = cc[i][j - 1] * (nn - j + 1) % MOD * modpow(j, MOD - 2) % MOD;
	}
	dfs(1);
	/*printf("%d\n", hm.sz);
	for (int i = 0; i < hm.N; i++) if (hm.vis[i]) {
		for (int j = hm.key[i], k = 0; k < n; k++, j /= m + 1) printf("%d ", j % 5);
		puts("");
	}*/
	for (int i = 0; i < 1 << n; i++)
	for (int j = 0; j < n; j++) if (i >> j & 1) bt[i].push_back(j);
	ll ans = 0;
	for (int i = 0; i < hm.N; i++) if (hm.vis[i]) {
		for (int j = hm.key[i], k = n - 2; k >= 0; k--, j /= m + 1) arr[k] = j % (m + 1);
		for (int j = 0; j < n - 1; j++) {
			int k = j;
			while (k < n - 1 && arr[k]) ++k;
			for (int l = j; l <= k; l++) brr[l - j] = arr[l];
			int temp = 0;
			for (int l = 0; l <= k - j; l++) temp = temp * (m + 1) + brr[l];
			hn.ins((ll)temp << 5 | (k - j + 1), 0);
			j = k;
		}
	}
	for (int i = 0; i < hn.N; i++) if (hn.vis[i]) {
		int now = hn.key[i] & 31, num = hn.key[i] >> 5;
		for (int j = num, k = now - 1; k >= 0; k--, j /= m + 1) brr[k] = j % (m + 1);
		hn.val[i] = calc(now);
	}
	for (int i = 0; i < hm.N; i++) if (hm.vis[i]) {
		for (int j = hm.key[i], k = n - 2; k >= 0; k--, j /= m + 1) arr[k] = j % (m + 1);
		ll mul = hm.val[i] % MOD, ss = mul;
		for (int j = 0; j < n - 1; j++) {
			int k = j;
			while (k < n - 1 && arr[k]) ++k;
			for (int l = j; l <= k; l++) brr[l - j] = arr[l];
			int temp = 0;
			for (int l = 0; l <= k - j; l++) temp = temp * (m + 1) + brr[l];
			mul = mul * hn.query((ll)temp << 5 | (k - j + 1)) % MOD;
			j = k;
		}
		ans += mul;
	}
	printf("%lld\n", ans % MOD);
	return 0;
}//for (int j = hm.key[i], k = n - 2; k >= 0; k--, j /= m + 1) arr[k] = j % (m + 1);