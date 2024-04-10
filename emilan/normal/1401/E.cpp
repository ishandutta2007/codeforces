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

const int maxd = 1e6, maxn = maxd + 5;
int bit[maxn];

int query0(int i) {
    int r = 0;
    for (i++; i; i -= i & -i) r += bit[i];
    return r;
}
int query(int l, int r) {
    return query0(r - 1) - query0(l - 1);
}

void update(int i, int d) {
    for (i++; i < maxn; i += i & -i) bit[i] += d;
}

struct VertSeg {
    int x, yl, yr;
    bool operator<(const VertSeg &o) const {
        return x < o.x;
    }
};

void solve() {
    update(0, 1);
    update(maxd, 1);

    int n, m;
    cin >> n >> m;
    vt<pii> hori_l, hori_r;
    while (n--) {
        int y, xl, xr;
        cin >> y >> xl >> xr;
        
        if (xl == 0) {
            update(y, 1);
            hori_l.emplace_back(xr + 1, y);
        } else {
            hori_r.emplace_back(xl, y);
        }
    }
    sort(all(hori_l));
    sort(all(hori_r));

    vt<VertSeg> vert(m);
    for (auto &s : vert) cin >> s.x >> s.yl >> s.yr;
    sort(all(vert));
    vert.push_back({maxd, 0, maxd});

    ll ans = 0;
    int ln = sz(hori_l), rn = sz(hori_r);
    int li = 0, ri = 0;
    set<int> ready;
    for (auto &s : vert) {
        for (; li < ln && hori_l[li].fi <= s.x; li++) {
            update(hori_l[li].se, -1);
        }

        for (; ri < rn && hori_r[ri].fi <= s.x; ri++) {
            ready.insert(hori_r[ri].se);
        }

        if (s.yl == 0) {
            ans += query(1, s.yr + 1);

            while (!ready.empty() && *ready.begin() <= s.yr) {
                update(*ready.begin(), 1);
                ready.erase(ready.begin());
            }
        } else {
            ans += query(s.yl, maxd);

            while (!ready.empty() && *ready.rbegin() >= s.yl) {
                update(*ready.rbegin(), 1);
                ready.erase(--ready.end());
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}