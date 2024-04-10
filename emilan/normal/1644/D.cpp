#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const ll kMod = 998244353;

ll mod_pow(ll b, int e) {
    ll r = 1;
    for (; e > 0; e /= 2, b = b * b % kMod) {
        if (e & 1) r = r * b % kMod;
    }
    return r;
}

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pii> tasks(q);
    for (auto &[x, y] : tasks) {
        cin >> x >> y;
        x--, y--;
    }

    int cnt = 0;
    vector<bool> row(n), col(m);
    int row_cnt = 0, col_cnt = 0;
    for (auto &[x, y] : vector(RALL(tasks))) {
        if ((row[x] && col[y]) || row_cnt == n || col_cnt == m) continue;

        cnt++;

        if (!row[x]) {
            row[x] = true;
            row_cnt++;
        }

        if (!col[y]) {
            col[y] = true;
            col_cnt++;
        }
    }

    cout << mod_pow(k, cnt) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}