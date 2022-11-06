#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, q;
	cin >> n;
	vector<int> a(n), lx(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = -1;
	vector<LL> sum(n);
	for (int i = 0; i < n; i++) {
		lx[i] = l;
		l = max(l, i - a[i]);
		if (i > 0) {
			sum[i] = sum[i - 1];
		}
		sum[i] += i - l;
	}
	lx[n] = l;
	vector<vector<pair<int, int>>> qr(n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		qr[p - 1].emplace_back(x, i);
	}
	vector<LL> ans(q);
	vector<int> stk, val;
	vector<LL> psum;
	stk.push_back(n), val.push_back(n), psum.push_back(0);
	for (int i = n - 1; i >= 0; i--) {
		for (auto [x, id] : qr[i]) {
			int now = max(lx[i], i - x);
			ans[id] = (i > 0) ? sum[i - 1] : 0;
			int d = upper_bound(val.begin(), val.end(), now, std::greater<int>()) - val.begin() - 1;
			ans[id] += psum[d];
			int r = stk[d] - 1;
			ans[id] += (i + r) * (r - i + 1ll) / 2 - now * (r - i + 1ll);
		}
		while (!stk.empty() && val.back() <= i - a[i]) {
			stk.pop_back(), val.pop_back(), psum.pop_back();
		}
		LL presum = 0;
		int r = stk.back() - 1;
		presum = psum.back() + (i + r) * (r - i + 1ll) / 2 - (i - a[i]) * (r - i + 1ll);
		stk.push_back(i);
		val.push_back(i - a[i]);
		psum.push_back(presum);
	}
	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
    return 0;
}