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
#define INF 1000000000000000009

#define yes "YES"
#define no "NO"

ll f(ll a, ll b) {
	if (log10(a) + log10(b) > 18.1) return INF;
	else return a * b;
}

void solve() {
	ll N, K, X;
	cin >> N >> K >> X;
	X--;
	string in, s;
	cin >> in;
	ll i;
	vector<ll> arr;
	for (i = 0; i < N; i++) {
		if (in[i] == '*') {
			if (i && in[i - 1] == '*') {
				arr.back()++;
			}
			else {
				s.push_back('*');
				arr.push_back(1);
			}
		}
		else s.push_back(in[i]);
	}
	if (arr.empty()) {
		cout << in << ln;
		return;
	}
	N = s.size();
	ll M = arr.size();
	for (i = 0; i < M; i++) arr[i] *= K, arr[i]++;
	vector<ll> ans(M), mul(M);
	mul[M - 1] = arr[M - 1];
	for (i = M - 2; i >= 0; i--) mul[i] = f(mul[i + 1], arr[i]);
	for (i = 0; i < M; i++) {
		if (i == M - 1) ans[i] = X;
		else {
			ans[i] = X / mul[i + 1];
			X %= mul[i + 1];
		}
	}
	ll cnt = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == '*') {
			for (ll j = 0; j < ans[cnt]; j++) cout << 'b';
			cnt++;
		}
		else cout << s[i];
	}
	cout << ln;
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