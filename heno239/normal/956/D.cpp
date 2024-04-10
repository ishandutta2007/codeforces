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
const ll mod = 998244353;
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
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
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
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

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
	ratio() { a = 0, b = 1; };
	ratio(ll x) { a = x; b = 1; };
	ratio(ll x, ll y) {
		a = x; b = y;
		ll g = gcd(x, y);
		if (g > 0) {
			a /= g, b /= g;
			if (b < 0)a = -a, b = -b;
		}
	};

};

void normalize(ratio &r) {
	ll g = gcd(r.a, r.b);
	r.a /= g; r.b /= g;
	if (r.b < 0)r.b = -r.b, r.a = -r.a;
}
bool operator<(const ratio &x, const ratio &y) {
	return x.a*y.b < x.b*y.a;
}
bool operator>(const ratio &x, const ratio &y) {
	return x.a*y.b > x.b*y.a;
}
bool operator==(const ratio &x, const ratio &y) {
	return x.a*y.b == x.b*y.a;
}
using rP = pair<ratio, ratio>;

void out(ratio &p) {
	ld res = p.a / (ld)p.b;
	cout << res << endl;
	return;
}

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

bool comp(P a, P b) {
	if (a.first != b.first)return a.first < b.first;
	return a.second > b.second;
}
ll calc(vector<rP> seg) {
	ll res = 0;
	vector<pair<ratio,int>> xs;
	rep(i, seg.size()) {
		xs.push_back({ seg[i].first,2 * i });
		xs.push_back({ seg[i].second,2 * i + 1 });
	}
	sort(all(xs));

	vector<P> nseg(seg.size());
	int tmp = 0;
	rep(i, xs.size()) {
		int id = xs[i].second;
		int r = id % 2; id /= 2;
		if (i > 0 && xs[i - 1].first == xs[i].first)tmp--;
		if (!r)nseg[id].first = tmp;
		else nseg[id].second = tmp;

		tmp++;
	}
	BIT b(tmp);
	sort(all(nseg),comp);
	rep(i, nseg.size()) {
		int l = nseg[i].first;
		int r = nseg[i].second;
		res += b.sum(r, tmp);
		b.add(r, 1);
	}
	return res;
}
void solve() {
	int n, w; cin >> n >> w;
	if (w == 0) {
		vector<ratio> vs;
		rep(i, n) {
			int x, v; cin >> x >> v;
			if (x > 0)vs.push_back({ x,-v });
			else vs.push_back({ -x,v });
		}
		sort(all(vs));
		ll ans = 0;
		rep(i, vs.size()) {
			int le = i;
			while (i + 1 < vs.size() && vs[i] == vs[i + 1])i++;
			ll len = i - le + 1;
			ans += len * (len - 1) / 2;
		}
		cout << ans << endl; return;
	}
	vector<pair<rP,bool>> seg(n);
	vector<rP> seg0, seg1;
	rep(i, n) {
		int x, v; cin >> x >> v;
		if (v > 0) {
			seg[i].first.first = { -x,v + w };
			seg[i].first.second = { -x,v - w };
			seg[i].second = 0;
			seg0.push_back(seg[i].first);
		}
		else {
			seg[i].first.first = { x,w-v };
			seg[i].first.second = { x,-w-v };
			seg[i].second = 1;
			seg1.push_back(seg[i].first);
		}
		/*cout << "is " << i << endl;
		out(seg[i].first.first);
		out(seg[i].first.second);*/
	}
	sort(all(seg));
	multiset<ratio> st0, st1;
	ll ans = 0;
	rep(i, n) {
		/*cout << i << " ?? " << st1.size() << endl;
		out(seg[i].first.first);
		out(seg[i].first.second);*/
		if (seg[i].second == 0) {
			while (!st1.empty()) {
				ratio r = *st1.begin();
				if (r < seg[i].first.first)st1.erase(st1.begin());
				else break;
			}
			
			ans += st1.size();
		}
		else {		
			st1.insert(seg[i].first.second);
		}
	}
	rep(i, n) {
		if (seg[i].second == 1) {
			while (!st0.empty()) {
				ratio r = *st0.begin();
				if (r < seg[i].first.first)st0.erase(st0.begin());
				else break;
			}
			ans += st0.size();
		}
		else {
			st0.insert(seg[i].first.second);
		}
	}
	ans += calc(seg0);
	ans += calc(seg1);

	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}