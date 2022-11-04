#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n+1, 0);
	string s;
	cin >> s;
	for (ll i = 0; i < n; i++) {
		arr[i+1] = arr[i]+(s[i]-'a'+1);
	}
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		cout << arr[r]-arr[l-1] << '\n';
	}
}