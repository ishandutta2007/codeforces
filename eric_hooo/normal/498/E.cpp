#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int MOD(long long a) {return a - a / mod * mod;}

struct matrix {
	int a[128][128];
	matrix() {memset(a, 0, sizeof(a));}
};

matrix mul(matrix a, matrix b, int n) {
	matrix res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				add(res.a[i][j], MOD(1ll * a.a[i][k] * b.a[k][j]));
			}
		}
	}
	return res;
}

int main () {
	matrix res;
	int pd = 1;
	for (int n = 1; n <= 7; n++) {
		int m; cin >> m;
		if (!m) continue;
		matrix trans;
		int full = (1 << n) - 1;
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int m1 = 0; m1 < (1 << n - 1); m1++) {
				for (int m2 = 0; m2 < (1 << n); m2++) {
					for (int i = 0; i < n; i++) {
						int cnt = !(mask >> i & 1) + (i == 0 || m1 >> i - 1 & 1) + (i == n - 1 || m1 >> i & 1) + (m2 >> i & 1);
						if (cnt == 4) goto NEXT;
					}
					trans.a[mask][~m2 & full]++;
					NEXT:;
				}
			}
		}
		matrix ans; int pdd = 1;
		while (m) {
			if (m & 1) {
				if (pdd) ans = trans, pdd = 0;
				else ans = mul(ans, trans, 1 << n);
			}
			trans = mul(trans, trans, 1 << n), m >>= 1;
		}
		if (pd) res = ans, pd = 0;
		else res = mul(res, ans, 1 << n);
	}
	cout << res.a[0][0] << endl;
	return 0;
}