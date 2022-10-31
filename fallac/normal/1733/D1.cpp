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
	ll X, Y;
	cin >> N >> X >> Y;
	int i;
	string s;
	cin >> s;
	for (i = 1; i <= N; i++) arr[i] = s[i - 1] - '0';
	cin >> s;
	int cnt = 0;
	int f = 0;
	for (i = 1; i <= N; i++) {
		arr[i] ^= (s[i - 1] - '0'), cnt += arr[i];
		if (arr[i] && !f) f = i;
	}
	if (cnt & 1) {
		cout << -1 << ln;
		return;
	}
	if (cnt == 2 && arr[f + 1]) {
		if (f > 2 || f < N - 2) cout << min(X, 2 * Y) << Ln;
		else if (1 < f && f + 1 < N) cout << min(X, 3 * Y) << Ln;
		else cout << X << ln;
	}
	else cout << ((ll)cnt / 2) * Y << ln;
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