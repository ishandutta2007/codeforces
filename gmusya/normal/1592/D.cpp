#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Ask(const vector<int>& v) {
    cout << "? ";
    cout << v.size() << ' ';
    for (int x : v) {
        cout << x + 1 << ' ';
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

vector<int> cur;
vector<pair<int, int>> e;
vector<bool> used;
vector<bool> used_v;
vector<vector<int>> g;

void Dfs(int v, int& cnt, int p = -1) {
    used_v[v] = true;
    for (int i : g[v]) {
        if (used[i]) {
            continue;
        }
        int u = (e[i].first ^ e[i].second ^ v);
        if (u != p) {
            if (cnt) {
                cur.emplace_back(i);
                --cnt;
            }
            Dfs(u, cnt, v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e.emplace_back(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }
    used.resize(n - 1);
    vector<int> comp;
    comp.reserve(n);
    for (int v = 0; v < n; ++v) {
        comp.emplace_back(v);
    }
    int answer = Ask(comp);
    int sz = n - 1;
    while (sz != 1) {
        used_v.assign(n, false);
        cur.clear();
        int new_sz = sz / 2;
        int diff = sz - new_sz;
        for (int v = 0; v < n; ++v) {
            if (!used_v[v]) {
                Dfs(v, diff);
            }
        }
        vector<int> values;
        for (int i : cur) {
            int u = e[i].first, v = e[i].second;
            values.push_back(u);
            values.push_back(v);
        }
        sort(values.begin(), values.end());
        values.resize(unique(values.begin(), values.end()) - values.begin());
        int res = Ask(values);
        if (res == answer) {
            sz = 0;
            used.assign(n - 1, true);
            for (int i : cur) {
                used[i] = false;
                ++sz;
            }
        } else {
            for (int i : cur) {
                used[i] = true;
                --sz;
            }
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (!used[i]) {
            cout << "! " << e[i].first + 1 << ' ' << e[i].second + 1 << endl;
            return 0;
        }
    }
    return 0;
}