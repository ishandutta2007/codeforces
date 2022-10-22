#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;

int mod;
vector <long long> all;
map <long long, int> S;
int n;

struct Matrix {
	int a[2][2];
	Matrix() {memset(a, 0, sizeof(a));}
	Matrix(int A, int B, int C, int D) {a[0][0] = A, a[0][1] = B, a[1][0] = C, a[1][1] = D;}
	Matrix operator * (const Matrix &A) const {
		Matrix res;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				long long tmp = 0;
				for (int k = 0; k < 2; k++) {
					tmp += 1ll * a[i][k] * A.a[k][j];
				}
				res.a[i][j] = tmp % mod;
			}
		}
		return res;
	}
};

Matrix st[50010][16];
Matrix FULL;
int s[50010];

void get_st() {
	for (int i = 0; i < n; i++) {
		st[i][0] = Matrix(s[(i + 1) % n], 1, s[i], 0);
	}
	for (int j = 1; j < 16; j++) {
		for (int i = 0; i < n; i++) {
			if (i + (1 << j) - 1 >= n) break;
			st[i][j] = st[i][j - 1] * st[i + (1 << j - 1)][j - 1];
		}
	}
}

Matrix get_rng(int l, int r) {
	Matrix ans(1, 0, 0, 1);
	for (int j = 15; j >= 0; j--) {
		if (l + (1 << j) - 1 > r) continue;
		ans = ans * st[l][j], l += 1 << j;
	}
	return ans;
}

Matrix get_matrix(long long x) {
	return Matrix(S.count(x + 1) ? S[x + 1] : s[(x + 1) % n], 1, S.count(x) ? S[x] : s[x % n], 0);
}

Matrix power(const Matrix &a, long long b) {
	if (!b) return Matrix(1, 0, 0, 1);
	Matrix tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp * a : tmp * tmp;
}

Matrix get_RNG(long long l, long long r) {
	if (l > r) return Matrix(1, 0, 0, 1);
	if (l / n == r / n) return get_rng(l % n, r % n);
	return get_rng(l % n, n - 1) * power(FULL, r / n - l / n - 1) * get_rng(0, r % n);
}

int main () {
	long long K; scanf("%I64d%d", &K, &mod);
	if (mod == 1) {
		printf("0\n");
		return 0;
	}
	if (K == 0) {
		printf("0\n");
		return 0;
	}
	if (K == 1) {
		printf("1\n");
		return 0;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		s[i] %= mod;
	}
	get_st(), FULL = get_rng(0, n - 1);
	int Q; scanf("%d", &Q);
	while (Q--) {
		long long x; int v; scanf("%I64d%d", &x, &v);
		v %= mod; 
		S[x] = v;
		all.push_back(x - 1), all.push_back(x);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	while (all.size() && all.back() > K - 2) all.pop_back();
	Matrix ans(1, 0, 0, 1);
	long long lst = 0;
	for (int i = 0; i < all.size(); i++) {
		long long x = all[i];
		ans = ans * get_RNG(lst, x - 1);
		ans = ans * get_matrix(x), lst = x + 1;
	}
	ans = ans * get_RNG(lst, K - 2);
	printf("%d\n", ans.a[0][0]);
	return 0;
}