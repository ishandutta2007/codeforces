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
	cin >> N;
	int i;
	vector<vector<int>> mp;
	vector<int> v;
	vector<int> endp;
	vector<int> startp;
	endp.push_back(-1);
	startp.push_back(-1);
	int C = 0;
	int x;
	for (i = 0; i < N; i++) {
		cin >> x;
		if (!x) {
			if (v.empty()) continue;
			endp.push_back(i - 1);
			mp.push_back(v);
			v.clear();
		}
		else {
			v.push_back(x);
			if(v.size()==1) startp.push_back(i);
		}
	}
	if (v.size()) mp.push_back(v), endp.push_back(N - 1);
	C = mp.size();
	if (C == 0) {
		cout << 0 << bb << N << ln;
		return;
	}
	int k;
	int mx = 0;
	pii mv = { 0, 0 };
	bool chk = false;
	for (k = 0; k < C; k++) {
		if (mp[k].size() > 1 || mp[k][0] > 0) chk = true;
		int cnt = 0;
		int N = mp[k].size();
		int fm, em;
		fm = em = -1;
		for (i = 0; i < N; i++) {
			if (mp[k][i] < 0) {
				cnt++;
				if (fm == -1) fm = i;
				em = i;
			}
		}
		if (cnt % 2 == 0) {
			int cnt2 = 0;
			for (i = 0; i < N; i++) if (abs(mp[k][i]) == 2) cnt2++;
			if (mx < cnt2) mx = cnt2, mv = { startp[k + 1], endp[k + 1] };
		}
		else {
			int fcnt = 0;
			int ecnt = 0;
			for (i = 0; i < em; i++) if (abs(mp[k][i]) == 2) fcnt++;
			for (i = fm + 1; i < N; i++) if (abs(mp[k][i]) == 2) ecnt++;
			if (mx < fcnt) mx = fcnt, mv = { startp[k + 1], endp[k + 1] - (N - 1 - em) - 1 };
			if (mx < ecnt) mx = ecnt, mv = { startp[k + 1] + 1 + fm, endp[k + 1] };
		}
	}
	if (!mx) {
		cout << 0 << bb << N << ln;
		return;
	}
	cout << mv.first << bb << N - 1 - mv.second << ln;
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