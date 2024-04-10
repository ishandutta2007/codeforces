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

	long long n;
	cin >> n;
	vector<long long> ps;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i) {
			continue;
		}
		ps.push_back(i);
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > 1) {
		ps.push_back(n);
	}
	cout << (ps.size() == 1 ? ps[0] : 1) << "\n";

	return 0;
}