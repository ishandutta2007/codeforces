/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define yes "YES"
#define no "NO"

struct seg {
	ll N;
	vector<ll> tree, l, r;
	ll s;
	void init(ll x = 1) {
		tree[x] = 0;
		if (x >= s) {
			l[x] = r[x] = x - s + 1;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
	}
	seg() {}
	seg(ll N) {
		s = 1LL << (ll)ceil(log2(N));
		tree.resize(2 * s + 1);
		l.resize(2 * s + 1);
		r.resize(2 * s + 1);
		init();
	}
	void update(ll x, ll a) {
		x += s - 1;
		tree[x] = a;
		x /= 2;
		while (x) {
			tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
			x /= 2;
		}
	}
	ll query(ll low, ll high, ll loc = 1) {
		if (low > high) return 0;
		if (l[loc] == low && r[loc] == high) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return max(query(low, r[loc * 2], loc * 2), query(l[loc * 2 + 1], high, loc * 2 + 1));
	}
};

void solve() {
	ll N;
	cin >> N;
	vector<vector<ll>> sv(2);
	sv[0] = vector<ll>(N + 1);
	sv[1] = vector<ll>(N + 1);
	ll i;
	vector<ll> arr(N + 1), sum(N + 1);
	for (i = 1; i <= N; i++) cin >> arr[i], sum[i] = sum[i - 1] + arr[i];
	for (i = 1; i <= N; i++) sv[1][i] = arr[i];
	ll ans = 1;
	for (i = 2; i <= N; i++) {
		ll c = 0;
		sv[i % 2] = vector<ll>(N + 1);
		ll j;
		for (j = N - 1; j >= 1; j--) {
			sv[(i - 1) % 2][j] = max(sv[(i - 1) % 2][j], sv[(i - 1) % 2][j + 1]);
		}
		for (j = i; j <= N; j++) {
			ll ss = sum[j] - sum[j - i];
			ll l = j + i - 1;
			if (l > N) break;
			ll res = sv[(i - 1) % 2][l];
			if (res <= ss) continue;
			else {
				sv[i % 2][j] = ss;
				c = 1;
			}
		}
		if (c) ans = i;
		else break;
	}
	cout << ans << Ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}