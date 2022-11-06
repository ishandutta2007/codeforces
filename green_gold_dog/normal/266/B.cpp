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
	ll n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	for (ll _ = 0; _ < t; _++) {
	  vector<ll> arr;
	  for (ll i = 1; i < n; i++) {
	    if (s[i] == 'G' && s[i - 1] == 'B') {
	      arr.push_back(i);
	    }
	  }
	  for (auto i : arr) {
	    swap(s[i], s[i - 1]);
	  }
	}
	for (auto i : s) {
	  cout << i;
	}
}

/*
















*/