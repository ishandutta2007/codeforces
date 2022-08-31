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

const int max_n = 1 << 19;
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

int tp;
//1==+,0==-
vector<P> expr(string &s, int &i);
vector<P> func(string &s, int &i);

vector<P> expr(string &s, int &i) {
	vector<P> res = func(s, i);
	while (i < s.size() && s[i] == '?') {
		i++;
		vector<P> nex = func(s, i);
		vector<P> alt(res.size() + nex.size(), { mod,-mod });
		//+
		rep(x, res.size())rep(y, nex.size()) {
			int z = x + y; if (tp > 0)z++;
			alt[z].first = min(alt[z].first, res[x].first + nex[y].first);
			alt[z].second = max(alt[z].second, res[x].second + nex[y].second);
		}
		//-
		rep(x, res.size())rep(y, nex.size()) {
			int z = x + y; if (tp == 0)z++;
			alt[z].first = min(alt[z].first, res[x].first - nex[y].second);
			alt[z].second = max(alt[z].second, res[x].second - nex[y].first);
		}

		if(alt.size()>101)alt.resize(101);
		swap(res, alt);
	}
	return res;
}
vector<P> func(string &s, int &i) {
	if ('0' <= s[i] && s[i] <= '9') {
		int mem = s[i] - '0';
		i++;
		return { {mem,mem} };
	}
	assert(s[i] == '(');
	i++;
	vector<P> res = expr(s, i);
	i++;
	return res;
}

void solve() {
	string s; int i=0; cin >> s;
	int a, b; cin >> a >> b;
	if (a <= 100)tp = 1;
	if (b <= 100)tp = 0;
	vector<P> res = expr(s, i);
	assert(i == s.size());
	ll ans;
	if (tp == 0) {
		ans = res[b].second;
	}
	else {
		ans = res[a].second;
	}
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}