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

#define yes "YES"
#define no "NO"

int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i, a;
	vector<pii> vpi;
	for (i = 1; i <= N; i++) {
		cin >> a;
		if (vpi.size() && vpi.back().first == a) vpi.back().second++;
		else vpi.emplace_back(a, 1);
	}
	while (1) {
		if (vpi.size() == 1) {
			if (vpi[0].second == 1) cout << vpi[0].first << ln;
			else cout << 0 << ln;
			return;
		}
		vector<pii> v2;
		int zcnt = 0;
		for (i = 0; i < vpi.size(); i++) zcnt += vpi[i].second - 1;
		if (zcnt) v2.emplace_back(0, zcnt);
		for (i = 1; i < vpi.size(); i++) v2.emplace_back(vpi[i].first - vpi[i - 1].first, 1);
		sort(v2.begin(), v2.end());
		for (i = 0; i < v2.size() - 1; i++) if (v2[i].first == v2[i + 1].first) v2[i + 1].second += v2[i].second, v2[i].first = 1010101;
		sort(v2.begin(), v2.end());
		while (v2.back().first == 1010101) v2.pop_back();
		v2.swap(vpi);
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