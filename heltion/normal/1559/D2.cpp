#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> p1(n + 1), p2(n + 1);
    for (int i = 1; i <= n; i += 1) p1[i] = p2[i] = i;
    function<int(vector<int>&, int)> f = [&](vector<int>& p, int u) {
        return p[u] == u ? u : p[u] = f(p, p[u]);
    };
    for (int i = 1; i <= m1; i += 1) {
        int u, v;
        cin >> u >> v;
        p1[f(p1, u)] = f(p1, v);
    }
    for (int i = 1; i <= m2; i += 1) {
        int u, v;
        cin >> u >> v;
        p2[f(p2, u)] = f(p2, v);
    }
    vector<set<int>> mp(n + 1);
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i += 1)
        mp[f(p1, i)].insert(i);
    for (int i = 1; i <= n; i += 1) if (mp[i].size())
        s.insert({mp[i].size(), i});
    vector<pair<int, int>> vp;
    vector<int> v;
    while(s.size() > 1) {
        auto [_x, x] = *s.begin();
        s.erase(s.begin());
        auto [_y, y] = *s.begin();
        s.erase(s.begin());
        int j = *mp[y].begin();
        int ti = 0, tj = 0;
        for (int i : mp[x])
            if (f(p2, i) != f(p2, j)) {
                ti = i;
                tj = j;
                break;
            }
        if (ti) {
            vp.push_back({ti, tj});
            p2[f(p2, ti)] = f(p2, tj);
            for (int i : mp[x])
                if (f(p2, i) != f(p2, j)) mp[y].insert(i);
            s.insert({mp[y].size(), y});
            continue;
        }
        int i = *mp[x].begin();
        mp[x].clear();
        for (auto it = mp[y].begin(); it != mp[y].end(); it = mp[y].erase(it))
            if (f(p2, *it) != f(p2, i)) {
                ti = i;
                tj = *it;
                break;
            }
        if (ti) {
            vp.push_back({ti, tj});
            p2[f(p2, ti)] = f(p2, tj);
            mp[y].insert(i);
            s.insert({mp[y].size(), y});
            continue;
        }
        v.push_back(i);
        v.push_back(j);
    }
    int y = 0;
    if (s.size()) y = s.begin()->second;
    vector<int> u;
    for (int i : v) {
        if (y) {
            int ti = 0, tj = 0, j = *mp[y].begin();
            for (auto it = mp[y].begin(); it != mp[y].end(); it = mp[y].erase(it))
                if (f(p2, *it) != f(p2, i)) {
                    ti = i;
                    tj = *it;
                    break;
                }
            if (ti) {
                vp.push_back({ti, tj});
                p2[f(p2, ti)] = f(p2, tj);
                mp[y].insert(i);
                s.insert({mp[y].size(), y});
                continue;
            }
            u.push_back(i);
            u.push_back(j);
            y = 0;
        }
        else u.push_back(i);
    }
    map<int, int> mpp;
    for (int i : u) mpp[f(p2, i)] = i;
    vector<int> w;
    for (auto [x, y] : mpp) w.push_back(y);
    for (int i = 1; i < (int)w.size(); i += 1) vp.push_back({w[i - 1], w[i]});
    cout << vp.size() << "\n";
    for (auto [x, y] : vp) cout << x << " " << y << "\n";
    return 0;
}