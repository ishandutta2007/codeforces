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

const int N = 1e7 + 20;

int cnt[N];
int a[N];

void run() {
	int n;
	cin >> n;
	ll ans = LLINF;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] == 2) {
			if (a[i] < ans) {
				ans = x = y = a[i];
			}
		}
	}
	for (int g = 1; g < N; g++) {
		int fi = 0, se = 0;
		for (int d = 1; 1LL * g * d < N; d++) {
			if (cnt[g * d] > 0) {
				if (fi == 0) {
					fi = g * d;
				} else {
					se = g * d;
					break;
				}
			}
		}
		if (se != 0) {
			int g_ = gcd(fi, se);
			if (1LL * fi / g_ * se < ans) {
				ans = 1LL * fi / g_ * se;
				x = fi;
				y = se;
			}
		}
	}
	vector<int> answer;
	for (int i = 0; i < n && answer.size() < 2; i++) {
		if (a[i] == x) {
			answer.push_back(i + 1);
			x = 0;
		} else if (a[i] == y) {
			answer.push_back(i + 1);
			y = 0;
		}
	}
	cout << min(answer[0], answer[1]) << " " << max(answer[0], answer[1]) << "\n";
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