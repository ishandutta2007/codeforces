#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------


void solve() {
	int n, m; cin >> n >> m;
	ul c[3];
	rep(i, 3)cin >> c[i];
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ul ans[4] = {};

	//0start
	vector<ul> dp(4);
	vector<ul> dpnum(4);
	dpnum[0] = 1;
	rep(i, n) {
		vector<ul> nex(4);
		vector<ul> nexnum(4);
		rep(j, 4) {
			nex[j] += dp[j];
			nexnum[j] += dpnum[j];
			if (j < 3) {
				nex[j + 1] += dp[j] + dpnum[j] * (ul)i * c[j];
				nexnum[j + 1] += dpnum[j];
			}
		}
		swap(dp, nex);
		swap(dpnum, nexnum);
	}
	ans[0] = dp[3];
	//0end

	//1start
	vector<ul> r(n + 1);
	rep(i, n) {
		r[i + 1] = r[i] + (ul)i;
	}
	rep(i, n) {
		for (int to : G[i]) {
			if (i < to) {
				ul cnt;
				//A?
				cnt = i;
				ans[1] += r[i] * c[0] + (ul)i *cnt* c[1] + (ul)to*cnt * c[2];
				//B?
				cnt = to - (i + 1);
				ans[1] += (ul)i * cnt*c[0] + (r[to] - r[i + 1]) * c[1] + (ul)to *cnt* c[2];
				//C?
				cnt = n - (to + 1);
				ans[1] += (ul)i *cnt* c[0] + (ul)to *cnt* c[1] + (r[n] - r[to + 1]) * c[2];
			}
		}
	}
	//1end

	//2start
	rep(i, n) {
		vector<int> vl, vr;
		for (int to : G[i]) {
			if (to < i)vl.push_back(to);
			else vr.push_back(to);
		}
		sort(all(vl));
		sort(all(vr));
		vector<ui> rvl(vl.size() + 1);
		rep(i, vl.size())rvl[i + 1] = rvl[i] + (ul)vl[i];
		vector<ui> rvr(vr.size() + 1);
		rep(i, vr.size())rvr[i + 1] = rvr[i] + (ul)vr[i];
		//i is A
		rep(j, vr.size()) {
			ul cnt = vr.size() - 1 - j;
			ans[2] += (ul)i * cnt * c[0] + (ul)vr[j] * cnt * c[1] + (rvr[vr.size()] - rvr[j + 1])*c[2];
		}
		//i is B
		ul cnt = (ll)vl.size() * vr.size();
		ans[2] += (ul)i * cnt * c[1] + rvl[vl.size()] *(ul)vr.size()* c[0] + rvr[vr.size()] *(ul)vl.size()* c[2];
		//i is C
		rep(j, vl.size()) {
			ul cnt = vl.size() - 1 - j;
			ans[2] += (ul)i * cnt * c[2] + (ul)vl[j] * cnt * c[0] + (rvl[vl.size()] - rvl[j + 1]) * c[1];
		}
	}
	//2end

	//3start
	rep(i, n)sort(all(G[i]));
	auto isadj = [&](int a, int b) {
		int loc = lower_bound(all(G[a]), b) - G[a].begin();
		return loc < G[a].size() && G[a][loc] == b;
	};
	const int bl = 200;
	vector<bool> exi(n);
	rep(i, n) {
		if (G[i].size() <= bl) {
			rep(j, G[i].size()) {
				if (i >= G[i][j])continue;
				Rep(k, j + 1, G[i].size()) {
					if (isadj(G[i][j], G[i][k])) {
						ans[3] += (ul)i * c[0] + (ul)G[i][j] * c[1] + (ul)G[i][k] * c[2];
					}
				}
			}
		}
		else {
			for (int to : G[i])exi[to] = true;
			Rep(j,i+1, n)for (int k : G[j])if(j<k) {
				//now i<j<k
				if (exi[j] && exi[k]) {
					ans[3] += (ul)i * c[0] + (ul)j * c[1] + (ul)k * c[2];
				}
			}
			for (int to : G[i])exi[to] = false;
		}
	}


	//3end

	cout << ans[0] - ans[1] + ans[2] - ans[3] << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}