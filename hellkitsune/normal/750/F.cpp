#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, h;
vector<int> path;
set<int> nei[500];

bool query(int v, vector<int> &res) {
    res.clear();
    cout << "? " << v << endl;
    int cnt;
    cin >> cnt;
    forn(i, cnt) {
        int x;
        cin >> x;
        res.pb(x);
    }
    if (cnt == 2) {
        cout << "! " << v << endl;
        return true;
    }
    return false;
}

void solve() {
    path.clear();
    forn(i, 500) {
        nei[i].clear();
    }
    cin >> h;
    vector<int> res;
    bool ok = false;
    if (query(1, res)) {
        return;
    }
    for (int x : res) {
        nei[1].insert(x);
    }
    path.pb(1);
    ok = int(res.size()) == 1;
    while (!ok) {
        int v = path.back();
        int u = *nei[v].begin();
        path.pb(u);
        nei[v].erase(nei[v].begin());
        if (query(u, res)) {
            return;
        }
        for (int x : res) {
            if (x == v) {
                continue;
            }
            nei[u].insert(x);
        }
        ok = int(res.size()) == 1;
    }
    ok = false;
    reverse(path.begin(), path.end());
    while (!ok) {
        int v = path.back();
        int u = *nei[v].begin();
        path.pb(u);
        nei[v].erase(nei[v].begin());
        if (query(u, res)) {
            return;
        }
        for (int x : res) {
            if (x == v) {
                continue;
            }
            nei[u].insert(x);
        }
        ok = int(res.size()) == 1;
    }
    int len = (int(path.size()) + 1) / 2;
    while (h - len > 3) {
        path.resize(len);
        ok = false;
        while (!ok) {
            int v = path.back();
            int u = *nei[v].begin();
            path.pb(u);
            nei[v].erase(nei[v].begin());
            if (query(u, res)) {
                return;
            }
            for (int x : res) {
                if (x == v) {
                    continue;
                }
                nei[u].insert(x);
            }
            ok = int(res.size()) == 1;
        }
        len = (int(path.size()) + 1) / 2;
    }
    int v = path[len - 1];
    int u = *nei[v].begin();
    nei[v].erase(nei[v].begin());
    if (query(u, res)) {
        return;
    }
    for (int x : res) {
        if (x == v) {
            continue;
        }
        nei[u].insert(x);
    }
    v = u;
    if (h - len == 2) {
        for (int x : nei[v]) {
            if (query(x, res)) {
                return;
            }
        }
    } else {
        int it = 0;
        for (int x : nei[v]) {
            if (query(x, res)) {
                return;
            }
            vector<int> res2 = res;
            for (int y : res2) {
                if (y == v) {
                    continue;
                }
                if (++it == 4) {
                    cout << "! " << y << endl;
                    return;
                }
                if (query(y, res)) {
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> tt;
    forn(test, tt) {
        solve();
    }
    return 0;
}