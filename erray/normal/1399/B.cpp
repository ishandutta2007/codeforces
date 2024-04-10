#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		int mn1 = *min_element(a.begin(), a.end()), mn2 = *min_element(b.begin(), b.end());
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += max(a[i] - mn1, b[i] - mn2);
		}
		cout << ans << '\n';
	}
}