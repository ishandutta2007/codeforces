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
	string s;
	int N, K;
	cin >> N >> K;
	cin >> s;
	vector<int> v(27), ans(27);
	for (auto x : s) v[x - 'a']++;
	int i, j;
	ans[0] = K;
	for (i = 0; i < min(26, (N / K)); i++) {
		ans[i + 1] = min(ans[i], v[i]);
		ans[i] -= ans[i + 1];
	}
	for (i = 25; i >= 0; i--) for (j = 1; j <= ans[i]; j++) cout << (char)('a' + i);
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