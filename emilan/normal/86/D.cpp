#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kS = 450;
const int kA = 1e6 + 1;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<array<int, 3>> tasks(q);
    for (int i = 0; i < q; i++) {
        auto &[l, r, j] = tasks[i];
        cin >> l >> r;
        l--;
        j = i;
    }

    sort(ALL(tasks), [](auto x, auto y) {
        if (x[0] / kS != y[0] / kS) return x[0] < y[0];
        else if ((x[0] / kS) & 1) return x[1] > y[1];
        else return x[1] < y[1];
    });

    ll pw = 0;
    array<int, kA> freq = {};
    auto add = [&](int i) {
        int x = a[i];
        pw += ll(x) * (2 * freq[x] + 1);
        freq[x]++;
    };
    auto rm = [&](int i) {
        int x = a[i];
        freq[x]--;
        pw -= ll(x) * (2 * freq[x] + 1);
    };

    vector<ll> ans(q);
    int l = 0, r = 0;
    for (auto [tl, tr, i] : tasks) {
        while (l > tl) add(--l);
        while (r < tr) add(r++);
        while (l < tl) rm(l++);
        while (r > tr) rm(--r);

        ans[i] = pw;
    }

    for (ll x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}