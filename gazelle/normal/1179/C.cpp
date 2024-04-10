#include<bits/stdc++.h>
#define FOR(i, n, m) for(int i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 1000000007;
constexpr long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	REP(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}

struct modint {
	ll n;
public:
	modint(const ll n = 0) : n((n % mod + mod) % mod) {}
	static modint pow(modint a, ll m) {
		// static vector<modint> v(1000010, -1);
		// if(m == mod - 2 && v[a.n] != -1) return v[a.n];
		// int tmp = a.n;
		modint r = 1;
		while(m > 0) {
			if(m & 1) { r *= a; }
			a = (a * a); m /= 2;
		}
		// if(m == mod - 2) return v[tmp] = r;
		return r;
	}
	modint &operator++() { *this += 1; return *this; }
	modint &operator--() { *this -= 1; return *this; }
	modint operator++(int) { modint ret = *this; *this += 1; return ret; }
	modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
	modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
	friend bool operator==(const modint& lhs, const modint& rhs) {
		return lhs.n == rhs.n;
	}
	friend bool operator<(const modint& lhs, const modint& rhs) {
		return lhs.n < rhs.n;
	}
	friend bool operator>(const modint& lhs, const modint& rhs) {
		return lhs.n > rhs.n;
	}
	friend modint &operator+=(modint& lhs, const modint& rhs) {
		lhs.n += rhs.n;
		if (lhs.n >= mod) lhs.n -= mod;
		return lhs;
	}
	friend modint &operator-=(modint& lhs, const modint& rhs) {
		lhs.n -= rhs.n;
		if (lhs.n < 0) lhs.n += mod;
		return lhs;
	}
	friend modint &operator*=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * rhs.n) % mod;
		return lhs;
	}
	friend modint &operator/=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * (~rhs).n) % mod;
		return lhs;
	}
	friend modint operator+(const modint& lhs, const modint& rhs) {
		return modint(lhs.n + rhs.n);
	}
	friend modint operator-(const modint& lhs, const modint& rhs) {
		return modint(lhs.n - rhs.n);
	}
	friend modint operator*(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * rhs.n);
	}
	friend modint operator/(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * (~rhs).n);
	}
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }

struct binomial_coefficient {
private:
	int m;
	vector<modint> fact;
public:
	binomial_coefficient(int m) : m(m) {
		fact.resize(m);
		fact[0] = 1;
		for(int i = 1; i < m; i++) fact[i] = fact[i - 1] * i;
	}
	modint comb(int n, int k) {
		if(n < 0 || k < 0 || n < k) return 0;
		return fact[n] / fact[n - k] / fact[k];
	}
};

using mi = modint;

static const int MAX_SIZE = 1 << 20;

typedef long long Int;
Int segMin[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

void add(int a, int b, int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return;
	if (a <= l && r <= b){
		segAdd[k] += x;
		return;
	}
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

Int getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return (LLONG_MAX);
	if (a <= l && r <= b) return (segMin[k] + segAdd[k]);
	Int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
	Int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
	return (min(left, right) + segAdd[k]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	REP(i, n) cin >> a[i];
	REP(i, m) cin >> b[i];
	REP(i, n) {
		add(0, a[i] + 1, -1);
	}
	REP(i, m) {
		add(0, b[i] + 1, 1);
	}
	int q;
	cin >> q;
	REP(query, q) {
		int ty, i, x;
		cin >> ty >> i >> x;
		i--;
		if(ty == 1) {
			add(0, a[i] + 1, 1);
			a[i] = x;
			add(0, a[i] + 1, -1);
		} else {
			add(0, b[i] + 1, -1);
			b[i] = x;
			add(0, b[i] + 1, 1);
		}
		int ok = 0, ng = 1010100;
		while(abs(ok - ng) > 1) {
			int med = (ok + ng) / 2;
			if(getMin(med, 1010100) < 0) ok = med;
			else ng = med;
		}
		if(ok == 0) cout << -1 << "\n";
		else cout << ok << "\n";
	}
	return 0;
}
// ---------------------------------------