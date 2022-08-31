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

struct SegT {
private:
	int sz; vector<P> node;
	const P init_c = { mod,0 };
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	P f(P a, P b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = { a,k - (sz - 1) };
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

vector<int> G[1 << 18];


vector<P> memo[1 << 18];
vector<int> ids[1 << 18];
P dfs(int id, int fr) {
	P res = { 0,id };
	for (int to : G[id]) {
		if (to == fr)continue;
		ids[id].push_back(to);
		P nex = dfs(to, id);
		nex.first++;
		memo[id].push_back(nex);
		res = max(res, nex);
	}
	return res;
}

int ma; vector<int> ans;
void invdfs(int id, P pre) {
	if (G[id].size() >= 3) {
		vector<P> v;
		for (P p : memo[id]) {
			v.push_back(p);
		}
		v.push_back(pre);
		sort(v.begin(), v.end(),greater<P>());
		int sum = 0; rep(i, 3)sum += v[i].first;
		if (ma < sum) {
			ma = sum;
			rep(i, 3)ans[i] = v[i].second;
		}
	}
	int len = memo[id].size();
	vector<P> lemi(len + 1, { -mod,0 }), rimi(len + 1, { -mod,0 });
	rep(i, len) {
		lemi[i + 1] = max(lemi[i], memo[id][i]);
	}
	per(i, len) {
		rimi[i] = max(rimi[i + 1], memo[id][i]);
	}
	rep(i, len) {
		P nex = max({ lemi[i],rimi[i + 1],pre });
		nex.first++;
		invdfs(ids[id][i], nex);
	}
}

void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int bl = 0;
	rep(i, n) {
		bl = max(bl, (int)G[i].size());
	}
	if (bl == 2) {
		rep(i, n)if (G[i].size() == 1)ans.push_back(i);
		rep(i, 3)if (i != ans[0] && i != ans[1])ans.push_back(i);
		cout << n - 1 << endl;
		rep(i, 3) {
			if (i > 0)cout << " ";
			cout << ans[i]+1;
		}
		cout << endl;
		return;
	}
	ma = 0;
	ans.resize(3);
	dfs(0, -1);
	invdfs(0, { 0,0 });
	cout << ma << endl;
	rep(i, 3) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}