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
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000500007;
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

ll ans[1 << 17];
int n, k;

vector<int> merge(vector<int>& a, vector<int>& b) {
	int id1 = 0;
	int id2 = 0;
	vector<int> res;
	while (id1 < a.size() || id2 < b.size()) {
		if (id2 == b.size()) {
			res.push_back(a[id1]);
			while (id1 + 1 < a.size() && a[id1] == a[id1 + 1])id1++;
			id1++;
		}
		else if (id1 == a.size()) {
			res.push_back(b[id2]);
			while (id2 + 1 < b.size() && b[id2] == b[id2 + 1])id2++;
			id2++;
		}
		else {
			if (a[id1] < b[id2]) {
				res.push_back(a[id1]);
				while (id1 + 1 < a.size() && a[id1] == a[id1 + 1])id1++;
				id1++;
			}
			else if (a[id1] > b[id2]) {
				res.push_back(b[id2]);
				while (id2 + 1 < b.size() && b[id2] == b[id2 + 1])id2++;
				id2++;
			}
			else {
				res.push_back(a[id1]);
				while (id1 + 1 < a.size() && a[id1] == a[id1 + 1])id1++;
				id1++;
				while (id2 + 1 < b.size() && b[id2] == b[id2 + 1])id2++;
				id2++;
			}
		}
	}
	return res;
}

void debug(vector<int> &v) {

	rep(i, v.size()) {
		cout << v[i] << " ";
	}
	cout << "\n";
}
int cnt[1 << 18];
void yaru(multiset<int>& st, int coef) {
	vector<int> as, bs;
	for (int id : st) {
		as.push_back(id - k + 1);
		bs.push_back(id + 1);
	}
	vector<int> cs = merge(as, bs);
	//cout << "hei\n";
	//debug(as); debug(bs); debug(cs);
	fill(cnt, cnt + cs.size(), 0);
	int loc = 0;
	int loc2 = 0;
	for (int id : st) {
		while (cs[loc] < id - k + 1) {
			loc++;
		}
		cnt[loc]++;
		while (cs[loc2] < id + 1) {
			loc2++;
		}
		cnt[loc2]--;
	}
	rep(i, cs.size()) {
		cnt[i + 1] += cnt[i];
		int doef = k;
		if (i + 1 < cs.size()) {
			doef = min(doef, cs[i + 1] - cs[i]);
		}
		ans[cnt[i]] += coef * doef;
	}
}
vector<int> calc(vector<int>vx) {
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	vector<int> res;
	rep(i, vx.size()) {
		res.push_back(vx[i] - k + 1);
		res.push_back(vx[i]+1);
	}
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	return res;
}
void solve() {
	cin >> n >> k;
	vector<int> x(n), y(n);
	vector<int> vx, vy;
	rep(i, n) {
		cin >> x[i] >> y[i];
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	vector<int> bx = calc(vx);
	vector<vector<int>> ads(bx.size()), decs(bx.size());
	rep(i, n) {
		int id = lower_bound(all(bx), x[i]-k+1) - bx.begin();
		ads[id].push_back(i);
		id = lower_bound(all(bx), x[i]+1) - bx.begin();
		decs[id].push_back(i);
	}
	multiset<int> st;
	rep(i,bx.size()) {
		for (int id : ads[i]) {
			st.insert(y[id]);
		}
		for (int id : decs[i]) {
			st.erase(st.find(y[id]));
		}
		int coef = k;
		if (i + 1 < bx.size()) {
			coef = min(coef, bx[i + 1] - bx[i]);
		}
		yaru(st, coef);
	}
	rep1(i, n) {
		if (i > 1)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}