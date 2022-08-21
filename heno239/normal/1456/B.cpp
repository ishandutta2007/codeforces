#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
#include<unordered_set>
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
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

const int max_n = 1 << 17;
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

struct Node {
	Node* ch[2];
	vector<int> ids;
	Node() {
		ch[0] = ch[1] = NULL;
	}
};
int s[1 << 17];
void add(Node* nd, int id) {
	per(i, 30) {
		int t = 0;
		if (s[id] & (1 << i)) {
			t = 1;
		}
		if (nd->ch[t] == NULL)nd->ch[t] = new Node();
		nd = nd->ch[t];
		nd->ids.push_back(id);
	}
}
int lef0[1 << 17][30];
int lef1[1 << 17][30];

int ans = mod;
void yaru(Node* nd,int tmp) {
	if (nd->ch[0] == NULL && nd->ch[1] == NULL)return;
	rep(j, 2)if (nd->ch[j] != NULL)yaru(nd->ch[j],tmp-1);
	if (nd->ch[0] != NULL && nd->ch[1] != NULL) {
		vector<int>& vl = nd->ch[0]->ids;
		vector<int>& vr = nd->ch[1]->ids;
		int loc = 0;
		rep(i, vr.size()) {
			while (loc < vl.size() && vl[loc] < lef1[vr[i]][tmp])loc++;
			if (loc > 0)ans = min(ans, vr[i] - vl[loc - 1] - 2);
		}
		loc = 0;
		rep(i, vl.size()) {
			while (loc < vr.size() && vr[loc] < lef0[vl[i]][tmp])loc++;
			if (loc > 0)ans = min(ans, vl[i] - vr[loc - 1] - 2);
		}
	}
}
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	s[0] = 0;
	rep(i, n)s[i + 1] = s[i] ^ a[i];
	Node* nd = new Node();
	rep(i, n + 1)add(nd, i);

	rep(j, 30)lef0[0][j] = lef1[0][j] = -1;
	for (int i = 0; i < n + 1; i++) {
		rep(j, 30) {
			lef0[i + 1][j] = lef0[i][j];
			lef1[i + 1][j] = lef1[i][j];
			if (s[i] & (1 << j)) {
				lef1[i + 1][j] = i;
			}
			else {
				lef0[i + 1][j] = i;
			}
		}
	}
	yaru(nd, 29);
	if (ans == mod)ans = -1;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}