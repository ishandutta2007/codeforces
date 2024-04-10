#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <time.h>
#include <random>
#include <bitset>

using namespace std;

const int MAXN = 2e5 + 7;

set <pair <int, int>> ms;

bool tree[MAXN * 4];
int n, m;

int find(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (tree[v]) return -1;

    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;
    int lres = find(v * 2 + 1, tl, tm, l, r);
    if (lres != -1) return lres;
    else return find(v * 2 + 2, tm + 1, tr, l, r);
}

void upd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        tree[v] = true;
        return;
    }

    int tm = (tl + tr) / 2;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p);
    else upd(v * 2 + 2, tm + 1, tr, p);
    tree[v] = (tree[v * 2 + 1] & tree[v * 2 + 2]);
}

bool get(int v, int tl, int tr, int p) {
    if (tl == tr) return tree[v];

    int tm = (tl + tr) / 2;
    if (p <= tm) return get(v * 2 + 1, tl, tm, p);
    else return get(v * 2 + 2, tm + 1, tr, p);
}

int dfs(int u) {
    upd(0, 0, n - 1, u);
    int res = 1;
    int last = -1;
    while (last < n - 1) {
        int v = find(0, 0, n - 1, last + 1, n - 1);
        if (v == -1) break;
        last = v;
        if (ms.find({u, v}) != ms.end()) continue;
        res += dfs(v);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        ms.insert({u - 1, v - 1});
        ms.insert({v - 1, u - 1});
    }

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (!get(0, 0, n - 1, i)) {
            ans.push_back(dfs(i));
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int elem : ans) cout << elem << ' ';
    cout << '\n';

    return 0;
}