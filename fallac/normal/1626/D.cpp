/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef int ll;
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

ll f(ll x) {
	ll i = 1;
	while (i < x) i <<= 1;
	return i;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> in;
	ll a;
	for (i = 1; i <= N; i++) cin >> a, in.push_back(a);
	sort(in.begin(), in.end());
	vector<ll> arr;
	for (i = 0; i < N; i++) {
		if (arr.empty()) arr.push_back(1);
		else {
			if (in[i] == in[i - 1]) arr.back()++;
			else arr.push_back(1);
		}
	}
	ll M = arr.size();
	ll pr, mid;
	pr = -1;
	ll j, k;
	ll prsum = 0;
	ll ans = 1000000000;
	for (j = 0; j < 20; j++) {
		while (pr + 1 < M && prsum + arr[pr + 1] <= (1 << j)) prsum += arr[pr + 1], pr++;
		ll midsum = 0;
		mid = pr;
		for (k = 0; k < 20; k++) {
			while (mid + 1 < M && midsum + arr[mid + 1] <= (1 << k)) midsum += arr[mid + 1], mid++;
			ans = min(ans, (1 << j) + (1 << k) + f(N - prsum - midsum));
		}
	}
	cout << ans - N << ln;
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