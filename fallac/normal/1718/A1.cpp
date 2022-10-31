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
int dp[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	map<int, int> mp;
	dp[0] = 0;
	mp[0] = 0;
	int sum = 0;
	for (i = 1; i <= N; i++) {
		sum ^= arr[i];
		dp[i] = dp[i - 1] + 1;
		if (i > 1 && arr[i] == arr[i - 1]) dp[i] = min(dp[i], dp[i - 2] + 1);
		if (mp.find(sum) != mp.end()) dp[i] = min(dp[i], mp[sum] + i - 1);
		if (arr[i] == 0) dp[i] = min(dp[i], dp[i - 1]);
		if (mp.find(sum) != mp.end()) mp[sum] = min(mp[sum], dp[i] - i);
		else mp[sum] = dp[i] - i;
	}
	cout << dp[N] << ln;
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