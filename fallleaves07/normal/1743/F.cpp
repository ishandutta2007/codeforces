#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

struct Matrix {
	int a[2][2];
	Matrix(int a00, int a01, int a10, int a11) {
		a[0][0] = a00, a[0][1] = a01, a[1][0] = a10, a[1][1] = a11;
	}
	Matrix(int val = 0) {
		memset(a, 0, sizeof(a));
		a[0][0] = a[1][1] = val;
	}
	Matrix operator*(const Matrix &b) const {
		Matrix c;
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 2; k++) {
				for (int j = 0; j < 2; j++) {
					c.a[i][j] = (c.a[i][j] + 1ll * a[i][k] * b.a[k][j]) % M;
				}
			}
		}
		return c;
	}
};

struct Segt {
	int n;
	Matrix f0, f1, g0, g1;
	vector<Matrix> t;
	Segt(const vector<int> &a) : 
		n(a.size()), f0(1, 0, 0, 0), f1(0, 1, 0, 0), g0(3, 0, 1, 2), g1(1, 2, 1, 2), t(n << 2 | 1) {
			build(a, 1, 1, n);
		}
	void change(int loc, int val) {
		change(loc, val, 1, 1, n);
	}
#define mid ((l + r) >> 1)
#define ls (v << 1)
#define rs (v << 1 | 1)
	void build(const vector<int> &a, int v, int l, int r) {
		if (l == r) {
			if (l == 1) {
				t[v] = (a[0] ? f1 : f0);
			} else {
				t[v] = (a[l - 1] ? g1 : g0);
			}
		} else {
			build(a, ls, l, mid);
			build(a, rs, mid + 1, r);
			t[v] = t[ls] * t[rs];
		}
	}
	void change(int loc, int val, int v, int l, int r) {
		if (l == r) {
			if (l == 1) {
				t[v] = (val ? f1 : f0);
			} else {
				t[v] = (val ? g1 : g0);
			}
		} else {
			if (loc <= mid) {
				change(loc, val, ls, l, mid);
			} else {
				change(loc, val, rs, mid + 1, r);
			}
			t[v] = t[ls] * t[rs];
		}
	}
#undef mid
#undef ls
#undef rs
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int>> rg;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		mx = max(mx, r + 1);
		rg.emplace_back(l, i + 1);
		rg.emplace_back(r + 1, -i - 1);
	}
	sort(rg.begin(), rg.end());
	vector<int> a(n, 0);
	Segt t(a);
	int ans = 0;
	for (int i = 0; i < (int)rg.size(); i++) {
		if (rg[i].first < mx) {
			if (rg[i].second > 0) {
				t.change(rg[i].second, 1);
			} else {
				t.change(-rg[i].second, 0);
			}
			if (rg[i].first < rg[i + 1].first) {
				ans = (ans + 1ll * t.t[1].a[0][1] * (rg[i + 1].first - rg[i].first)) % M;
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}