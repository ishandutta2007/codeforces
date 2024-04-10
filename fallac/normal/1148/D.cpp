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

#define MAX 401010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

void solve() {
	ll N;
	cin >> N;
	ll i;
	set<pll> arr, rem;
	ll a, b;
	map<pll, ll> num;
	for (i = 1; i <= N; i++) {
		cin >> a >> b;
		num[{a, b}] = i;
		num[{b, a}] = i;
		if (a < b) rem.emplace(a, b);
		else arr.emplace(b, a);
	}
	vector<ll> seq;
	ll pv = 0;
	while (arr.size()) {
		auto t = *arr.begin();
		arr.erase(arr.begin());
		if (pv < t.second) pv = t.first, seq.push_back(num[t]);		
	}
	vector<ll> ans = seq;
	seq.clear();
	pv = 0;
	arr = rem;
	while (arr.size()) {
		auto t = *arr.begin();
		arr.erase(arr.begin());
		if (pv < t.second) pv = t.first, seq.push_back(num[t]);		
	}
	reverse(seq.begin(), seq.end());
	if (ans.size() < seq.size()) ans.swap(seq);
	cout << ans.size() << ln;
	for (auto v : ans) cout << v << ln;
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