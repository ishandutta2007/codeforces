/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 1000000007
ll MOD;
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "Yes"
#define no "No"



void solve() {
	ll k, n, m;
	cin >> k >> n >> m;
	ll i;
	vector<ll> a, b;
	a.resize(n + 1);
	b.resize(m + 1);
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = 1; i <= m; i++) cin >> b[i];
	vector<ll> ans;
	ll ptr1, ptr2;
	ptr1 = ptr2 = 1;
	while (ptr1 <= n || ptr2 <= m) {
		if (ptr1 > n) {
			if (b[ptr2] <= k) {
				ans.push_back(b[ptr2]);
				if (!b[ptr2]) k++;
				ptr2++;
			}
			else {
				cout << -1 << ln;
				return;
			}
		}
		else {
			if (ptr2 > m) {
				if (a[ptr1] <= k) {
					ans.push_back(a[ptr1]);
					if (!a[ptr1]) k++;
					ptr1++;
				}
				else {
					cout << -1 << ln;
					return;
				}
			}
			else {
				if (a[ptr1] <= k) {
					ans.push_back(a[ptr1]);
					if (!a[ptr1]) k++;
					ptr1++;
				}
				else {
					if (b[ptr2] <= k) {
						ans.push_back(b[ptr2]);
						if (!b[ptr2]) k++;
						ptr2++;
					}
					else {
						cout << -1 << ln;
						return;
					}
				}
			}
		}
	}
	for (auto x : ans) cout << x << ln;
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