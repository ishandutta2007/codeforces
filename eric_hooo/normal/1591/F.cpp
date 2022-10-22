#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n;
int a[200010];
int st[200010][18];
int lg[200010];

struct BIT {
	int T[200010];
BIT() {memset(T, 0, sizeof(T));}
void modify(int x, int v) {
	x++;
	while (x <= 200005) ADD(T[x], v), x += x & -x;
}

int query(int x) {
	x++;
	int res = 0;
	while (x) ADD(res, T[x]), x -= x & -x;
	return res;
}
}T, S;

int MIN(int x, int y) {
	return a[x] < a[y] ? x : y;
}

int Query(int l, int r) {
	int k = lg[r - l + 1];
	return MIN(st[l][k], st[r - (1 << k) + 1][k]);
}

int Solve(int l, int r) {
	if (l == r) return T.query(l);
	int mid = Query(l, r - 1);
	int sum = Solve(l, mid);
	int val = 1ll * sum * a[mid] % mod;
	T.modify(mid + 1, mod - val);
	T.modify(r + 1, val);
	ADD(sum, Solve(mid + 1, r));
	return sum;
}

int main() {
	scanf("%d", &n);
	lg[0] = -1; for (int i = 1; i <= n; i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		st[i][0] = i;
	}
	for (int j = 1; j < 18; j++) {
		for (int i = 0; i < n; i++) {
			if (i + (1 << j) - 1 >= n) break;
			st[i][j] = MIN(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}
	T.modify(0, 1), T.modify(1, mod - 1);
	Solve(0, n);
	int ans = T.query(n);
	if (n & 1) ans = (mod - ans) % mod;
	printf("%d\n", ans);
	return 0;
}