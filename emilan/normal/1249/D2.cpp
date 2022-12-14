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

struct Segment {
    int l, r, i;
    bool operator<(const Segment& o) const {
        if (l < o.l) return true;
        else if (l == o.l && r > o.r) return true;
        return false;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<Segment> a(n);
    rep(i, n) cin >> a[i].l >> a[i].r, a[i].i = i + 1;
    sort(all(a));

    vi p(200002);
    rep(i, n) p[a[i].l]++, p[a[i].r + 1]--;

    vi ans;
    map<int, vi> seg;
    int cur = 0, i = 0;
    rep(j, sz(p)) {
        cur += p[j];
        while (i != n && a[i].l <= j) {
            seg[a[i].r + 1].pb(a[i].i);
            i++;
        }

        while (cur > k) {
            auto take = seg.rbegin();
            p[take->fi]++;
            ans.pb(take->se.back());
            take->se.pop_back();
            if (take->se.empty()) seg.erase(take->fi);

            cur--;
        }
    }

    cout << sz(ans) << '\n';
    for (int j : ans) cout << j << ' ';

    return 0;
}