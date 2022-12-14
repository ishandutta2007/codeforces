#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int M = 5e5 + 1;
int s[M], f[M];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vector<int> pri;
    for (int i = 2; i < M; i++) {
        if (s[i] == 0) {
            s[i] = i;
            pri.push_back(i);
        }

        for (int j : pri) {
            if (j > s[i] || i * j >= M) break;
            s[i * j] = j;
        }
    }

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        while (a[i] > 1) {
            d[i].push_back(s[a[i]]);
            a[i] /= s[a[i]];
        }
        d[i].erase(unique(d[i].begin(), d[i].end()), d[i].end());
    }

    vector<int> in(n);

    auto query = [&](int i) -> int {
        int m = d[i].size();
        int ans = 0;
        for (int msk = 0; msk < 1 << m; msk++) {
            int x = 1;
            for (int j = 0; j < m; j++) if (msk >> j & 1) {
                x *= d[i][j];
            }

            if (__builtin_parity(msk)) ans -= f[x];
            else ans += f[x];
        }

        return ans;
    };

    auto update = [&](int i, int v) -> void {
        int m = d[i].size();
        for (int msk = 0; msk < 1 << m; msk++) {
            int x = 1;
            for (int j = 0; j < m; j++) if (msk >> j & 1) {
                x *= d[i][j];
            }

            f[x] += v;
        }
    };

    ll ans = 0;
    while (q--) {
        int i;
        cin >> i;
        i--;

        if (!in[i]) {
            ans += query(i);
            update(i, 1);
        } else {
            update(i, -1);
            ans -= query(i);
        }

        in[i] ^= 1;

        cout << ans << '\n';
    }
}