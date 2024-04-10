/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 1000000007
ll MOD;
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"

ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	while (b) b %= a ^= b ^= a ^= b;
	return a;
}

vector<ll> tree, l, r;
ll s;

void init(ll x = 1) {
	if (x >= s) {
		l[x] = r[x] = x - s + 1;
		return;
	}
	init(x * 2);
	init(x * 2 + 1);
	l[x] = l[x * 2];
	r[x] = r[x * 2 + 1];
	tree[x] = gcd(tree[x * 2], tree[x * 2 + 1]);
}

ll query(ll low, ll high, ll loc = 1) {
	if (l[loc] == low && r[loc] == high) return tree[loc];
	if (r[loc * 2] >= high) return query(low, high, loc * 2);
	if (l[loc * 2 + 1] <= low) return query(low, high, loc * 2 + 1);
	return gcd(query(low, r[loc * 2], loc * 2), query(l[loc * 2 + 1], high, loc * 2 + 1));
}

void solve() {
	ll N;
	cin >> N;
	ll g = 0;
	ll i;
	vector<ll> X;
	X.resize(N);
	for (i = 0; i < N; i++) cin >> X[i], g = gcd(X[i], g);
	for (i = 0; i < N; i++) X[i] /= g;
	s = 1LL << (ll)ceil(log2(N * 2));
	tree.resize(2 * s + 1);
	l.resize(2 * s + 1);
	r.resize(2 * s + 1);
	ll cnt = 0;
	for (i = s; i < 2 * s; i++, cnt++) tree[i] = X[cnt % N];
	init();
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		ll l, r;
		l = -1, r = N - 1;
		while (r - l > 1) {
			ll mid = (l + r + 1) / 2;
			if (query(i, i + mid) == 1) r = mid;
			else l = mid;
		}
		ans = max(ans, r);
	}
	cout << ans << ln;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		solve();
	}
}