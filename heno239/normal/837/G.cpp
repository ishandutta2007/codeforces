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
const ll mod = 1000000007;
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


struct func {
	int x1, x2, y1, a, b, y2;
};

struct status {
	int x, a, b,y;
	bool operator<(const status &s)const {
		if (x != s.x)return x < s.x;
		if (a != s.a)return a < s.a;
		if (y != s.y)return y < s.y;
		return b < s.b;
	}
};
struct memos {
	ll y, a, b;
};

vector<status> mergee(vector<status> &a, vector<status> &b) {
	int l1 = a.size();
	int l2 = b.size();
	int c1 = 0, c2 = 0;
	vector<status> res;
	while (c1 < l1&&c2 < l2) {
		if (a[c1] < b[c2]) {
			res.push_back(a[c1]); c1++;
		}
		else {
			res.push_back(b[c2]); c2++;
		}
	}
	while (c1 < l1) {
		res.push_back(a[c1]); c1++;
	}
	while (c2 < l2) {
	    res.push_back(b[c2]); c2++;
	}
	return res;
}
struct range_tree {
private:
	int sz = 1;
	vector<vector<status>> nodex1;
	vector<vector<status>> nodex2;
	vector<vector<memos>> memox1;
	vector<vector<memos>> memox2;
	vector<ll> suma,sumb;

public:
	range_tree(vector<func> &v) {
		int n = v.size();
		while (sz < n)sz *= 2;
		nodex1.resize(sz * 2 - 1);
		nodex2.resize(sz * 2 - 1);
		memox1.resize(sz * 2 - 1);
		memox2.resize(sz * 2 - 1);
		suma.resize(sz * 2 - 1, 0);
		sumb.resize(sz * 2 - 1, 0);
		rep(i, n) {
			int k = sz - 1 + i;
			nodex1[k].push_back({ v[i].x1,v[i].a,v[i].b,v[i].y1 });
			nodex2[k].push_back({ v[i].x2,v[i].a,v[i].b,v[i].y2 });
			suma[k] = v[i].a;
			sumb[k] = v[i].b;
		}
		per(i, sz - 1) {
			nodex1[i]=mergee(nodex1[2 * i + 1], nodex1[2 * i + 2]);
			nodex2[i] = mergee(nodex2[2 * i + 1], nodex2[2 * i + 2]);
			suma[i] = (suma[2 * i + 1] + suma[2 * i + 2]);
			sumb[i] = (sumb[2 * i + 1] + sumb[2 * i + 2]);
		}
		rep(i, 2 * sz - 1) {
			{
				vector<memos> &v = memox1[i];
				vector<status> &s = nodex1[i];
				v.resize(s.size() + 1);
				rep(j, s.size()) {
					v[j + 1].y = v[j].y + s[j].y;
					v[j + 1].a = v[j].a + s[j].a;
					v[j + 1].b = v[j].b + s[j].b;
				}
			}
			{
				vector<memos> &v = memox2[i];
				vector<status> &s = nodex2[i];
				v.resize(s.size() + 1);
				rep(j, s.size()) {
					v[j + 1].y = v[j].y + s[j].y;
					v[j + 1].a = v[j].a + s[j].a;
					v[j + 1].b = v[j].b + s[j].b;
				}
			}
		}
	}
	LP calc(int k, int x) {
		LP res = { 0,0 };
		ll a = suma[k], b = sumb[k];

		{
			vector<status> &vs = nodex1[k];
			vector<memos> &ms = memox1[k];
			int id = lower_bound(all(vs), status{ x,-1,-1,-1 }) - vs.begin();
			ll c = ms.back().y - ms[id].y;
			a -= ms.back().a - ms[id].a;
			//cout << "?? " << id << endl;
			b -= ms.back().b - ms[id].b;
			res.second += c;
		}
		{
			vector<status> &vs = nodex2[k];
			vector<memos> &ms = memox2[k];
			int id = lower_bound(all(vs), status{ x,-1,-1,-1 }) - vs.begin();
			ll c = ms[id].y;
			a -= ms[id].a;
			b -= ms[id].b;
			res.second += c;
		}
		res.first = a; res.second += b;
		//cout << res.first << " " << res.second << endl;
		return res;
	}
	LP merge(LP a, LP b) {
		return { a.first + b.first,a.second + b.second };
	}
	LP query(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return { 0,0 };
		if (a <= l && r <= b) {
			return calc(k, x);
		}
		else {
			LP vl = query(x, a, b, 2 * k + 1, l, (l + r) / 2);
			LP vr = query(x, a, b, 2 * k + 2, (l + r) / 2, r);
			return merge(vl, vr);
		}
	}
};



void solve() {
	int n; cin >> n;
	vector<func> f(n);
	rep(i, n) {
		scanf("%d %d %d %d %d %d", &f[i].x1, &f[i].x2, &f[i].y1, &f[i].a, &f[i].b, &f[i].y2);
		//cin >> f[i].x1 >> f[i].x2 >> f[i].y1 >> f[i].a >> f[i].b >> f[i].y2;
	}
	range_tree rt(f);

	int q; cin >> q;
	ll las = 0;
	rep(aa, q) {

		int l, r, x; 
		scanf("%d %d %d", &l, &r, &x);
		//cin >> l >> r >> x; 
		l--; r--;
		x += las; x %= (1000000000);
		LP ss = rt.query(x,l, r + 1);
		ll ans = ss.first*x + ss.second;
		printf("%lld\n", ans);
		//cout << ans << "\n";
		ans %= (1000000000);
		las = ans;
	}
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}