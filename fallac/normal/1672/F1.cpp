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

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int query(int x) {
	cout << "? " << x << endl;
	int v;
	cin >> v;
	return v;
}

vector<int> mp[301010];
int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	map<int, int> cmap;
	for (i = 1; i <= N; i++) {
		mp[i].clear();
		cin >> arr[i];
		cmap[arr[i]]++;
	}
	int cnt = 0;
	while (1) {
		if (cmap.empty()) break;
		vector<int> ev;
		vector<int> cyc;
		for (auto it = cmap.begin(); it != cmap.end(); it++) {
			it->second--;
			if (it->second == 0) ev.push_back(it->first);
			cyc.push_back(it->first);
		}
		for (i = 0; i < cyc.size(); i++) mp[cyc[i]].push_back(cyc[(i + 1) % (int)cyc.size()]);
		for (auto e : ev) cmap.erase(e);
	}
	for (i = 1; i <= N; i++) {
		cout << mp[arr[i]].back() << bb;
		mp[arr[i]].pop_back();
	}
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