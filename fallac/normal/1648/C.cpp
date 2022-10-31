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
 
#define MAX 201010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000
 
#define yes "YES"
#define no "NO"
 
int s[MAX];
int t[MAX];
ll fact[MAX];
ll res;
ll cnt[MAX];
 
struct segtree {
	vector<ll> tree;
	int N;
	segtree(int N) :N(N) { tree.resize(N + 1); }
	void update(int i, ll x) {
		while (i <= N) {
			tree[i] += x;
			i += (i & -i);
		}
	}
	ll sum(int i) {
		if (!i) return 0;
		ll ans = 0;
		while (i) {
			ans += tree[i];
			i -= (i & -i);
		}
		return ans;
	}
};
 
ll mpow(ll x, ll y) {
	if (y == 0) return 1;
	ll res = mpow(x, y / 2);
	res *= res, res %= MOD;
	if (y & 1) res *= x;
	return res % MOD;
}
 
ll inv(ll x) { return mpow(x, MOD - 2); }
 
segtree bit(200000);
 
void add(int x) {
	res *= fact[cnt[x]];
	res %= MOD;
	cnt[x]++;
	bit.update(x, 1);
	res *= inv(fact[cnt[x]]);
	res %= MOD;
}
void sub(int x) {
	res *= fact[cnt[x]];
	res %= MOD;
	cnt[x]--;
	bit.update(x, -1);
	res *= inv(fact[cnt[x]]);
	res %= MOD;
}
 
void solve() {
	int N, M;
	cin >> N >> M;
	int i;
	for (i = 1; i <= N; i++) cin >> s[i];
	for (i = 1; i <= M; i++) cin >> t[i];
	fact[0] = 1;
	for (i = 1; i <= max(N, M); i++) fact[i] = (fact[i - 1] * i) % MOD;
	res = fact[N];
	for (i = 1; i <= N; i++) {
		add(s[i]);
	}
	ll ans = 0;
	int c = 1;
	ans += ((res * inv(N)) % MOD) * bit.sum(t[1] - 1);
	ans %= MOD;
	for (i = 1; i <= min(N, M) - 1; i++) {
		if (cnt[t[i]]) sub(t[i]), res *= inv(N - i + 1), res %= MOD;
		else {
			c = 0;
			break;
		}
		ans += ((res * inv(N - i)) % MOD) * bit.sum(t[i + 1] - 1);
		ans %= MOD;
	}
	if (c) {
		if (cnt[t[i]]) {
			sub(t[i]);
			if (N < M) ans++;
		}
	}
	cout << ans % MOD << ln; //FST in test 61 :()
}
 
void init() {
 
}
 
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}