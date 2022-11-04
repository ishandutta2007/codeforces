#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct lun {
	vector<ll> arr;
	vector<pair<ll, ll>> ans;
	ll len;
	lun(istream& inp, ll n = 0) {
		len = n;
		arr.resize(len, 0);
		for (ll i = 0; i < n; i++) {
			inp >> arr[i];
		}
		ans.resize(len, {0, 0});
		count();
	}
	void count() {
		for (ll i = len - 1; i >= 0; i--) {
			if (i + arr[i] > len - 1) {
				ans[i] = {i, 1};
			} else {
				ans[i] = {ans[i + arr[i]].first, ans[i + arr[i]].second + 1};
			}
		}
	}
	pair<ll, ll> calc(ll n) {
		return ans[n];
	}
	void change(ll n, ll num) {
		arr[n] = num;
		count();
	}
};

struct sqrt_lun {
	vector<lun> luns = vector<lun>(0, lun(cin));
	ll len, k = 700, lenl;
	sqrt_lun(istream& inp, ll n = 0) {
		len = n;
		for (ll i = 0; i < floor(len/k); i++) {
			luns.push_back(lun(inp, k));
		}
		if (len%k > 0) {
			luns.push_back(lun(inp, len%k));
		}
		lenl = luns.size();
	}
	pair<ll, ll> calc(ll n) {
		pair<ll, ll> ans = {0, 0};
		ll summ = 0, last = 0, a = 0;
		for (ll i = 0; i < lenl; i++) {
			if ((n < luns[i].len) && (n >= 0)) {
				ans = luns[i].calc(n);
				last = luns[i].arr[ans.first] + ans.first;
				a = ans.first + summ;
			}
			if (n < 0) {
				if (last < luns[i].len) {
					pair<ll, ll> ansn = luns[i].calc(last);
					ans.first = ansn.first;
					ans.second += ansn.second;
					last = luns[i].arr[ans.first] + ans.first;
					a = ans.first + summ;
				}
			}
			summ += luns[i].len;
			last -= luns[i].len;
			n -= luns[i].len;
		}
		return {a, ans.second};
	}
	void change(ll n, ll num) {
		for (ll i = 0; i < lenl; i++) {
			if (n < luns[i].len) {
				return luns[i].change(n, num);
			}
			n -= luns[i].len;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	sqrt_lun sq(cin, n);
	for (ll i = 0; i < m; i++) {
		ll zap;
		cin >> zap;
		if (zap) {
			ll a;
			cin >> a;
			pair<ll, ll> ans = sq.calc(a - 1);
			cout << ans.first + 1 << ' ' << ans.second << endl;
		} else {
			ll a, b;
			cin >> a >> b;
			sq.change(a - 1, b);
		}
	}
}