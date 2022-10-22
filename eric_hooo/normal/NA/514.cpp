#include <bits/stdc++.h>
using namespace std;

const int B = 1000000;

long long mod;

long long MUL(long long a, long long b) {
	static int BB = (1 << 15) - 1;
	return (a & BB) * b % mod + ((a >> 15 & BB) * b % mod << 15) % mod
		 + (((a >> 30) * b % mod << 15) % mod << 15) % mod;
}

struct Matrix {
	long long a[2][2];
	Matrix() {memset(a, 0, sizeof(a));}
	Matrix operator * (const Matrix &A) const {
		Matrix res;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
			res.a[i][j] = (res.a[i][j] + MUL(a[i][k], A.a[k][j])) % mod;
		}
		return res;
	}
}A;

int f[20010];
vector <long long> a;

long long GetF(long long n) {
	Matrix ans, tmp = A; ans.a[0][0] = 1, ans.a[1][1] = 1;
	while (n) {
		if (n & 1) ans = ans * tmp;
		tmp = tmp * tmp, n >>= 1;
	}
	return ans.a[1][0];
}

int main() {
	mod = 10000;
	long long len = 15000;
	f[1] = 1; for (int i = 2; i <= 15010; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
	long long x; cin >> x;
	for (int i = 0; i < 15000; i++) if (f[i] == x % mod) a.push_back(i);
	A.a[0][0] = 0, A.a[0][1] = 1, A.a[1][0] = 1, A.a[1][1] = 1;
	for (int t = 4; t < 13; t++) {
		mod = mod * 10; int S = a.size();
		for (int i = 1; i < 10; i++) for (int j = 0; j < S; j++) a.push_back(a[j] + i * len);
		vector <long long> b;
		for (int i = 0; i < a.size(); i++) if (GetF(a[i]) == x % mod) b.push_back(a[i]);
		a = b, len = len * 10;
	}
	if (!a.size()) cout << -1 << endl;
	else cout << a[0] << endl;
	return 0;
}