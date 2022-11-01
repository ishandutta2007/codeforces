#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

bool cmp(ll a, ll b) {
	if (a == 1 && b != 1) return true;
	if (b == 1) return false;
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.rbegin(), a.rend());
		vector <int> w(k);
		for (int i = 0; i < k; i++)
			cin >> w[i];
		sort(w.begin(), w.end(), cmp);
		int pos = 0;
		ll ans = 0;
		for (int i = 0; i < k; i++) {
			ans += a[i];
			if (w[i] == 1) {
				ans += a[i];
				continue;
			}
			ans += a.back();
			w[i]--;
			while (w[i]--) a.pop_back();
		}
		cout << ans << '\n';
	}
	return 0;
}