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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct edge {
	int to, w, c;
};
void solve() {
	int n; cin >> n;
	ll s; cin >> s;
	vector<vector<edge>> G(n);
	rep(i, n - 1) {
		int a, b, w, c; cin >> a >> b >> w >> c; a--; b--;
		G[a].push_back({ b,w,c });
		G[b].push_back({ a,w,c });
	}
	vector<int> ch(n);
	vector<int> ws(n), cs(n);
	function<void(int, int)>dfs = [&](int id, int fr) {
		for (edge e : G[id]) {
			if (e.to == fr)continue;
			ws[e.to] = e.w;
			cs[e.to] = e.c;
			dfs(e.to, id);
			ch[id] += ch[e.to];
		}
		if (G[id].size() == 1 && fr >= 0)ch[id]++;
	};
	dfs(0, -1);
	//rep(i, n)cout << ws[i] << "\n";
	ll sum = 0;
	priority_queue<LP> q;

	vector<ll> ss[2];
	rep1(cost, 2) {
		sum = 0;
		rep1(i, n - 1) {
			if (cs[i] == cost) {
				sum += (ll)ch[i] * ws[i];
				ll dec = (ws[i] + 1) / 2; dec *= ch[i];
				q.push({ dec,i });
			}
		}
		ss[cost - 1].push_back(sum);
		while (sum>0) {
			//cout << "? " << cost << " " << sum << "\n";
			
			LP p = q.top(); q.pop();
			//cout << "e? " << p.first << " " << p.second << "\n";
			sum -= p.first; ss[cost - 1].push_back(sum);
			int id = p.second;
			ws[id] /= 2;
			ll dec = (ws[id] + 1) / 2; dec *= ch[id];
			q.push({ dec,id });
		}
		while (!q.empty())q.pop();
	}
	int ri = ss[1].size()-1;
	int ans = mod;
	rep(i, ss[0].size()) {
		//if (ss[0][i] > s)break;
		while (ri>0&&ss[0][i] + ss[1][ri-1] <= s)ri--;
		if(ss[0][i]+ss[1][ri]<=s)ans = min(ans, i + ri * 2);
	}
	cout << ans << "\n";
}






signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}