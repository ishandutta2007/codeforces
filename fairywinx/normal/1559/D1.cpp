#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

struct dsu {
    vector<int> p;
    dsu(int n) {
        p.resize(n);
        iota(all(p), 0);
    }

    int get(int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }

    void update(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return;
        p[a] = b;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    for (int i = 0; i < m1; ++i) {
        int a, b;
        cin >> a >> b;
        d1.update(a - 1, b - 1);
    }
    for (int i = 0; i < m2; ++i) {
        int a, b;
        cin >> a >> b;
        d2.update(a - 1, b - 1);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (d1.get(i) != d1.get(j) && d2.get(i) != d2.get(j)) {
                ans.emplace_back(i + 1, j + 1);
                d1.update(i, j);
                d2.update(i, j);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i.first << ' ' << i.second << '\n';
}