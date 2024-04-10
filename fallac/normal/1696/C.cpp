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
typedef pair<int, int> pii;

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

#define yes "Yes"
#define no "No"

ll arr[MAX];

void solve() {
	ll N, M, K;
	cin >> N >> M;
	ll i;
	vector<pll> vp;
	ll a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		ll cnt = 1;
		while (a % M == 0) {
			a /= M;
			cnt *= M;
		}
		if (vp.size() && vp.back().first == a) vp.back().second += cnt;
		else vp.emplace_back(a, cnt);
	}
	cin >> K;
	for (i = 1; i <= K; i++) cin >> arr[i];
	for (i = K; i >= 1; i--) {
		if (vp.size() == 0) {
			cout << no << ln;
			return;
		}
		else {
			if (vp.back().first > arr[i]) {
				cout << no << ln;
				return;
			}
			if (arr[i] % vp.back().first) {
				cout << no << ln;
				return;
			}
			ll cnt = arr[i] / vp.back().first;
			ll cpy = cnt;
			if (vp.back().second < cnt) {
				cout << no << ln;
				return;
			}
			while (cpy) {
				if (cpy == 1) break;
				if (cpy % M) {
					cout << no << ln;
					return;
				}
				cpy /= M;
			}
			vp.back().second -= cnt;
			if (!vp.back().second) vp.pop_back();
		}
	}
	if (vp.size()) {
		cout << no << ln;
		return;
	}
	cout << yes << ln;
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