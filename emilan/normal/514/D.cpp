#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1e5 + 1, maxm = 5, maxk = 18;
int st[maxk][maxn][maxm];

int n, m, K;

vt<int> query(int l, int r) {
    int k = __lg(r - l);
    vt<int> ret(m);
    for (int i = 0; i < m; i++) {
        ret[i] = max(st[k][l][i], st[k][r - (1 << k)][i]);
    }
    return ret;
}

void solve() {
    cin >> n >> m >> K;
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &v : a) {
        for (int &x : v) cin >> x;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[0][i][j] = a[i][j];
        }
    }
    for (int k = 1; k < maxk; k++) {
        for (int i = 0; i <= n - (1 << k); i++) {
            for (int j = 0; j < m; j++) {
                st[k][i][j] = max(
                    st[k - 1][i][j],
                    st[k - 1][i + (1 << (k - 1))][j]
                );
            }
        }
    }

    auto check = [&](int s) {
        for (int i = 0; i <= n - s; i++) {
            vt<int> q(query(i, i + s));
            if (accumulate(all(q), 0) <= K) return q;
        }
        return vt<int>();
    };

    if (check(1).empty()) {
        for (int i = 0; i < m; i++) cout << "0 ";
        return;
    }

    int l = 1, r = n;
    while (l < r) {
        int mi = (l + r + 1) / 2;
        if (!check(mi).empty()) l = mi;
        else r = mi - 1;
    }

    vt<int> ans(check(l));
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}