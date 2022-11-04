#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

void solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> ans(n, 0);
	if (k % 2 == 1) {
		bool b = false;
		for (ll i = 0; i < n; i++) {
			if (s[i] == '1' && !b) {
				b = true;
				ans[i]++;
			} else {
				s[i] = (s[i] == '1' ? '0' : '1');
			}
		}
		if (!b) {
			s.back() = '0';
			ans.back()++;
		}
		k--;
	}
	vector<ll> zeros;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0') {
			zeros.push_back(i);
		}
	}
	reverse(zeros.begin(), zeros.end());
	while (k > 0 && zeros.size() > 1) {
		k -= 2;
		s[zeros.back()] = '1';
		ans[zeros.back()]++;
		zeros.pop_back();
		s[zeros.back()] = '1';
		ans[zeros.back()]++;
		zeros.pop_back();
	}
	if (zeros.size() == 1 && k > 0) {
		ans[zeros.back()]++;
		s[zeros.back()] = '1';
		ans.back()++;
		s.back() = '0';
		k -= 2;
	}
	ans.back() += k;
	cout << s << '\n';
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
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}