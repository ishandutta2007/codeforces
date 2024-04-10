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
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int needx[100], needy[100];
int x[100][100];
int y[100][100];
int main() {
	int n, m; cin >> n >> m;
	int mi = 1000; P chk;
	rep(i, n) {
		rep(j, m) {
			cin >> x[i][j];
			if (x[i][j] < mi) {
				mi = x[i][j]; chk = { i,j };
			}
		}
	}
	int sum = mi*min(n,m);
	rep(i, m) {
		needy[i] += x[chk.first][i] - mi;
		sum += needy[i];
	}
	rep(i, n) {
		needx[i] += x[i][chk.second] - mi;
		sum += needx[i];
	}
	if (n < m) {
		rep(i, n) {
			needx[i] += mi;
		}
	}
	else {
		rep(i, m) {
			needy[i] += mi;
		}
	}
	rep(i, n) {
		rep(j, m) {
			y[i][j] += needx[i];
		}
	}
	rep(i, m) {
		rep(j, n) {
			y[j][i] += needy[i];
		}
	}
	bool same = true;
	rep(i, n) {
		rep(j, m) {
			if (x[i][j] != y[i][j])same = false;
		}
	}
	if (!same)cout << -1 << endl;
	else {
		cout << sum << endl;
		rep(i, n) {
			rep(j, needx[i]) {
				cout << "row " << i + 1 << endl;
			}
		}
		rep(i, m) {
			rep(j, needy[i]) {
				cout << "col " << i + 1 << endl;
			}
		}
	}
	return 0;
}