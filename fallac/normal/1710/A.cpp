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

ll arr[MAX];

void solve() {
	ll N, M, K;
	cin >> N >> M >> K;
	ll i;
	ll mx = 0;
	for (i = 1; i <= K; i++) cin >> arr[i], mx = max(mx, arr[i]);
	if (mx >= N * M) {
		cout << "Yes" << ln;
		return;
	}
	ll cnt = 0;
	ll mmx = 0;
	ll ccnt = 0;
	for (i = 1; i <= K; i++) {
		if (arr[i] >= 2 * M) cnt += arr[i] / M, mmx = max(mmx, arr[i] / M), ccnt++;
	}
	if (cnt >= N) {
		if (cnt != N) {
			if (N <= ccnt * 2) {
				if (N % 2 == 0) {
					cout << "Yes" << ln;
					return;
				}
				else if (mmx > 2) {
					cout << "Yes" << ln;
					return;
				}
			}
			else {
				if (mmx > 2) {
					cout << "Yes" << ln;
					return;
				}
			}
		}
		else {
			cout << "Yes" << ln;
			return;
		}
	}
	mmx = 0;
	swap(N, M);
	cnt = 0;
	ccnt = 0;
	for (i = 1; i <= K; i++) {
		if (arr[i] >= 2 * M) cnt += arr[i] / M, mmx = max(mmx, arr[i] / M), ccnt++;
	}
	if (cnt >= N) {
		if (cnt != N) {
			if (N <= ccnt * 2) {
				if (N % 2 == 0) {
					cout << "Yes" << ln;
					return;
				}
				else if (mmx > 2) {
					cout << "Yes" << ln;
					return;
				}
			}
			else {
				if (mmx > 2) {
					cout << "Yes" << ln;
					return;
				}
			}
		}
		else {
			cout << "Yes" << ln;
			return;
		}
	}
	cout << "No" << ln;
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