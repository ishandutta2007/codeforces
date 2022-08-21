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

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % mod;
		x = x * x % mod; n >>= 1;
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


int n, m, k;
vector<int> vt, va, vb;


void solve2(ll ans) {
	set<P> st, sa, sb, sab;

	set<P> rest, resa, resb, resab;

	rep(i, n) {
		int t = vt[i], a = va[i], b = vb[i];
		if (a == 0 && b == 0) {
			rest.insert({ t,i });
		}
		else if (a == 1 && b == 0)resa.insert({ t,i });
		else if (a == 0 && b == 1)resb.insert({ t,i });
		else {
			resab.insert({ t,i });
		}
	}
	ll sum = 0;

	while (resa.size() > k) {
		P val = *resa.rbegin();
		resa.erase(--resa.end());
		rest.insert(val);
	}
	while (resb.size() > k) {
		P val = *resb.rbegin();
		resb.erase(--resb.end());
		rest.insert(val);
	}
	while (resab.size() > k) {
		P val = *resab.rbegin();
		resab.erase(--resab.end());
		rest.insert(val);
	}

	//zero
	while (sa.size() < k && resa.size()) {
		P val = *resa.begin();
		resa.erase(resa.begin());
		sa.insert(val);
		sum += val.first;
	}
	while (sb.size() < k && resb.size()) {
		P val = *resb.begin();
		resb.erase(resb.begin());
		sb.insert(val);
		sum += val.first;
	}
	while (st.size() + sa.size() + sb.size() < m && rest.size()) {
		P val = *rest.begin();
		rest.erase(rest.begin());
		st.insert(val);
		sum += val.first;
	}
	if (st.size() + sa.size() + sb.size() == m && sa.size() == k && sb.size() == k) {
		if (ans == sum) {
			vector<int> vs;
			for (P p : sa)vs.push_back(p.second);
			for (P p : st)vs.push_back(p.second);
			for (P p : sb)vs.push_back(p.second);
			for (P p : sab)vs.push_back(p.second);

			rep(i, vs.size()) {
				if (i > 0)cout << " ";
				cout << vs[i] + 1;
			}
			cout << "\n";
			return;
		}
	}
	rep1(i, k) {
		assert(resa.empty());
		assert(resb.empty());
		if (resab.empty())break;
		P val = *resab.begin();
		sum += val.first;
		resab.erase(resab.begin());
		sab.insert(val);

		while (sa.size() && sa.size() + sab.size() > k) {
			P val = *(--sa.end());
			sa.erase(--sa.end());
			sum -= val.first;
			rest.insert(val);
		}
		while (sb.size() && sb.size() + sab.size() > k) {
			P val = *(--sb.end());
			sb.erase(--sb.end());
			sum -= val.first;
			rest.insert(val);
		}
		while (st.size() + sa.size() + sb.size() + sab.size() < m && rest.size()) {
			P val = *rest.begin();
			sum += val.first;
			st.insert(val);
			rest.erase(rest.begin());
		}
		while (st.size() + sa.size() + sb.size() + sab.size() > m && st.size()) {
			P val = *--st.end();
			sum -= val.first;
			rest.insert(val);
			st.erase(--st.end());
		}

		while (st.size() && rest.size() && ((*--st.end()) > (*rest.begin()))) {
			P valle = *--st.end();
			P valri = *rest.begin();
			sum += valri.first - valle.first;
			st.erase(valle);
			st.insert(valri);

			rest.erase(valri);
			rest.insert(valle);
		}

		if (st.size() + sa.size() + sb.size() + sab.size() == m && sa.size() + sab.size() == k && sb.size() + sab.size() == k) {
			if (ans == sum) {
				vector<int> vs;
				for (P p : sa)vs.push_back(p.second);
				for (P p : st)vs.push_back(p.second);
				for (P p : sb)vs.push_back(p.second);
				for (P p : sab)vs.push_back(p.second);

				rep(j, vs.size()) {
					if (j > 0)cout << " ";
					cout << vs[j] + 1;
				}
				cout << "\n";
				return;
			}
		}
	}
	assert(false);
}
void solve() {
	cin >> n >> m >> k;
	vt.resize(n);
	va.resize(n);
	vb.resize(n);
	rep(i, n) {
		cin >> vt[i] >> va[i] >> vb[i];
	}

	set<P> st, sa, sb, sab;

	set<P> rest, resa, resb, resab;

	rep(i, n) {
		int t = vt[i], a = va[i], b = vb[i];
		if (a == 0 && b == 0) {
			rest.insert({ t,i });
		}
		else if (a == 1 && b == 0)resa.insert({ t,i });
		else if (a == 0 && b == 1)resb.insert({ t,i });
		else {
			resab.insert({ t,i });
		}
	}
	ll sum = 0;
	ll ans = INF;

	while (resa.size() > k) {
		P val = *resa.rbegin();
		resa.erase(--resa.end());
		rest.insert(val);
	}
	while (resb.size() > k) {
		P val = *resb.rbegin();
		resb.erase(--resb.end());
		rest.insert(val);
	}
	while (resab.size() > k) {
		P val = *resab.rbegin();
		resab.erase(--resab.end());
		rest.insert(val);
	}

	//zero
	while (sa.size() < k && resa.size()) {
		P val = *resa.begin();
		resa.erase(resa.begin());
		sa.insert(val);
		sum += val.first;
	}
	while (sb.size() < k && resb.size()) {
		P val = *resb.begin();
		resb.erase(resb.begin());
		sb.insert(val);
		sum += val.first;
	}
	while (st.size() + sa.size() + sb.size() < m && rest.size()) {
		P val = *rest.begin();
		rest.erase(rest.begin());
		st.insert(val);
		sum += val.first;
	}
	if (st.size() + sa.size() + sb.size() == m && sa.size() == k && sb.size() == k) {
		ans = min(ans, sum);
	}
	rep1(i, k) {
		assert(resa.empty());
		assert(resb.empty());
		if (resab.empty())break;
		P val = *resab.begin();
		sum += val.first;
		resab.erase(resab.begin());
		sab.insert(val);

		while (sa.size() && sa.size() + sab.size() > k) {
			P val = *(--sa.end());
			sa.erase(--sa.end());
			sum -= val.first;
			rest.insert(val);
		}
		while (sb.size() && sb.size() + sab.size() > k) {
			P val = *(--sb.end());
			sb.erase(--sb.end());
			sum -= val.first;
			rest.insert(val);
		}
		while (st.size() + sa.size() + sb.size() + sab.size() < m && rest.size()) {
			P val = *rest.begin();
			sum += val.first;
			st.insert(val);
			rest.erase(rest.begin());
		}
		while (st.size() + sa.size() + sb.size() + sab.size() > m && st.size()) {
			P val = *--st.end();
			sum -= val.first;
			rest.insert(val);
			st.erase(--st.end());
		}

		while (st.size() && rest.size() && ((*--st.end()) > (*rest.begin()))) {
			P valle = *--st.end();
			P valri = *rest.begin();
			sum += valri.first - valle.first;
			st.erase(valle);
			st.insert(valri);

			rest.erase(valri);
			rest.insert(valle);
		}

		if (st.size() + sa.size() + sb.size() + sab.size() == m && sa.size() + sab.size() == k && sb.size() + sab.size() == k) {
			ans = min(ans, sum);
		}
	}
	if (ans == INF) {
		cout << -1 << "\n"; return;
	}
	else {
		cout << ans << "\n";
		solve2(ans);
	}
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}