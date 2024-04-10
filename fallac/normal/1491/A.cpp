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

ll arr[MAX];

void solve() {
	ll N, Q;
	cin >> N >> Q;
	ll i, num = 0;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i]) num++;
	}
	ll a, b;
	for (i = 1; i <= Q; i++) {
		cin >> a >> b;
		if (a == 1) {
			if (arr[b] == 1) {
				num--;
			}
			else num++;
			arr[b] = 1 - arr[b];
		}
		else {
			if (b <= num) {
				cout << 1 << ln;
			}
			else cout << 0 << ln;
		}
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}