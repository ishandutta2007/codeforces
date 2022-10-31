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
	vector<int> arr;
	int i, a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		arr.push_back(a);
	}
	vector<pi> qv;
	int cnt = 0;
	vector<int> ansv;
	while (arr.size()) {
		if (((int)arr.size()) & 1) {
			cout << -1 << ln;
			return;
		}
		int f = arr[0];
		int ind = -1;
		for (i = 1; i < arr.size(); i++) {
			if (arr[i] == f) {
				ind = i;
				break;
			}
		}
		if (ind == -1) {
			cout << -1 << ln;
			return;
		}
		if (ind == 1) {
			cnt += 2;
			arr.erase(arr.begin());
			arr.erase(arr.begin());
			ansv.push_back(2);
			continue;
		}
		vector<int> midn;
		for (i = 1; i < ind; i++) midn.push_back(arr[i]);
		for (i = 0; i < midn.size(); i++) qv.emplace_back(ind + 1 + cnt + i, midn[i]);
		arr.erase(arr.begin());
		arr.erase(arr.begin());
		reverse(midn.begin(), midn.end());
		for (i = 0; i < midn.size(); i++) arr[i] = midn[i];
		cnt += ((int)midn.size()) * 2 + 2;
		ansv.push_back(((int)midn.size()) * 2 + 2);
	}
	cout << qv.size() << ln;
	for (auto p : qv) cout << p.first << bb << p.second << ln;
	cout << ansv.size() << ln;
	for (auto ans : ansv) cout << ans << bb;
	cout << ln;
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