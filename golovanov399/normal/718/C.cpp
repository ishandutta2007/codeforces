#include "bits/stdc++.h"

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

struct Matrix {
	long long a[3];

	Matrix() {
		// a = (long long*)malloc(sizeof(long long) * 3);
		memset(a, 0, sizeof(long long) * 3);
	}

	Matrix (const Matrix& other) {
		// a = (long long*)malloc(sizeof(long long) * 3);
		memcpy(a, other.a, sizeof(long long) * 3);
	}

	~Matrix() {
		// free(a);
	}

	Matrix(const vector<long long>& ar) {
		// a = (long long*)malloc(sizeof(long long) * 3);
		a[0] = ar[0];
		a[1] = ar[1];
		a[2] = ar[2];
	}

	Matrix operator *(const Matrix& m) const {
		Matrix res;
		// res.a[0][0] = (a[0][0] * m.a[0][0] + a[0][1] * m.a[1][0]) % mod;
		// res.a[0][1] = res.a[1][0] = (a[0][0] * m.a[0][1] + a[0][1] * m.a[1][1]) % mod;
		// res.a[1][1] = (a[1][0] * m.a[0][1] + a[1][1] * m.a[1][1]) % mod;
		res.a[0] = (a[0] * m.a[0] + a[1] * m.a[1]) % mod;
		res.a[1] = (a[0] * m.a[1] + a[1] * m.a[2]) % mod;
		res.a[2] = (a[1] * m.a[1] + a[2] * m.a[2]) % mod;
		return res;
	}

	Matrix operator +(const Matrix& m) const {
		Matrix res;
		// for (int i = 0; i < 2; i++) {
		// 	for (int j = 0; j < 2; j++) {
		// 		res.a[i][j] = a[i][j] + m.a[i][j];
		// 		if (res.a[i][j] >= mod) {
		// 			res.a[i][j] -= mod;
		// 		}
		// 	}
		// }
		for (int i = 0; i < 3; i++) {
			res.a[i] = a[i] + m.a[i];
			if (res.a[i] >= mod) {
				res.a[i] -= mod;
			}
		}
		return res;
	}

	// pair<int, int> operator *(const pair<int, int>& p) const {
	// 	return make_pair((a[0][0] * p.first + a[0][1] * p.second) % mod,
	// 					 (a[1][0] * p.first + a[1][1] * p.second) % mod);
	// }
} id({1, 0, 1}), fib({0, 1, 1}), zero;

struct SegmentTree {
	int n;
	vector<Matrix> a;
	vector<Matrix> tomult;

	SegmentTree(const vector<Matrix>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); i++) {
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; i--) {
			a[i] = a[i + i] + a[i + i + 1];
		}
		tomult.resize(n + n, id);
	}

	void relax(int v) {
		if (v >= n) {
			return;
		}
		tomult[v + v] = tomult[v + v] * tomult[v];
		tomult[v + v + 1] = tomult[v + v + 1] * tomult[v];
		a[v] = a[v] * tomult[v];
		tomult[v] = id;
	}

	Matrix _get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return zero;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return a[v] * tomult[v];
		}
		int mid = (l1 + r1) / 2;
		relax(v);
		return _get(v + v, l1, mid, l, r) + _get(v + v + 1, mid, r1, l, r);
	}

	Matrix get(int l, int r) {
		return _get(1, 0, n, l, r);
	}

	void _mult(int v, int l1, int r1, int l, int r, const Matrix& m) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			tomult[v] = tomult[v] * m;
			return;
		}
		int mid = (l1 + r1) / 2;
		relax(v);
		_mult(v + v, l1, mid, l, r, m);
		_mult(v + v + 1, mid, r1, l, r, m);
		a[v] = a[v + v] * tomult[v + v] + a[v + v + 1] * tomult[v + v + 1];
	}

	void mult(int l, int r, const Matrix& m) {
		_mult(1, 0, n, l, r, m);
	}
};

Matrix pw(Matrix a, long long b) {
	Matrix res = id;
	while (b) {
		if (b & 1ll) {
			res = res * a;
		}
		b >>= 1;
		a = a * a;
	}
	return res;
}

int main(){

	int n = nxt(), m = nxt();
	vector<Matrix> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = pw(fib, nxt());
	}

	SegmentTree tree(a);

	cout.sync_with_stdio(0);

	for (int i = 0; i < m; i++) {
		int tp = nxt();
		if (tp == 1) {
			int l = nxt() - 1, r = nxt();
			int x = nxt();
			tree.mult(l, r, pw(fib, x));
		} else {
			int l = nxt() - 1, r = nxt();
			cout << tree.get(l, r).a[1] << "\n";
		}
	}

	return 0;
}