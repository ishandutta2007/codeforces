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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void out(vector<vector<int>> &v,bool b) {
	cout << "YES" << endl;
	if (!b) {
		int n = v.size(), m = v[0].size();
		vector<int> trans(n*m + 1);
		rep(i, n)rep(j, m) {
			trans[j*n + i + 1] = i * m + 1 + j;
		}
		rep(i, v.size()) {
			rep(j, v[i].size()) {
				if (j > 0)cout << " ";
				cout << trans[v[i][j]];
			}
			cout << endl;
		}
	}
	else {
		
		rep(i, v[0].size()) {
			rep(j, v.size()) {
				if (j > 0)cout << " ";
				cout << v[j][i];
			}
			cout << endl;
		}
	}
}

void solve() {
	int n, m; cin >> n >> m;
	bool b = false;
	if (n < m) {
		b = true; swap(n, m);
	}
	vector<vector<int>> ans(n);
	rep(i, n) {
		ans[i].resize(m);
	}
	if (n == 1 && m == 1) {
		ans[0][0] = 1;
		out(ans,b); return;
	}
	else if (n == 2 && m == 1) {
		cout << "NO" << endl; return;
	}
	else if (n == 2 && m == 2) {
		cout << "NO" << endl; return;
	}
	else if (n == 3 && m == 1) {
		cout << "NO" << endl; return;
	}
	else if (n == 3 && m == 2) {
		cout << "NO" << endl; return;
	}
	else if (n == 3 && m == 3) {
		ans = { {2,7,6},{9,5,1},{4,3,8} };
		out(ans, b); return;
	}
	else if (n == 4) {
		vector<int> ids = { 3,1,4,2 };
		rep(j, m) {
			if (j % 2 == 0) {
				rep(i, n) {
					ans[i][j] = ids[i] + n * j;
				}
			}
			else {
				rep(i, n) {
					ans[i][j] = ids[n - 1 - i] + n * j;
				}
			}
		}
		out(ans, b); return;
	}
	else {
		vector<int> ids,ids2;
		for (int i = n-1; i >= 1; i -= 2) {
			ids.push_back(i);
		}
		for (int i = n; i >= 1; i -= 2) {
			ids.push_back(i);
			ids2.push_back(i);
		}
		for (int i = n - 1; i >= 1; i -= 2) {
			ids2.push_back(i);
		}
		rep(j, m) {
			if (j % 2 == 0) {
				rep(i, n) {
					ans[i][j] = ids[i] + n * j;
				}
			}
			else {
				rep(i, n) {
					ans[i][j] = ids2[i] + n * j;
				}
			}
		}
		out(ans, b); return;
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