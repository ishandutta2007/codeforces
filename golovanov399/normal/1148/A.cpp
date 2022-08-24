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

	long long a = nxt(), b = nxt(), c = nxt();
	if (a != b) {
		cout << 2 * min(a, b) + 1 + 2 * c << "\n";
	} else {
		cout << 2 * a + 2 * c << "\n";
	}

	return 0;
}