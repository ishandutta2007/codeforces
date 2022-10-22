#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		int best = 0, w = 0;
		for(int a, i = 1; i <= n; ++i) {
			cin >> a;
			w += a;
			best = max(best, w);
		}
		cin >> m;
		int best2 = 0;
		w = 0;
		for(int a,i = 1; i <= m; ++i) {
			cin >> a;
			w += a;
			best2 = max(best2, w);
		}
		cout << best + best2 << '\n';
	}
	
}