#include <bits/stdc++.h>

using namespace std;

// range-query, point-update version
template <typename T>
class Bit {
  public:
    Bit(int n) : n_(n), a_(n_ + 1) {}

    template <class rand_iter_t>
    Bit(rand_iter_t it_begin, rand_iter_t it_end)
        : n_(int(it_end - it_begin)), a_(n_ + 1) {
        for (int i = 1; i <= n_; i++) {
            a_[i] += it_begin[i - 1];
            if (int j = i + (i & -i); j <= n_) {
                a_[j] += a_[i];
            }
        }
    }

    template <typename U>
    Bit(const vector<U> &a) : Bit(begin(a), end(a)) {}

    // range: [l, r)
    T query(int l, int r) const {
        assert(l <= r);
        return query0_(r - 1) - query0_(l - 1);
    }

    void update(int i, T d) {
        for (i++; i <= n_; i += i & -i) {
            a_[i] += d;
        }
    }

    // binary lift on query(0, i) >= target
    // constraints: a_[i] >= 0 for all i in [0, n_)
    // returns n + 1 if not found
    int first(T target) const {
        if (target <= 0) return 0;
        int i = 0;
        for (int s = __lg(n_); s >= 0; s--) {
            if (int ni = i | (1 << s);
                    ni <= n_ && target > a_[ni]) {
                target -= a_[ni];
                i = ni;
            }
        }
        return i + 1;
    }

  private:
    int n_;
    vector<T> a_;

    T query0_(int i) const {
        T r = 0;
        for (i++; i > 0; i -= i & -i) {
            r += a_[i];
        }
        return r;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    Bit<int> bit(f);
    while (q--) {
        int x;
        cin >> x;
        if (x > 0) bit.update(x, 1);
        else {
            int i = bit.first(-x);
            bit.update(i - 1, -1);
        }
    }

    int i = bit.first(1);
    if (i == n + 2) cout << 0;
    else cout << i - 1;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}