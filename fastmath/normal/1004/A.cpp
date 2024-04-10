#include <bits/stdc++.h>
    
using namespace std;

#define int long long
#define x first
#define y second   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	int n, d;
	cin >> n >> d;

	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
	 	cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 2;
	for (int i = 0; i < n - 1; ++i) {
	 	if (a[i + 1] - a[i] == 2 * d) {
	 	 	++ans;
	 	}
	 	else if (a[i + 1] - a[i] > 2 * d) {
	 	 	ans += 2;
	 	}
	}

	cout << ans << '\n';
    return 0;
}