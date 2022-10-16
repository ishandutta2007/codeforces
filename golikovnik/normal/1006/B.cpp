#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = {x, i};
	}	
	sort(a.rbegin(), a.rend());
	vector<int> todo(k);
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		todo[i] = a[i].second;
		ans += a[i].first;
	}
	cout << ans << "\n";
        if (k == 1) {
              cout << n;
return 0;
}
	sort(all(todo));
	cout << todo[0] + 1 << " ";
	for (int i = 1; i < k - 1; ++i) {
		cout << todo[i] - todo[i-1] << " ";
	}
	if (k > 1)
    	cout << n - todo[k-2] - 1<< "\n";
	return 0;	
}