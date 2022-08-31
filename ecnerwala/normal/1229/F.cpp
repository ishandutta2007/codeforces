#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e4;
int N;
ll A[MAXN];
ll L[MAXN];
ll R[MAXN];

ll cost(ll x0) {
	//cerr << x0 << '\n';
	ll loshift = 0;
	ll hishift = 0;
	priority_queue<ll, vector<ll>, less<ll>> los;
	priority_queue<ll, vector<ll>, greater<ll>> his;
	for (int i = 0; i < N+10; i++) {
		los.push(x0);
		his.push(x0);
	}

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		hishift += R[i] - A[i];
		loshift += L[i] - A[i];

		if (his.top() + hishift < 0) {
			ans += 0 - (his.top() + hishift);
			los.push(his.top() + hishift - loshift); his.pop();
			his.push(-hishift);
			his.push(-hishift);
		} else if (los.top() + loshift > 0) {
			ans += (los.top() + loshift) - 0;
			his.push(los.top() + loshift - hishift); los.pop();
			los.push(-loshift);
			los.push(-loshift);
		} else {
			los.push(-loshift);
			his.push(-hishift);
		}
	}

	for (ll i = 1; x0 > his.top() + hishift; i++) {
		ll a = his.top() + hishift; his.pop();
		ans += i * (min(x0, his.top() + hishift) - a);
	}

	for (ll i = 1; x0 < los.top() + loshift; i++) {
		ll a = los.top() + loshift; los.pop();
		ans += i * (a - max(x0, los.top() + loshift));
	}

	//cerr << x0 << ' ' << ans << '\n';

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> L[i] >> R[i];
	}

	ll mi = -2e9, ma = 2e9;
	while (ma - mi > 1) {
		ll md = (ma + mi) / 2;
		if (cost(md) < cost(md+1)) {
			ma = md;
		} else {
			mi = md;
		}
	}
	cout << cost(ma) << '\n';

	return 0;
}