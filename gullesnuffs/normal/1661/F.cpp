#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll cost(int diff, int extra_teles) {
	ll teles = extra_teles+1;
	ll lo_dis = diff/teles;
	ll hi_dis = lo_dis+1;
	ll num_at_hi_dis = diff-lo_dis*teles;
	ll num_at_lo_dis = teles - num_at_hi_dis;
	assert(num_at_lo_dis*lo_dis+num_at_hi_dis*hi_dis == diff);
	return num_at_lo_dis*lo_dis*lo_dis+num_at_hi_dis*hi_dis*hi_dis;
}

ll g(int diff, int extra_teles) {
	return cost(diff, extra_teles) - cost(diff, extra_teles+1);
}

// Extra teleporters to add as long as we want >= gain
int num_extra(int diff, ll gain) {
	int lo = -1, hi = diff;
	while (hi-lo > 1) {
		int mid = (lo+hi)/2;
		if (g(diff, mid) >= gain) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return hi;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	rep(i,0,n)
		cin >> a[i+1];
	ll m;
	cin >> m;
	ll lo = 0, hi = 1e18;
	ll ans = 1e18;
	while (hi-lo > 1) {
		ll gain = (lo+hi)/2;
		ll extra_teles = 0;
		ll c = 0;
		rep(i,0,n) {
			int diff = a[i+1]-a[i];
			int e = num_extra(diff, gain);
			extra_teles += e;
			c += cost(diff, e);
		}
		if (c > m) {
			hi = gain;
		} else {
			ll new_ans = extra_teles - ((m-c)/(gain));
			ans = new_ans;
			lo = gain;
		}
	}
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
		solve();
}