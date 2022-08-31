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
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<P> v;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&a[i] == a[i + 1])i++;
		int cnt = i - le + 1;
		v.push_back({ cnt,a[i] });
	}
	sort(v.begin(), v.end(), greater<P>());
	int sup = v[0].first;
 
	vector<int> rv(v.size() + 1);
	rep(i, v.size()) {
		rv[i + 1] = rv[i] + v[i].first;
	}
	int loc = 0;
 
	int ma = 0; int chk, chk2;
	for (ll h = n; h >= 1; h--) {
		while (loc<v.size() && v[loc].first>h) {
			loc++;
		}
		int sum = loc * h + n - rv[loc];
		if (h*h > sum)continue;
		ll num = h * (sum / h);
		if (ma < num) {
			chk = h;
			chk2 = sum / h;
			ma = num;
		}
	}
	int h = chk;
	int w = chk2;
	a.clear();
	rep(i, v.size()) {
		v[i].first = min(v[i].first, h);
		rep(j, v[i].first) {
			a.push_back(v[i].second);
		}
	}
	vector<vector<int>> ans(h);
	rep(i, h) {
		ans[i].resize(w);
	}
	int tmp = 0;
	rep(j, w) {
		rep(i, h) {
			int val = a[tmp]; tmp++;
			int x = i;
			int y = (i + j) % w;
			ans[x][y] = val;
		}
	}
	cout << h * w << endl;
	cout << h << " " << w << endl;
	rep(i, h) {
		rep(j, w) {
			if (j > 0)cout << " ";
			cout << ans[i][j];
		}
		cout << "\n";
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