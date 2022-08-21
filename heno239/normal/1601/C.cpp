#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
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
modint operator/=(modint& a, modint b) { a = a / b; return a; }
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll x, ll y) {
	x = abs(x), y = abs(y);
	if (x < y)swap(x, y);
	while (y) {
		ll r = x % y; x = y; y = r;
	}
	return x;
}

struct BIT {
private:
    vector<ll> node; int n;
public:
    BIT(int n_) {
        n = n_; node.resize(n, 0);
    }
    //0-indexed
    void add(int a, ll w) {
        for (int i = a; i < n; i |= i + 1)node[i] += w;
    }
    //[0,a)
    ll sum(int a) {
        ll ret = 0;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
        return ret;
    }
    //[a,b)
    ll sum(int a, int b) {
        return sum(b) - sum(a);
    }
};

/**
 * @brief Slope-Trick
 * @docs docs/slope-trick.md
 * @see https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
 */
template< typename T >
struct SlopeTrick {

    const T INF = numeric_limits< T >::max() / 3;

    T min_f;
    priority_queue< T, vector< T >, less<> > L;
    priority_queue< T, vector< T >, greater<> > R;
    T add_l, add_r;

    void push_R(const T& a) {
        R.push(a - add_r);
    }

    T top_R() const {
        if (R.empty()) return INF;
        else return R.top() + add_r;
    }

    T pop_R() {
        T val = top_R();
        if (not R.empty()) R.pop();
        return val;
    }

    void push_L(const T& a) {
        L.push(a - add_l);
    }

    T top_L() const {
        if (L.empty()) return -INF;
        else return L.top() + add_l;
    }

    T pop_L() {
        T val = top_L();
        if (not L.empty()) L.pop();
        return val;
    }

    size_t size() {
        return L.size() + R.size();
    }

    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}

    struct Query {
        T lx, rx, min_f;
    };

    // return min f(x)
    /*Query query() const {
        return (Query) { top_L(), top_R(), min_f };
    }*/

    // f(x) += a
    void add_all(const T& a) {
        min_f += a;
    }

    // add \_
    // f(x) += max(a - x, 0)
    void add_a_minus_x(const T& a) {
        min_f += max(T(0), a - top_R());
        push_R(a);
        push_L(pop_R());
    }

    // add _/
    // f(x) += max(x - a, 0)
    void add_x_minus_a(const T& a) {
        min_f += max(T(0), top_L() - a);
        push_L(a);
        push_R(pop_L());
    }

    // add \/
    // f(x) += abs(x - a)
    void add_abs(const T& a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }

    // \/ -> \_
    // f_{new} (x) = min f(y) (y <= x)
    void clear_right() {
        while (not R.empty()) R.pop();
    }

    // \/ -> _/
    // f_{new} (x) = min f(y) (y >= x)
    void clear_left() {
        while (not L.empty()) L.pop();
    }

    // \/ -> \_/
    // f_{new} (x) = min f(y) (x-b <= y <= x-a)
    void shift(const T& a, const T& b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }

    // \/. -> .\/
    // f_{new} (x) = f(x - a)
    void shift(const T& a) {
        shift(a, a);
    }

    // L, R 
    T get(const T& x) {
        T ret = min_f;
        while (not L.empty()) {
            ret += max(T(0), pop_L() - x);
        }
        while (not R.empty()) {
            ret += max(T(0), x - pop_R());
        }
        return ret;
    }

    void merge(SlopeTrick& st) {
        if (st.size() > size()) {
            swap(st.L, L);
            swap(st.R, R);
            swap(st.add_l, add_l);
            swap(st.add_r, add_r);
            swap(st.min_f, min_f);
        }
        while (not st.R.empty()) {
            add_x_minus_a(st.pop_R());
        }
        while (not st.L.empty()) {
            add_a_minus_x(st.pop_L());
        }
        min_f += st.min_f;
    }
};


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<int> b(m);
    rep(i, m)cin >> b[i];
    sort(all(b));
    SlopeTrick<ll> st;
    rep(i, n) {
        int cl = lower_bound(all(b), a[i]) - b.begin();
        int cr = upper_bound(all(b), a[i]) - b.begin();
        st.add_a_minus_x(cl);
        st.add_x_minus_a(cr);
        st.clear_right();
    }
    ll ans = st.min_f;
    //cout << ans << "\n";
    vector<int> va = a;
    sort(all(va)); va.erase(unique(all(va)), va.end());
    BIT bt(va.size());
    rep(i, n) {
        int loc = lower_bound(all(va), a[i]) - va.begin();
        ans += bt.sum(loc+1, va.size());
        bt.add(loc, 1);
    }
    cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init_f();
	//init();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}