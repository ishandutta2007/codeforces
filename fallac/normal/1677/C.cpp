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

#define MAX 1010101
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr1[MAX];
int arr2[MAX];
int arr[MAX];
int cpy[MAX];
int vis[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	vector<int> cyc;
	for (i = 1; i <= N; i++) vis[i] = 0, cin >> arr1[i];
	for (i = 1; i <= N; i++) cin >> arr2[i];
	for (i = 1; i <= N; i++) cpy[arr2[i]] = i;
	for (i = 1; i <= N; i++) arr[i] = cpy[arr1[i]];
	for (i = 1; i <= N; i++) {
		if (vis[i]) continue;
		int sz = 0;
		int v = i;
		while (1) {
			if (vis[v]) break;
			vis[v] = 1;
			sz++;
			v = arr[v];
		}
		cyc.push_back(sz);
	}
	int plus = 0;
	ll ans = 0;
	for (auto v : cyc) {
		if (v == 1) continue;
		plus += v / 2;
	}
	for (i = 1; i <= plus; i++) ans -= i;
	for (i = N; i >= N - plus + 1; i--) ans += i;
	cout << ans * 2 << ln;
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