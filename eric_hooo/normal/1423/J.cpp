#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int inv2 = 500000004;
const int M = 128;

struct Hash_table {
	int head[M];
	int nxt[M], val[M], tot;
	long long to[M];
	void clear() {memset(head, -1, sizeof(head)), tot = 0;}
	int &operator [] (const long long &x) {
		for (int i = head[x % M]; ~i; i = nxt[i]) {
			if (to[i] == x) return val[i];
		}
		to[tot] = x, nxt[tot] = head[x % M], val[tot] = 0, head[x % M] = tot++;
		return val[tot - 1];
	}
	int count(const long long &x) const {
		for (int i = head[x % M]; ~i; i = nxt[i]) {
			if (to[i] == x) return 1;
		}
		return 0;
	}
}all;

int dfs(long long m) {
	if (m < 0) return 0;
	if (m < 2) return 1;
	if (all.count(m)) return all[m];
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += dfs((m >> 1) - i) - mod;
		ans += ans >> 31 & mod;
	}
	return all[m] = ans;
}

vector <long long> ord;
int dp[60000000];
int DP[10000];
int st[1000], tp;

long long read() {
	long long x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x;
}

void print(int x) {
	tp = 0;
	if (!x) st[tp++] = 0;
	while (x) {
		st[tp++] = x % 10;
		x /= 10;
	}
	while (tp--) putchar('0' + st[tp]);
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		long long n; scanf("%I64d", &n);
		n = n >> 1;
		long long m = n >> 1; m++, m %= mod;
		long long ans = m * (m + 1) % mod;
		if (n % 2 == 0) ans = (ans - m + mod) % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}