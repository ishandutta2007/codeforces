#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, t, k = 400;
	cin >> n >> t;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<tuple<pair<ll, ll>, ll, ll, ll>> q;
	for (ll i = 0; i < t; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		q.push_back(make_tuple(make_pair(l / k, r), l, r, i));
	}
	sort(q.begin(), q.end());
	vector<tuple<ll, ll, ll>> nq;
	for (auto&[_, l, r, i] : q) {
		nq.push_back(tie(l, r, i));
	}
	vector<pair<ll, ll>> ans;
	ll nl = 0, nr = -1, na = 0;
	vector<ll> col(1000001, 0);
	for (auto&[l, r, num] : nq) {
		if (r >= nr) {
			for (; nr != r; nr++) {
				ll now = col[arr[nr+1]];
				na -= now * now * arr[nr+1];
				now++;
				col[arr[nr+1]] = now;
				na += now * now * arr[nr+1];
			}
		} else {
			for (; nr != r; nr--) {
				ll now = col[arr[nr]];
				na -= now * now * arr[nr];
				now--;
				col[arr[nr]] = now;
				na += now * now * arr[nr];
			}
		}
		if (l <= nl) {
			for (; nl != l; nl--) {
				ll now = col[arr[nl-1]];
				na -= now * now * arr[nl-1];
				now++;
				col[arr[nl-1]] = now;
				na += now * now * arr[nl-1];
			}
		} else {
			for (; nl != l; nl++) {
				ll now = col[arr[nl]];
				na -= now * now * arr[nl];
				now--;
				col[arr[nl]] = now;
				na += now * now * arr[nl];
			}
		}
		ans.push_back({num, na});
	}
	sort(ans.begin(), ans.end());
	for (auto[_, a] : ans) {
		cout << a << '\n';
	}
}