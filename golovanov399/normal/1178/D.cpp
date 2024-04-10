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

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void solve(int n) {
	int m = n;
	int can = n / 2;
	vector<pair<int, int>> edges;
	for (int i = 0; i < n; ++i) {
		edges.push_back({i + 1, (i + 1) % n + 1});
	}
	int l = 1, r = 1 + n / 2;
	while (!isPrime(m)) {
		assert(can);
		--can;
		++m;
		edges.push_back({l++, r++});
	}
	printf("%d\n", (int)edges.size());
	for (auto [x, y] : edges) {
		printf("%d %d\n", x, y);
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	solve(n);

	return 0;
}