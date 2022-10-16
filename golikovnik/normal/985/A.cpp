#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n / 2);
	for (int &x: p) cin >> x;
	sort(all(p));
	int ans_odd = 0;
	int ans_even = 0;
	for (int i = 0; i < n / 2; ++i) {
		ans_odd += abs(p[i] - 2 * i - 1);
		ans_even += abs(p[i] - 2 * (i + 1));
	}
	cout << min(ans_odd, ans_even);
	return 0;	

}