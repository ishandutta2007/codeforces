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
		for (int i = 0; i < n; ++i) cin >> a[n - i - 1];
		bool bef, start = false;
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[i - 1]) continue;
			if (!start) {
				bef = a[i] < a[i - 1];
				start = true;
			}
			else {
				bool cur = a[i] < a[i - 1];
				if (!cur && bef) {
					ans = n - i;
					break;
				}
				bef = cur;
			}						         		
		}
		cout << ans << '\n'; 
	}
}