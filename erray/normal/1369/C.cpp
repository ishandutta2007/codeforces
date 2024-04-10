#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), w(k);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < k; ++i) cin >> w[i];
		sort(a.begin(), a.end());
		sort(w.begin(), w.end(), greater<int> ());
		long long ans = 0;
		while (!a.empty() && w.back() == 1) {
			ans += a.back() << 1;
			w.pop_back();
			a.pop_back();			
		}
		for (int i = 0; i < w.size(); ++i) {
			ans += a.back();
			a.pop_back();
			--w[i];
		}
		for (int i = 0, ind = 0; i < w.size(); ++i) {
			ans += a[ind];
			ind += w[i];	
		}
		cout << ans << '\n';
	}
}