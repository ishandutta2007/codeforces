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
	int N, M;
	cin >> N >> M;
	int i;
	string s(M, '0');
	vector<int> val(M);
	for (i = 0; i < M; i++) {
		s[i] = '1';
		cout << '?' << bb << s << endl;
		cin >> val[i];
		s[i] = '0';
	}
	vector<int> v;
	for (i = 0; i < M; i++) v.push_back(i);
	sort(v.begin(), v.end(), [&](int i, int j) {return val[i] < val[j]; });
	int ans = 0;
	for (i = 0; i < M; i++) {
		int e = v[i];
		s[e] = '1';
		cout << '?' << bb << s << endl;
		int x;
		cin >> x;
		if (ans + val[e] == x) ans += val[e];
		else s[e] = '0';
	}
	cout << '!' << bb << ans << endl;
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