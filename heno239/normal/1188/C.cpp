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
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

ll rdp[1001][1001];
void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> d;
	rep(i, n) {
		Rep(j, i + 1, n) {
			d.push_back(a[j] - a[i]);
		}
	}
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	vector<ll> num;
	rep(i, d.size()) {
		int dif = d[i];
		int z = 1; int cur = a[0];
		int loc = 0; int id = 1;
		bool valid = true;
		rep(j, k - 1) {
			while (id < n&&a[id] - a[loc] < dif)id++;
			if (id == n) {
				valid = false; break;
			}
			loc = id;
		}
		if (!valid)break;
		vector<int> pre(n);
		int le = 0;
		rep(j, n) {
			while (le<n&&a[j] - a[le] >= dif)le++;
			pre[j] = le;
		}
		rep(j, n + 1) {
			rep(l, k + 1) {
				rdp[j][l] = 0;
			}
		}
		rep(j, n + 1) {
			rdp[j][1] = j;
		}

		rep(j, n) {
			Rep1(l, 2, k) {
				rdp[j + 1][l] = rdp[j][l] + rdp[pre[j]][l - 1];
				if (rdp[j + 1][l] >= mod)rdp[j + 1][l] -= mod;
			}
		}

		ll sum = rdp[n][k];
		num.push_back(sum);
	}
	int len = num.size();
	num.push_back(0);
	ll ans = 0;
	rep(i, len) {
		//cout << num[i] << endl;
		ll cnum = num[i] - num[i + 1];
		if (cnum < 0)cnum += mod;
		ans = (ans + cnum * d[i]) % mod;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
	return 0;
}