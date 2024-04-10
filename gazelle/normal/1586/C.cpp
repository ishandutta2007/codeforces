#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using li = long long;
using ld = long double;
using P = pair<li, li>;
constexpr li inf = 1000000000;
constexpr li mod = 998244353;
constexpr ld eps = 1e-6;
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, v.size()) {
        if(i) os << " ";
        os << v[i];
    }
    return os;
}

struct modint {
    li n;
public:
    modint(const li n = 0) : n((n % mod + mod) % mod) {}
    static modint pow(modint a, int m) {
        modint r = 1;
        while(m > 0) {
            if(m & 1) { r *= a; }
            a = (a * a); m /= 2;
        }

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

using mi = modint;

li mod_pow(__int128 a, __int128 n, __int128 m = mod) {
    using li = __int128;
    li ret = 1;
    li tmp = a;
    while(n > 0) {
        if(n % 2) ret *= tmp;
        ret %= m;
        tmp = tmp * tmp;
        tmp %= m;
        n /= 2;
    }
    return ret % m;
}

constexpr int MAX_N = 2020202;
mi mod_fact  [MAX_N + 1];
mi mod_fact_i[MAX_N + 1];
mi mod_comb(long long n, long long k) {
    static bool initialized = false;
    if(n < 0 || k < 0 || n < k) return 0;
    if(not initialized) {
        mod_fact[0] = 1;
        for(int i = 1; i <= MAX_N; ++i) {
            mod_fact[i] = i * mod_fact[i - 1];
        }
        mod_fact_i[MAX_N] = mod_pow(mod_fact[MAX_N].n, mod - 2);
        for(int i = MAX_N - 1; i >= 0; --i) {
            mod_fact_i[i] = mod_fact_i[i + 1] * (i + 1);
        }
        initialized = true;
    }
    return mod_fact[n] * mod_fact_i[n - k] * mod_fact_i[k];
}

struct union_find {
    union_find(int n) : par_(n, -1) {}
    void init(int n) { par_.assign(n, -1); }
    int root(int x) { return par_[x] < 0 ? x : par_[x] = root(par_[x]); }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par_[x] < par_[y]) {
            par_[x] += par_[y];
            par_[y] = x;
        } else {
            par_[y] += par_[x];
            par_[x] = y;
        }
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par_[root(x)]; }
    vector<int> par_;
};
 
li gcd(li a, li b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

li lcm(li a, li b) {
    li g = gcd(a, b);
    return a / g * b;
}

li N = 202020;
li bit[202020];
void add(li a, li w) {
    a++;
    for (li x = a; x <= N; x += x & -x) bit[x] += w;
}
li sum(li a) {
    a++;
    li ret = 0;
    for (li x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}
// return the sum between [a, b)
li sum(li a, li b) {
    li ret = 0;
    if(b == 0) return 0;
    ret += sum(b - 1);
    if(a) ret -= sum(a - 1);
    return ret;
}

template <typename T> struct segment_tree {
private:
	int n;
	const function<T(T, T)> op;
	const T ie;
	vector<T> seq;

public:
	segment_tree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
		n = 1;
		while(n < _n) n *= 2;
		seq.resize(2 * n - 1);
		for(int i = 0; i < 2 * n - 1; i++) seq[i] = ie;
	}

	void update(int k, const T e) {
		k += n - 1;
		seq[k] = e;
		while(k > 0) {
			k = (k - 1) / 2;
			seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
		}
	}

	T get(int k) {
		k += n - 1;
		return seq[k];
	}

	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if(r == -1) r = n;
		if(r <= a || b <= l) return ie;
		if(a <= l && r <= b) return seq[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
};
// segment_tree<ll> rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// segment_tree<ll> rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// segment_tree<ll> rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    REP(i, n) cin >> g[i];

    vector<vector<int>> exit_col(n, vector<int>(m, -1));
    vector<vector<int>> non_det(n, vector<int>(m, -1));
    vector<vector<int>> reach_col(n, vector<int>(m, 0));

    segment_tree<int> rMq(m, [] (int a, int b) { return max(a, b); }, -1e9);

    REP(i, n) REP(j, m) {
        if(g[i][j] == 'X') {
            exit_col[i][j] = -1;
            reach_col[i][j] = j + 1;
        } else {
            if(i == 0 || j == 0) exit_col[i][j] = j;
            if(i > 0) exit_col[i][j] = max(exit_col[i][j], exit_col[i - 1][j]);
            if(j > 0) exit_col[i][j] = max(exit_col[i][j], exit_col[i][j - 1]);

            reach_col[i][j] = j;
            if(i > 0) reach_col[i][j] = min(reach_col[i][j], reach_col[i - 1][j]);
            if(j > 0) reach_col[i][j] = min(reach_col[i][j], reach_col[i][j - 1]);

        }
        if(i > 0 && j > 0) {
            if(exit_col[i - 1][j] != -1 || exit_col[i][j - 1] != -1) {
                non_det[i][j] = -1;
            } else {
                non_det[i][j] = min(reach_col[i - 1][j], reach_col[i][j - 1]);
            }
            if(i > 1) non_det[i][j] = max(non_det[i][j], non_det[i - 1][j]);
        }
        if(i == n - 1) {
            // cout << j << " " << non_det[i][j] << endl;
            rMq.update(j, non_det[i][j]);
        }
    }

    int q;
    cin >> q;

    REP(i, q) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--;
        x2--;
        int th = rMq.query(x1, x2 + 1);
        if(x1 < th) cout << "NO" << "\n";
        else        cout << "YES" << "\n";
    }

    return 0;
}