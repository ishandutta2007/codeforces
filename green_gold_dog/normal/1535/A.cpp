#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<ll> arr;
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		arr.push_back(d);
		sort(arr.begin(), arr.end());
		if (((max(a, b) == arr[3]) && (max(c, d) == arr[2])) || ((max(a, b) == arr[2]) && (max(c, d) == arr[3]))) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}