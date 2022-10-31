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

#define MAX 1010101
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];
ll streak[MAX];
ll ssum[MAX];
ll ans[MAX];

void solve() {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	int K = N * M;
	int i, j;
	ll sum1 = 0;
	for (i = 1; i <= N * M; i++) arr[i] = s[i - 1] - '0', ans[i] = N + M, ssum[i] = 0, streak[i] = 0;
	for (i = 1; i <= K; i++) {
		if (arr[i] == 0) streak[i] = streak[i - 1] + 1;
		if (i > M) ssum[i] = ssum[i - M];
		if (streak[i] >= min(M, i)) ssum[i]++;
		ans[i] -= (ssum[i] + N - (ll)(i - 1) / M - 1);
	}
	ll sum2 = 0;
	for (i = 0; i <= K; i++) ssum[i] = streak[i] = 0;
	for (i = 1; i <= K; i++) {
		if (arr[i] == 0) streak[i] = ((i > M) ? streak[i - M] : 0) + 1;
		if (streak[i] >= (i - 1) / M + 1) ssum[i]++;
		ssum[i] += ssum[i - 1];
		ans[i] -= (ssum[i] - ((i > M) ? ssum[i - M] : 0) + M - min(i, M));
	}
	for (i = 1; i <= K; i++) cout << ans[i] << bb;
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