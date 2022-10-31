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

#define MAX 101010
#define MOD 100000009
#define INF 10000000000000

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
	ll N;
	cin >> N;
	string s;
	cin >> s;
	ll i, j;
	ll a = 97;
	for (i = 0; i < 26; i++) {
		ll chk = 1;
		for (j = 0; j < N; j++) {
			if (s[j] == (char)(a + i)) {
				chk = 0;
				break;
			}
		}
		if (chk) {
			char c = a + i;
			cout << c << ln;
			return;
		}
	}
	ll k;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			ll chk = 1;
			for (k = 0; k < N - 1; k++) {
				if ((s[k] == (char)(a + i)) && (s[k + 1] == (char)(a + j))) {
					chk = 0;
					break;
				}
			}
			if (chk) {
				char c = a + i;
				cout << c;
				c = a + j;
				cout << c << ln;
				return;
			}
		}
	}
	ll l;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			for (k = 0; k < 26; k++) {
				ll chk = 1;
				for (l = 0; l < N - 2; l++) {
					if ((s[l] == (char)(a + i)) && (s[l + 1] == (char)(a + j)) && (s[l + 2] == (char)(a + k))) {
						chk = 0;
						break;
					}
				}
				if (chk) {
					char c = a + i;
					cout << c;
					c = a + j;
					cout << c;
					c = a + k;
					cout << c << ln;
					return;
				}
			}
		}
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