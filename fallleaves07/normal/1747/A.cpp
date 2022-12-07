#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	ll suma = 0, sumb = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			suma += a[i];
		} else {
			sumb += a[i];
		}
	}
	printf("%lld\n", abs(abs(suma) - abs(sumb)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}