#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, k;
	cin >> n >> k;
	vector<int> derangements = {1, 0, 1, 2, 9};
	int ans = 0;
	//k is big
	auto C = [](int n, int k) {
		int res = 1;
		for (int i = n; i > k; --i) {
			res *= i;
		}
		for (int i = 1; i <= n - k; ++i) {
			res /= i;
		}
		return res;
	};
	for (int nfixed = n - k; nfixed <= n; ++nfixed) {
		ans += C(n, nfixed) * derangements[n - nfixed];
	}
	cout << ans << "\n";
	return 0;	
}