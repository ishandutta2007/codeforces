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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

int h,w;


void solve() {
	cin >> h >> w;
	vector<string> mp(h);
	rep(i, h) {
		cin >> mp[i];
	}
	vector<vector<bool>>cans(h);
	vector<vector<bool>>cang(h);
	rep(i, h) {
		cans[i].resize(w, false);
		cang[i].resize(w, false);
	}
	cans[0][0] = true;
	rep(i, h) {
		rep(j, w) {
			if (!cans[i][j])continue;
			if (j + 1 < w&&mp[i][j+1]=='.') {
				cans[i][j + 1] = true;
			}
			if (i + 1 < h&&mp[i + 1][j] == '.') {
				cans[i + 1][j] = true;
			}
		}
	}
	if (!cans[h - 1][w - 1]) {
		cout << 0 << endl; return;
	}
	cang[h - 1][w - 1] = true;
	per(i, h) {
		per(j, w) {
			if (!cang[i][j])continue;
			if (i - 1 >= 0 && mp[i - 1][j] == '.') {
				cang[i - 1][j] = true;
			}
			if (j - 1 >= 0 && mp[i][j - 1] == '.') {
				cang[i][j - 1] = true;
			}
		}
	}
	Rep1(i,1, h + w-3) {
		int x = i, y = 0;
		if (x > h-1) {
			int dif = x - (h - 1);
			x -= dif;
			y += dif;
		}
		int cnt = 0;
		while (x>=0&&y < w) {
			if (cans[x][y] && cang[x][y])cnt++;
			x--; y++;
		}
		if (cnt == 1) {
			cout << 1 << endl; return;
		}
	}
	cout << 2 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}