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
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = -i;
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	ll ans = -arr[0].second + n - 1 + arr.back().second;
	if (arr[0].second < arr.back().second) {
		ans--;
	}
	cout << ans;
}

/*
















*/