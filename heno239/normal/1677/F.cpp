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
//constexpr ll mod = 1000000007;
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
	//if (x == 0)return 0;
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
bool operator<(modint a, modint b) { return a.n < b.n; }
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
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;

mt19937 mt(time(0));

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------
int get_premitive_root() {
	int primitive_root = 0;
	if (!primitive_root) {
		primitive_root = [&]() {
			set<int> fac;
			int v = mod - 1;
			for (ll i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
			if (v > 1) fac.insert(v);
			for (int g = 1; g < mod; g++) {
				bool ok = true;
				for (auto i : fac) if (mod_pow(g, (mod - 1) / i) == 1) { ok = false; break; }
				if (ok) return g;
			}
			return -1;
		}();
	}
	return primitive_root;
}
const int proot = get_premitive_root();
int bsf(int x) {
	int res = 0;
	while (!(x & 1)) {
		res++; x >>= 1;
	}
	return res;
}
int ceil_pow2(int n) {
	int x = 0;
	while ((1 << x) < n) x++;
	return x;
}
using poly = vector<modint>;
void butterfly(poly& a) {
	int n = int(a.size());
	int g = proot;
	int h = ceil_pow2(n);

	static bool first = true;
	static modint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
	if (first) {
		first = false;
		modint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
		int cnt2 = bsf(mod - 1);
		modint e = mod_pow(g, (mod - 1) >> cnt2);
		modint ie = (modint)1 / e;
		for (int i = cnt2; i >= 2; i--) {
			// e^(2^i) == 1
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		modint now = 1;
		for (int i = 0; i < cnt2 - 2; i++) {
			sum_e[i] = es[i] * now;
			now *= ies[i];
		}
	}
	for (int ph = 1; ph <= h; ph++) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		modint now = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
			for (int i = 0; i < p; i++) {
				auto l = a[i + offset];
				auto r = a[i + offset + p] * now;
				a[i + offset] = l + r;
				a[i + offset + p] = l - r;
			}
			now *= sum_e[bsf(~(unsigned int)(s))];
		}
	}
}

void butterfly_inv(poly& a) {
	int n = int(a.size());
	int g = proot;
	int h = ceil_pow2(n);

	static bool first = true;
	static modint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
	if (first) {
		first = false;
		modint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
		int cnt2 = bsf(mod - 1);
		modint e = mod_pow(g, (mod - 1) >> cnt2);
		modint ie = (modint)1 / e;
		for (int i = cnt2; i >= 2; i--) {
			// e^(2^i) == 1
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		modint now = 1;
		for (int i = 0; i < cnt2 - 2; i++) {
			sum_ie[i] = ies[i] * now;
			now *= es[i];
		}
	}

	for (int ph = h; ph >= 1; ph--) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		modint inow = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
			for (int i = 0; i < p; i++) {
				auto l = a[i + offset];
				auto r = a[i + offset + p];
				a[i + offset] = l + r;
				a[i + offset + p] =
					(unsigned long long)(mod+(ll)l-(ll)r) *
					(ll)inow;
			}
			inow *= sum_ie[bsf(~(unsigned int)(s))];
		}
	}
}


poly multiply(poly g, poly h) {
	int n = g.size();
	int m = h.size();
	if (n == 0 || m == 0)return {};
	if (min(g.size(), h.size()) < 60) {
		poly res(g.size() + h.size() - 1);
		rep(i, g.size())rep(j, h.size()) {
			res[i + j] += g[i] * h[j];
		}
		return res;
	}
	int z = 1 << ceil_pow2(n + m - 1);
	g.resize(z);
	butterfly(g);
	h.resize(z);
	butterfly(h);
	rep(i, z) {
		g[i] *= h[i];
	}
	butterfly_inv(g);
	g.resize(n + m - 1);
	modint iz = (modint)1 / (modint)z;
	rep(i, n + m - 1) {
		g[i] *= iz;
	}
	return g;
}
struct FormalPowerSeries :vector<modint> {
	using vector<modint>::vector;
	using fps = FormalPowerSeries;
	void shrink() {
		while (this->size() && this->back() == (modint)0)this->pop_back();
	}

	fps operator+(const fps& r)const { return fps(*this) += r; }
	fps operator+(const modint& v)const { return fps(*this) += v; }
	fps operator-(const fps& r)const { return fps(*this) -= r; }
	fps operator-(const modint& v)const { return fps(*this) -= v; }
	fps operator*(const fps& r)const { return fps(*this) *= r; }
	fps operator*(const modint& v)const { return fps(*this) *= v; }


	fps& operator+=(const fps& r) {
		if (r.size() > this->size())this->resize(r.size());
		rep(i, r.size())(*this)[i] += r[i];
		shrink();
		return *this;
	}
	fps& operator+=(const modint& v) {
		if (this->empty())this->resize(1);
		(*this)[0] += v;
		shrink();
		return *this;
	}
	fps& operator-=(const fps& r) {
		if (r.size() > this->size())this->resize(r.size());
		rep(i, r.size())(*this)[i] -= r[i];
		shrink();
		return *this;
	}
	fps& operator-=(const modint& v) {
		if (this->empty())this->resize(1);
		(*this)[0] -= v;
		shrink();
		return *this;
	}
	fps& operator*=(const fps& r) {
		if (this->empty() || r.empty())this->clear();
		else {
			poly ret = multiply(*this, r);
			*this = fps(all(ret));
		}
		shrink();
		return *this;
	}
	fps& operator*=(const modint& v) {
		for (auto& x : (*this))x *= v;
		shrink();
		return *this;
	}
	fps operator-()const {
		fps ret = *this;
		for (auto& v : ret)v = -v;
		return ret;
	}

	modint sub(modint x) {
		modint t = 1;
		modint res = 0;
		rep(i, (*this).size()) {
			res += t * (*this)[i];
			t *= x;
		}
		return res;
	}
	fps pre(int sz)const {
		fps ret(this->begin(), this->begin() + min((int)this->size(), sz));
		ret.shrink();
		return ret;
	}
	fps integral() const {
		const int n = (int)this->size();
		fps ret(n + 1);
		ret[0] = 0;
		for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / (modint)(i + 1);
		return ret;
	}
	fps inv(int deg = -1)const {
		const int n = this->size();
		if (deg == -1)deg = n;
		fps ret({ (modint)1 / (*this)[0] });
		for (int i = 1; i < deg; i <<= 1) {
			ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
		}
		ret = ret.pre(deg);
		ret.shrink();
		return ret;
	}
	fps diff() const {
		const int n = (int)this->size();
		fps ret(max(0, n - 1));
		for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * (modint)i;
		return ret;
	}
	// F(0) must be 1
	fps log(int deg = -1) const {
		assert((*this)[0] == 1);
		const int n = (int)this->size();
		if (deg == -1) deg = n;
		return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
	}
	// F(0) must be 0
	fps exp(int deg = -1)const {
		assert((*this)[0] == 0);
		const int n = (int)this->size();
		if (deg == -1)deg = n;
		fps ret = { 1 };
		for (int i = 1; i < deg; i <<= 1) {
			ret = (ret * (pre(i << 1) + 1 - ret.log(i << 1))).pre(i << 1);
		}
		//cout << "!!!! " << ret.size() << "\n";
		return ret.pre(deg);
	}
	fps div(fps g) {
		assert(g.size() && g.back() != (modint)0);
		fps f = *this;
		if (f.size() < g.size())return {};
		int dif = f.size() - g.size();
		reverse(all(f));
		reverse(all(g));
		g = g.inv(dif + 1);
		fps fg = f * g;
		fps ret(dif + 1);
		rep(i, fg.size()) {
			int id = i - dif;
			if (-dif <= id && id <= 0) {
				ret[-id] = fg[i];
			}
		}
		return ret;
	}
	fps divr(fps g) {
		fps ret = (*this) - g * (*this).div(g);
		ret.shrink();
		return ret;
	}
};
using fps = FormalPowerSeries;

vector<modint> Multipoint_Evaluation(fps c, vector<modint> p) {
	int n = p.size();
	vector<modint> ret(n);
	int sz = 1;
	while (sz < n)sz *= 2;
	vector<fps> f(2 * sz - 1);
	function<void(int, int, int)> dfs = [&](int k, int l, int r) {
		if (l + 1 == r) {
			f[k] = { -p[l],1 };
		}
		else {
			dfs(2 * k + 1, l, (l + r) / 2);
			dfs(2 * k + 2, (l + r) / 2, r);
			f[k] = f[2 * k + 1] * f[2 * k + 2];
		}
	};
	dfs(0, 0, n);
	vector<fps> g(2 * sz - 1);
	function<void(int, int, int)> invdfs = [&](int k, int l, int r) {
		if (k == 0) {
			g[k] = c.divr(f[k]);
		}
		else {
			g[k] = g[(k - 1) / 2].divr(f[k]);
		}
		if (r - l <= 100) {
			Rep(i, l, r) {
				ret[i] = g[k].sub(p[i]);
			}
		}
		else {
			invdfs(2 * k + 1, l, (l + r) / 2);
			invdfs(2 * k + 2, (l + r) / 2, r);
		}
	};
	invdfs(0, 0, n);
	return ret;
}

fps Interpolation(vector<modint> x, vector<modint> y) {
	int n = x.size();
	vector<modint> ret(n);
	vector<fps> vg;
	rep(i, n) {
		vg.push_back({ -x[i],1 });
	}
	while (vg.size() > 1) {
		vector<fps> nvg;
		for (int i = 0; i < vg.size(); i+=2) {
			if (i + 1 < vg.size()) {
				nvg.push_back(vg[i] * vg[i + 1]);
			}
			else {
				nvg.push_back(vg[i]);
			}
		}
		swap(vg, nvg);
	}
	fps g = vg[0];
	fps gp = g.diff();
	vector<modint> vx = Multipoint_Evaluation(gp, x);
	function<pair<fps, fps>(int, int)> dfs = [&](int l, int r) {
		pair<fps, fps> res;
		if (l + 1 == r) {
			res.first = { y[l] / vx[l] };
			res.second = { -x[l],1 };
		}
		else {
			auto pl = dfs(l, (l + r) / 2);
			auto pr = dfs((l + r) / 2, r);
			res.first = pl.first * pr.second + pl.second * pr.first;
			res.second = pl.second * pr.second;
		}
		return res;
	};
	auto vp = dfs(0, n);
	fps res = g;
	res *= vp.first;
	res.resize(n);
	res *= vp.second.inv();
	res.resize(n);
	return res;
}

//x in [l,r)
fps Interpolation2(int l, int r, vector<modint> y) {
	int n = r - l;
	assert(y.size() == n);
	vector<int>x(n);
	rep(i, n)x[i] = l + i;
	vector<modint> ret(n);
	vector<fps> vg;
	rep(i, n) {
		vg.push_back({ -x[i],1 });
	}
	while (vg.size() > 1) {
		vector<fps> nvg;
		for (int i = 0; i < vg.size(); i += 2) {
			if (i + 1 < vg.size()) {
				nvg.push_back(vg[i] * vg[i + 1]);
			}
			else {
				nvg.push_back(vg[i]);
			}
		}
		swap(vg, nvg);
	}
	fps g = vg[0];
	fps gp = g.diff();
	vector<modint> vx(n);
	rep(i, n) {
		vx[i] = fact[i];
		vx[i] *= fact[n - 1 - i];
		if ((n - 1 - i) % 2)vx[i] = -vx[i];
	}
	function<pair<fps, fps>(int, int)> dfs = [&](int l, int r) {
		pair<fps, fps> res;
		if (l + 1 == r) {
			res.first = { y[l] / vx[l] };
			res.second = { -x[l],1 };
		}
		else {
			auto pl = dfs(l, (l + r) / 2);
			auto pr = dfs((l + r) / 2, r);
			res.first = pl.first * pr.second + pl.second * pr.first;
			res.second = pl.second * pr.second;
		}
		return res;
	};
	auto vp = dfs(0, n);
	fps res = g;
	res *= vp.first;
	res.resize(n);
	res *= vp.second.inv();
	res.resize(n);
	return res;
}

struct Data {
	fps c, sc;
};
Data operator*(Data &a, Data &b) {
	Data res;
	res.c = a.c * b.c;
	res.sc = a.c * b.sc + a.sc * b.c;
	return res;
}
Data operator+(Data a, Data& b) {
	return Data{ a.c + b.c,a.sc + b.sc };
}
void solve() {
	int n, k, p; cin >> n >> k >> p;
	vector<int> a(n); rep(i, n)cin >> a[i];
	vector<modint> vs(k+2);
	modint sum = 0;
	rep1(i,k + 1) {
		sum += mod_pow(p, i) * mod_pow(i, k);
		vs[i] = sum;
	}
	modint c;
	rep(i, k + 1)c += comb(k + 1, i+1) * (modint)mod_pow(-p, k - i) * vs[i];
	c /= mod_pow(1 - p, k + 1); vector<modint> ys(k + 2);
	modint div = 1, rp = (modint)1 / (modint)p;
	rep(i, k + 2) {
		ys[i] = (vs[i] - c) * div; div *= rp;
	}
	ys.erase(ys.begin());
	fps pp = Interpolation2(1, k + 2, ys);
	vector<modint> ca(n); rep(i, n)ca[i] = a[i];
	vector<modint> val = Multipoint_Evaluation(pp, ca);
	rep(i, val.size()) {
		val[i] *= mod_pow(p, a[i]); val[i] += c;
	}

	vector<vector<modint>> ml(n, vector<modint>(2));
	auto mr = ml;
	modint dp[2] = {};
	modint cop[2] = {};
	rep(i, n) {
		dp[0] += 1;
		rep(j, 2)ml[i][j] = dp[j];
		cop[0] += dp[0] * (modint)(a[i] + 1);
		cop[1] += dp[1] * (modint)(a[i] + 1);
		cop[1] += dp[0] * (modint)a[i];
		rep(j, 2) {
			dp[j] = cop[j];
			cop[j] = 0;
		}
	}
	rep(j, 2)dp[j] = 0;
	per(i, n) {
		dp[0] += 1;
		rep(j, 2)mr[i][j] = dp[j];
		cop[0] += dp[0] * (modint)(a[i] + 1);
		cop[1] += dp[1] * (modint)(a[i] + 1);
		cop[1] += dp[0] * (modint)a[i];
		rep(j, 2) {
			dp[j] = cop[j];
			cop[j] = 0;
		}
	}
	modint ans = 0;
	rep(i, n) {
		modint num = 0;
		rep(x, 2)rep(y, 2) {
			if (x && y)continue;
			num += ml[i][x] * mr[i][y];
		}
		ans += num * val[i];
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}