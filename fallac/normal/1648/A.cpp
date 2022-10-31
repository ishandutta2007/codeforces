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

vector<int> X[MAX];
vector<int> Y[MAX];

void solve() {
	int N, M;
	cin >> N >> M;
	int i, j, a;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> a;
			X[a].push_back(i);
			Y[a].push_back(j);
		}
	}
	ll ans = 0;
	for (i = 1; i <= 100000; i++) {
		if (X[i].empty()) continue;
		ll sum = 0;
		for (auto x : X[i]) sum += x;
		int cnt = 0;
		for (auto x : X[i]) {
			cnt++;
			if (cnt == X[i].size()) break;
			sum -= x;
			ans += sum - (ll)(X[i].size() - cnt) * (ll)x;
		}
	}
	for (i = 1; i <= 100000; i++) {
		sort(Y[i].begin(), Y[i].end());
		if (Y[i].empty()) continue;
		ll sum = 0;
		for (auto x : Y[i]) sum += x;
		int cnt = 0;
		for (auto x : Y[i]) {
			cnt++;
			if (cnt == X[i].size()) break;
			sum -= x;
			ans += sum - (ll)(X[i].size() - cnt) * (ll)x;
		}
	}
	cout << ans << ln;
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