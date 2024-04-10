#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector <ll> pre(n);
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
		pre[i] = a[i] + pre[i - 1];
	vector <int> pos;
	for (int i = 0; i < n - 1; i++)
		if (a[i] != a[i + 1])
			pos.push_back(i);
	pos.push_back(n - 1);
	ll ans = 1e18;
	for (int i = 0; i < pos.size(); i++) {
		int lpos = (i ? pos[i - 1] + 1 : 0);
		int rpos = pos[i];
		ll need = k - (rpos - lpos + 1);
		if (need <= 0) {
			cout << 0;
			return 0;
		}
		ll lsum = (lpos * a[lpos]) - (lpos ? pre[lpos - 1] : 0);
		ll rsum = (pre[n - 1] - pre[rpos]) - (n - rpos - 1) * a[lpos];
		if (lpos >= need) ans = min(ans, lsum - lpos + need);
		if (n - rpos - 1 >= need) ans = min(ans, rsum - (n - rpos - 1) + need);
		ans = min(ans, lsum + rsum - (n - k));
	}
	cout << ans;
	return 0;
}