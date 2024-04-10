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
	ll i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	for (i = 1; i <= N; i++) {
		if (arr[i] != arr[N - i + 1]) break;
	}
	if (i > N) cout << yes << ln;
	else {
		ll a, b;
		a = arr[i];
		b = arr[N - i + 1];
		vector<ll> v;
		for (i = 1; i <= N; i++) if (arr[i] != a) v.push_back(arr[i]);
		ll c = 1;
		for (i = 0; i < v.size(); i++) if (v[i] != v[v.size() - i - 1]) c = 0;
		if (c) {
			cout << yes << ln;
			return;
		}
		a = b;
		v.clear();
		for (i = 1; i <= N; i++) if (arr[i] != a) v.push_back(arr[i]);
		c = 1;
		for (i = 0; i < v.size(); i++) if (v[i] != v[v.size() - i - 1]) c = 0;
		if (c) cout << yes << ln;
		else cout << no << ln;
	}
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