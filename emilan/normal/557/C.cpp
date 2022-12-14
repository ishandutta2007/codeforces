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

struct FenTree {
    vi v;

    FenTree(int n) : v(n + 1) {}

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += v[x];
            x -= x & -x;
        }
        return ret;
    }

    void update(int x, int y) {
        while (x < sz(v)) {
            v[x] += y;
            x += x & -x;
        }
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vii a(n);
    rep(i, n) cin >> a[i].fi;
    rep(i, n) cin >> a[i].se;
    sort(all(a));

    vii b(n);
    rep(i, n) b[i] = {a[i].se, i};
    sort(all(b));

    vi idx(n);
    rep(i, n) idx[b[i].se] = i;

    FenTree ftI(n + 1), ftEn(n + 1);
    rep(i, n) ftI.update(i + 1, 1), ftEn.update(i + 1, b[i].fi);

    int mn = 1 << 30, low = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i && a[i - 1].fi == a[i].fi) continue;

        int lowNext = a[i].se;
        ftI.update(idx[i] + 1, -1);
        ftEn.update(idx[i] + 1, ftEn.query(idx[i]) - ftEn.query(idx[i] + 1));
        int cnt = 1;
        for (int j = i + 1; j < n && a[j - 1].fi == a[j].fi; j++) {
            cnt++;
            lowNext += a[j].se;
            ftI.update(idx[j] + 1, -1);
            ftEn.update(idx[j] + 1, ftEn.query(idx[j]) - ftEn.query(idx[j] + 1));
        }

        int rmCnt = max(0, i - cnt + 1);
        int l = 0, r = n;
        while (l < r) {
            int mi = (l + r) / 2;
            if (ftI.query(mi) < rmCnt) l = mi + 1;
            else r = mi;
        }

        mn = min(mn, low + ftEn.query(l));
        low += lowNext;
    }

    cout << mn;

    return 0;
}