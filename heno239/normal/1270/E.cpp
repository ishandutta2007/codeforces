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
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<int> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}

void solve() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	int c1 = 0, c2 = 0;
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	rep1(i, n - 1) {
		x[i] -= x[0];
		y[i] -= y[0];
		x[i] = abs(x[i]);
		y[i] = abs(y[i]);
	}
	x[0] = 0, y[0] = 0;
	while (true) {
		bool exi = false;
		rep(i, n) {
			if (x[i] % 2 || y[i] % 2)exi = true;
		}
		if (!exi) {
			rep(i, n) {
				x[i] /= 2, y[i] /= 2;
			}
		}
		else break;
	}
	bool exi = false;
	rep(i, n) {
		if (x[i] % 2 != y[i] % 2) {
			exi = true;
		}
	}
	vector<int> ans;
	if (exi) {
		rep(i, n) {
			if (x[i] % 2 == y[i] % 2)ans.push_back(i+1);
		}
		cout << ans.size() << endl; debug(ans);
	}
	else {
		rep(i, n) {
			if (x[i] % 2 == 0 && y[i] % 2 == 0)ans.push_back(i+1);
		}
		cout << ans.size() << endl; debug(ans);
	}

}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}