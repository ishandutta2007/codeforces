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

const int inf = 1 << 30;

struct Seg {
    int l, r;
    bool operator<(const Seg &o) const {
        return r == o.r ? l > o.l : r < o.r;
    }
    bool operator==(const Seg &o) const {
        return !(*this < o) && !(o < *this);
    }
};

void solve() {
    int n;
    cin >> n;
    map<Seg, int> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[{x, y}] = 1;
    }

    auto f = [&](Seg seg_cur) {
        vt<pii> cnt{{0, 0}};
        for (auto p : m) {
            Seg seg = p.fi;
            if (seg.l < seg_cur.l
                    || seg.r > seg_cur.r
                    || seg == seg_cur) {
                continue;
            }

            auto it = lower_bound(all(cnt), pii{seg.l, -inf});
            it--;
            int new_cnt = it->se + p.se;
            if (new_cnt > cnt.back().se) {
                if (cnt.back().fi == seg.r) cnt.pop_back();
                cnt.emplace_back(seg.r, new_cnt);
            }
        }

        return cnt.back().se;
    };

    for (auto &p : m) {
        p.se = f(p.fi) + 1;
    }

    cout << f({1, inf}) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}