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

int A[MAX];

void solve() {
	int N, K;
	cin >> N;
	int i;
	cin >> K;
	int mn = 101010;
	for (i = 1; i <= N; i++) cin >> A[i], mn = min(mn, A[i]);
	priority_queue<pii> pq;
	for (i = 1; i <= N; i++) pq.emplace(A[i], i);
	int ans = 101010;
	while (1) {
		auto t = pq.top();
		pq.pop();
		ans = min(ans, t.first - mn);
		if (t.first == 0) break;
		int nv = A[t.second] / t.first + 1;
		if (nv > K) break;
		pq.emplace(A[t.second] / nv, t.second), mn = min(mn, A[t.second] / nv);
	}
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