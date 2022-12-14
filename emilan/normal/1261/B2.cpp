#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

vi ft;

int query(int i) {
    int ret = 0;
    while (i) {
        ret += ft[i];
        i -= i & -i;
    }
    return ret;
}

void update(int i) {
    while (i < sz(ft)) {
        ft[i]++;
        i += i & -i;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int m;
    cin >> m;

    vii b(n);
    rep(i, n) b[i] = {a[i], i};

    sort(all(b), [](ii& x, ii& y) {
            if (x.fi > y.fi) return true;
            else if (x.fi == y.fi && x.se < y.se) return true;
            return false;
    });

    vii q(m);
    vector<map<int, int>> ans(n + 1);
    rep(i, m) {
        cin >> q[i].fi >> q[i].se;
        ans[q[i].fi][q[i].se] = 0;
    }

    ft.resize(n + 1);
    rep(i, n) {
        update(b[i].se + 1);

        for (auto& j : ans[i + 1]) {
            int l = 1, r = n;
            while (l < r) {
                int mi = (l + r) / 2;
                if (query(mi) >= j.fi) r = mi;
                else l = mi + 1;
            }
            j.se = a[l - 1];
        }
    }

    for (auto& i : q) {
        cout << ans[i.fi][i.se] << '\n';
    }

    return 0;
}