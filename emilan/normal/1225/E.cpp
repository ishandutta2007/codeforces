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
class PrefixSum2D {
  public:
    PrefixSum2D() {}

    template <class array2d_t>
    PrefixSum2D(const array2d_t &a)
        : n_(int(size(a))), m_(int(size(a[0]))),
          a_(n_ + 1, vector<T>(m_ + 1)) {

        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                a_[i + 1][j + 1] = a[i][j]
                    + a_[i][j + 1] + a_[i + 1][j] - a_[i][j];
            }
        }
    }

    T query(int x1, int y1, int x2, int y2) const {
        return a_[x2][y2] - a_[x2][y1] - a_[x1][y2] + a_[x1][y1];
    }

  private:
    int n_, m_;
    vector<vector<T>> a_;
};

const int kMod = 1e9 + 7;

void mod_add(int &x, int y) {
    x = (x + y) % kMod;
}

int solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) return 1;
    vector a(n, vector<bool>(m));
    for (auto &v : a) {
        for (auto x : v) {
            char c;
            cin >> c;
            x = c == 'R';
        }
    }

    PrefixSum2D<int> pre2d(a);

    vector diff_row(n, vector<int>(m + 1));
    vector diff_col(n + 1, vector<int>(m));
    vector row(n, vector<int>(m));
    vector col(n, vector<int>(m));

    diff_row[0][0] = 1;
    diff_row[0][1] = -1;
    diff_col[0][0] = 1;
    diff_col[1][0] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mod_add(row[i][j], (j > 0 ? row[i][j - 1] : 0) + diff_row[i][j]);
            mod_add(col[i][j], (i > 0 ? col[i - 1][j] : 0) + diff_col[i][j]);

            int row_rocks = pre2d.query(i, j + 1, i + 1, m);
            mod_add(diff_row[i][j + 1], col[i][j]);
            mod_add(diff_row[i][m - row_rocks], kMod - col[i][j]);

            int col_rocks = pre2d.query(i + 1, j, n, j + 1);
            mod_add(diff_col[i + 1][j], row[i][j]);
            mod_add(diff_col[n - col_rocks][j], kMod - row[i][j]);
        }
    }

    return (row[n - 1][m - 1] + col[n - 1][m - 1]) % kMod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << '\n';
}