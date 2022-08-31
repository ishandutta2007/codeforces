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
const ll mod = 998244353;
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
	int n; cin >> n;
	vector<int> a(n);
	vector<P> b;
	rep(i, n) {
		cin >> a[i];
		b.push_back({ a[i],i });
	}
	sort(b.begin(), b.end(),greater<P>());
	vector<vector<bool>> ans(n+1);
	rep(i, n+1) {
		ans[i].resize(n);
	}
	rep(i, n) {
		int rest = n- i;

		int tmp = 0;
		per(j, rest) {
			ans[j][i] = true; tmp++;
			if (tmp == b[i].first)break;
		}
		if (tmp <b[i].first) {
			rep(j, b[i].first-tmp) {
				ans[rest + 1+j][i] = true;
			}
		}
	}
	vector<vector<char>> tans(n + 1);
	rep(i, n + 1)tans[i].resize(n);
	rep(j, n) {
		int id = b[j].second;
		rep(i, n + 1) {
			if (ans[i][j]) {
				tans[i][id] = '1';
			}
			else {
				tans[i][id] = '0';
			}
		}
	}
	/*rep(i, tans.size()) {
		rep(j, n)cout << tans[i][j];
		cout << endl;
	}*/
	vector<string> zans;
	rep(i, n + 1) {
		int cnt = 0;
		rep(j, n) {
			if (tans[i][j] == '1')cnt++;
		}
		if (cnt > 0) {
			string nex;
			rep(j, n)nex.push_back(tans[i][j]);
			zans.push_back(nex);
		}
	}
	cout << zans.size() << endl;
	rep(i, zans.size()) {
		cout << zans[i] << endl;
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