#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 200105;

int n, x, y, z;
vector<pii> g[MAXN];
vector<pii> cycle;
int clr[MAXN], pr[MAXN], found_cycle;
ll maxdepth[MAXN];
int in_cycle[MAXN];
ll pref_all[MAXN], suff_all[MAXN];
ll pref_begin[MAXN], suff_begin[MAXN];
ll pref_end[MAXN], suff_end[MAXN];
ll pref_len[MAXN], suff_len[MAXN];

void dfs_cycle(int v, int p = -1) {
    if (found_cycle || clr[v] == 2)
        return;
    pr[v] = p;
    if (clr[v] == 1) {
        int cur = v;
        do {
            in_cycle[cur] = cycle.size() + 1;
            for (pii to : g[cur]) {
                if (to.first == pr[cur]) {
                    cycle.push_back({cur, to.second});
                    break;
                }
            }
            cur = pr[cur];
        } while (cur != v);
        found_cycle = true;
        return;
    }
    clr[v] = 1;
    for (pii to : g[v])
        if (to.first != p)
            dfs_cycle(to.first, v);
    clr[v] = 2;
}

ll dfs_calc_maxdepth(int v, int p = -1) {
    ll ans = 0;
    for (pii to : g[v]) {
        if (to.first == p || in_cycle[to.first])
            continue;
        ans = max(ans, dfs_calc_maxdepth(to.first, v) + to.second);
    }
    maxdepth[v] = ans;
    return ans;
}

ll dist[MAXN];

void dfs(int v, ll cur = 0) {
    if (dist[v] != -1)
        return;
    dist[v] = cur;
    for (pii to : g[v])
        dfs(to.first, cur + to.second);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    dfs_cycle(1);
    for (int i = 1; i <= n; ++i) {
        if (in_cycle[i])
            dfs_calc_maxdepth(i);
    }

    pref_begin[0] = pref_end[0] = pref_all[0] = maxdepth[cycle[0].first];
    pref_len[0] = 0;
    for (int i = 1; i < cycle.size(); ++i) {
        pref_all[i] = max(pref_all[i - 1], pref_begin[i - 1] + cycle[i - 1].second + maxdepth[cycle[i].first]);
        pref_begin[i] = max(maxdepth[cycle[i].first], pref_begin[i - 1] + cycle[i - 1].second);
        pref_len[i] = pref_len[i - 1] + cycle[i - 1].second;
        pref_end[i] = max(pref_end[i - 1], pref_len[i] + maxdepth[cycle[i].first]);
    }

    suff_begin[0] = suff_end[0] = suff_all[0] = 0;
    suff_len[0] = 0;
    for (int i = cycle.size() - 1; i > 0; --i) {
        suff_all[i] = max(suff_all[(i + 1) % cycle.size()], suff_begin[(i + 1) % cycle.size()] + cycle[i].second + maxdepth[cycle[i].first]);
        suff_begin[i] = max(maxdepth[cycle[i].first], suff_begin[(i + 1) % cycle.size()] + cycle[i].second);
        suff_len[i] = suff_len[(i + 1) % cycle.size()] + cycle[i].second;
        suff_end[i] = max(suff_end[(i + 1) % cycle.size()], suff_len[i] + maxdepth[cycle[i].first]);
    }

    ll mx = 9e18;
    int mxi = -1;
    for (int i = 0; i < cycle.size(); ++i) {
        ll cur = max(max(pref_all[i], suff_all[(i + 1) % cycle.size()]), pref_end[i] + suff_end[(i + 1) % cycle.size()]);
        if (cur < mx)
            mx = cur, mxi = i;
    }

    int va = cycle[mxi].first;
    int vb = cycle[(mxi + 1) % cycle.size()].first;
    for (int i = 0; i < g[va].size(); ++i) {
        if (g[va][i].first == vb) {
            g[va].erase(g[va].begin() + i);
            break;
        }
    }
    for (int i = 0; i < g[vb].size(); ++i) {
        if (g[vb][i].first == va) {
            g[vb].erase(g[vb].begin() + i);
            break;
        }
    }

    for (int i = 0; i < MAXN; ++i) dist[i] = -1;
    dfs(1);
    mx = -1;
    mxi = -1;
    for (int i = 1; i <= n; ++i)
        if (dist[i] > mx)
            mx = dist[i], mxi = i;
    for (int i = 0; i < MAXN; ++i) dist[i] = -1;
    dfs(mxi);
    mx = -1;
    mxi = -1;
    for (int i = 1; i <= n; ++i)
        if (dist[i] > mx)
            mx = dist[i], mxi = i;
    cout << mx << endl;

    return 0;
}