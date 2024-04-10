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
#include<chrono>
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
modint operator^(modint a, ll n) {
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dp[10001][2];


void solve() {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	vector<int> las(n,n);
	rep(i, n) {
		if(s[i] == '.')continue;
		int c = 1;
		Rep(j, i + 1, n) {
			if (s[j] == '.')c--;
			else c++;
			if (c == 0) {
				las[i] = j; break;
			}
		}
	}

	rep(i, n)dp[i][0] = mod;
	dp[0][0] = 0;
	rep(j, m) {

		int id = j % 2;
		rep(i, n+1)dp[i][id ^ 1] = mod;

		vector<P> st;
		int ad = 0;
		rep(i, n) {
			if (s[i] == '.')ad--;
			else ad++;
			while (st.size() && st.back().second < i)st.pop_back();
			if (s[i] == '.') {
				if (i + 1 < n) {
					dp[i + 1][id] = min(dp[i + 1][id], dp[i][id]+1);
				}
			}
			else {
				if (las[i] + 1 < n) {
					dp[las[i] + 1][id] = min(dp[las[i] + 1][id], dp[i][id]);
				}
				P p = { dp[i][id] - ad,las[i] };
				if (st.empty()||st.back().first > p.first) {
					st.push_back(p);
				}
			}
			if (s[i] == t[j]) {
				if (st.size()) {
					int val = st.back().first + ad;
					dp[i + 1][id ^ 1] = min(dp[i + 1][id ^ 1], val);
				}
			}
		}
		/*cout << "he\n";
		rep(i, n+1) {
			cout << dp[i][id ^ 1] << " ";
		}
		cout << "\n";*/
	}
	int ans = mod;
	rep(i, n + 1) {
		int c = 0;
		int ad = 0;
		Rep(j, i, n) {
			if (s[j] == '.')c--;
			else c++;
			if (c < 0) {
				c = 0; ad++;
			}
		}
		ad += c;
		ans = min(ans, ad + dp[i][m % 2]);
	}
	cout << ans << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	//init_f();
	//init();
	//int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}