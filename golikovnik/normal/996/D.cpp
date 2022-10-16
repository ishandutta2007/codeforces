#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int &x: a) cin >> x;
	int ans = 0;
	for (int i = 0; i < 2 * n; i += 2) {
		if (a[i] == a[i + 1]) continue;
		int j = i + 1;
		while (a[j] != a[i]) ++j;
		while (j - 1 > i) {
			++ans;
			swap(a[j], a[j - 1]);
			--j;
		}
	}	
	cout << ans << "\n";
	return 0;	
}