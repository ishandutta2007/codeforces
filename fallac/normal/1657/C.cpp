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
	cin >> N;
	cin >> s;
	int i;
	int cnt = 0;
	int all = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == '(') {
			if (i != N - 1) {
				cnt++;
				i++;
				all += 2;
			}
		}
		else {
			int j;
			for (j = i + 1; j < N; j++) {
				if (s[j] == ')') break;
			}
			if (j == N) i = N;
			else {
				cnt++;
				all += j - i + 1;
				i = j;
			}
		}
	}
	cout << cnt << bb << N - all << ln;
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