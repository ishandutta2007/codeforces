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

void chmin(int &a, int b) {
	a = min(a, b);
}
void chmax(int &a, int b) {
	a = max(a, b);
}
ll mod_pow(ll a, ll n, ll m = mod) {
	a %= m;
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
const int max_n = 10001000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

ll calc(string &s) {
	ll t = 1;
	ll res = 0;
	rep(i, s.size()) {
		res += t * (s[i] - 'a' + 1);
		t *= 27;
	}
	return res;
}

int dp[1000000];
void solve() {


	string s; cin >> s;
	vector<string> vs;
	vector<ll> ids;
	rep(i, s.size()) {
		i++;
		int le = i;
		while (s[i] != '>')i++;
		vs.push_back(s.substr(le, i - le));
	}


	vector<vector<int>> ch(vs.size() + 1);

	vector<int> par;
	par.push_back(vs.size());
	rep(i, vs.size()) {
		string &x = vs[i];
		if (x[0] == '/') {
			int mem = par.back();
			par.pop_back();
			ch[par.back()].push_back(mem);
		}
		else if (x.back() == '/') {
			ch[par.back()].push_back(i);
			x.pop_back();
		}
		else {
			par.push_back(i);
		}
	}


	rep(i, vs.size()) {
		ids.push_back(calc(vs[i]));
	}
	ids.push_back(-2);

	vector<int> ord;
	queue<int> q;
	q.push(vs.size());
	while (!q.empty()) {
		int id = q.front(); q.pop();
		ord.push_back(id);
		for (int to : ch[id]) {
			q.push(to);
		}
	}

	int n; cin >> n;
	string in; getline(cin, in);
	rep(i, n) {
		getline(cin, in);
		vector<string> qs;


		int le = 0;
		rep(j, in.size()) {
			if (in[j] == ' ') {
				qs.push_back(in.substr(le, j - le));
				le = j + 1;
			}
		}
		qs.push_back(in.substr(le, in.size() - le));

		vector<ll> acs;
		rep(j, qs.size()) {
			acs.push_back(calc(qs[j]));
		}

		//rep(j, qs.size())cout << acs[j] << "\n";
		int ans = 0;
		dp[vs.size()] = 0;
		for (int id : ord) {
			if (ids[id] == acs[dp[id]]) {
				if (dp[id] + 1 == qs.size())ans++;
				else dp[id]++;
			}
			for (int to : ch[id]) {
				dp[to] = dp[id];
			}
		}

		cout << ans << "\n";

	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();

	solve();
	stop
		return 0;
}