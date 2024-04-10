#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int n, x;
int a[150010];
int ans;
int pw[150010];

int GetMid(int l, int r, int d) {
	return lower_bound(a + l, a + r, (a[l] >> d | 1) << d) - a;
	int mid = l; while (mid < r && !(a[mid] >> d & 1)) mid++;
	return mid;
}

int Solve(int l, int r, int L, int R, int d) {
	if (d == -1 || l == r || L == R) return 1ll * (pw[r - l] - 1) * (pw[R - L] - 1) % mod;
	int m = GetMid(l, r, d), M = GetMid(L, R, d);
	if (!(x >> d & 1)) {
		int ans = 0;
		ADD(ans, Solve(l, m, L, M, d - 1)), ADD(ans, Solve(m, r, M, R, d - 1));
		return ans;
	}
	int ls = (1ll * Solve(l, m, M, R, d - 1) + pw[m - l] + pw[R - M] + mod - 1) % mod;
	int rs = (1ll * Solve(m, r, L, M, d - 1) + pw[r - m] + pw[M - L] + mod - 1) % mod;
	int ans = 1ll * ls * rs % mod;
	SUB(ans, pw[r - l]);
	SUB(ans, pw[R - L]);
	ADD(ans, 1);
	return ans;
}

void Solve(int l, int r, int d) {
	int mid = GetMid(l, r, d);
	ADD(ans, pw[mid - l] - 1), ADD(ans, pw[r - mid] - 1);
	ADD(ans, Solve(l, mid, mid, r, d - 1));
}

int main() {
	pw[0] = 1; for (int i = 1; i <= 150005; i++) pw[i] = pw[i - 1] * 2 % mod;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (x == 0) {
		for (int i = 0; i < n; i++) {
			int j = i, mul = 1; while (j < n && a[i] == a[j]) j++, mul = mul * 2 % mod;
			ADD(ans, mul - 1);
			i = j - 1;
		}
		printf("%d\n", ans);
		return 0;
	}
	int d = 29; while (!(x >> d) & 1) d--;
	for (int i = 0; i < n; i++) {
		int j = i; while (j < n && (a[i] >> d + 1) == (a[j] >> d + 1)) j++;
		Solve(i, j, d);
		i = j - 1;
	}
	printf("%d\n", ans);
	return 0;
}