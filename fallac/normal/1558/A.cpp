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

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);
	ll N = a + b;
	vector<ll> ans;
	ll i;
	
	ll A = (N + 1) / 2;
	ll B = N - A;
	ll mn = (a - A);
	ll mx = b + min(B, a);
	for (i = mn; i <= mx; i += 2) ans.push_back(i);
	swap(A, B);

	mn = (a - A);
	mx = b + min(B, a);
	for (i = mn; i <= mx; i += 2) ans.push_back(i);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << ln;
	for (auto v : ans) cout << v << bb;
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