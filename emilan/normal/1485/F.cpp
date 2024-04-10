#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
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

const ll kMod = 1e9 + 7;

struct Fenwick {
    int n;
    vector<ll> a;

    Fenwick(int p_n) : n(p_n), a(n + 1) {}

    ll query0(int i) {
        ll r = 0;
        for (i++; i > 0; i -= i & -i) r += a[i];
        return r % kMod;
    }

    ll query(int l, int r) {
        return (query0(r - 1) - query0(l - 1) + kMod) % kMod;
    }

    void update(int i, ll d) {
        d %= kMod;
        if (d < 0) d += kMod;
        for (i++; i <= n; i += i & -i) a[i] = (a[i] + d) % kMod;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b) cin >> x;

    vector<ll> b_pre(n + 1);
    partial_sum(ALL(b), begin(b_pre) + 1);

    map<ll, vector<int>> b_pre_pos;
    map<ll, int> ptr;
    for (int i = 0; i <= n; i++) {
        b_pre_pos[b_pre[i]].push_back(i);
    }
    ptr[0] = 1;

    Fenwick ft(n);
    ft.update(0, 1);
    for (int i = 1; i < n; i++) {
        ft.update(i, ft.query(0, i));

        int &p = ptr[b_pre[i]];
        if (p > 0) {
            int q = b_pre_pos[b_pre[i]][p - 1];
            ft.update(q, -ft.query(q, q + 1));
        }
        p++;
    }
    cout << ft.query(0, n) << '\n';
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