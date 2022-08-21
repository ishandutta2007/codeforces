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
	int n, t, a, b; cin >> n >> t >> a >> b;
	vector<int> e(n);
	rep(i, n)cin >> e[i];
	vector<int> x(n);
	vector<P> v;
	rep(i, n) {
		cin >> x[i];
		v.push_back({ x[i],i });
	}
	sort(v.begin(), v.end());
	ll rest[2] = { 0,0 };
	rep(i, n) {
		if (e[i])rest[1]++;
		else rest[0]++;
	}
	int ans = 0;
	ll cost = 0; int num = 0;
	rep(i, n) {
		ll sx = v[i].first - 1;
		ll dif = sx - cost;
		if (dif >= 0) {
			if (rest[0] * a <= dif) {
				int res = num + rest[0];
				res += min(rest[1], (dif - rest[0] * a) / b);
				ans = max(ans, res);
			}
			else {
				int res = num + dif / a;
				ans = max(ans, res);
			}
		}
		int le = i;
		while (i + 1 < n&&v[i].first == v[i + 1].first) {
			i++;
		}
		for (int j = le; j <= i; j++) {
			num++;
			int id = v[j].second;
			if (e[id]) {
				cost += b;
				rest[1]--;
			}
			else {
				cost += a;
				rest[0]--;
			}
		}
	}
	ll sx = t;
	ll dif = sx - cost;
	if (dif >= 0) {
		if (rest[0] * a <= dif) {
			int res = num + rest[0];
			res += min(rest[1], (dif - rest[0] * a) / b);
			ans = max(ans, res);
		}
		else {
			int res = num + dif / a;
			ans = max(ans, res);
		}
	}
	//cout << "ans is ";
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//stop
		return 0;
}