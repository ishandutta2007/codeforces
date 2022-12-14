#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
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

struct Fenwick {
    int n;
    vector<ll> a;

    Fenwick(int p_n) : n(p_n), a(n + 1) {}

    ll query(int i) {
        ll r = 0;
        for (i++; i <= n; i += i & -i) r += a[i];
        return r;
    }

    void update0(int i, ll d) {
        for (i++; i > 0; i -= i & -i) a[i] += d;
    }

    void update(int l, int r, ll d) {
        update0(l - 1, -d);
        update0(r - 1, d);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    map<int, int> color_left{{0, 0}, {n, -1}};
    vector<ll> color_val(n);
    Fenwick offset(n);
    while (q--) {
        string t;
        cin >> t;
        if (t == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            l--, c--;

            for (int i = l; i < r;) {
                auto it_r = color_left.upper_bound(i);
                auto it_l = prev(it_r);

                int cur_c = it_l->second;
                int j = it_r->first;
                color_left.erase(i);

                offset.update(i, min(j, r), color_val[cur_c] - color_val[c]);
                if (j > r) color_left[r] = cur_c;
                i = j;
            }

            color_left[l] = c;
        } else if (t == "Add") {
            int c, d;
            cin >> c >> d;
            c--;

            color_val[c] += d;
        } else {
            int i;
            cin >> i;
            i--;

            int c = prev(color_left.upper_bound(i))->second;
            cout << offset.query(i) + color_val[c] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}