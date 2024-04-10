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
	int N;
	cin >> N;
	int i;
	int j;
	vector<int> cnt(N);
	int x = 0, a;
	for (i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (j = 0; j < N; j++) {
			a = s[j] - '0';
			if (a) {
				cnt[(i - j + N) % N]--;
				x++;
			}
			else cnt[(i - j + N) % N]++;
		}
	}
	int mn = cnt[0];
	for (i = 0; i < N; i++) mn = min(mn, cnt[i]);
	cout << mn + x << Ln;
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