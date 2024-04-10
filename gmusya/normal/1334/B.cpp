#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll x;
		cin >> n >> x;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.rbegin(), a.rend());
		ll sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (x * (i + 1) <= sum) ans = i + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}