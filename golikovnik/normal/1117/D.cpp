#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

const int N = 105;

using Matrix = array<array<int, N>, N>;

Matrix empty() {
	Matrix res;
	for (int i = 0; i < N; i++) {
		res[i].fill(0);
	}
	return res;
}

int add(int x, int y) {
	return x + y >= MOD ? x + y - MOD : x + y;
}

int mul(int x, int y) {
	return 1LL * x * y % MOD;
}

Matrix add(Matrix &a, Matrix &b) {
	Matrix c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = add(a[i][j], b[i][j]);
		}
	}
	return c;
}

Matrix mul(Matrix &a, Matrix &b) {
	Matrix c = empty();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return c;
}

Matrix pw(Matrix &a, ll n) {
	Matrix res;
	for (int i = 0; i < N; i++) {
		res[i][i] = 1;
	}
	for (; n; n >>= 1, a = mul(a, a)) if (n & 1) {
		res = mul(res, a);
	}
	return res;
}

void run() {
	ll n, m;
	cin >> n >> m;
	Matrix A = empty();
	A[0][0] = A[0][m - 1] = 1;
	for (int i = 1; i < m; i++) {
		A[i][i - 1] = 1;
	}
	A = pw(A, n);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans = add(ans, A[m - 1][i]);
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}