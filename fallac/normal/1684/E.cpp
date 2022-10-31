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

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<int> v;
vector<int> uniq;
int N, K;

int chk(int x) {
	int rk = K;
	int i;
	int cnt = 0;
	for (i = 0; i < uniq.size(); i++) if (uniq[i] < x) cnt++;
	if (x - cnt > K) return -1;
	vector<int> cpy = v;
	while (cpy.back() >= x && K > 0) cpy.pop_back(), K--;
	int ans = 0;
	vector<int> vv;
	for (i = 0; i < cpy.size(); i++) if (cpy[i] >= x) vv.push_back(cpy[i]);
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	ans = vv.size();

	K = rk;
	return ans;
}

void solve() {
	v.clear();
	uniq.clear();
	cin >> N >> K;
	int i;
	int x;
	for (i = 1; i <= N; i++) {
		cin >> x;
		v.push_back(x);
	}
	if (K >= N) {
		cout << 0 << ln;
		return;
	}
	sort(v.begin(), v.end());
	uniq = v;
	uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
	int l, r;
	l = 0;
	r = N + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int res = chk(mid);
		if (res == -1) r = mid;
		else l = mid;
	}
	int mex = l;
	vector<pii> vp;
	for (i = 0; i < N; i++) {
		if (v[i] < mex) continue;
		if (vp.empty() || vp.back().second != v[i]) vp.emplace_back(1, v[i]);
		else vp.back().first++;
	}
	sort(vp.begin(), vp.end());
	reverse(vp.begin(), vp.end());
	while (vp.size()) {
		if (K >= vp.back().first) {
			K -= vp.back().first;
			vp.pop_back();
		}
		else break;
	}
	cout << vp.size() << ln;
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