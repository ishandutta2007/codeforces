#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

template <typename T>
class SparseTable {
  public:
    template <class rand_iter_t>
    SparseTable(rand_iter_t it_begin, rand_iter_t it_end)
        : n_(int(it_end - it_begin)) {
        assert(n_ <= 1 << kK_);
        a_[0].resize(n_);
        copy(it_begin, it_end, begin(a_[0]));
        for (int k = 0; k < kK_ - 1; k++) {
            int m = n_ - (2 << k) + 1;
            if (m <= 0) return;
            a_[k + 1].resize(m);
            for (int i = 0; i < m; i++) {
                a_[k + 1][i] = max(a_[k][i], a_[k][i + (1 << k)]);
            }
        }
    }

    template <typename U>
    SparseTable(const vector<U> &a) : SparseTable(begin(a), end(a)) {}

    // range: [l, r)
    T query(int l, int r) const {
        assert(l <= r);
        if (l == r) return numeric_limits<T>::min();
        int k = l + 1 == r ? 0 : __lg(r - l - 1);
        return max(a_[k][l], a_[k][r - (1 << k)]);
    }

  private:
    static constexpr inline int kK_ = 30;

    int n_;
    array<vector<T>, kK_> a_;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> idx(n + 1);
    for (int i = 0; i < n; i++) idx[a[i]] = i;

    SparseTable<int> spt(a);

    int ans = 0;
    auto dnc = [&](auto &self, int l, int r) -> void {
        if (l + 2 >= r) return;

        int m = idx[spt.query(l, r)];

        if (m - l < r - (m + 1)) {
            for (int i = l; i < m; i++) {
                if (int j = idx[a[m] - a[i]]; m + 1 <= j && j < r) ans++;
            }
        } else {
            for (int i = m + 1; i < r; i++) {
                if (int j = idx[a[m] - a[i]]; l <= j && j < m) ans++;
            }
        }

        self(self, l, m);
        self(self, m + 1, r);
    };
    dnc(dnc, 0, n);

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}