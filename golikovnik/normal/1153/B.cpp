#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

const int N = 105;

int col[N], row[N];

void run() {
	int n, m, h;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> col[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> row[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool have;
			cin >> have;
			cout << (have ? min(row[i], col[j]) : 0) << " ";
		}
		cout << "\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s.\n";
	return 0;
}