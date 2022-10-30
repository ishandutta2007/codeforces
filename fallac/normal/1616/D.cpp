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

ll arr[MAX];
ll chk[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 1; i <= N; i++) cin >> arr[i], chk[i] = 0;
	ll X;
	cin >> X;
	for (i = 1; i <= N; i++) arr[i] -= X;
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		if (arr[i] < 0) {
			if (i > 1) {
				if (chk[i - 1] && arr[i - 1] + arr[i] < 0) continue;
			}
			chk[i] = 1;
			cnt++;
			if (i < N && arr[i + 1] >= 0) arr[i + 1] += arr[i];
		}
		else chk[i] = 1, cnt++;
	}
	cout << cnt << ln;
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