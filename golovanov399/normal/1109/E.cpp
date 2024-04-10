#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

using Shit = array<int, 12>;
Shit shit;

int mod;
const int N = 111111;
int erat[N];
int idx[N];
struct Num {
	long long rem;
	long long cop;
	Shit M;

	void operator *=(const Num& ot) {
		rem = rem * ot.rem % mod;
		cop = cop * ot.cop % mod;
		for (int i = 0; i < (int)M.size(); ++i) {
			M[i] += ot.M[i];
		}
	}
};

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

inline int inv(int a, int b = mod) {
	return a == 1 ? 1 : b - 1ll * inv(b % a, a) * b / a % b;
}

vector<long long> pws[12];

struct SegTree {
	int n;
	vector<long long> sum;
	vector<Num> a;

	SegTree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		sum.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			sum[n + i] = ar[i] % mod;
			a[n + i].rem = ar[i] % mod;
			a[n + i].cop = 1;
			a[n + i].M = shit;
			for (int x = ar[i]; x > 1; x /= erat[x]) {
				if (mod % erat[x]) {
					a[n + i].cop *= erat[x];
				} else {
					a[n + i].M[idx[erat[x]]] += 1;
				}
			}
			a[n + i].cop %= mod;
		}
		for (int i = (int)ar.size(); i < n; ++i) {
			sum[n + i] = 0;
			a[n + i].rem = a[n + i].cop = 0;
		}
		for (int i = n - 1; i > 0; --i) {
			sum[i] = (sum[i + i] + sum[i + i + 1]) % mod;
			a[i].rem = 1;
			a[i].cop = 1;
		}
	}

	void push(int v) {
		for (int i = 2 * v; i < 2 * v + 2; ++i) {
			a[i] *= a[v];
			sum[i] = sum[i] * a[v].rem % mod;
		}
		a[v].rem = 1;
		a[v].cop = 1;
		a[v].M = shit;
	}

	void mul(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			sum[v] = sum[v] * x % mod;
			a[v].rem = a[v].rem * x % mod;
			while (x > 1) {
				if (mod % erat[x]) {
					a[v].cop = a[v].cop * erat[x] % mod;
				} else {
					a[v].M[idx[erat[x]]] += 1;
				}
				x /= erat[x];
			}
			return;
		}
		int m = (l1 + r1) / 2;
		push(v);
		mul(v + v, l1, m, l, r, x);
		mul(v + v + 1, m, r1, l, r, x);
		sum[v] = (sum[v + v] + sum[v + v + 1]) % mod;
	}

	void mult(int l, int r, int x) {
		mul(1, 0, n, l, r, x);
	}

	void div(int p, int x) {
		vector<int> vertices;
		for (int i = p + n; i > 0; i /= 2) {
			vertices.push_back(i);
		}
		reverse(all(vertices));
		vertices.pop_back();
		for (int v : vertices) {
			push(v);
		}
		int v = p + n;
		while (x > 1) {
			if (mod % erat[x]) {
				a[v].cop = a[v].cop * inv(erat[x], mod) % mod;
			} else {
				a[v].M[idx[erat[x]]] -= 1;
			}
			x /= erat[x];
		}
		a[v].rem = a[v].cop;
		for (int i = 0; i < (int)a[v].M.size(); ++i) {
			a[v].rem = a[v].rem * pws[i][a[v].M[i]] % mod;
		}
		sum[v] = a[v].rem;
		for (int i = (p + n) / 2; i > 0; i /= 2) {
			sum[i] = (sum[i + i] + sum[i + i + 1]) % mod;
		}
	}

	long long getSum(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return sum[v];
		}
		int m = (l1 + r1) / 2;
		push(v);
		return (getSum(v + v, l1, m, l, r) + getSum(v + v + 1, m, r1, l, r)) % mod;
	}

	long long getSum(int l, int r) {
		return getSum(1, 0, n, l, r);
	}
};

// #define TEST

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shit.fill(0);

	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
	}

#ifndef TEST
	int n = nxt(); mod = nxt();
#else
	int n = 100000; mod = 223092870;
#endif

	for (int i = 2, cur = 0; i < N; ++i) {
		if (erat[i] == i && mod % i == 0) {
			idx[i] = cur;
			pws[cur] = {1};
			int cn = 0;
			long long x = 1;
			while (x < N) {
				x *= i;
				++cn;
			}
			cn *= n;
			cn += 100;
			for (int j = 0; j < cn; ++j) {
				pws[cur].push_back(pws[cur][j] * i % mod);
			}

			++cur;
		}
	}
	for (int i = 0; i < 12; ++i) {
		if (pws[i].empty()) {
			pws[i] = {1};
		}
	}

	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
#ifndef TEST
		ar[i] = nxt();
#else
		ar[i] = rand() % 100000 + 1;
#endif
	}
	SegTree tree(ar);

#ifndef TEST
	int q = nxt();
#else
	int q = 100000;
#endif
	while (q--) {
#ifndef TEST
		int t = nxt();
#else
		int t = rand() % 3 + 1;
#endif
		if (t == 1) {
#ifndef TEST
			int l = nxt() - 1, r = nxt(), x = nxt();
#else
			int l = rand() % n, r = rand() % n, x = rand() % 100000 + 1;
			if (l > r) {
				swap(l, r);
			}
			++r;
#endif
			tree.mult(l, r, x);
		} else if (t == 2) {
#ifndef TEST
			int p = nxt() - 1, x = nxt();
#else
			int p = rand() % n, x = rand() % 100000 + 1;
#endif
			tree.div(p, x);
		} else if (t == 3) {
#ifndef TEST
			int l = nxt() - 1, r = nxt();
#else
			int l = rand() % n, r = rand() % n;
			if (l > r) {
				swap(l, r);
			}
			++r;
#endif
			printf("%lld\n", tree.getSum(l, r));
		} else {
			assert(false);
		}
	}

	return 0;
}