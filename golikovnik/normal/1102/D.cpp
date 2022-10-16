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

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(3);
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
		cnt[a[i]]++;
	}
	vector<vector<int>> suff(n, vector<int>(3));
	suff[n - 1][a[n - 1]] = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int b = 0; b < 3; b++) {
			suff[i][b] += (suff[i + 1][b] + (a[i] == b));
		}
	}
	int need = n / 3;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] == need) {
			continue;
		}
		if (cnt[a[i]] > need) {
			for (int j = 0; j < 3; j++) if (j != a[i]) {
				if (cnt[j] < need) {
					if (j < a[i] || (i + 1 == n) || (cnt[a[i]] - need) > suff[i + 1][a[i]]) {
						cnt[a[i]]--;
						cnt[j]++;
						a[i] = j;
						break;
					}
				}
			}
		} else {
			// for (int j = 0; j < 3; j++) if (j != a[i]) {
			// 	if (cnt[j] > need) {
			// 		if (j < a[i] || (i + 1 == n) || (need - cnt[a[i]]) > suff[i + 1][a[i]]) {
			// 			cnt[a[i]]++;
			// 			cnt[j]--;
			// 			a[i] = j;
			// 			break;
			// 		}
			// 	}
			// }
		}
	}
	for (int x : a) {
		cout << x;
	}
	cout << "\n";
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