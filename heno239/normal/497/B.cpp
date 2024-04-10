#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int rc[1<<17][2];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		rc[i + 1][0] = rc[i][0];
		rc[i + 1][1] = rc[i][1];
		if (a[i] == 1)rc[i + 1][0]++;
		else rc[i + 1][1]++;
	}
	vector<int> v[2];
	rep(i, 2) {
		v[i].resize(n + 1);
		rep(j, n + 1) {
			v[i][j] = rc[j][i];
		}
	}
	vector<P> ans;
	for (int t = 1; t <= n; t++) {
		int loc = 0;
		int c[2] = { 0,0 };
		int m[2] = { 0,0 };
		bool valid = true;
		while (true) {
			int le = lower_bound(v[0].begin(), v[0].end(), v[0][loc] + t) - v[0].begin();
			int ri = lower_bound(v[1].begin(), v[1].end(), v[1][loc] + t) - v[1].begin();
			int mi = min(le,ri);
			if (mi == n+1) {
				valid = false; break;
			}
			if (le == mi) {
				m[0]++; loc =le;
			}
			else {
				m[1]++; loc = ri;
			}
			if (loc == n)break;
		}
		if (m[0] == m[1])valid = false;
		if (m[0] > m[1]) {
			if (a[n - 1] == 2)valid = false;
		}
		if (m[1] > m[0]) {
			if (a[n - 1] == 1)valid = false;
		}
		if (valid) {
			ans.push_back({ max(m[0],m[1]),t });
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}