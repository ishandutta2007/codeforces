#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

typedef long long ll;

const ll INF = 1e10;

using namespace std;

int main() {
	int t;
	cin >> t;  
	while (t--) {
		int n;
		cin >> n;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll maxval = -INF;
		ll maxdif = -INF;
		for (int i = 0; i < n; i++) {
			maxval = max(maxval, a[i]);
			maxdif = max(maxval - a[i], maxdif);
		}
		ll ans = 0;
		ll p = 1;
		ans = 0;
		while (p <= maxdif) {
			ans++;
			p *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}