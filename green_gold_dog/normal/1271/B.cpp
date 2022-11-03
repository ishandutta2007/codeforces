#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

random_device rd;
mt19937 rnd32(rd());
mt19937_64 rnd64(rd());

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll cw = 0;
	for (auto i : s) {
		cw += i == 'W';
	}
	ll cb = n - cw;
	if (cb % 2 == 1 && cw % 2 == 1) {
		cout << -1 << '\n';
		return;
	}
	if (cw % 2 == 1) {
		for (auto& i : s) {
			i = (i == 'W' ? 'B' : 'W');
		}
	}
	vector<ll> ans;
	for (ll i = 0; i < n - 1; i++) {
		if (s[i] == 'W') {
			ans.push_back(i + 1);
			s[i] = 'B';
			s[i + 1] = (s[i + 1] == 'W' ? 'B' : 'W');
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}