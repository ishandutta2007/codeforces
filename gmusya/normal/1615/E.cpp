#pragma GCC optimize("O3")

#include <iostream>
#include <set>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

using ll = long long;

const ll INF = 1e18;

vector<bool> used;
vector<pair<int, int>> to_upd;

void DFS(int v, vi& p, vi& d, vvi& g, int par = -1) {
    for (int u : g[v]) {
        if (u != par) {
            p[u] = v;
            d[u] = d[v] + 1;
            DFS(u, p, d, g, v);
        }
    }
}

void DFS2(int v, int new_d, vvi& g, int par = -1) {
    for (int u : g[v]) {
        if (u == par) {
            continue;
        }
        if (!used[u]) {
            DFS2(u, new_d + 1, g, v);
        }
    }
    to_upd.emplace_back(v, new_d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vvi g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi p(n), d(n);
    DFS(0, p, d, g);
    set<pair<int, int>, greater<>> set;
    for (int v = 0; v < n; ++v) {
        set.insert({d[v], v});
    }
    used.assign(n, false);
    int white = n;
    int blue = n;
    int red = 0;
    ll ans = -INF;
    while (!set.empty() && red < k) {
        int v = set.begin()->second;
        white--;
        red++;
        vi roots;
        if (!used[v]) {
            while (!used[v]) {
                roots.push_back(v);
                used[v] = true;
                v = p[v];
                --blue;
            }
            to_upd.resize(0);
            for (int x : roots) {
                DFS2(x, -1, g, p[x]);
            }
            for (auto& now : to_upd) {
                int u = now.first, w = now.second;
                set.erase({d[u], u});
                d[u] = w;
                set.insert({d[u], u});
            }
        }
        if (red > k) {
            break;
        }
        if (blue <= red) {
            ans = max(ans, (white - blue) * 1ll * (red - blue));
        } else {// minimize (white - x) * (red - x)
            ll L = 0, R = blue;
            ll res = INF;
            while (R - L >= 6) {
                ll M1 = L + (R - L) / 3;
                ll M2 = L + (R - L) * 2 / 3;
                ll F1 = (white - M1) * 1ll * (red - M1);
                ll F2 = (white - M2) * 1ll * (red - M2);
                if (F1 <= F2) {
                    R = M2;
                } else {
                    L = M1;
                }
            }
            for (ll x = L; x <= R; ++x) {
                res = min(res, (white - x) * 1ll * (red - x));
            }
            ans = max(ans, res);
        }
    }
    cout << ans;
    return 0;
}

/*
20 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
1 16
1 17
1 18
1 19
1 20
 */