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
#include<numeric>
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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 17;
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

ll gcd(ll x, ll y) {
	x = abs(x), y = abs(y);
	if (x < y)swap(x, y);
	while (y) {
		ll r = x % y; x = y; y = r;
	}
	return x;
}

//0/0
struct ratio {
	ll a, b;
	ratio(ll x) { a = x; b = 1; };
	ratio(ll x, ll y) {
		a = x; b = y;
		
	};

};

void normalize(ratio& r) {
	ll g = gcd(r.a, r.b);
	r.a /= g; r.b /= g;
	if (r.b < 0)r.b = -r.b, r.a = -r.a;
}
bool operator<(const ratio& x, const ratio& y) {
	return x.a * y.b < x.b* y.a;
}
bool operator==(const ratio& x, const ratio& y) {
	return x.a * y.b == x.b * y.a;
}



void solve() {
	int n; cin >> n;
	vector<ll> xl(n), xr(n), y(n);
	rep(i, n) {
		cin >> xl[i] >> xr[i] >> y[i];
	}
	vector<pair<ratio, ratio>> v;
	vector<ratio> vr;
	rep(i, n)rep(j, n) {
		if (y[i] >= y[j])continue;
		int dy = y[j] - y[i];
		ratio le(-xr[j]+xl[i], dy);
		ratio ri(-xl[j]+xr[i], dy);
		v.push_back({ le,ri });

		vr.push_back(le);
		vr.push_back(ri);
	}
	if (v.empty()) {
		ld ans = 0;
		ld lx = mod, rx = -mod;
		rep(i, n) {
			lx = min(lx, (ld)xl[i]);
			rx = max(rx, (ld)xr[i]);
		}
		ans = rx - lx;
		cout << ans << "\n";
		return;
	}

	sort(all(vr));
	vr.erase(unique(all(vr)), vr.end());
	vector<P> segs;
	rep(i, v.size()) {
		int l = lower_bound(all(vr), v[i].first) - vr.begin();
		int r = lower_bound(all(vr), v[i].second) - vr.begin();
		segs.push_back({ l,r });
	}
	vector<int> cnt(vr.size() + 1);
	for (P p : segs) {
		int l = p.first, r = p.second;
		cnt[l + 1]++;
		cnt[r]--;
	}
	vector<ratio> cs;
	rep(i, vr.size()) {
		cnt[i + 1] += cnt[i];
		if (cnt[i] == 0) {
			cs.push_back(vr[i]);
		}
	}
	

	vector<ld> lx(cs.size()), rx(cs.size());
	{
		vector<LP> vx;
		rep(i, n) {
			vx.push_back({ y[i],xl[i] });
		}
		sort(all(vx), greater<LP>());

		vector<LP> memos;

		auto check = [&](LP a, LP b, LP c)->bool {
			return (c.second - a.second) * (a.first - b.first) + (a.second) * (a.first - c.first) <= b.second * (a.first - c.first);
		};
		rep(i, vx.size()) {
			if (memos.size() && memos.back().first == vx[i].first)memos.pop_back();
			while (memos.size() >= 2 && check(memos[memos.size() - 2], memos.back(), vx[i])) {
				memos.pop_back();
			}
			memos.push_back(vx[i]);
		}
		auto val = [&](LP a, ratio r)->ld {
			return a.second + a.first * r.a/(ld)r.b;
		};
		int loc = 0;
		rep(i, cs.size()) {
			while (loc + 1 < memos.size() && val(memos[loc], cs[i]) > val(memos[loc+1], cs[i])) {
				loc++;
			}
			lx[i] = val(memos[loc], cs[i]);
		}
	}
	{
		vector<LP> vx;
		rep(i, n) {
			vx.push_back({ y[i],xr[i] });
		}
		sort(all(vx));

		vector<LP> memos;

		auto check = [&](LP a, LP b, LP c)->bool {
			return (c.second - a.second)* -(a.first - b.first) + (a.second) * -(a.first - c.first) >= b.second * -(a.first - c.first);
		};
		rep(i, vx.size()) {
			if (memos.size() && memos.back().first == vx[i].first)memos.pop_back();
			while (memos.size() >= 2 && check(memos[memos.size() - 2], memos.back(), vx[i])) {
				memos.pop_back();
			}
			memos.push_back(vx[i]);
		}
		//cout << "! " << memos.size() << "\n";
		auto val = [&](LP a, ratio r)->ld {
			return a.second + a.first * r.a / (ld)r.b;
		};
		int loc = 0;
		rep(i, cs.size()) {
			while (loc + 1 < memos.size() && val(memos[loc], cs[i]) < val(memos[loc + 1], cs[i])) {
				loc++;
			}
			rx[i] = val(memos[loc], cs[i]);
		}
	}
	ld ans = INF;
	rep(i, cs.size()) {
		ld dx = rx[i] - lx[i];
		ans = min(ans, dx);
		//cout << "? " << cs[i].a << " " << cs[i].b << "\n";
		//cout << lx[i] << " " << rx[i] << "\n";
	}
	cout << ans << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//cout << grandy(2, 3, false, false) << "\n";
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}