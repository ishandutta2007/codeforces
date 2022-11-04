#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> ans(n, 0);
	ll u = 0;
	for (ll i = 0; i < n; i++) {
		arr[i] -= ans[i] * i;
		arr[i] -= u - i;
		while (arr[i] > 0) {
			if (u == i) {
				arr[i] -= i;
			}
			ans[u] = 1;
			arr[i]--;
			u++;
		}
		u++;
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}