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

const int maxn = 1e5 + 5;
pii st[maxn << 1];

pii Merge(pii x, pii y) {
    if (x.fi == y.fi) return {x.fi, x.se + y.se};
    if (x.fi > y.fi) swap(x, y);
    if (x.fi == 0) return y;

    int g = gcd(x.fi, y.fi);
    if (g == x.fi) return x;

    return {g, 0};
}

int query(int l, int r) {
    pii ret;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = Merge(ret, st[l++]);
        if (r & 1) ret = Merge(ret, st[--r]);
    }

    return ret.se;
}

void solve() {
    int n;
    cin >> n;
    for (int i = maxn; i < maxn + n; i++) {
        cin >> st[i].fi;
        st[i].se = 1;
    }

    for (int i = maxn - 1; i; i--) {
        st[i] = Merge(st[i << 1], st[i << 1 | 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << r - l + 1 - query(l - 1, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}