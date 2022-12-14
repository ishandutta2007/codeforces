#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

struct Gap {
    ll l, r, i;
    bool operator<(const Gap& o) const {
        return r < o.r;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    if (m < n - 1) {
        cout << "No";
        return 0;
    }

    vector<pair<ll, ll>> a(n);
    rep(i, n) cin >> a[i].fi >> a[i].se;
    map<ll, vi> b;
    rep(i, m) {
        ll x;
        cin >> x;
        b[x].pb(i + 1);
    }

    vector<Gap> gaps(n - 1);
    rep(i, n - 1) {
        gaps[i].l = a[i + 1].fi - a[i].se;
        gaps[i].r = a[i + 1].se - a[i].fi;
        gaps[i].i = i;
    }
    sort(all(gaps));

    vi ret(n - 1);
    for (Gap& i : gaps) {
        auto it = b.lower_bound(i.l);
        if (it == b.end() || it->fi > i.r) {
            cout << "No";
            return 0;
        }

        ret[i.i] = it->se.back();
        it->se.pop_back();
        if (it->se.empty()) b.erase(it);
    }

    cout << "Yes\n";
    for (int i : ret) cout << i << ' ';

    return 0;
}