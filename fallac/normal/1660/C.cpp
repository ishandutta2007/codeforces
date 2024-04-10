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
	int N;
	string s;
	cin >> s;
	N = s.size();
	int i;
	int cnt = 0;
	vector<int> dp(27, -1);
	dp[26] = 0;
	int j;
	for (i = 0; i < N; i++) {
		int c = s[i] - 'a';
		int a = max(dp[26], dp[c] + 1);
		dp[c] = max(dp[c], dp[26] + 1);
		dp[26] = a;
	}
	cout << N - dp[26] << ln;
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