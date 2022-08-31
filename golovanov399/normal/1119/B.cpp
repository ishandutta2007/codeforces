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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), h = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int k = n; k >= 0; --k) {
		vector<int> b = {a.begin(), a.begin() + k};
		sort(all(b));
		reverse(all(b));
		long long need = 0;
		for (int i = 0; i < (int)b.size(); i += 2) {
			need += b[i];
		}
		if (need <= h) {
			cout << k << "\n";
			return 0;
		}
	}

	return 0;
}