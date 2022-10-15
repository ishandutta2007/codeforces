#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int l, r;
		long long m;
		cin >> l >> r >> m;
		bool ok = false;
		for (int i = l; i <= r; ++i) {
			long long k = m % (long long) i, k2 = (i - k) % i;
			if (k2 <= r - l) {
				cout << i << ' ' << r - k2 << ' ' << r << '\n';
				ok = true;
				break;	
			}
			if (k <= r - l && i <= m) {
				cout << i << ' ' << r << ' ' << r - k << '\n';
				ok = true;
				break;
			} 
		}
		assert(ok);
	}
}