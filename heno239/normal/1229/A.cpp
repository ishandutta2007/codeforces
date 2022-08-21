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
#include<cstdlib>
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
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

void solve() {
	int n; cin >> n;
	vector<ll> x;
	vector<ll> a(n), b(n);
	rep(i, n) {
		cin >> a[i]; x.push_back(a[i]);
	}
	sort(x.begin(), x.end());
	vector<ll> oks;
	rep(i, x.size()) {
		int le = i;
		while (i + 1 < (int)x.size() && x[i] == x[i + 1])i++;
		if (i > le)oks.push_back(x[i]);
	}
	rep(i, n) {
		cin >> b[i];
	}
	ll ans = 0;
	rep(i, n) {
		bool f = false;
		rep(j, oks.size()) {
			if ((a[i] & oks[j]) == a[i]) {
				f = true; break;
			}
		}
		if (f) {
			ans += b[i];
		}
	}
	cout << ans << endl;
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