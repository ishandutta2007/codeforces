
#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll t;
    cin >> t;
    for (ll _ = 0; _ < t; _++) {
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        ll minn = 1000000000000000;
        for (ll i = 0; i < n; i++) {
          cin >> arr[i];
          minn = min(minn, arr[i]);
        }
        ll ans = 0;
        for (auto i : arr) {
          ans += i > minn;
        }
        cout << ans << '\n';
    }
}