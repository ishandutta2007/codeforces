#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
         
using namespace std;

const int MAXN = 1e5 + 7; 

int a[MAXN];
int pref[MAXN];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	a[n] = m;

	pref[0] = a[0];
	for (int i = 1; i < n; ++i) {
		if (i % 2) pref[i] = pref[i - 1];
		else pref[i] = pref[i - 1] + (a[i] - a[i - 1]);
	}

	int ans = pref[n - 1];
	if ((n - 1) % 2) ans += m - a[n - 1];
	int x = 0;
	for (int i = n - 1; i >= 0; --i) {
		int r;
	 	r = a[i + 1] - a[i];
		
		ans = max(ans, pref[i] + x + r - 1);

		if (i % 2 == 0) {
		 	x += a[i + 1] - a[i];
		}
	}

	cout << ans << '\n';
    return 0;
}