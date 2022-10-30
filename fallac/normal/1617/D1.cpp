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

ll query(ll a, ll b, ll c) {
	a++;
	b++;
	c++;
	cout << '?' << bb << a << bb << b << bb << c << endl;
	ll x;
	cin >> x;
	return !x;
}

void solve() {
	ll N;
	cin >> N;
	ll K = N / 3;
	ll i;
	vector<ll> v(K);
	vector<ll> one, zero;
	for (i = 0; i < K; i++) {
		v[i] = query(i * 3, i * 3 + 1, i * 3 + 2);
		if (v[i]) one.push_back(i);
		else zero.push_back(i);
	}
	ll p, q;
	vector<ll> ans(N);
	if (zero.size() < one.size()) {
		ll x = one[0];
		for (auto z : zero) {
			ll c = 0;
			ll res = query(z * 3, z * 3 + 1, x * 3);
			if (res == 0) {
				res = query(z * 3, z * 3 + 1, x * 3 + 1);
				if (res == 0) {
					res = query(z * 3, z * 3 + 2, x * 3);
					if (res == 0) {
						res = query(z * 3, z * 3 + 2, x * 3 + 1);
						if (res) {
							c = 1;
							p = z * 3;
							q = z * 3 + 2;
						}
						else {
							res = query(z * 3, x * 3, x * 3 + 1);
							if (res == 0) {
								c = 1;
								p = x * 3;
								q = x * 3 + 1;
							}
							else {
								c = 1;
								p = z * 3;
								q = x * 3;
							}
						}
					}
					else {
						c = 1;
						p = z * 3;
						q = z * 3 + 2;
					}
				}
				else {
					c = 1;
					p = z * 3;
					q = z * 3 + 1;
				}
			}
			else {
				c = 1;
				p = z * 3;
				q = z * 3 + 1;
			}
			if (c) break;
		}
	}
	else {
		ll x = zero[0];
		for (auto z : one) {
			ll c = 0;
			ll res = query(z * 3, z * 3 + 1, x * 3);
			if (res == 1) {
				res = query(z * 3, z * 3 + 1, x * 3 + 1);
				if (res == 1) {
					res = query(z * 3, z * 3 + 2, x * 3);
					if (res == 1) {
						res = query(z * 3, z * 3 + 2, x * 3 + 1);
						if (!res) {
							c = 1;
							p = z * 3;
							q = z * 3 + 2;
						}
						else {
							res = query(z * 3, x * 3, x * 3 + 1);
							if (res) {
								c = 1;
								p = x * 3;
								q = x * 3 + 1;
							}
							else {
								c = 1;
								p = z * 3;
								q = x * 3;
							}
						}
					}
					else {
						c = 1;
						p = z * 3;
						q = z * 3 + 2;
					}
				}
				else {
					c = 1;
					p = z * 3;
					q = z * 3 + 1;
				}
			}
			else {
				c = 1;
				p = z * 3;
				q = z * 3 + 1;
			}
			if (c) break;
		}
	}
	ll oo, zz;
	for (i = 0; i < N; i++) {
		if (p == i || q == i) continue;
		ans[i] = query(p, q, i);
		if (ans[i]) oo = i;
		else zz = i;
	}
	ans[p] = query(oo, zz, p);
	ans[q] = !ans[p];
	ll cnt = 0;
	for (i = 0; i < N; i++) {
		if (ans[i]) cnt++;
	}
	cout << '!' << bb << cnt;
	for (i = 0; i < N; i++) {
		if (ans[i]) cout << bb << i + 1;
	}
	cout << endl;
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