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

//var

//

void solve() {
	int N;
	cin >> N;
	int i;
	vector<int> v;
	map<int, int> mp;
	for (i = 1; i <= N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		mp[a]++;
	}
	sort(v.begin(), v.end());
	int ones, twos;
	ones = twos = 0;
	for (auto &[x, c] : mp) {
		if (c >= 2) twos++;
		else ones++;
	}
	int ans = 0;
	if (ones == 0) ans = max(ans, twos + ones / 2);
	else ans = max((ones - 1) / 2 + twos + 1, ans);
	
	cout << ans << ln;
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