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
	string s1, s2;
	cin >> s1 >> s2;
	for (ll i = 0; i < s1.size(); i++) {
	  if (s1[i] == '1' && s2[i] == '0' || s1[i] == '0' && s2[i] == '1') {
	    cout << 1;
	  } else {
	    cout << 0;
	  }
	}
}

/*
















*/