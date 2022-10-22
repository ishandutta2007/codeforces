#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long MOD(long long x) {return (x % mod + mod) % mod;}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

struct Point {
	int x, y;
	Point() {x = y = 0;}
	Point(int X, int Y) {x = X, y = Y;}
	Point operator + (const Point &A) const {return Point(x + A.x, y + A.y);}
	Point operator - (const Point &A) const {return Point(x - A.x, y - A.y);}
	long long operator ^ (const Point &A) const {return 1ll * x * A.y - 1ll * y * A.x;}
	// long long operator * (const Point &A) const {return 1ll * x * A.x + 1ll * y * A.y;}
};

int n;
Point a[500010];
int X[1000010], Y[1000010];
int s0[1000010], s1[1000010];

long long GetPointSum(int l, int r, Point x) {
	return MOD(Point(X[r] - X[l], Y[r] - Y[l]) ^ x);
	// int ans = 0;
	// for (int i = l; i < r; i++) {
	// 	ADD(ans, MOD(a[i % n] ^ x));
	// }
	// return ans;
}

long long GetEdgeSum(int l, int r, int c1, int c2) {
	return (1ll * c1 * (s0[r] - s0[l] + mod) + 1ll * c2 * (s1[r] - s1[l] + mod)) % mod;
	// int ans = 0;
	// for (int i = l; i < r; i++) {
	// 	ADD(ans, 1ll * MOD(a[i % n] ^ a[(i + 1) % n]) * c1 % mod);
	// 	ADD(ans, 1ll * MOD(a[i % n] ^ a[(i + 1) % n]) * i % mod * c2 % mod);
	// }
	// return ans;
}

long long GetSum(int i, int l, int r) { // [l, r)
	// [i, l) + [i, l + 1) + ... + [i, r)
	// int ans = 0;
	// for (int j = l; j < r; j++) {
	// 	for (int t = l; t < j; t++) {
	// 		ADD(ans, MOD(a[t % n] ^ a[(t + 1) % n]));
	// 	}
	// 	// ADD(ans, MOD(a[j % n] ^ a[i % n]));
	// }
	// ADD(ans, GetEdgeSum(i, l, r - l, 0));
	// ADD(ans, GetPointSum(l, r, a[i]));
	// return ans;
	return (GetEdgeSum(i, l, r - l, 0) + GetEdgeSum(l, r, r - 1, mod - 1) + GetPointSum(l, r, a[i])) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	reverse(a, a + n);
	; for (int i = 0; i < n * 2; i++) ADD(X[i + 1] = X[i], MOD(a[i % n].x));
	; for (int i = 0; i < n * 2; i++) ADD(Y[i + 1] = Y[i], MOD(a[i % n].y));
	; for (int i = 0; i < n * 2; i++) ADD(s0[i + 1] = s0[i], MOD(a[i % n] ^ a[(i + 1) % n]));
	; for (int i = 0; i < n * 2; i++) ADD(s1[i + 1] = s1[i], 1ll * MOD(a[i % n] ^ a[(i + 1) % n]) * i % mod);
	int j = 1;
	long long S = 0, tot = 0; for (int i = 0; i < n; i++) tot += a[i] ^ a[(i + 1) % n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (S < tot - S) {
			S -= a[j % n] ^ a[i];
			S += a[j % n] ^ a[(j + 1) % n];
			S += a[(j + 1) % n] ^ a[i];
			j++;
		}
		// [i + 2, j), [j, i + n - 1)
		ADD(ans, (tot % mod * (j - i - 2) % mod - 2 * GetSum(i, i + 2, j) % mod + mod) % mod);
		ADD(ans, (2 * GetSum(i, j, i + n - 1) - tot % mod * (i + n - 1 - j) % mod + mod) % mod);
		S -= a[j % n] ^ a[i];
		S -= a[i] ^ a[(i + 1) % n];
		S += a[j % n] ^ a[(i + 1) % n];
	}
	ans = ans & 1 ? ans + mod >> 1 : ans >> 1;
	printf("%d\n", ans);
	return 0;
}