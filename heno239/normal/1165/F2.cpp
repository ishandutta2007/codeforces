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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

int n, m;
vector<int> loc[1 << 18];
void solve() {
	cin >> n >> m;
	vector<int> k(n);
	int sum = 0;
	rep(i, n) {
		cin >> k[i]; sum += k[i];
	}
	rep(i, m) {
		int d, t; cin >> d >> t; t--;
		loc[t].push_back(d);
	}
	rep(i, n) {
		sort(loc[i].begin(), loc[i].end());
		loc[i].erase(unique(loc[i].begin(), loc[i].end()), loc[i].end());
	}
	int le = 0, ri = (1 << 19);
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		vector<P> v;
		rep(i, n) {
			int id = upper_bound(loc[i].begin(), loc[i].end(), mid) - loc[i].begin();
			if (id > 0) {
				v.push_back({ loc[i][id - 1],i });
			}
		}
		sort(v.begin(), v.end());
		int cur = 0; int rest = 0;
		rep(i, v.size()) {
			rest += v[i].first - cur; cur = v[i].first;
			int mi = min(rest, k[v[i].second]);
			rest -= mi;
		}
		rest += mid - cur;
		if (rest / 2 + mid - rest >= sum) {
			ri = mid;
		}
		else {
			le = mid;
		}
	}
	cout << ri << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}