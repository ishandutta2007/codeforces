#include <bits/stdc++.h>
using namespace std;

const int B = 10;

int n;
long long a[1000010];
int b[1000010];
int cnt[1 << 16];

struct BIT {
	int T[1000010];
	long long S[1000010];
	void clear() {memset(T, 0, sizeof(T)), memset(S, 0, sizeof(S));}
	void modify(int x, int v) {
		for (int i = x; i <= 1000005; i += i & -i) {
			T[i] += v, S[i] += x * v;
		}
	}
	void modify(int l, int r, int v) {
		modify(l, v), modify(r + 1, -v);
	}
	int query(int x) {
		long long res = 0;
		for (int i = x; i; i -= i & -i) {
			res += 1ll * (x + 1) * T[i] - S[i];
		}
		return res;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
}f[10], g[10];

int p[1000010], q[1000010], tp, tq;

int PopCount(long long x) {return cnt[x & 65535] + cnt[x >> 16 & 65535] + cnt[x >> 32 & 65535] + cnt[x >> 48];}

long long Solve(int it) {
	long long ans = 0;
	int sum = 0;
	tp = tq = 0, p[tp++] = 0, q[tq++] = 0;
	for (int i = 0; i < 10; i++) {
		f[i].clear(), g[i].clear();
	}
	auto Calc = [&](BIT &f, int l, int r, int v, BIT &g) -> void {
		f.modify(l, r, v), sum += v * g.query(l, r);
	};
	for (int i = 1; i <= n; i++) {
		while (tp > 1 && a[p[tp - 1]] > a[i]) {
			tp--;
			int x = b[p[tp]];
			if (x / B == it) Calc(f[x % B], p[tp - 1] + 1, p[tp], -1, g[x % B]);
		}
		p[tp] = i;
		int x = b[i];
		if (x / B == it) Calc(f[x % B], p[tp - 1] + 1, p[tp], 1, g[x % B]);
		tp++;
		while (tq > 1 && a[q[tq - 1]] < a[i]) {
			tq--;
			int x = b[q[tq]];
			if (x / B == it) Calc(g[x % B], q[tq - 1] + 1, q[tq], -1, f[x % B]);
		}
		q[tq] = i;
		if (x / B == it) Calc(g[x % B], q[tq - 1] + 1, q[tq], 1, f[x % B]);
		tq++;
		ans += sum;
	}
	return ans;
}

int main() {
	for (int i = 0; i < (1 << 16); i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = PopCount(a[i]);
	}
	long long ans = 0;
	for (int it = 0; it < 6; it++) {
		ans += Solve(it);
	}
	printf("%lld\n", ans);
	return 0;
}