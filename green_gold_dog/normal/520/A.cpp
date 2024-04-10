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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	set<char> se;
	for (auto i : s) {
		se.insert(i);
	}
	cout << (se.size() == 26 ? "YES" : "NO");
}

/*
















*/