#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

using ull = unsigned long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ull rand_ull() {
    static uniform_int_distribution<ull> dist(0, ULLONG_MAX);
    return dist(rng);
}

struct Bit2d {
    int n, m;
    vector<vector<ull>> a;

    Bit2d(int n_, int m_) : n(n_), m(m_), a(n + 1, vector<ull>(m + 1)) {}

    ull query(int x, int y) {
        ull ans = 0;
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                ans += a[i][j];
            }
        }
        return ans;
    }

    void update0(int x, int y, ull d) {
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                a[i][j] += d;
            }
        }
    }

    void update(int x1, int y1, int x2, int y2, ull d) {
        update0(x1 - 1, y1 - 1, d);
        update0(x1 - 1, y2 - 1, -d);
        update0(x2 - 1, y1 - 1, -d);
        update0(x2 - 1, y2 - 1, d);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector h(n, vector<ull>(m));
    Bit2d bit(n, m);
    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (t == 1) {
            h[x1][y1] = rand_ull();
            bit.update(x1, y1, x2 + 1, y2 + 1, h[x1][y1]);
        } else if (t == 2) {
            bit.update(x1, y1, x2 + 1, y2 + 1, -h[x1][y1]);
        } else if (t == 3) {
            if (bit.query(x1, y1) == bit.query(x2, y2)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}