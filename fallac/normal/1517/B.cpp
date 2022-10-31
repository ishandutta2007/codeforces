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
#define INF 100000000000

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
	ll N, M;
	cin >> N >> M;
	ll i, j;
	vector<multiset<ll>> arr;
	arr.resize(N + 1);
	for (i = 1; i <= N; i++) {
		ll a;
		for (j = 1; j <= M; j++) cin >> a, arr[i].insert(a);
	}
	vector<vector<ll>> ans;
	vector<ll> v;
	for (i = 1; i <= M; i++) {
		v.clear();
		ll loc;
		ll mn;
		mn = INF;
		for (j = 1; j <= N; j++) if (mn > *arr[j].begin()) mn = *arr[j].begin(), loc = j;
		arr[loc].erase(arr[loc].find(mn));
		for (j = 1; j <= N; j++) {
			if (j != loc) {
				multiset<ll>::iterator it;
				it = arr[j].end();
				it--;
				v.push_back(*it);
				arr[j].erase(it);
			}
			else v.push_back(mn);
		}
		ans.push_back(v);
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cout << ans[j - 1][i - 1] << bb;
		}
		cout << ln;
	}
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