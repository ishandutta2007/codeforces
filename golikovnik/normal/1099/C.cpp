#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

void run() {
	string s;
	int k;
	cin >> s >> k;
	int n = szof(s);
	int mn = 0;
	vector<int> qs, asteriks, normal;
	for (int i = 0; i < n; i++) {
		if (isalpha(s[i])) {
			if (i + 1 >= n || isalpha(s[i + 1])) {
				mn++;
				normal.push_back(i);
			}
		} else if (s[i] == '?') {
			qs.push_back(i);
		} else {
			asteriks.push_back(i);
		}
	}
	if (k < mn) {
		cout << "Impossible\n";
		return;
	}
	if (!szof(asteriks)) {
		int mx = mn + szof(qs);
		if (k > mx) {
			cout << "Impossible\n";
			return;
		}
		int left = k - mn;
		vector<int> ans = normal;
		while (left) {
			ans.push_back(qs.back() - 1);
			qs.pop_back();
			left--;
		}
		sort(all(ans));
		for (int x : ans) {
			cout << s[x];
		}
		cout << "\n";
	} else {
		vector<int> ans = normal;
		int left = k - mn;
		for (int i = 0; i < left; i++) {
			ans.push_back(asteriks.back() - 1);
		}
		sort(all(ans));
		for (int x : ans) {
			cout << s[x];
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
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}