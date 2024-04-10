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
	string s;
	cin >> s;
	ll i = 0;
	ll n = s.size();
	for (; i < n; i++) {
		if (s[i] == 'h') {
			break;
		}
	}
	for (; i < n; i++) {
		if (s[i] == 'e') {
			break;
		}
	}
	for (; i < n; i++) {
		if (s[i] == 'i') {
			break;
		}
	}
	for (; i < n; i++) {
		if (s[i] == 'd') {
			break;
		}
	}
	bool b = false;
	for (; i < n; i++) {
		if (s[i] == 'i') {
			b = true;
			break;
		}
	}
	cout << (b ? "YES" : "NO");
}
/*
















*/