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

const int inf = 1e9;
const int maxn = 15;
pii dp[1 << maxn][maxn];
bool dp_vis[1 << maxn];

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> box(n);
    vt<vt<bool>> vis(n);
    vt<vt<int>> par_cnt(n);
    vt<vt<pii>> chi(n);
    vt<ll> need(n);
    map<int, pii> num;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        box[i].resize(m);
        vis[i].resize(m);
        par_cnt[i].resize(m);
        chi[i].resize(m, {-1, -1});

        for (int j = 0; j < sz(box[i]); j++) {
            cin >> box[i][j];
            sum += box[i][j];
            need[i] -= box[i][j];
            num[box[i][j]] = {i, j};
        }
    }

    if (sum % n) return void(cout << "no");

    ll target = sum / n;
    for (int i = 0; i < n; i++) {
        need[i] += target;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(box[i]); j++) {
            ll get = need[i] + box[i][j];
            if (get <= inf && get >= -inf && num.count(get)) {
                pii c = num[get];
                if (i == c.fi && j != c.se) continue;

                par_cnt[c.fi][c.se]++;
                chi[i][j] = {c.fi, c.se};
            }
        }
    }

    auto prune = [&](pii u, auto &f) -> void {
        if (par_cnt[u.fi][u.se]) return;

        vis[u.fi][u.se] = true;
        if (pii v = chi[u.fi][u.se]; v != pii{-1, -1}) {
            chi[u.fi][u.se] = {-1, -1};
            par_cnt[v.fi][v.se]--;
            f(v, f);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(box[i]); j++) {
            prune({i, j}, prune);
        }
    }

    auto dfs = [&](pii u, pii ori, int bits, auto &f) -> vt<pii> {
        vt<pii> ret;

        if (bits && u == ori) ret.push_back(u);
        else {
            pii v = chi[u.fi][u.se];
            if (!vis[v.fi][v.se] && ~bits & 1 << v.fi) {
                vis[v.fi][v.se] = true;
                ret = f(v, ori, bits | 1 << v.fi, f);
                if (!ret.empty()) ret.push_back(u);
            }
        }

        return ret;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(box[i]); j++) {
            if (!vis[i][j]) {
                vt<pii> ret = dfs({i, j}, {i, j}, 0, dfs);

                if (!ret.empty()) {
                    int bits = 0;
                    for (pii p : ret) bits |= 1 << p.fi;

                    dp_vis[bits] = true;
                    for (int k = 1; k < sz(ret); k++) {
                        dp[bits][ret[k - 1].fi] = {
                            box[ret[k - 1].fi][ret[k - 1].se],
                            ret[k].fi + 1
                        };
                    }
                }
            }
        }
    }

    for (int i = 0; i < 1 << n; i++) {
        for (int j = i; j && !dp_vis[i]; j = (j - 1) & i) {
            if (dp_vis[i & ~j] && dp_vis[j]) {
                dp_vis[i] = true;
                for (int k = 0; k < n; k++) {
                    if (i & ~j & 1 << k) dp[i][k] = dp[i & ~j][k];
                    else if (j & 1 << k) dp[i][k] = dp[j][k];
                }
            }
        }
    }

    if (!dp_vis[(1 << n) - 1]) cout << "no";
    else {
        cout << "yes\n";

        auto &ret = dp[(1 << n) - 1];
        for (int k = 0; k < n; k++) {
            cout << ret[k].fi << ' ' << ret[k].se << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}