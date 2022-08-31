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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

const int sz = 100000;
int d[sz+1];
vector<int> p[sz + 1];
bool isp[sz + 1];

vector<int> di[sz + 1];

ll inv[sz + 1];
ll mod_inverse(ll x) {
	int n = mod - 2;
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
void init() {
	fill(isp + 2, isp + sz + 1, true);
	for (int i = 2; i <= sz; i++) {
		if (!isp[i])continue;
		p[i].push_back(i);
		for (int j = 2 * i; j <= sz; j += i) {
			isp[j] = false;
			p[j].push_back(i);
		}
	}
	d[1] = 0;
	for (int i = 2; i <= sz; i++) {
		int pro = 1;
		rep(j, p[i].size()) {
			pro = pro * p[i][j];
		}
		if (pro != i) {
			d[i] = -1;
		}
		else {
			d[i] = p[i].size();
		}
	}
	for (int i = 1; i <= sz; i++) {
		for (int j = i; j <= sz; j += i) {
			di[j].push_back(i);
		}
	}
	rep1(i, sz) {
		inv[i] = mod_inverse(i);
	}
}

int m;
int calc(int x,int g) {
	int sum = 0;
	int dd = x / g;
	rep(j, di[dd].size()) {
		int v = di[dd][j];
		if (d[v] < 0)continue;
		if (d[v]%2 == 0) {
			sum += m / (g*v);
		}
		else {
			sum -= m / (g*v);
		}
	}
	return sum;
}
ll dp[sz + 1];
void solve() {
	cin >> m;
	dp[1] = 0;
	for (int i = 2; i <= m; i++) {
		ll pro;
		ll sum = 1;
		for (int j = 0; j < di[i].size();j++) {
			int g = di[i][j];
			if (g == i) {
				pro = m * inv[m - m / i] % mod;
			}
			else {
				ll csum= calc(i, g)*inv[m] % mod*dp[g] % mod;
				sum = (sum + csum) % mod;
			}
		}
		dp[i] = pro * sum%mod;
	}
	ll sum = 1;
	rep1(i, m) {
		sum += dp[i]*inv[m]; sum %= mod;
	}
	cout << sum << endl;
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