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

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];

void solve() {
	ll N;
	cin >> N;
	ll l, r;
	l = 1, r = N + 1;
	ll i;
	vector<ll> A, B;
	A.resize(N + 1);
	B.resize(N + 1);
	for (i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
	}
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		vector<pll> range(N + 1);
		for (i = 1; i <= N; i++) {
			range[i] = { mid - A[i] - 1, B[i] };
		}
		ll cnt = 0;
		for (i = 1; i <= N; i++) {
			if (range[i].first <= cnt && cnt <= range[i].second) cnt++;
		}
		if (cnt >= mid) l = mid;
		else r = mid;
	}
	cout << l << ln;
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