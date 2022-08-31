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
const ll mod = 998244353;
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

void Z_algorithm(const string &s, vector<int> &a) {
	int sz = s.size();
	//a.clear();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz&&s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz&&k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

void solve() {
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	string ans = s[0];
	vector<int> ra;
	rep1(i, n - 1) {
		int len = s[i].length();
		string t = s[i];
		if (s[i].length() > ans.length()) {
			t += ans;
		}
		else {
			for (int j = ans.size() - t.size(); j < ans.size(); j++) {
				t.push_back(ans[j]);
			}
		}
		Z_algorithm(t, ra);
		int alllen = t.size(); int ma = 0;
		for (int j = len; j < alllen; j++) {
			if (j + ra[j] == alllen) {
				ma = ra[j]; break;
			}
		}
		for (int j = ma; j < len; j++) {
			ans.push_back(s[i][j]);
		}
	}
	cout << ans << endl;
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