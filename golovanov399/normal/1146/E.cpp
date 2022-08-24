#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Query {
	int sign;
	int x;

	void scan() {
		char c;
		cin >> c >> x;
		sign = (c == '>') ? 1 : -1;
		x = x * 2 + sign;
	}
};

const int N = 222222;

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] ^= x;
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res ^= a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int bij[2 * N + 1000];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() * 2;
	}

	vector<Query> qrs(q);
	for (auto& qr : qrs) {
		qr.scan();
	}

	vector<int> xs;
	for (const auto& qr : qrs) {
		xs.push_back(abs(qr.x));
	}
	make_unique(xs);

	int center_sign = 1;
	for (const auto& qr : qrs) {
		if ((qr.sign > 0) != (qr.x > 0)) {
			center_sign *= -1;
		}
	}

	Fenwick f(2 * N + 10);

	int idx = q - 1;
	reverse(all(xs));
	vector<array<int, 3>> shit;
	int last = N - 1;
	for (int x : xs) {
		while (abs(qrs[idx].x) > x) {
			f.add(qrs[idx].x * qrs[idx].sign + N, 1);
			--idx;
		}
		int sign = -qrs[idx].sign;
		shit.push_back({x, last, f.get(-last + N) ? -sign : sign});
		last = x;
	}

	for (int i = -xs.back() + 1; i < xs.back(); ++i) {
		bij[i + N] = i * center_sign;
	}
	for (const auto& ar : shit) {
		for (int i = ar[0]; i < ar[1]; ++i) {
			bij[i + N] = bij[-i + N] = ar[2] * i;
		}
	}

	for (int x : a) {
		printf("%d ", bij[x + N] / 2);
	}
	printf("\n");

	return 0;
}