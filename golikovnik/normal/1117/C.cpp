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
	int xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n;
	string wind;
	cin >> n >> wind;
	vector<int> dx(n + 1), dy(n + 1);
	for (int i = 0; i < n; i++) {
		char c = wind[i];
		dx[i + 1] = dx[i];
		dy[i + 1] = dy[i];
		if (c == 'U') {
			dy[i + 1]++;
		} else if (c == 'D') {
			dy[i + 1]--;
		} else if (c == 'R') {
			dx[i + 1]++;
		} else {
			dx[i + 1]--;
		}
	}
	ll left = -1, right = LLINF;
	while (left + 1 < right) {
		ll middle = (left + right) / 2;
		ll curx = xs, cury = ys;
		curx += 1LL * dx[n] * (middle / n);
		curx += dx[middle % n];
		cury += 1LL * dy[n] * (middle / n);
		cury += dy[middle % n];
		ll need_x = llabs(xt - curx), need_y = llabs(yt - cury);
		if (middle >= need_x + need_y) {
			right = middle;
		} else {
			left = middle;
		}
	}
	cout << (right == LLINF ? -1 : right) << "\n";
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