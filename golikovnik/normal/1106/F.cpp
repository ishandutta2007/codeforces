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

const int K = 105;

using Matrix = array<array<int, K>, K>;

int add(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return x + y >= mod ? x + y - mod : x + y;
}

int sub(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return x - y < 0 ? x - y + mod : x - y;
}

int mul(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return 1LL * x * y % mod;
}

int pw(int a, int n, int mod = MOD998) {
	assert(0 <= a && a < mod);
	int res = 1 % mod;
	while (n) {
		if (n & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
		n >>= 1;
	}
	return res;
}

int inv(int x, int mod = MOD998) {
	return pw(x, mod - 2, mod);
}

vector<int> get_invs(int upto, int mod = MOD998) {
	vector<int> res(upto + 1);
	res[1] = 1;
	for (int i = 2; i <= upto; i++) {
		res[i] = mod - mul(mod / i, res[mod % i], mod);
	}
	return res;
}

Matrix add(Matrix a, Matrix b) {
	Matrix c;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			c[i][j] = add(a[i][j], b[i][j], MOD998 - 1);
		}
	}
	return c;
}

Matrix empty() {
	Matrix res;
	for (int i = 0; i < K; i++) {
		res[i].fill(0);
	}
	return res;
}

Matrix mul(Matrix a, Matrix b) {
	Matrix c = empty();
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < K; k++) {
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j], MOD998 - 1), MOD998 - 1);
			}
		}
	}
	return c;
}

Matrix eye() {
	Matrix res = empty();
	for (int i = 0; i < K; i++) {
		res[i][i] = 1;
	}
	return res;
}

Matrix pw(Matrix a, int n) {
	Matrix res = eye();
	for (; n; n >>= 1, a = mul(a, a)) if (n & 1) {
		res = mul(res, a);
	}
	return res;
}

void run() {
	int k;
	cin >> k;
	vector<int> b(k);
	for (int &x : b) {
		cin >> x;
		x %= (MOD998 - 1);
	}
	int n, m;
	cin >> n >> m;
	Matrix A = empty();
	for (int i = 0; i < k - 1; i++) {
		A[i][i + 1] = 1;
	}
	for (int i = 0; i < k; i++) {
		A[k - 1][i] = b[k - i - 1];
	}
	A = pw(A, n - k);
	int power = A[k - 1][k - 1];
	int root = 3;
	int base = pw(root, power);
	if (!base) {
		cout << "-1\n";
		return;
	}
	int N = 31595;
	int P = (MOD998 + N - 1) / N;
	map<int, int> fp;
	for (int i = 0; i < P; i++) {
		int deg = N * (i + 1) % (MOD998 - 1);
		fp[pw(base, deg)] = N * (i + 1);
	}
	for (int i = 0; i <= N; i++) {
		int fq = mul(m, pw(base, i));
		if (fp.count(fq)) {
			cout << pw(root, (fp[fq] - i)) << "\n";
			return;
		}
	}
	cout << "-1\n";
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