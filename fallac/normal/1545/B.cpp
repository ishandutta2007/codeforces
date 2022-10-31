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
#define MOD 998244353
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll fact[MAX];
ll get(ll x) {
	if (fact[x]) return fact[x];
	else return (fact[x] = (get(x - 1) * x) % MOD);
}

ll mpow(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y % 2) res *= x;
	res %= MOD;
	return res;
}

ll inv(ll x) {
	return mpow(x, MOD - 2);
}

ll C(ll N, ll R) {
	ll n, r, nr;
	n = get(N);
	r = get(R);
	nr = get(N - R);
	n *= inv(r);
	n %= MOD;
	n *= inv(nr);
	n %= MOD;
	return n;
}

ll H(ll n, ll r) {
	return C(n + r - 1, r);
}

void solve() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll i;
	vector<ll> v;
	v.resize(N);
	ll o = 0;
	ll chk = 0;
	ll cnt = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == '1') {
			cnt++;
			if (chk) {
				if (chk == 1) {
					o--;
					chk = -1;
				}
				else {
					o++;
					chk = 1;
				}
			}
			else {
				chk = 1;
				o++;
			}
		}
		else {
			chk = 0;
		}
	}
	cout << H(N - cnt + 1, (cnt - o) / 2) << ln;
}

void init() {
	fact[1] = 1;
	fact[0] = 1;
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