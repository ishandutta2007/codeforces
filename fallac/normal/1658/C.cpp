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
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	int cnt = 0;
	for (i = 0; i < N; i++) cin >> arr[i], cnt += (arr[i] == 1 ? 1 : 0);
	if (cnt != 1) {
		cout << no << ln;
		return;
	}
	int loc = 0;
	for (i = 0; i < N; i++) {
		if (arr[i] == 1) {
			loc = i;
			break;
		}
	}
	vector<int> v;
	while (v.size() != N) {
		v.push_back(arr[loc]);
		loc = (loc + 1) % N;
	}
	for (i = 1; i < N; i++) {
		if (v[i - 1] < v[i]) {
			if (v[i] - v[i - 1] != 1) {
				cout << no << Ln;
				return;
			}
		}
	}
	cout << yes << ln;
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