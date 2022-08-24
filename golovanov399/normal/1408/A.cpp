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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n = nxt();
	vector<int> a(n), b(n), c(n);
	generate(all(a), nxt);
	generate(all(b), nxt);
	generate(all(c), nxt);
	vector<int> p(n);
	p[0] = a[0];
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] == p[i - 1]) {
			p[i] = b[i];
		} else {
			p[i] = a[i];
		}
	}
	for (int x : {a[n - 1], b[n - 1], c[n - 1]}) {
		if (x != p[n - 2] && x != p[0]) {
			p[n - 1] = x;
			break;
		}
	}
	for (int x : p) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}