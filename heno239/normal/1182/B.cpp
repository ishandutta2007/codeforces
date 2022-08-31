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

char mp[500][500];
bool yes[500][500];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void solve() {
	int w, h; cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> mp[i][j];
		}
	}
	vector<int> ch(h,0), cw(w,0);
	rep(i, h) {
		rep(j, w) {
			if (mp[i][j] == '*') {
				ch[i]++; cw[j]++;
			}
		}
	}
	vector<int> x;
	rep(i, ch.size()) {
		if (ch[i] > 2)x.push_back(i);
	}
	vector<int> y;
	rep(i, cw.size()) {
		if (cw[i] > 2)y.push_back(i);
	}
	if (x.size() != 1 || y.size() != 1) {
		cout << "NO" << endl; return;
	}
	int cx = x[0], cy = y[0];
	if (mp[cx][cy] != '*') {
		cout << "NO" << endl; return;
	}
	yes[cx][cy] = true;
	rep(j, 4) {
		int cnt = 0;
		int curx = cx, cury = cy;
		while (true) {
			int nx = curx + dx[j], ny = cury + dy[j];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)break;
			if (mp[nx][ny] == '.')break;
			cnt++;
			curx = nx, cury = ny;
			yes[curx][cury] = true;
		}
		if (cnt == 0) {
			cout << "NO" << endl; return;
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (!yes[i][j] && mp[i][j] == '*') {
				cout << "NO" << endl; return;
			}
		}
	}
	cout << "YES" << endl;
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