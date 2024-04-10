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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int cnt[500][500][4];
int calc(int lx, int ly, int rx, int ry, int k) {
	int res = cnt[rx][ry][k];
	if (lx > 0)res -= cnt[lx - 1][ry][k];
	if (ly > 0)res -= cnt[rx][ly - 1][k];
	if (lx > 0 && ly > 0)res += cnt[lx - 1][ly - 1][k];
	return res;
}
char mp[500][500];
int exicnt[251][500][500];
int calc2(int lx, int ly, int rx, int ry, int k) {
	int res = exicnt[k][rx][ry];
	if (lx > 0)res -= exicnt[k][lx - 1][ry];
	if (ly > 0)res -= exicnt[k][rx][ly - 1];
	if (lx > 0 && ly > 0)res += exicnt[k][lx - 1][ly - 1];
	return res;
}

string col = "RGYB";
void solve() {
	int h, w,q; cin >> h >> w>>q;
	rep(i, h)rep(j, w) {
		cin >> mp[i][j];
	}
	rep(i, h)rep(j, w) {
		int id = 0;
		rep(k, 4)if (col[k] == mp[i][j])id = k;
		cnt[i][j][id]++;
		rep(k, 4) {
			if (i > 0)cnt[i][j][k] += cnt[i - 1][j][k];
			if (j > 0)cnt[i][j][k] += cnt[i][j - 1][k];
			if (i > 0 && j > 0)cnt[i][j][k] -= cnt[i - 1][j - 1][k];
		}
	}
	//cout << calc(1, 2, 1, 2, 1) << endl;
	rep(i, h)rep(j, w) {
		int ok = 0;
		for (int sz = 1; sz <= 500; sz++) {
			if (i + 2 * sz > h || j + 2 * sz > w)break;
			if (calc(i, j, i + sz - 1, j + sz - 1, 0) != sz * sz)continue;
			if (calc(i, j+sz, i + sz - 1, j + 2*sz - 1, 1) != sz * sz)continue;
			if (calc(i+sz, j, i + 2*sz - 1, j + sz - 1, 2) != sz * sz)continue;
			if (calc(i + sz, j+sz , i + 2*sz - 1, j + 2*sz - 1, 3) != sz * sz)continue;
			ok = sz; break;
		}
		//cout << i << " " << j << " " << ok << endl;
		exicnt[ok][i][j] = 1;
	}
	/*per(sz, 251) {
		rep1(i, h-1)rep1(j, w-1) {
			exicnt[sz][i][j] += exicnt[sz + 1][i - 1][j - 1];
		}
	}*/
	rep(sz, 251) {
		rep(i, h)rep(j, w) {
			if (i > 0)exicnt[sz][i][j] += exicnt[sz][i - 1][j];
			if (j > 0)exicnt[sz][i][j] += exicnt[sz][i][j - 1];
			if (i > 0 && j > 0)exicnt[sz][i][j] -= exicnt[sz][i - 1][j - 1];
		}
	}
	rep(aa, q) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		lx--; ly--; rx--; ry--;
		int le = 0, ri = 251;
		while (ri - le > 1) {
			int mid = (le+ri) / 2;
			int lex = lx, ley = ly;
			int rix = rx - (2 * mid - 1);
			int riy = ry - (2 * mid - 1);
			if (lex > rix || ley > riy) {
				ri = mid; continue;
			}
			int c = calc2(lex, ley, rix, riy, mid);
			if (c > 0)le = mid;
			else ri = mid;
		}
		cout << 4*le * le << endl;
	}
	
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}