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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];

void solve() {
	int N;
	ll X;
	cin >> N >> X;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	set<ll> st;
	int cnt = 0;
	st.insert(arr[1]);
	for (i = 2; i <= N; i++) {
		ll mn, mx;
		mn = *st.begin();
		mx = *st.rbegin();
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
		if (mx - mn > 2 * X) {
			st.clear();
			st.insert(arr[i]);
			cnt++;
		}
		else {
			st.insert(arr[i]);
		}
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