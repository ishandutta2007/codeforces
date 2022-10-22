#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, q;
long long a[110];
long long b[100010];
long long T[100010], S[100010];
long long sumb = 0;

long long GetSum(int x) {return 1ll * (1 + x) * x / 2;}

void modify(int x, int v) {
	for (int i = x; i <= N; i += i & -i) {
		T[i] += v, S[i] += v * x;
	}
}

void modify(int l, int r, int x) {
	modify(l, x), modify(r + 1, -x);
}

long long query(int x) {
	long long res = 0;
	for (int i = x; i; i -= i & -i) {
		res += (x + 1) * T[i] - S[i];
	}
	return res;
}

long long query(int l, int r) {
	return query(r) - query(l - 1);
}

long long Solve() {
	long long ans = sumb, sum = query(1, m - 1);
	for (int i = 1; i < n; i++) {
		long long x = a[i]; sum += x;
		int pos = 0; long long val = 0;
		for (int j = 16; j >= 0; j--) {
			int np = pos | 1 << j;
			if (np < m && val + T[np] <= x) pos = np, val += T[np];
		}
		ans += (pos + i) * x + query(pos + 1, m - 1);
	}
	ans = sum * (n + m - 1) - ans;
	ans += (a[0] + b[0]) * (n + m - 1);
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &b[i]);
	}
	for (int i = n - 1; i >= 1; i--) {
		a[i] -= a[i - 1];
	}
	for (int i = m - 1; i >= 1; i--) {
		b[i] -= b[i - 1];
	}
	for (int i = 1; i < m; i++) {
		modify(i, b[i] - (i == 1 ? 0 : b[i - 1]));
		sumb += b[i] * i;
	}
	while (q--) {
		int op, k, d; scanf("%d%d%d", &op, &k, &d);
		if (op == 1) {
			for (int i = n - k; i < n; i++) {
				a[i] += d;
			}
		} else {
			if (m == k) b[0] += d;
			modify(max(1, m - k), d);
			sumb += d * (GetSum(m - 1) - GetSum(max(1, m - k) - 1));
		}
		printf("%lld\n", Solve());
	}
	return 0;
}