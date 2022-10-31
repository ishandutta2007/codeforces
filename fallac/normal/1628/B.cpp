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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[26][26];
string sts[MAX];

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

void solve() {
	ll N;
	cin >> N;
	memset(arr, 0, sizeof(arr));
	ll i;
	for (i = 1; i <= N; i++) cin >> sts[i];
	map<string, bool> three;
	for (i = 1; i <= N; i++) {
		if (sts[i].size() == 1) {
			cout << yes << ln;
			return;
		}
		else if (sts[i].size() == 2) {
			if (sts[i][0] == sts[i][1]) {
				cout << yes << ln;
				return;
			}
			if (arr[sts[i][1] - 'a'][sts[i][0] - 'a']) {
				cout << yes << ln;
				return;
			}
			arr[sts[i][0] - 'a'][sts[i][1] - 'a'] = 1;
		}
		else {
			if (three[rev(sts[i])]) {
				cout << yes << ln;
				return;
			}
			three[sts[i]] = 1;
			if (sts[i][0] == sts[i][2]) {
				cout << yes << Ln;
				return;
			}
		}
	}
	memset(arr, 0, sizeof(arr));
	for (i = 1; i <= N; i++) {
		if (sts[i].size() == 3) arr[sts[i][0] - 'a'][sts[i][1] - 'a'] = 1;
		if (sts[i].size() == 2) {
			if (arr[sts[i][1] - 'a'][sts[i][0] - 'a']) {
				cout << yes << ln;
				return;
			}
		}
	}
	memset(arr, 0, sizeof(arr));
	for (i = N; i >= 1; i--) {
		if (sts[i].size() == 3) arr[sts[i][1] - 'a'][sts[i][2] - 'a'] = 1;
		if (sts[i].size() == 2) {
			if (arr[sts[i][1] - 'a'][sts[i][0] - 'a']) {
				cout << yes << ln;
				return;
			}
		}
	}
	cout << no << ln;
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