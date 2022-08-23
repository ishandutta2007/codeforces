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

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> v(n);
	rep(i, n) {
		v[i].resize(k);
		rep(j, k) {
			cin >> v[i][j];
		}
	}
	rep(i, k) {
		int cnt = 0;
		rep(j, n) {
			if (!v[j][i])cnt++;
		}
		if (cnt == 0) {
			cout << "NO" << endl; return;
		}
	}
	if (k == 1||k==2) {
		cout << "YES" << endl; return;
	}
	else if (k == 3) {
		rep(i, n) {
			int cnt = 0;
			rep(j, 3) {
				if (!v[i][j])cnt++;
			}
			if (cnt >= 2) {
				cout << "YES" << endl; return;
			}
		}
		cout << "NO" << endl;
	}
	else if (k == 4) {
		bool exi[16] = {};
		rep(i, n) {
			int cnt = 0;
			rep(j, 4) {
				if (!v[i][j])cnt++;
			}
			if (cnt >= 3) {
				cout << "YES" << endl; return;
			}
			if (cnt == 2) {
				int s = 0;
				rep(j, 4) {
					if (!v[i][j])s += (1 << j);
				}
				exi[s] = true;
			}
		}
		rep(i, 16) {
			if (exi[i] && exi[15 - i]) {
				cout << "YES" << endl; return;
			}
		}
		cout << "NO" << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	solve();
	//stop
	return 0;
}