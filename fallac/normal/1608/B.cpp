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

//var

//

void solve() {
	ll N;
	ll A, B;
	cin >> N >> A >> B;
	ll aaa, bbb;
	aaa = A, bbb = B;
	ll i;
	ll mn, mx;
	mn = mx = 0;
	ll c;
	if (abs(A - B) >= 2) {
		cout << -1 << ln;
		return;
	}
	if (A < B) c = 1, swap(A, B);
	else c = 0;
	vector<ll> v(1, 0);
	for (i = 1; i <= A; i++) {
		v.push_back(mx + 1);
		v.push_back(mn - 1);
		mx++, mn--;
	}
	if (B != A) {
		while (v.size() < N) {
			v.push_back(mn - 1);
			mn--;
		}
	}
	else {
		while (v.size() < N) {
			v.push_back(mx + 1);
			mx++;
		}
	}
	if (v.size() != N) {
		cout << -1 << ln;
		return;
	}
	for (i = 0; i < N; i++) v[i] -= mn, v[i]++;
	if (c) {
		for (i = 0; i < N; i++) v[i] = N + 1 - v[i];
	}
	ll a, b;
	a = b = 0;
	for (i = 1; i < N - 1; i++) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) a++;
		if (v[i - 1] > v[i] && v[i] < v[i + 1]) b++;
	}
	if (aaa == a && bbb == b) {
		for (i = 0; i < N; i++) cout << v[i] << bb;
		cout << ln;
	}
	else cout << -1 << Ln;
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