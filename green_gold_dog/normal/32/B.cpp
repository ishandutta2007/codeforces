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
T square(T& a) {
	return a * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string ans = "";
	string s;
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			ans.push_back('0');
		} else {
			i++;
			if (s[i] == '.') {
				ans.push_back('1');
			} else {
				ans.push_back('2');
			}
		}
	}
	cout << ans;
}
/*
















*/