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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
LP dis[300][300];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int cdx[4] = { 1,1,-1,-1 };
int cdy[4] = { 1,-1,-1,1 };
//1,2,3
void init(int n) {
	rep(i, 3*n*n) {
		rep(j, 3*n*n) {
			if (i != j) {
				dis[i][j] = { mod,mod };
			}
		}
	}
	rep(i, 3*n*n) {
		int d = i % (n*n);
		rep(j, 3) {
			int nx = j * n*n + d;
			dis[i][nx] = { 1,1 };
		}
	}
	rep(i, n*n) {
		int x = i / n;
		int y = i % n;
		rep(k, 8) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			dis[i][nx * n + ny] = { 1,0 };
		}
	}
	rep(i, n*n) {
		int fr = i + n*n;
		int x = i / n; int y = i % n;
		rep(k, 4) {
			int nx = x + cdx[k]; int ny = y + cdy[k];
			while (true) {
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)break;
				dis[fr][nx*n + ny + n * n] = { 1,0 };
				nx += cdx[k]; ny += cdy[k];
			}
		}
	}
	rep(i, n*n) {
		int fr = i + 2 * n*n;
		int x = i / n; int y = i % n;
		rep(k, n) {
			dis[fr][n*x + 2 * n*n + k] = { 1,0 };
			dis[fr][y + 2 * n*n + n * k] = { 1,0 };
		}
	}
	rep(k, 3*n*n) {
		rep(i, 3 * n*n) {
			rep(j, 3 * n*n) {
				LP kk = { dis[i][k].first + dis[k][j].first,dis[i][k].second + dis[k][j].second };
				dis[i][j] = min(dis[i][j],kk);
			}
		}
	}
}
LP dp[3]; int n;
void debag() {
	cout << "aaa" << endl;
	rep(i, 3 * n*n) {
		rep(j, 3 * n*n) {
			int cf = i / (n*n); int ct = j / (n*n);
			int ni = i % (n*n); int nj = j % (n*n);
			int xf = ni / n; int yf = ni % n;
			int xt = nj / n; int yt = nj % n;
			cout << cf << " " << xf << " " << yf << endl;
			cout << ct << " " << xt << " " << yt << endl;
			cout << dis[i][j].first << " " << dis[i][j].second << endl;
		}
	}
}
int main() {
	cin >> n; init(n);
	vector<P> v;
	rep(i, n) {
		rep(j, n) {
			int a; cin >> a;
			v.push_back({ a,i*n + j });
		}
	}
	sort(v.begin(), v.end());
	rep(j, 3) {
		dp[j] = { 0,0 };
	}
	rep(i, n*n-1) {
		LP nex[3]; rep(j, 3)nex[j] = { mod,mod };
		rep(j, 3) {
			rep(k, 3) {
				int fr = v[i].second + j * n*n;
				int to = v[i + 1].second + k * n*n;
				LP kk = { dp[j].first + dis[fr][to].first,dp[j].second + dis[fr][to].second };
				nex[k] = min(nex[k], kk);
			}
		}
		rep(j, 3) {
			dp[j] = nex[j];
		}
	}
	LP mi = { mod,mod };
	rep(i, 3) {
		mi = min(mi, dp[i]);
	}
	cout << mi.first << " " << mi.second << endl;
	
	return 0;
}