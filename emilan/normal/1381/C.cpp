#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, x, y;
        cin >> n >> x >> y;
        vt<int> a(n);
        vt<vt<int>> pos(n + 2);
        vt<set<int>> cnt(n + 1);
        int mxcnt = 0;
        rep(i, n) {
            cin >> a[i];

            int len = sz(pos[a[i]]);
            if (len) cnt[len].erase(a[i]);
            cnt[len + 1].insert(a[i]);
            mxcnt = max(mxcnt, len + 1);

            pos[a[i]].pb(i);
        }

        int unused = 1;
        for (; unused < n + 1 && !pos[unused].empty(); unused++);

        vt<int> ans(n), t;
        rep(i, x) {
            int idx = pos[*cnt[mxcnt].begin()].back();
            pos[*cnt[mxcnt].begin()].pop_back();

            ans[idx] = a[idx];

            if (mxcnt > 1) cnt[mxcnt - 1].insert(*cnt[mxcnt].begin());
            cnt[mxcnt].erase(cnt[mxcnt].begin());
            while (mxcnt && cnt[mxcnt].empty()) mxcnt--;
        }

        if (x != n) {
            vt<int> t, idx, fi;

            for (int i : pos[*cnt[mxcnt].begin()]) {
                fi.pb(a[i]);
                t.pb(i);
            }
            cnt[mxcnt].erase(cnt[mxcnt].begin());

            for (;;) {
                while (mxcnt && cnt[mxcnt].empty()) mxcnt--;
                if (!mxcnt) break;

                for (int i : pos[*cnt[mxcnt].begin()]) {
                    fi.pb(a[i]);
                    idx.pb(i);
                }
                cnt[mxcnt].erase(cnt[mxcnt].begin());
            }

            idx.insert(idx.end(), all(t));
            int i = 0, j = 0;
            rep(r, n - x) {
                if (r < y - x) {
                    while (j < sz(fi) && a[idx[i]] == fi[j]) j++;
                    if (j == sz(fi)) break;
                    ans[idx[i++]] = fi[j++];
                } else ans[idx[i++]] = unused;
            }
            if (i != sz(idx)) {
                cout << "NO\n";
                continue;
            }
        }

        cout << "YES\n";
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }

}