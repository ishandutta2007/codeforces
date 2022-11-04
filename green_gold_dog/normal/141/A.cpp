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
	string s1, s2, s3;
	cin >> s2 >> s3 >> s1;
	map<char, ll> m;
	for (auto i : s1 + s2 + s3) {
		m[i] = 0;
	}
	for (auto i : s1) {
		m[i]++;
	}
	for (auto i : s2 + s3) {
		m[i]--;
	}
	bool ans = true;
	for (auto i : s1 + s2 + s3) {
		ans = ans && m[i] == 0;
	}
	cout << (ans ? "YES" : "NO");
}

/*
















*/