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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

long long ask(int pos) {
	cout << "? " << pos + 1 << endl;
	return nxt();
}

// #define TEST

#ifdef TEST
const int g_n = 100000;
const int g_k = 2;
const int g_p = 1;
#endif

int main() {
#ifdef TEST
	int n = g_n, k = g_k;
#else
	int n = nxt(), k = nxt();
#endif
	vector<long long> a(n, k);
	vector<long long> b(n, k);
	auto make_one_move = [&]() {
		fill(all(b), 0);
		for (int i = 1; i < n; ++i) {
			b[(i + n - 1) % n] += a[i] / 2;
			b[(i + 1) % n] += (a[i] + 1) / 2;
		}
		b[1] += a[0];
		a.swap(b);
	};

	vector<int> can(n);
	iota(all(can), 0);
	int sz = n;
	int rem = 1000;
	while (sz > 1) {
		// cerr << sz << " ";
		assert(rem--);
		int pos = rand() % n;
		while (sz < 1000) {
			long long last = -1;
			for (int i = 0; i < sz; ++i) {
				auto x = a[(pos - can[i] + n) % n];
				if (last == -1) {
					last = x;
				} else if (last != x) {
					last = -2;
				}
			}
			if (last == -2 || sz == n) {
				break;
			} else {
				pos = (pos + 1) % n;
			}
		}
#ifdef TEST
		auto x = a[(pos - g_p + n) % n];
#else
		auto x = ask(pos);
#endif
		for (int i = 0; i < sz; ++i) {
			if (a[(pos - can[i] + n) % n] != x) {
				swap(can[i--], can[--sz]);
			}
		}
		make_one_move();
	}

#ifdef TEST
	assert(can[0] == g_p);
	cerr << rem << " of 1000 remaining\n";
#else
	cout << "! " << can[0] + 1 << endl;
#endif

	return 0;
}