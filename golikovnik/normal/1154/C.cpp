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
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = 0;
	vector<int> who = {0, 1, 2, 0, 2, 1, 0};;
	for (int day = 0; day < 7; day++) {
		ll cur_ans = 0;
		vector<ll> cur = {a, b, c};
		for (int cur_day = day; cur_day < 7; cur_day++) {
			if (!cur[who[cur_day]]) {
				ans = max(ans, cur_ans);
				break;
			}
			cur_ans++;
			cur[who[cur_day]]--;
		}
		ll periods = min({cur[0] / 3, cur[1] / 2, cur[2] / 2});
		cur_ans += periods * 7;
		cur[0] -= periods * 3;
		cur[1] -= periods * 2;
		cur[2] -= periods * 2;
		for (int cur_day = 0; cur_day < 7; cur_day++) {
			if (!cur[who[cur_day]]) {
				ans = max(ans, cur_ans);
				break;
			}
			cur_ans++;
			cur[who[cur_day]]--;
		}
	}
	cout << ans << "\n";
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