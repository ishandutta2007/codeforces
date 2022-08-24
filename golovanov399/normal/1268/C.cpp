#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <typename T = int>
struct Fenwick {
	int n;
	vector<T> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, T x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	T get(int pos) {
		T res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	int getmin(T need) {
		int res = 0;
		for (int i = (1 << 20); i > 0; i /= 2) {
			if (res + i <= n && a[res + i - 1] < need) {
				need -= a[res + i - 1];
				res += i;
			}
		}
		return res;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
	}
	vector<int> q(n);
	for (int i = 0; i < n; ++i) {
		q[p[i]] = i;
	}

	long long inversions = 0;
	long long sum = 0;
	Fenwick<int> f(n);
	Fenwick<long long> fs(n);
	for (int i = 0; i < n; ++i) {
		inversions += i - f.get(q[i]);
		sum += q[i];
		f.add(q[i], 1);
		fs.add(q[i], q[i]);
		int pos = f.getmin(i / 2 + 1);
		printf("%lld ", inversions + 1ll * pos * (i / 2) - 1ll * (i / 2) * (i / 2 + 1) / 2 - fs.get(pos - 1) + sum - fs.get(pos) - 1ll * pos * ((i + 1) / 2) - 1ll * (i + 1) / 2 * ((i + 1) / 2 + 1) / 2);
	}
	printf("\n");

	return 0;
}