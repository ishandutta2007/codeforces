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

ll mod_pow(ll x, ll n = mod - 2) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
ll inv[5001];
void init() {
	rep(i, 5001) {
		inv[i] = mod_pow(i);
	}
}

ll dp[5001];// cop[5001];
ll rdp[5002];

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> num;
	rep(i, n) {
		int le = i;
		while (i + 1 < n&&a[i] == a[i + 1])i++;
		num.push_back(i - le + 1);
		//v.push_back({ a[i],i - le + 1 });
	}
	int sz = num.size();
	//int sz = v.size();
	ll ans = 0;
	rep(i, sz) {
		dp[i] = num[i] * inv[n] % mod;
		if (num[i] >= 2) {
			ans = (ans + dp[i] * (num[i] - 1)%mod*inv[n - 1]) % mod;
		}
		rdp[i + 1] = rdp[i] + dp[i];
		if (rdp[i + 1] >= mod)rdp[i + 1] -= mod;
	}
	rep(i, sz - 1) {
		int rest = n - 1 - i;
		//rep(j, sz)cop[j] = 0;
		rep(j, sz) {
			dp[j] = rdp[j] * num[j] % mod*inv[rest] % mod;
			if (num[j] >= 2) {
				ans = (ans + dp[j] * (num[j] - 1) % mod*inv[rest - 1]) % mod;
			}
		}
		rep(j, sz) {
			rdp[j + 1] = rdp[j] + dp[j];
			if (rdp[j + 1] >= mod)rdp[j + 1] -= mod;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}