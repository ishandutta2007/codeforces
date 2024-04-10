#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
int g_x;
#endif

long long ask(long long a, long long b) {
#ifdef TEST
	return gcd(g_x + a, g_x + b);
#else
	cout << "? " << a << " " << b << endl;
	return nxt();
#endif
}

void solve() {
#ifdef TEST
	g_x = rand() % (int)1e9 + 1;
#endif
	const int d = 1 << 30;
	int x = 0;
	for (int i = 0; i < 30; ++i) {
		if (ask((1 << i) - x, d + (1 << i) - x) & ((1 << (i + 1)) - 1)) {
			// pass;
		} else {
			x += 1 << i;
		}
	}
#ifdef TEST
	cerr << x << "? (" << g_x << ")\n";
	assert(x == g_x);
#else
	cout << "! " << x << endl;
#endif
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}