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
int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	vector<int> v;
	string s;
	cin >> s;
	int ans = 0;
	for (i = 0; i < N * 2; i++) {
		if (s[i] == '(') v.push_back(-1);
		else {
			while (v.back() >= 1) {
				ans += v.back();
				v.pop_back();
			}
			v.pop_back();
			if (!v.size() || v.back() < 1) v.push_back(1);
		}
	}
	while (v.size()) ans += v.back(), v.pop_back();
	cout << ans << Ln;
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