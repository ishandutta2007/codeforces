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
typedef pair<int, int> pi;

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
	string s;
	cin >> s;
	N = s.size();
	vector<vector<int>> mp(26, vector<int>(N));
	int i, j;
	mp[s[N - 1] - 'a'][N - 1] = 1;
	for (i = N - 2; i >= 0; i--) {
		for (j = 0; j < 26; j++) mp[j][i] = mp[j][i + 1];
		mp[s[i] - 'a'][i] = 1;
	}
	for (i = 0; i < N; i++) {
		int c = s[i] - 'a';
		if (i == N - 1) {
			for (; i < N; i++) cout << s[i];
			cout << ln;
			return;
		}
		else {
			if (mp[c][i + 1]) continue;
			else {
				for (; i < N; i++) cout << s[i];
				cout << ln;
				return;
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