#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  ll t;
  cin >> t;
  for (ll i = 0; i < t; i++) {
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
    }
    ll ans = 0;
    for (ll i = 1; i < n; i++) {
      ans = max(ans, arr[i]*arr[i-1]);
    }
    cout << ans << '\n';
  }
}