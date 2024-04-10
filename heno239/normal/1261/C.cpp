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
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

vector<vector<int>> sum;
int calc(int lx, int ly, int rx, int ry) {
	int res = sum[rx][ry];
	if (lx > 0)res -= sum[lx - 1][ry];
	if (ly > 0)res -= sum[rx][ly - 1];
	if (lx > 0 && ly > 0)res += sum[lx - 1][ly - 1];
	return res;
}
void solve() {
	int h, w; cin >> h >> w;
	vector<string> mp(h);
	sum.resize(h);
	rep(i, h) {
		sum[i].resize(w);
		cin >> mp[i];
		rep(j, w) {
			if (mp[i][j] == 'X')sum[i][j]++;
			if (i > 0)sum[i][j] += sum[i - 1][j];
			if (j > 0)sum[i][j] += sum[i][j - 1];
			if (i > 0 && j > 0)sum[i][j] -= sum[i - 1][j - 1];
		}
	}
	vector<vector<int>> cnt(h + 1);
	rep(i, h + 1) {
		cnt[i].resize(w + 1);
	}
	int le = 0, ri = 1000001;
	while (ri - le > 1) {
		int x = (le + ri) / 2;
		rep(i, h + 1)fill(cnt[i].begin(), cnt[i].end(), 0);
		rep(i, h)rep(j, w) {
			int lx = i, ly = j;
			int rx = i + 2 * x, ry = j + 2 * x;
			if (rx >= h || ry >= w)continue;
			if (calc(lx, ly, rx, ry) == (rx - lx + 1)*(ry - ly + 1)) {
				cnt[i][j]++;
				cnt[i][j + 2 * x+1]--;
				cnt[i + 2 * x + 1][j]--;
				cnt[i + 2 * x + 1][j + 2 * x + 1]++;
			}
		}
		rep(i, h)rep(j, w) {
			cnt[i][j + 1] += cnt[i][j];
		}
		rep(j, w)rep(i, h) {
			cnt[i + 1][j] += cnt[i][j];
		}
		bool valid = true;
		rep(i, h)rep(j, w) {
			if (mp[i][j] == 'X'&&cnt[i][j] == 0) {
				valid = false; break;
			}
		}
		if (valid) {
			le = x;
		}
		else {
			ri = x;
		}
	}
	vector<string> ans(h);
	rep(i, h) {
		ans[i].resize(w, '.');
	}
	int x = le;
	rep(i, h)rep(j, w) {
		int lx = i, ly = j;
		int rx = i + 2 * x, ry = j + 2 * x;
		if (rx >= h || ry >= w)continue;
		if (calc(lx, ly, rx, ry) == (rx - lx + 1)*(ry - ly + 1)) {
			ans[i + x][j + x] = 'X';
		}
	}
	cout << x << "\n";
	rep(i, h)cout << ans[i] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}