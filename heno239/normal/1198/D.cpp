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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

char mp[50][50];

int num[50][50];
int calc(int lx, int ly, int rx, int ry) {
	int ret = num[rx][ry];
	if (lx - 1 >= 0) {
		ret -= num[lx - 1][ry];
	}
	if (ly - 1 >= 0) {
		ret -= num[rx][ly - 1];
	}
	if (lx - 1 >= 0 && ly - 1 >= 0) {
		ret += num[lx - 1][ly - 1];
	}
	return ret;
}

bool used[50][50][50][50];
int ans[50][50][50][50];

int dfs(int lx,int ly,int rx,int ry) {
	if (used[lx][ly][rx][ry])return ans[lx][ly][rx][ry];
	used[lx][ly][rx][ry] = true;
	if (calc(lx, ly, rx, ry) == 0) {
		//cout << "!!" << endl;
		//cout << lx << " " << ly << " " << rx << " " << ry << endl;
		return ans[lx][ly][rx][ry] = 0;
	}
	int ret = max(rx - lx + 1, ry - ly + 1);
	//cout << lx << " " << ly << " " << rx << " " << ry << " " << ret << endl;
	for (int i = lx; i < rx; i++) {
		/*if (lx == 0 & ly == 0 && rx == 3 && ly == 0) {
			cout << i<<" ? "<<dfs(lx, ly, i, ry) << " " << dfs(i + 1, ly, rx, ry) << endl;
		}*/
		ret = min(ret, dfs(lx, ly, i, ry) + dfs(i+1, ly, rx, ry));
	}
	for (int i = ly; i < ry; i++) {
		ret = min(ret, dfs(lx, ly, rx, i) + dfs(lx, i + 1, rx, ry));
	}
	//cout << lx << " " << ly << " " << rx << " " << ry << " " << ret << endl;
	return ans[lx][ly][rx][ry] = ret;
}
void solve() {
	int n; cin >> n;

	rep(i, n) {
		rep(j, n) {
			cin >> mp[i][j];
		}
	}
	num[0][0] = 0;
	rep(i, n) {
		rep(j, n) {
			num[i][j] = 0;
			if (mp[i][j] == '#')num[i][j] = 1;
			if (i > 0)num[i][j] += num[i - 1][j];
			if (j > 0)num[i][j] += num[i][j - 1];
			if (i > 0 && j > 0)num[i][j] -= num[i - 1][j - 1];
			//cout << num[i][j];
		}
		//cout << endl;
	}
	cout << dfs(0, 0, n - 1, n - 1) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}