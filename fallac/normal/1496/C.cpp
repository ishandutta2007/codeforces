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

#define MAX 101010
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll arr1[MAX], arr2[MAX];

void solve() {
	ll N;
	cin >> N;
	double ans = 0l;
	ll i,a, b;
	ll p1, p2;
	p1 = p2 = 0;
	for (i = 1; i <= 2 * N; i++) {
		cin >> a >> b;
		if (a) arr1[++p1] = abs(a);
		if (b) arr2[++p2] = abs(b);
	}
	sort(arr1 + 1, arr1 + N + 1);
	sort(arr2 + 1, arr2 + N + 1);
	for (i = 1; i <= N; i++) {
		ans += sqrt(arr1[i] * arr1[i] + arr2[i] * arr2[i]);
	}
	printf("%.10lf\n", ans);
}

void init() {
	
}

signed main() {
	//ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}