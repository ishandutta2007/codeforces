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
	cin >> N;
	int i;
	string s;
	cin >> s;
	vector<int> v;
	for (i = 0; i < N; i++) if (s[i] == '0') v.push_back(i);
	int ans = 0;
	int a, b;
	for (i = 1; i < v.size(); i++) {
		a = v[i - 1];
		b = v[i];
		if (v[i] - v[i - 1] == 1) ans += 2;
		else if (v[i] - v[i - 1] == 2) ans += 1;
	}
	cout << ans << ln;
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