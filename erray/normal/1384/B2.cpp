#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k, l;
		cin >> n >> k >> l;
		++l;
		vector<int> d(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		bool ok = true, way = false;
		int cur = k;
		for (int i = 0; i < n; ++i) {
			if (d[i] + k < l) {
				cur = k;
				way = false;	    	
			} else {
				cur += (way ? 1 : -1);
				if (!way) cur = min(cur, l - d[i] - 1);
				if (d[i] + cur >= l || cur < 0) {
					ok = false;					
				}
				if (cur == 0) way = true;
			}
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
}