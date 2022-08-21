#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
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
const int max_n = 1 << 10;
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

//size i,masita:j,sita:k
modint precalc[41][41][41];
void init(int n) {
	rep1(i, n)rep(j, n-i+1)rep(k, n-i+1) {
		if (j > k)continue;
		modint val = 1;
		modint val2 = 1;
		int rest = n - i - k;
		val *= fact[rest+i-1];
		val *= combP(n, k);
		rest = n - i - (k - j);
		val2 *= fact[rest + i - 1];
		val2 *= combP(n, k - j);
		modint cop = 1;
		rep(t, i)cop *= val;
		precalc[i][j][k] += cop;
		cop = 1;
		rep(t, i)cop *= val2;
		if(j>0)precalc[i][j][k] -= cop;
	}
}

map<vector<P>, bool> chked[41];
map<vector<P>, modint> memo[41];

int n;
modint dp(vector<P> cs, int alt) {
	if (cs.empty())return 1;
	if (chked[alt][cs])return memo[alt][cs];
	chked[alt][cs] = true;
	vector<int> dec(cs.size());
	int pre = n;
	for (P p : cs)pre -= p.first*p.second;
	modint res = 0;
	function<void(int)> dfs = [&](int loc) {
		if (loc == cs.size()) {
			vector<P> ncs;
			int sum = 0;
			modint pro = 1;
			rep(j, cs.size()) {
				sum += cs[j].first*dec[j];
				if (cs[j].second - dec[j] > 0) {
					ncs.push_back({ cs[j].first,cs[j].second - dec[j] });
				}
				pro *= comb(cs[j].second, dec[j]);
				pro *= mod_pow(precalc[cs[j].first][alt][pre],dec[j]);
			}
			if (sum == 0)return;
			//cout <<"? "<< pro << " "<<alt<<" "<<pre<<"\n";
			res += dp(ncs, sum) * pro;
		}
		else {
			rep(j, cs[loc].second+1) {
				dec[loc] = j;
				dfs(loc + 1);
			}
		}
	};
	dfs(0);
	//cout << "hello\n";
	//for (P p : cs)cout << p.first << " " << p.second << " "; cout << alt << " " << res << "\n";
	return memo[alt][cs]=res;
}
void solve() {
	cin >> n; init(n);
	//cout << precalc[2][0][0] << "\n";
	vector<int> cs;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i]; p[i]--;
	}
	vector<bool> used(n);
	rep(i, n) {
		if (used[i])continue;
		used[i] = true;
		int num = 1;
		int cur = p[i];
		while (cur != i) {
			used[cur] = true;
			num++; cur = p[cur];
		}
		cs.push_back(num);
	}
	sort(all(cs));
	vector<P> ori;
	rep(i, cs.size()) {
		int le = i;
		while (i + 1 < cs.size() && cs[i] == cs[i + 1])i++;
		ori.push_back({ cs[i],i - le + 1 });
	}
	//cout << ori[0].first << " " << ori[0].second << "\n";
	modint ans = dp(ori, 0);
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}