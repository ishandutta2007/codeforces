#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
ll square(T a) {
	return a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		set<char> se;
		se.insert(s[0]);
		bool b = true;
		for (ll i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				if (se.count(s[i]) != 0) {
					b = false;
					break;
				}
				se.insert(s[i]);
			}
		}
		cout << (b ? "YES" : "NO") << '\n';
	}
}
/*
















*/