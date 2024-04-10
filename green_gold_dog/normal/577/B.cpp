#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = arr[i] % m;
	}
	bitset<1000> dp, nz;
	for (ll i = 0; i < m; i++) {
		nz[i] = 1;
	}
	for (ll i = 0; i < n; i++) {
		dp |= ((dp << arr[i]) | (dp >> (m - arr[i])));
		dp[arr[i]] = 1;
		dp &= nz;
	}
	cout << (dp[0] ? "YES" : "NO");
}

/*
















*/