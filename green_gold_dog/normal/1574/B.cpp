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
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll m;
		vector<ll> arr(3, 0);
		cin >> arr[0] >> arr[1] >> arr[2] >> m;
		sort(arr.begin(), arr.end());
		cout << ((arr[0] + arr[1] + arr[2] - 3 >= m) && (arr.back() - arr[1] - arr[0] - 1 <= m) ? "YES" : "NO") << '\n';
	}
}

/*
















*/