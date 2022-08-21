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
const ll mod = 1000000087;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

int num[40][40];
int calc(int lx, int ly, int rx, int ry) {
	int res = num[rx][ry];
	if (lx > 0)res -= num[lx - 1][ry];
	if (ly > 0)res -= num[rx][ly - 1];
	if (lx > 0 && ly > 0)res += num[lx - 1][ly - 1];
	return res;
}
//fix leftup
int cnt[40][40][40][40];
bool isok[40][40][40][40];

int ans[40][40][40][40];

void solve() {
	int h, w, q; cin >> h >> w >> q;
	rep(i, h) {
		string s; cin >> s;
		rep(j, w) {
			if (s[j] == '1')num[i][j]++;
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (i > 0)num[i][j] += num[i - 1][j];
			if (j > 0)num[i][j] += num[i][j - 1];
			if (i > 0 && j > 0)num[i][j] -= num[i - 1][j - 1];
		}
	}
	rep(i, h) {
		rep(j, w) {
			Rep(k, i, h) {
				Rep(l, j, w) {
					isok[i][j][k][l] = (calc(i, j, k, l) == 0);
					if (isok[i][j][k][l]) {
						cnt[i][j][k][l]++;
					}
					if (k > i)cnt[i][j][k][l] += cnt[i][j][k - 1][l];
					if (l > j)cnt[i][j][k][l] += cnt[i][j][k][l - 1];
					if (k > i&&l > j)cnt[i][j][k][l] -= cnt[i][j][k - 1][l - 1];
				}
			}
		}
	}
	per(k, h) {
		per(l, w) {
			per(i, k + 1) {
				per(j, l + 1) {
					ans[i][j][k][l] += cnt[i][j][k][l];
					if (i < k)ans[i][j][k][l] += ans[i+1][j][k][l];
					if (j < l)ans[i][j][k][l] += ans[i][j + 1][k][l];
					if (i < k&&j < l)ans[i][j][k][l] -= ans[i + 1][j + 1][k][l];
				}
			}
		}
	}
	rep(i, q) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		cout << ans[a][b][c][d] << endl;
	}
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