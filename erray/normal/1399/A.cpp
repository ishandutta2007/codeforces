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
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		bool ok = true;
		for (int i = 1; i < (int) a.size(); ++i) {
			ok &= (a[i] == (a[i - 1] + 1));
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}