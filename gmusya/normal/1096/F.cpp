#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll BinPow(ll a, ll p) {
    if (!p) {
        return 1;
    }
    if (p & 1) {
        return BinPow(a, p - 1) * a % MOD;
    } else {
        ll tmp = BinPow(a, p / 2);
        return tmp * tmp % MOD;
    }
}

ll Inv(ll a) {
    return BinPow(a, MOD - 2);
}

ll Frac(ll a, ll b) {
    return a * Inv(b) % MOD;
}

struct FenwickTree {
    int n;
    vector<int> t;
    explicit FenwickTree(int _n) {
        n = _n;
        t.resize(n);
    }
    void Upd(int pos, int val) {
        while (pos < n) {
            t[pos] += val;
            pos |= pos + 1;
        }
    }
    int Get(int pos) {
        int result = 0;
        while (pos != -1) {
            result += t[pos];
            pos &= pos + 1;
            pos--;
        }
        return result;
    }
};

struct Rational {
    ll a;
    ll b;

    Rational(ll x, ll y) {
        a = x;
        b = y;
    }

    Rational operator+(const Rational& other) const {
        ll res_a = a * other.b + b * other.a;
        ll res_b = b * other.b;
        res_a %= MOD;
        res_b %= MOD;
        return Rational(res_a, res_b);
    }

    Rational operator-(const Rational& other) const {
        ll res_a = a * other.b - b * other.a;
        ll res_b = b * other.b;
        res_a %= MOD;
        res_b %= MOD;
        return Rational(res_a, res_b);
    }

    Rational operator*(const Rational& other) const {
        ll res_a = a * other.a;
        ll res_b = b * other.b;
        res_a %= MOD;
        res_b %= MOD;
        return Rational(res_a, res_b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] != -1) {
            --p[i];
        }
    }
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            used[p[i]] = true;
        }
    }
    vector<int> unused;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            unused.push_back(i);
        }
    }
    int before = 0;
    int after = (int) unused.size();
    int all = after;
    Rational ans = Rational(0, 1);
    for (int i = 0; i < n; ++i) {
        if (p[i] == -1) {
            --after;
            ans = ans + Rational(1, 2) * Rational(before, 1);
            ++before;
        } else {
            int lower_unused = (int) (lower_bound(unused.begin(), unused.end(), p[i]) - unused.begin());
            int bigger_unused = all - lower_unused;
            ans = ans + Rational(before, 1) * Rational(bigger_unused, all);
            ans = ans + Rational(after, 1) * Rational(lower_unused, all);
        }
    }
    FenwickTree fenwick_tree(n);
    ll kek = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            kek += fenwick_tree.Get(n - 1) - fenwick_tree.Get(p[i]);
            fenwick_tree.Upd(p[i], 1);
        }
    }
    kek %= MOD;
    if (all == 0) {
        cout << kek;
        return 0;
    }
    ans = ans + Rational(kek, 1);
    cout << (ans.a * Inv(ans.b) % MOD + MOD) % MOD;
    return 0;
}