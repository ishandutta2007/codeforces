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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
ll mod_inverse(ll a) {
	ll n = mod - 2;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}
const int N_MAX = 1<<18;
ll p[N_MAX], invp[N_MAX];
void init() {
	p[0] = 1;
	rep1(i, N_MAX - 1) {
		p[i] = p[i - 1] * i%mod;
	}
	invp[N_MAX - 1] = mod_inverse(p[N_MAX - 1]);
	per(i, N_MAX - 1) {
		invp[i] = invp[i + 1] * (i + 1) % mod;
	}
}
//xCy
ll comb(ll x, ll y) {
	if (x < y || y<0)return 0;
	ll res = p[x];
	(res *= invp[y]) %= mod;
	(res *= invp[x - y]) %= mod;
	return res;
}
//xPy
ll comb2(ll x, ll y) {
	return p[x] * invp[x - y] % mod;
}
int bit[1 << 18]; int n;
void add(int a, int w) {
	for (int i = a; i <= n + 1; i += i & -i)bit[i] += w;
}
int sum(int a) {
	int ret = 0;
	for (int i = a; i > 0; i -= i & -i)ret += bit[i];
	return ret;
}
int a[1 << 18];
bool used[1 << 18];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		if (a[i] > 0)used[a[i]] = true;
	}
	vector<int> v;
	rep1(i, n) {
		if (used[i])continue;
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	ll ans = 0; int cnt = 0;
	int len = v.size();
	rep(i, n) {
		if (a[i] > 0) {
			int num = i-cnt-sum(a[i]);
			ans = (ans + num) % mod;
			int id = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			(ans += (ll)cnt*(len - id) % mod*mod_inverse(len) % mod) %= mod;
			(ans += (ll)(len - cnt)*id%mod*mod_inverse(len) % mod) %= mod;
			add(a[i], 1);
		}
		else {
			cnt++;
		}
	}
	(ans += (ll)len * (len - 1)%mod*mod_inverse(4)%mod)%=mod;
	cout << ans << endl;
	//stop
	return 0;
}