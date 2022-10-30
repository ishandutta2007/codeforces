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

multiset<ll> ms;

ll p[MAX];
ll val[MAX];

ll find(ll x) {
	if (x == p[x]) return p[x];
	else return p[x] = find(p[x]);
}

ll uni(ll a, ll b) {
	a = find(a);
	b = find(b);
	if (a == b) return 1;
	p[b] = a;
	ms.erase(ms.find(val[a]));
	ms.erase(ms.find(val[b]));
	val[a] += val[b];
	ms.insert(val[a]);
	return 0;
}

void solve() {
	ll N;
	ll d;
	cin >> N >> d;
	ll i;
	ll rem = 1;
	multiset<ll>::iterator it;
	ll a, b;
	for (i = 1; i <= N; i++) p[i] = i, val[i] = -1, ms.insert(-1);
	for (i = 1; i <= d; i++) {
		cin >> a >> b;
		ll res = uni(a, b);
		if (res) rem++;
		ll ans = 0;
		ll cnt = 0;
		for (it = ms.begin(); it != ms.end(); it++) {
			if (cnt >= rem) break;
			cnt++;
			ans += *it;
		}
		cout << -ans - 1 << ln;
	}
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