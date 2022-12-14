#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (auto &v : a) {
        int m;
        cin >> m;
        v.resize(m);
        for (int &x : v) cin >> x;
    }

    int m;
    cin >> m;
    set<vector<int>> banned;
    while (m--) {
        vector<int> v(n);
        for (int &x : v) cin >> x;
        banned.insert(v);
    }

    vector<int> bestest(n);
    for (int i = 0; i < n; i++) {
        bestest[i] = a[i].size();
    }

    vector<int> best(n, 1);
    set<vector<int>> vis{bestest};
    queue<vector<int>> q;
    q.push(bestest);
    while (!q.empty()) {
        vector<int> u = q.front();
        q.pop();

        if (!banned.count(u)) {
            int u_p = 0, best_p = 0;
            for (int i = 0; i < n; i++) {
                u_p += a[i][u[i] - 1];
                best_p += a[i][best[i] - 1];
            }
            if (u_p > best_p) best = u;

            continue;
        }

        for (int i = 0; i < n; i++) {
            if (u[i] == 1) continue;

            vector<int> v(u);
            v[i]--;
            if (!vis.count(v)) {
                q.push(v);
                vis.insert(v);
            }
        }
    }

    for (int x : best) cout << x << ' ';
    cout << '\n';
}