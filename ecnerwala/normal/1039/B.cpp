#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll N;
int K;

bool query(ll l, ll r) {
	assert(0 <= l && l < r && r <= N);
	l++;
	assert(1 <= l && l <= r && r <= N);
	cout << l << ' ' << r << endl;
	string s; cin >> s;
	if (s == "Yes") {
		if (l == r) {
			// exit immediately
			exit(0);
		}
		return true;
	} else if (s == "No") {
		return false;
	} else if (s == "Bad") {
		// darn
		exit(0);
	} else assert(false);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin >> N >> K;
	ll mi = 0, ma = N; // half-open range
	while (true) {
		ll q = uniform_int_distribution<ll>(mi + 1, ma)(rng);
		query(q-1, q);
		mi = max(0ll, mi - K);
		ma = min(N, ma + K);
		ll md = (ma + mi) / 2;
		assert(md < ma);
		bool r = query(md, ma); // if ma = mi + 1, then md = mi
		if (r) {
			mi = md;
		} else {
			ma = md;
		}
		mi = max(0ll, mi - K);
		ma = min(N, ma + K);
	}

	return 0;
}