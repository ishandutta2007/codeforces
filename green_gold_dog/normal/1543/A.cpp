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
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		cout << abs(a-b) << ' ' << min(b-b/abs(a-b)*abs(a-b), (b+abs(a-b)-1)/abs(a-b)*abs(a-b)-b) << '\n';
	}
}