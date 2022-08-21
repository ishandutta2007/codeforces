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

int n, k;
int mp[2000][2000];
int ans[2002][2002];
void solve() {
	cin >> n >> k;
	rep(i, n) {
		string s; cin >> s;
		rep(j, n) {
			if (s[j] == 'B')mp[i][j] = 1;
			else mp[i][j] = 0;
		}
	}
	rep(i, n) {
		vector<int> v;
		rep(j, n) {
			if (mp[i][j])v.push_back(j);
		}
		if (v.empty()) {
			ans[0][0]++;
			ans[n][0]--;
			ans[0][n]--;
			ans[n][n]++;
		}
		else {
			int le = v[0], ri = v.back();
			if (ri - le + 1 > k)continue;
			int dif = k - (ri - le + 1);
			int l = max(0, le - dif);
			int r = le;
			int lid = i - k + 1; if (lid < 0)lid = 0;
			ans[lid][l]++;
			ans[i + 1][l]--;
			ans[lid][r + 1]--;
			ans[i + 1][r + 1]++;
		}
	}
	rep(i, n) {
		vector<int> v;
		rep(j, n) {
			if (mp[j][i])v.push_back(j);
		}
		if (v.empty()) {
			ans[0][0]++;
			ans[n][0]--;
			ans[0][n]--;
			ans[n][n]++;
		}
		else {
			int le = v[0], ri = v.back();
			if (ri - le + 1 > k)continue;
			int dif = k - (ri - le + 1);
			int l = max(0, le - dif);
			int r = le;
			int lid = i - k + 1; if (lid < 0)lid = 0;
			ans[l][lid]++;
			ans[l][i+1]--;
			ans[r + 1][lid]--;
			ans[r + 1][i+1]++;
		}
	}
	rep(i, n) {
		rep(j,n) {
			ans[i][j + 1] += ans[i][j];
		}
	}
	rep(i, n) {
		rep(j, n) {
			ans[j + 1][i] += ans[j][i];
		}
	}
	int ma = 0;
	rep(i, n) {
		rep(j, n) {
			ma = max(ma, ans[i][j]);
		}
	}
	cout << ma << endl;
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