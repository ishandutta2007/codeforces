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

//var

//

void solve() {
	int N, M;
	cin >> N >> M;
	int i;
	vector<int> cnt(M + 3);
	int a;
	for (i = 1; i <= N; i++) cin >> a, a = min(a, M + 1 - a), cnt[a]++;
	for (i = 1; i <= M; i++) {
		if (i > M + 1 - i) {
			if (cnt[M + 1 - i]) cout << 'A', cnt[M + 1 - i]--;
			else cout << 'B';
		}
		else {
			if (cnt[i]) cout << 'A', cnt[i]--;
			else cout << 'B';
		}
	}
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