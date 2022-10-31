/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

struct segtree {
	ll N;
	vector<ll> tree;
	segtree() {}
	segtree(ll N) {
		tree.resize(N + 10);
		segtree::N = N;
	}
	void update(ll x) {
		while (x <= N) {
			tree[x]++;
			x += (x & -x);
		}
	}
	ll sum(ll x){
		ll ans = 0;
		while (x) {
			ans += tree[x];
			x -= (x & -x);
		}
		return ans;
	}
	ll query(ll low, ll high) {
		if (low > 1) return sum(high) - sum(low);
		return sum(high);
	}
};

void solve() {
	ll N;
	cin >> N;
	string s, t;
	cin >> s >> t;
	//N = s.size();
	s = '.' + s;
	t = '.' + t;
	ll i;
	vector<vector<ll>> mp(26);
	for (i = 1; i <= N; i++) mp[s[i] - 'a'].push_back(i);
	for (i = 0; i < 26; i++) reverse(mp[i].begin(), mp[i].end());
	ll j;
	ll cnt = 0;
	ll ans = INT_FAST64_MAX;
	segtree seg(N + 10);
	for (i = 1; i <= N; i++) {
		for (j = 0; j < t[i] - 'a'; j++) {
			if (mp[j].empty()) continue;
			ll t = mp[j].back();
			ll res = seg.query(t, N);
			ans = min(ans, cnt + t + res - i);
		}
		ll c = t[i] - 'a';
		if (mp[c].empty()) break;
		ll t = mp[c].back();
		mp[c].pop_back();
		ll res = seg.query(t, N);
		cnt += t + res - i;
		seg.update(t);
	}
	if (ans == INT_FAST64_MAX) cout << -1 << ln;
	else cout << ans << ln;
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