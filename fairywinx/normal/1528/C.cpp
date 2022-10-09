#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>
#include <array>
#include <set>

#define all(a) a.begin(), a.end()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = (1 << 19);

vector<int> G[N];
vector<int> g[N];

int timer = 0;
int tin[N], tout[N];

void dfs_tin(int v) {
    tin[v] = timer++;
    for (int i : g[v])
        dfs_tin(i);

    tout[v] = timer;
}

int ans = 1;
set<int> tmp;
vector<int> del;

int t[2 * N];
int mod[2 * N];

void push(int v) {
    if (mod[v] == -2)
        return;
    t[v * 2 + 1] = mod[v];
    t[v * 2] = mod[v];
    mod[v * 2 + 1] = mod[v];
    mod[v * 2] = mod[v];
    mod[v] = -2;
}

int get(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l)
        return -1;
    if (L <= l && r <= R)
        return t[v];

    push(v);
    int m = (l + r) / 2;
    return max(get(v * 2 + 1, l, m, L, R), get(v * 2, m, r, L, R));
}

void update(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R) {
        t[v] = val;
        mod[v] = val;
        return;
    }

    push(v);
    int m = (l + r) / 2;
    update(v * 2, m, r, L, R, val);
    update(v * 2 + 1, l, m, L, R, val);
    t[v] = max(t[v * 2 + 1], t[v * 2]);
}

int get(int l, int r) {
    return get(1, 0, timer, l, r);
}

void update(int l, int r, int val) {
    update(1, 0, timer, l, r, val);
}

int cnt = 0;

void dfs_solve(int v) {
    int sz = del.size();
    bool upd = false;
    if (get(tin[v], tout[v]) != -1) {
        int c = get(tin[v], tout[v]);
        if (tin[c] <= tin[v] && tin[v] < tout[c]) {
            del.push_back(c);
            update(tin[c], tout[c], -1);
            update(tin[v], tout[v], v);
        }
    } else {
        update(tin[v], tout[v], v);
        upd = true;
        cnt++;
    }

    ans = max(ans, cnt);

    for (int i : G[v]) {
        dfs_solve(i);
    }
    update(tin[v], tout[v], -1);
    if (upd)
        --cnt;
    while (del.size() > sz) {
        update(tin[del.back()], tout[del.back()], del.back());
        del.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    fill (t, t + min(2 * N, 4 * n), -1);
    fill(mod, mod + min(2 * N, 4 * n), -2);
    for (int i = 0; i < n; ++i) {
        G[i].clear();
        g[i].clear();
    }
    timer = 0;
    ans = 1;
    tmp.clear();
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        G[p - 1].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    dfs_tin(0);
    dfs_solve(0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}