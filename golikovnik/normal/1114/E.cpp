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

int ask(int i) {
	cout << "? " << i << endl;
	int x;
	cin >> x;
	return x;
}

void run() {
	int n;
	cin >> n;
	if (n <= 60) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = ask(i + 1);
		}
		sort(all(a));
		cout << "! " << a[0] << " " << a[1] - a[0] << endl;
		return;
	}
	vector<bool> asked(n);
	int k = 29;
	vector<int> a(k);
	for (int it = 0; it < k; it++) {
		int i;
		do {
			i = rnd(1, n);
		} while (asked[i - 1]);
		a[it] = ask(i);
		asked[i - 1] = 1;
	}
	int g = 0;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			int x = abs(a[i] - a[j]);
			g = gcd(g, x);
		}
	}
	int l = -1, r = INF;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		cout << "> " << mid << endl;
		int ok;
		cin >> ok;
		if (ok) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int first = r - g * (n - 1);
	cout << "! " << first << " " << g << endl;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}