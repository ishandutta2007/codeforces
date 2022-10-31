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

int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	vector<int> o, e;
	for (i = 1; i <= N; i++) cin >> arr[i];
	for (i = 1; i <= N; i++) {
		if ((arr[i] ^ arr[1]) & 1) o.push_back(i);
		else e.push_back(i);
	}
	reverse(e.begin(), e.end());
	vector<pii> vpi;
	for (i = 1; i < e.size(); i++) vpi.emplace_back(e[i], e[0]);
	for (auto v : o) vpi.emplace_back(1, v);
	cout << vpi.size() << Ln;
	for (auto& [a, b] : vpi) cout << a << bb << b << Ln;
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