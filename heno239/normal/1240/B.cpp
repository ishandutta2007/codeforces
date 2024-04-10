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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> x;
	rep(i, n) {
		cin >> a[i]; x.push_back(a[i]);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()),x.end());
	vector<int> trans(n + 1);
	rep(i, x.size())trans[x[i]] = i;
	vector<int> le(x.size(),mod), ri(x.size(),-mod);
	vector<int> num(x.size(),1);
	rep(i, n) {
		int id = trans[a[i]];
		le[id] = min(le[id], i);
		ri[id] = max(ri[id], i);
	}
	int ma = 0;
	rep(i, x.size()) {
		if (i + 1 < x.size()) {
			if (ri[i] < le[i + 1]) {
				num[i + 1] = num[i] + 1;
			}
		}
		ma = max(ma, num[i]);
	}
	cout << x.size() - ma << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	int q; cin >> q;
	rep(i, q) {
		solve();
	}

	//cout << "finish" << endl;
	//stop
		return 0;
}