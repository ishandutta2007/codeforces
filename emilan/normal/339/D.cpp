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

int st[1 << 18];
int n;

void pull(int i) {
    if ((__lg(n) ^ __lg(i)) & 1) st[i] = st[i << 1] | st[i << 1 | 1];
    else st[i] = st[i << 1] ^ st[i << 1 | 1];
}

void update(int i, int v) {
    for (st[i += n] = v; i >>= 1;) pull(i);
}

void solve() {
    int q;
    cin >> n >> q;
    n = 1 << n;

    for (int i = n; i < n << 1; i++) cin >> st[i];
    for (int i = n - 1; i; i--) pull(i);

    while (q--) {
        int i, v;
        cin >> i >> v;

        update(--i, v);
        cout << st[1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}