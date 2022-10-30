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
	cin >> N;
	string s;
	cin >> s;
	vector<ll> v;
	vector<ll> A, B, C;
	A.resize(N);
	B.resize(N);
	C.resize(N);
	ll i;
	for (i = 0; i < N; i++) {
		if (s[i] == 'a') v.push_back(i);
		if (i) {
			A[i] = A[i - 1];
			B[i] = B[i - 1];
			C[i] = C[i - 1];
		}
		if (s[i] == 'a') A[i]++;
		if (s[i] == 'b') B[i]++;
		if (s[i] == 'c') C[i]++;
	}
	if (v.size() <= 1) {
		cout << -1 << ln;
		return;
	}
	ll mn = 10;
	for (i = 1; i < v.size(); i++) {
		ll b, c;
		b = B[v[i]] - B[v[i - 1]];
		c = C[v[i]] - C[v[i - 1]];
		if (b <= 1 && c <= 1) mn = min(mn, v[i] - v[i - 1] + 1);
	}
	if (mn == 10) {
		if (N >= 7) {
			if (A[6] == 3 && B[6] == 2 && C[6] == 2) {
				cout << 7 << ln;
				return;
			}
			else {
				for (i = 7; i < N; i++) {
					ll a, b, c;
					a = A[i] - A[i - 7];
					b = B[i] - B[i - 7];
					c = C[i] - C[i - 7];
					if (a == 3 && b == 2 && c == 2) {
						cout << 7 << ln;
						return;
					}
				}
				cout << -1 << ln;
				return;
			}
		}
		else {
			cout << -1 << ln;
			return;
		}
	}
	cout << mn << ln;
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