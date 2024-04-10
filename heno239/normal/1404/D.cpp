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
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}


void solve() {
	int n; cin >> n;
	if (n % 2 == 0) {
		int cop = n;
		int tmp = 0;
		while (cop % 2 == 0) {
			tmp++; cop /= 2;
		}
		int s = (1 << tmp);
		cout << "First" << endl;
		vector<P> v;
		rep(i, 2*n / (2*s)) {
			rep(j, s) {
				v.push_back({ i * 2*s + 1 + j,i *2* s + 1 + j +s });
			}
		}
		//for (P p : v)cout << p.first << " " << p.second << endl;
		vector<int> ans(2*n+1);
		rep(j, v.size()) {
			ans[v[j].first] = ans[v[j].second] = j + 1;
		}
		rep1(i, 2 * n) {
			if (i > 1)cout << " ";
			cout << ans[i];
		}
		cout << endl;
		int res; cin >> res; return;
	}
	else {
		cout << "Second" << endl;
		vector<vector<int>> b(n, vector<int>(2,-1));
		vector<int>p(2 * n+1);
		rep1(i, 2 * n)cin >> p[i];
		p[0] = p[2 * n];
		rep(i, 2 * n) {
			p[i]--;
			if (b[p[i]][0] < 0) {
				b[p[i]][0] = i;
			}
			else b[p[i]][1] = i;
		}
		vector<bool> used(n, false);
		vector<vector<int>> vl, vr;
		vector<int> cl, cr;
		rep(i, n) {
			if (used[i])continue;
			int cur = i;
			vector<int> ls, rs;
			while (true) {
				int to = b[p[cur]][0] ^ b[p[cur]][1] ^ cur;
				ls.push_back(cur);
				rs.push_back(to);
				if (to == i + n) {
					used[i] = true; break;
				}
				cur = (to + n) % (2 * n);
				used[cur % n] = true;
			}
			int c0 = 0, c1 = 0;
			for (int id : ls)if (id >= n)c0++;
			for (int id : rs)if (id >= n)c1++;
			cl.push_back(c0); cr.push_back(c1);
			vl.push_back(ls); vr.push_back(rs);
		}
		//cout << cl[0] << " " << cr[0] << "\n";
		int chk = -1;
		rep(i, cl.size())if ((cl[i] + cr[i]) % 2)chk = i;
		vector<int> ans;
		int tmp = 0;
		rep(i, cl.size())if (i != chk) {
			for (int id : vl[i])ans.push_back(id);
			tmp += cl[i];
		}
		if ((tmp + cl[chk]) % 2 == (n/2) % 2) {
			for (int id : vl[chk])ans.push_back(id);
		}
		else {
			for (int id : vr[chk])ans.push_back(id);
		}
		rep(i, ans.size())if (ans[i] == 0)ans[i] = 2 * n;
		sort(all(ans));
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}

}

signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}