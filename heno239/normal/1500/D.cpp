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
typedef long double ld;
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
const int max_n = 1 << 2;
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


template<typename T>
struct minimumqueue {
private:
	T init_c;
	function<T(T, T)> f;
	vector<T> backs;
	vector<T> fronts;
	T frontsum;
public:
	void init(function<T(T,T)> _f,T _init_c) {
		f = _f, init_c = _init_c;
	}
	void init() {
		fronts.clear();
		backs.clear();
		frontsum = init_c;
	}
	void push(T x) {
		fronts.push_back(x);
		frontsum = f(frontsum, x);
	}
	void pop_front() {
		if (backs.size())backs.pop_back();
		else {
			//assert(fronts.size());
			frontsum = init_c;
			T cur = init_c;
			per(i, fronts.size()) {
				cur = f(cur, fronts[i]);
				backs.push_back(cur);
			}
			fronts.clear();
			backs.pop_back();
		}
	}
	T take_val() {
		T res = frontsum;
		if (backs.size())res = f(res, backs.back());
		return res;
	}
};
using ar = array<P,11>;
int cnt[1501 * 1501];
void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n,vector<int>(n));
	rep(i, n)rep(j, n)cin >> a[i][j];
	vector<int> ans(n + 1);

	vector<ar> ori(n);
	rep(i, n) {
		rep(j, 11)ori[i][j] = { mod,mod };
	}
	ar init_c; rep(i, 11)init_c[i] = { mod,mod };
	minimumqueue<ar> que;

	function<ar(ar, ar)> merge = [&](ar a, ar b)->ar {
		int idl = 0, idr = 0;
		ar res;
		rep(t, 11) {
			while (a[idl].first < mod && cnt[a[idl].second])idl++;
			while (b[idr].first < mod && cnt[b[idr].second])idr++;
			if (a[idl] < b[idr]) {
				res[t] = a[idl]; idl++;
			}
			else {
				res[t] = b[idr]; idr++;
			}
			if (res[t].first < mod)cnt[res[t].second] = 1;
		}
		rep(t, 11) {
			if (res[t].first < mod)cnt[res[t].second] = 0;
		}
		return res;
	};
	que.init(merge, init_c);
	per(j, n) {
		rep(i, n) {
			ar x = init_c;
			x[0] = { j,a[i][j] };
			ori[i] = merge(ori[i], x);
		}
		que.init();
		int r = 0;
		rep(l, n) {
			//[l,r)
			while (r<n) {
				ar x = que.take_val();
				if (x[k].first - j + 1 > r - l) {
					//add r
					que.push(ori[r]);
					r++;
				}
				else break;
			}
			//cout << j << " " << l << " " << r << "\n";
			//ans[min(r -1- l,n-j)]++;
			ar x = que.take_val();
			if (x[k].first - j + 1 > r - l) {
				ans[min(r - l, n - j)]++;
			}
			else {
				ans[min(r - l - 1, n - j)]++;
			}
			que.pop_front();
			//cout << j << " " << l << " " << x[k].first << "\n";
			//cout << "start " << j << " " << l << "\n";
			//rep(t, k + 1)cout << x[t].first << " " << x[t].second << "\n";
		}
	}
	for (int i = n; i > 0; i--)ans[i - 1] += ans[i];
	rep1(i, n)cout << ans[i] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}