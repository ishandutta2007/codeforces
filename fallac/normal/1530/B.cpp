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
	ll N, M;
	cin >> N >> M;
		ll i, j;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++) {
				if (i == 1 || i == N || j == 1 || j == M) {
					if (i == 1 || i == N) {
						if (i % 2) {
							if (j % 2) cout << 1;
							else cout << 0;
						}
						else {
							if ((j % 2) && (j >= 3) && (j <= M - 2)) cout << 1;
							else cout << 0;
						}
					}
					else {
						if (i % 2) cout << 1;
						else cout << 0;
					}
				}
				else cout << 0;
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