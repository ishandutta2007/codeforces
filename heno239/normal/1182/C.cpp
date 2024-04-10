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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;

string s = "aiueo";
int trans(char t) {
	rep(i, 5)if (t == s[i])return i;
	return -1;
}
P c(string &str) {
	int ret = 0;
	int chk = 5;
	rep(i, str.size()) {
		int z = trans(str[i]);
		if (z >= 0) {
			ret++; chk = z;
		}
	}
	return { ret,chk };
}
void solve() {
	int n; cin >> n;
	vector<string> v(n);
	vector<pair<int, string>> u[6];
	rep(i, n) {
		cin >> v[i];
		P  p = c(v[i]);
		u[p.second].push_back({ p.first,v[i] });
	}
	rep(i, 6) {
		sort(u[i].begin(), u[i].end());
	}
	vector<pair<int, string>> r;
	vector<pair<string, string>> las,pre;
	rep(i, 5) {
		rep(j, u[i].size()) {
			if (j + 1 < (int)u[i].size() && u[i][j].first == u[i][j + 1].first) {
				las.push_back({ u[i][j].second,u[i][j + 1].second });
				j++;
			}
			else {
				r.push_back(u[i][j]);
			}
		}
	}
	rep(j, u[5].size())r.push_back(u[5][j]);
	sort(r.begin(), r.end());
	rep(i, r.size()) {
		if (i + 1 < (int)r.size() && r[i].first == r[i + 1].first) {
			pre.push_back({ r[i].second,r[i + 1].second });
			i++;
		}
	}
	vector<pair<string, string>> ans;
	while (pre.size() < las.size()) {
		pre.push_back(las.back());
		las.pop_back();
	}
	rep(i, min(pre.size(), las.size())) {
		ans.push_back({ pre[i].first,las[i].first });
		ans.push_back({ pre[i].second,las[i].second });
	}
	cout << ans.size() / 2 << endl;
	rep(i, ans.size()) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(11);
	/*while (cin >> n, n) {
		solve();
	}*/
	solve();
	//stop
	return 0;
}