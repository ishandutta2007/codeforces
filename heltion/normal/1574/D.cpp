#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0, c; i < n; i += 1) {
        cin >> c;
        a[i].resize(c);
        for (int& x : a[i]) cin >> x;
    }
    int m;
    cin >> m;
    set<vector<int>> s;
    for (int i = 0; i < m; i += 1) {
        vector<int> b(n);
        for (int& x : b) {
            cin >> x;
            x -= 1;
        }
        s.insert(b);
    }
    priority_queue<pair<int, vector<int>>> pq;
    pair<int, vector<int>> sp;
    for (int i = 0; i < n; i += 1) {
        sp.first += a[i].back();
        sp.second.push_back((int)a[i].size() - 1);
    }
    pq.push(sp);
    set<pair<int, vector<int>>> shit;
    shit.insert(sp);
    while (true) {
        auto up = pq.top();
        pq.pop();
        if (not s.count(up.second)) {
            for (int x : up.second)
                cout << x + 1 << " ";
            return 0;
        }
        for (int i = 0; i < n; i += 1) if (up.second[i]) {
            auto vp = up;
            vp.first += a[i][vp.second[i] - 1] - a[i][vp.second[i]];
            vp.second[i] -= 1;
            if (not shit.count(vp)) {
                pq.push(vp);
                shit.insert(vp);
            }
        }
    }
    return 0;
}