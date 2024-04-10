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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;

struct perm {
private:
	int sz;
	vector<ll> p, invp;
public:
	perm(int n) {
		sz = n + 1;
		p.resize(sz), invp.resize(sz);
		p[0] = 1;
		rep1(i, sz - 1) {
			p[i] = p[i - 1] * i%mod;
		}
		invp[sz - 1] = 1;
		ll cop = mod - 2, x = p[sz - 1];
		while (cop) {
			if (cop % 2)invp[sz - 1] = invp[sz - 1] * x%mod;
			cop >>= 1; x = x * x % mod;
		}
		per(i, sz - 1) {
			invp[i] = invp[i + 1] * (i + 1) % mod;
		}
	}
	ll comb(ll x, ll y) {
		if (x < y || y < 0)return 0;
		ll ret = p[x];
		(ret *= invp[y]) %= mod;
		(ret *= invp[x - y]) %= mod;
		return ret;
	}
	ll combP(ll x, ll y) {
		if (x < y || y < 0)return 0;
		return p[x] * invp[x - y] % mod;
	}
};
perm p(1 << 20);

vector<P> v[1 << 20];
vector<int> c[1 << 20];

const int mn = (1 << 20);
bool isp[1 << 20];
void init() {
	fill(isp + 2, isp + mn, true);
	Rep(i, 2, mn) {
		if (!isp[i])continue;
		c[i].push_back(i);
		for (int j = 2 * i; j <mn; j+=i) {
			isp[j] = false;
			c[j].push_back(i);
		}
	}
	Rep(i, 2, mn) {
		int cop = i;
		rep(j, c[i].size()) {
			int d = c[i][j];
			int cnt = 0;
			while (cop%d == 0) {
				cnt++; cop /= d;
			}
			v[i].push_back({ d,cnt });
		}
	}
}
int n;
ll dfs(int k, int r) {
	if (k == 1)return 1;
	ll ret = 0;
	rep(i, v[k].size()) {
		ll pro = 1;
		rep(j, v[k].size()) {
			int len = v[k][j].second;
			if (i == j)len--;
			rep(l, len) {
				pro = pro * v[k][j].first;
			}
		}
		ll num = n / pro - n / k;
		ll csum = p.combP(r-1, num-1);
		csum = csum * num%mod;
		csum = csum * dfs(pro, r - num) % mod;
		ret = (ret + csum) % mod;
	}
	//cout << k << " " << r << " " << ret << endl;
	return ret;
}
void solve() {
	init();
	cin >> n;
	int ma = 0;
	rep1(i, n) {
		int sum = 0;
		rep(j, v[i].size()) {
			sum += v[i][j].second;
		}
		ma = max(ma, sum);
	}
	vector<int> z;
	rep1(i, n) {
		int sum = 0;
		rep(j, v[i].size()) {
			sum += v[i][j].second;
		}
		if (ma == sum) {
			z.push_back(i);
		}
	}
	ll ans = 0;
	rep(i, z.size()) {
		ll csum = dfs(z[i], n - 1);
		ans = (ans + csum) % mod;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> w>>h>>n,n)solve();
	solve();
	//stop
	return 0;
}