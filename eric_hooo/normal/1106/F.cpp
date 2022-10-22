#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, MOD = 998244352;

struct Num {
	int a, b;
	Num() {a = b = 0;}
	Num(int x, int y) {a = x, b = y;}
	Num operator + (const Num &A) const {return Num((a + A.a) % MOD, (b + A.b) % MOD);}
	Num operator * (const int &A) const {return Num(1ll * a * A % MOD, 1ll * b * A % MOD);}
};

struct Matrix {
	int a[110][110];
	Matrix() {memset(a, 0, sizeof(a));}
	Matrix operator * (const Matrix &A) const {
		Matrix res;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				for (int k = 0; k < 100; k++) {
					res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * A.a[k][j]) % MOD;
				}
			}
		}
		return res;
	}
}A, ans;

struct Hash_table {
	int head[10000009], nxt[10000000], to[10000000], val[10000000], TOT;
	void clear() {memset(head, -1, sizeof(head)), TOT = 0;}
	void set(const int &x, int y) {
		int H = x % 10000009;
		for (int i = head[H]; ~i; i = nxt[i]) {
			if (to[i] == x) return ;
		}
		to[TOT] = x, val[TOT] = y, nxt[TOT] = head[H], head[H] = TOT++;
	}
	int get(const int &x) const {
		int H = x % 10000009;
		for (int i = head[H]; ~i; i = nxt[i]) {
			if (to[i] == x) return val[i];
		}
		return -1;
	}
}hsh;

int Block = 30000;

void precalc(int G, int P) {
	long long mul = 1;
	for (int i = 0; i < Block; i++) {
		mul = mul * G % P;
	}
	long long pw = mul;
	hsh.clear();
	for (int i = Block; i - Block < P; i += Block) {
		hsh.set(pw, i);
		pw = pw * mul % P;
	}
}

int get_e(int x, int G, int P) {
	if (x == 1) return 0;
	long long pw = x;
	for (int i = 0; i < Block; i++) {
		int tmp = hsh.get(pw);
		if (tmp != -1) return tmp - i;
		pw = pw * G % P;
	}
	assert(0);
}

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main () {
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> A.a[i][0];
		A.a[i][0] %= MOD;
	}
	for (int i = 0; i + 1 < k; i++) {
		A.a[i][i + 1] = 1;
	}
	int n, val; cin >> n >> val;
	precalc(3, mod);
	val = get_e(val, 3, mod);
	n -= k;
	for (int i = 0; i < k; i++) {
		ans.a[i][i] = 1;
	}
	for (int i = 0; i < 30; i++) {
		if (n >> i & 1) ans = ans * A;
		A = A * A;
	}
	int a = ans.a[0][0];
	int x, y, g = exgcd(a, MOD, x, y);
	if (val % g) cout << -1 << endl;
	else {
		x = ((1ll * val / g * x) % MOD + MOD) % MOD;
		cout << power(3, x) << endl;
	}
	return 0;
}