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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		a[i] = nxt();
	}

	int need = n - a[m - 1];
	vector<int> b(m - 1, 1);
	int sum = m - 1;
	for (int i = m - 2; i >= 0; --i) {
		int tmp = min(a[i] - 1, need - sum);
		if (tmp < 0) {
			tmp = 0;
		}
		b[i] += tmp;
		sum += tmp;
	}
	if (sum != need) {
		cout << "-1\n";
		return 0;
	}
	b.insert(b.begin(), 0);
	for (int i = 1; i < m; ++i) {
		b[i] += b[i - 1];
	}
	for (int i = 0; i < m; ++i) {
		if (b[i] + a[i] > n) {
			cout << "-1\n";
			return 0;
		}
	}
	for (auto& x : b) {
		x += 1;
	}
	for (auto x : b) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}