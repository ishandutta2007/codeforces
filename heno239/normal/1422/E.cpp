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

const int max_n = 1 << 2;
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

struct ste {
	char c;
	int l, r;
	char pro;
};
void solve() {
	string s; cin >> s;
	int n = s.size();
	vector<int> num(n);
	vector<string> out(n);
	int sum = 0;
	deque<ste> deq;
	per(i, n) {
		if (deq.empty()) {
			deq.push_front({ s[i],i,i,'a' - 1 });
			sum++;
		}
		else {
			if (deq.front().c == s[i] && deq.front().l == i + 1) {
				deq.front().l = i;
				sum++;
			}
			else {
				ste cur = { s[i],i,i };
				if (deq.front().c == s[i]) {
					cur.pro = deq.front().pro;
				}
				else {
					cur.pro = deq.front().c;
				}
				deq.push_front(cur);
				sum++;
			}
			if (deq.size() >= 2) {
				ste sl = deq.front(); deq.pop_front();
				ste sr = deq.front(); deq.pop_front();
				bool erb = false;
				if (sl.c > sr.c) {
					erb = true;
				}
				else if (sl.c == sr.c) {
					if (sl.c > sl.pro)erb = true;
				}
				if (erb) {
					int len = sl.r - sl.l + 1;
					int to = len % 2;
					sum -= len - to;
					sl.r = sl.l + to - 1;
				}
				deq.push_front(sr);
				if (sl.l <= sl.r)deq.push_front(sl);
			}
			if (deq.size() == 1) {
				ste s = deq.front(); deq.pop_front();
				int len = s.r - s.l + 1;
				sum %= 2; len %= 2;
				s.r = s.l + len - 1;
				if (s.l <= s.r)deq.push_front(s);
			}
		}
		num[i] = sum;
		if (sum > 10) {
			string pr;
			vector<ste> memo;
			int rest = 5;
			while (rest > 0) {
				ste s = deq.front(); deq.pop_front();
				memo.push_back(s);
				int mi = min(rest, s.r - s.l + 1);
				rep(aa, mi)pr.push_back(s.c);
				rest -= mi;
			}
			while (memo.size()) {
				deq.push_front(memo.back()); memo.pop_back();
			}
			string las;
			rest = 2;
			while (rest > 0) {
				ste s = deq.back(); deq.pop_back();
				memo.push_back(s);
				int mi = min(rest, s.r - s.l + 1);
				rep(aa, mi)las.push_back(s.c);
				rest -= mi;
			}
			while (memo.size()) {
				deq.push_back(memo.back()); memo.pop_back();
			}
			reverse(all(las));
			out[i] = pr + "..." + las;
		}
		else {
			string pr;
			vector<ste> memo;
			int rest = sum;
			while (rest>0) {
				ste s = deq.front(); deq.pop_front();
				memo.push_back(s);
				int mi = min(rest, s.r - s.l + 1);
				rep(aa, mi)pr.push_back(s.c);
				rest -= mi;
			}
			while (memo.size()) {
				deq.push_front(memo.back()); memo.pop_back();
			}
			out[i] = pr;
		}
	}


	rep(i, n) {
		cout << num[i] << " " << out[i] << "\n";
	}
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