#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

void solve() {
	string s;
	cin >> s;
	map<ll, bool> m;
	for (auto i : s) {
		if ('A' <= i && i <= 'Z') {
			if (!m[i - 'A']) {
				cout << "NO\n";
				return;
			}
		} else {
			m[i - 'a'] = true;
		}
	}
	cout << "YES\n";
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
/*
















*/