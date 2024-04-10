/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000

#define pll pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll sq(ll x) {
	return x * x;
}

void solve() {
	ll a, b, c;
	vector<ll> A, B, C;
	cin >> a >> b >> c;
	ll i;
	ll x;
	for (i = 1; i <= a; i++) cin >> x, A.push_back(x);
	for (i = 1; i <= b; i++) cin >> x, B.push_back(x);
	for (i = 1; i <= c; i++) cin >> x, C.push_back(x);
	ll aa;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	ll ans = INT64_MAX;
	for (i = 0; i < a; i++) {
		aa = A[i];
		ll b1, b2;
		ll c1, c2;
		ll indb = lower_bound(B.begin(), B.end(), aa) - B.begin();
		if (indb >= b) b1 = b2 = B[indb - 1];
		else if (indb == 0) b1 = b2 = B[0];
		else b1 = B[indb - 1], b2 = B[indb];
		ll indc = lower_bound(C.begin(), C.end(), aa) - C.begin();
		if (indc >= c) c1 = c2 = C[indc - 1];
		else if (indc == 0) c1 = c2 = C[0];
		else c1 = C[indc - 1], c2 = C[indc];
		ans = min(ans, sq(aa - b1) + sq(aa - c1) + sq(b1 - c1));
		ans = min(ans, sq(aa - b2) + sq(aa - c1) + sq(b2 - c1));
		ans = min(ans, sq(aa - b1) + sq(aa - c2) + sq(b1 - c2));
		ans = min(ans, sq(aa - b2) + sq(aa - c2) + sq(b2 - c2));
	}
	swap(a, b);
	swap(A, B);
	for (i = 0; i < a; i++) {
		aa = A[i];
		ll b1, b2;
		ll c1, c2;
		ll indb = lower_bound(B.begin(), B.end(), aa) - B.begin();
		if (indb >= b) b1 = b2 = B[indb - 1];
		else if (indb == 0) b1 = b2 = B[0];
		else b1 = B[indb - 1], b2 = B[indb];
		ll indc = lower_bound(C.begin(), C.end(), aa) - C.begin();
		if (indc >= c) c1 = c2 = C[indc - 1];
		else if (indc == 0) c1 = c2 = C[0];
		else c1 = C[indc - 1], c2 = C[indc];
		ans = min(ans, sq(aa - b1) + sq(aa - c1) + sq(b1 - c1));
		ans = min(ans, sq(aa - b2) + sq(aa - c1) + sq(b2 - c1));
		ans = min(ans, sq(aa - b1) + sq(aa - c2) + sq(b1 - c2));
		ans = min(ans, sq(aa - b2) + sq(aa - c2) + sq(b2 - c2));
	}
	swap(a, c);
	swap(A, C);
	for (i = 0; i < a; i++) {
		aa = A[i];
		ll b1, b2;
		ll c1, c2;
		ll indb = lower_bound(B.begin(), B.end(), aa) - B.begin();
		if (indb >= b) b1 = b2 = B[indb - 1];
		else if (indb == 0) b1 = b2 = B[0];
		else b1 = B[indb - 1], b2 = B[indb];
		ll indc = lower_bound(C.begin(), C.end(), aa) - C.begin();
		if (indc >= c) c1 = c2 = C[indc - 1];
		else if (indc == 0) c1 = c2 = C[0];
		else c1 = C[indc - 1], c2 = C[indc];
		ans = min(ans, sq(aa - b1) + sq(aa - c1) + sq(b1 - c1));
		ans = min(ans, sq(aa - b2) + sq(aa - c1) + sq(b2 - c1));
		ans = min(ans, sq(aa - b1) + sq(aa - c2) + sq(b1 - c2));
		ans = min(ans, sq(aa - b2) + sq(aa - c2) + sq(b2 - c2));
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