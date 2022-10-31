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

void solve() {
	int N;
	string s;
	cin >> N;
	cin >> s;
	int i;
	int cnt = 0;
	for (i = 0; i < N; i++) if (s[i] == '1') cnt++;
	if (cnt % 2 || cnt == 0) {
		cout << no << ln;
		return;
	}
	int rot = N;
	vector<pii> ans;
	vector<pii> vp;
	for (i = 0; i < N; i++) {
		if (vp.empty()) {
			vp.emplace_back(s[i] - '0', i);
			continue;
		}
		int c = s[i] - '0';
		vp.emplace_back(c, i);
		while (vp.size() >= 2) {
			int p1, p2;
			int c1, c2;
			p1 = vp[vp.size() - 1].second;
			p2 = vp[vp.size() - 2].second;
			c1 = vp[vp.size() - 1].first;
			c2 = vp[vp.size() - 2].first;
			if (c1 ^ c2) {
				ans.emplace_back(p1, p2);
				vp.pop_back();
				vp.pop_back();
				if (c1) vp.emplace_back(1, p2);
				else vp.emplace_back(1, p1);
			}
			else break;
		}
	}
	while (vp.size() != 1) {
		int p1, p2;
		p1 = vp[vp.size() - 1].second;
		p2 = vp[vp.size() - 2].second;
		vp.pop_back();
		vp.pop_back();
		ans.emplace_back(p1, p2);
		vp.emplace_back(0, p2);
		while (vp.size() >= 2) {
			int p1, p2;
			int c1, c2;
			p1 = vp[vp.size() - 1].second;
			p2 = vp[vp.size() - 2].second;
			c1 = vp[vp.size() - 1].first;
			c2 = vp[vp.size() - 2].first;
			if (c1 ^ c2) {
				ans.emplace_back(p1, p2);
				vp.pop_back();
				vp.pop_back();
				if (c1) vp.emplace_back(1, p2);
				else vp.emplace_back(1, p1);
			}
			else break;
		}
	}
	cout << yes << Ln;
	for (auto& p : ans) cout << p.first + 1 << bb << p.second + 1 << ln;
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