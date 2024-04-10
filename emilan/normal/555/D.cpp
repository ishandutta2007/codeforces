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

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> a(n), idx(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = i;
    }
    vt<int> sa(a);
    sort(all(sa));

    for (int i = 0; i < n; i++) {
        idx[m[sa[i]]] = i;
    }

    while (q--) {
        int i, x;
        cin >> i >> x;
        i = idx[i - 1];

        int ri = upper_bound(
            sa.begin() + i,
            sa.end(),
            sa[i] + x
        ) - sa.begin() - 1;
        x -= sa[ri] - sa[i];

        int li = lower_bound(
            sa.begin(),
            sa.begin() + ri + 1,
            sa[ri] - x
        ) - sa.begin();
        x -= sa[ri] - sa[li];

        while (li < ri) {
            int d = sa[ri] - sa[li];
            int p = x / d & 1;
            x %= d;

            if (!p) {
                ri = upper_bound(
                    sa.begin() + li,
                    sa.begin() + ri + 1,
                    sa[li] + x
                ) - sa.begin() - 1;
                x -= sa[ri] - sa[li];
            }

            li = lower_bound(
                sa.begin() + li,
                sa.begin() + ri + 1,
                sa[ri] - x
            ) - sa.begin();
            x -= sa[ri] - sa[li];
        }

        cout << m[sa[li]] + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}