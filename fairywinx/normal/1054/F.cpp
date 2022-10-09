#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int N = 1e3 + 228;

vector<int> G[N];
int used[N];
int par[N];

int timer = 1;

bool kun(int v) {
    if (used[v] == timer)
        return false;
    used[v] = timer;
    for (int i : G[v]) {
        if (par[i] == -1 || kun(par[i])) {
            par[i] = v;
            return true;
        }
    }
    return false;
}

void dfs(int v, set<int> &a) {
    used[v] = timer;
    for (int i : G[v]) {
        a.insert(i);
        if (par[i] != -1 && used[par[i]] != timer)
            dfs(par[i], a);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, vector<int>> c1, c2;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        c1[x].push_back(y);
        c2[y].push_back(x);
    }
    for (auto &i : c1)
        sort(all(i.second));
    for (auto &i : c2)
        sort(all(i.second));
    
    vector<pair<int, int>> v1, v2;
    for (auto x : c1) {
        for (int i = 0; i < (int) x.second.size() - 1; ++i) {
            v1.emplace_back(x.first, i);
        }
    }
    for (auto x : c2) {
        for (int i = 0; i < (int) x.second.size() - 1; ++i) {
            v2.emplace_back(x.first, i);
        }
    }
    sort(all(v1));
    sort(all(v2));
    v1.resize(unique(all(v1)) - v1.begin());
    v2.resize(unique(all(v2)) - v2.begin());

    for (auto x : c1) {
        for (int i = 0; i < (int) x.second.size() - 1; ++i) {
            for (auto y : c2) {
                for (int j = 0; j < (int) y.second.size() - 1; ++j) {
                    if (y.second[j] < x.first && x.first < y.second[j + 1] && x.second[i] < y.first && y.first < x.second[i + 1]) {
                        int v = lower_bound(all(v1), make_pair(x.first, i)) - v1.begin();
                        int u = lower_bound(all(v2), make_pair(y.first, j)) - v2.begin();
                        G[v].push_back(u);
                    }
                }
            }
        }
    }
    fill(par, par + n, -1);
    for (int i = 0; i < n; ++i) {
        if (kun(i))
            ++timer;
    }
    vector<int> good(n, 1);
    ++timer;
    for (int i = 0; i < n; ++i) {
        if (par[i] != -1)
            good[par[i]] = 0;
    }
    set<int> Y;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            dfs(i, Y);
        }
    }
    set<int> X;
    for (int i = 0; i < n; ++i) {
        if (used[i] != timer)
            X.insert(i);
    }
    vector<array<int, 4>> ans;
    for (auto x : c2) {
        int lstX = x.second[0];
        for (int i = 0; i < (int) x.second.size(); ++i) {
            if (Y.count(lower_bound(all(v2), make_pair(x.first, i)) - v2.begin()) || i + 1 == (int) x.second.size()) {
                ans.push_back({lstX, x.first, x.second[i], x.first});
                if (i + 1 != (int) x.second.size())
                    lstX = x.second[i + 1];
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    ans.clear();
    for (auto x : c1) {
        int lstX = x.second[0];
        for (int i = 0; i < (int) x.second.size(); ++i) {
            if (X.count(lower_bound(all(v1), make_pair(x.first, i)) - v1.begin()) || i + 1 == (int) x.second.size()) {
                ans.push_back({x.first, lstX, x.first, x.second[i]});
                if (i + 1 != (int) x.second.size())
                    lstX = x.second[i + 1];
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}