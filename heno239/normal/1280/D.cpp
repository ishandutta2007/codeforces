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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
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

//ll inv(ll a, ll p) {
//	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
//}
//modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


using lP = pair<int, ll>;
using speP = pair<vector<int>, vector<lP>>;

lP merge(lP &a, lP &b) {
	return { a.first + b.first,a.second + b.second };
}

void upd(speP &l) {
	int len = l.first.size() - 1;
	rep1(i, len) {
		if (l.second[i].second > 0) {
			l.first[i] = max(l.first[i], l.second[i].first + 1);
		}
		else {
			l.first[i] = max(l.first[i], l.second[i].first);
		}
	}
}
speP merge(speP &l,speP &r) {
	int l1 = l.first.size()-1;
	int l2 = r.first.size()-1;
	speP res;
	res.first.resize(l1 + l2 + 1,0);
	res.second.resize(l1 + l2 + 1, { 0,-INF });
	rep1(x, l1) {
		rep1(y, l2) {
			res.first[x + y] = max(res.first[x + y], l.first[x] + r.first[y]);
			res.second[x + y] = max(res.second[x + y], { l.second[x].first + r.first[y],l.second[x].second });
			res.second[x + y-1] = max(res.second[x + y-1], merge(l.second[x],r.second[y]));
		}
	}
	upd(res);
	return res;
}

ll b[3000], w[3000];
vector<int> G[3000];
speP dfs(int id, int fr) {
	speP res;
	res.first = { 0,w[id]>b[id] };
	res.second = { {0,0},{0,w[id] - b[id]} };
	for (int to : G[id]) {
		if (to == fr)continue;
		speP nex = dfs(to, id);
		res = merge(res, nex);
	}
	//if (id == 0)cout << res.second[4].first<<" "<<res.second[4].second << endl;
	upd(res);
	return res;
}

void solve() {
	int n, k; cin >> n >> k;
	rep(i, n)cin >> b[i];
	rep(i, n)cin >> w[i];
	rep(i, n) {
		G[i].clear();
	}
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	speP out = dfs(0, -1);
	int ans = out.first[k];
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}