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

int query(vector<int> const& a, vector<int> const& b) {
	cout << szof(a) << " " << szof(b) << " ";
	for (int x : a) {
		cout << x + 1 << " ";
	}
	for (int x : b) {
		cout << x + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void run() {
	int n;
	cin >> n;
	vector<int> vs(n);
	iota(all(vs), 0);
	vs.erase(vs.begin());
	int dst = query({0}, vs);
	while (szof(vs) > 1) {
		int half = szof(vs) / 2;
		vector<int> qr(vs.begin(), vs.begin() + half);
		int cur = query({0}, qr);
		if (cur == dst) {
			vs = qr;
		} else {
			vs = {vs.begin() + half, vs.end()};
		}
	}
	vector<int> all_vs(n);
	iota(all(all_vs), 0);
	all_vs.erase(find(all(all_vs), vs[0]));
	int ans = query({vs[0]}, all_vs);
	cout << "-1 " << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s.\n";
	return 0;
}