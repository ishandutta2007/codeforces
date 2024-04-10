#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}

int const N = 55;

int dp[N][N][N];

struct {
    int l, r, x, c;

    void read() {
        cin >> l >> r >> x >> c;
        l--, r--;
    }
} qs[N];

void run() {
    int n, h, m;
    cin >> n >> h >> m;
    for (int i = 0; i < m; i++) {
        qs[i].read();
    }
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            for (int hh = 0; hh <= h; hh++) {
                for (int where = l; where <= r; where++) {
                    int to_relax = hh * hh;
                    for (int q = 0; q < m; q++) {
                        if (l <= qs[q].l && qs[q].l <= where && where <= qs[q].r && qs[q].r <= r && hh > qs[q].x) {
                            to_relax -= qs[q].c;
                        }
                    }
                    if (where != l) {
                        to_relax += dp[l][where - 1][hh];
                    }
                    if (where != r) {
                        to_relax += dp[where + 1][r][hh];
                    }
                    dp[l][r][hh] = max(dp[l][r][hh], to_relax);
                }
                if (hh != 0) {
                	dp[l][r][hh] = max(dp[l][r][hh], dp[l][r][hh - 1]);
                }
            }
        }
    }
    cout << dp[0][n - 1][h] << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(10); cout << fixed;
    int tests = 1;
    // cin >> tests;
    while (tests--) {
        run();
    }
    cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s.\n";
    return 0;
}