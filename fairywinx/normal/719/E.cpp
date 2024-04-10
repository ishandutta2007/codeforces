#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>

// #include <algorithm>
// #define int long long

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int MOD = 1e9 + 7;
const int N = 1e5 + 1;

struct fib {
	int A[2][2];
	fib() {
		A[0][0] = 1, A[0][1] = 0, A[1][0] = 0, A[1][1] = 1;
	}
	fib(int a1, int a2, int a3, int a4) {
		A[0][0] = a1, A[0][1] = a2, A[1][0] = a3, A[1][1] = a4;
	}
};

fib operator* (const fib &a, const fib &b) {
	int ans[2][2] = {
		{0, 0},
		{0, 0}
	};
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {

			for(int k = 0; k < 2; ++k)
				ans[i][j] = (ans[i][j] + (long long) a.A[i][k] * b.A[k][j]) % MOD;

		}
	}
	return fib(ans[0][0], ans[0][1], ans[1][0], ans[1][1]);
}

fib pow(fib num, int x) {
	fib ans;
	while(x > 0) {
		if (x & 1)
			ans = ans * num;
		num = num * num;
		x = x >> 1;
	}
	return ans;
}

fib operator+ (fib a, fib b) {
	int ans[2][2];
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 2; ++j) {
			ans[i][j] = a.A[i][j] + b.A[i][j];
			if (ans[i][j] > MOD)
				ans[i][j] -= MOD;
		}
	}
	return fib(ans[0][0], ans[0][1], ans[1][0], ans[1][1]);
}

fib t[4 * N];
fib mod[4 * N];

fib norm = fib(1, 0, 0, 1);

fib st = fib(0, 1, 1, 1);

void push(int v, int l, int r) {
	t[v * 2] = t[v * 2] * mod[v];
	mod[v * 2] = mod[v * 2] * mod[v];
	t[v * 2 + 1] = t[v * 2 + 1] * mod[v];
	mod[v * 2 + 1] = mod[v * 2 + 1] * mod[v];
	mod[v] = norm;
}

void build(int v, int l, int r, vector<int> &a) {
	mod[v] = norm;
	if (r - l == 1) {
		t[v] = pow(st, a[l] - 1);
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m, a);
	build(v * 2, m, r, a);
	t[v] = t[v * 2 + 1] + t[v * 2];
}

int get(int v, int l, int r, int L, int R) {
	if (r <= L || R <= l)
		return 0;
	if (l >= L && r <= R)
		return t[v].A[1][1];

	push(v, l, r);
	int m = (l + r) / 2;
	int z = (get(v * 2 + 1, l, m, L, R) + get(v * 2, m, r, L, R));
	if (z >= MOD)
		z -= MOD;
	return z;
}

fib tmp;

void update(int v, int l, int r, int L, int R) {
	if (r <= L || R <= l)
		return;
	if (l >= L && r <= R) {
		t[v] = t[v] * tmp;
		mod[v] = mod[v] * tmp;
		return;
	}

	push(v, l, r);
	int m = (l + r) / 2;
	update(v * 2 + 1, l, m, L, R);
	update(v * 2, m, r, L, R);
	t[v] = t[v * 2 + 1] + t[v * 2];
}

signed main() {
	setup();

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build(1, 0, n, a);
	while(m--) {
		int type;
		cin >> type;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << get(1, 0, n, l - 1, r) << '\n';
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			tmp = pow(st, x);
			update(1, 0, n, l - 1, r);
		}
	}

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}