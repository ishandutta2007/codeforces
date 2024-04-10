#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (LL& ai : a) cin >> ai;
    LL ans = 0, pre = 0;
    for (int i = 0; i < n; i += 1) {
        queue<int> q;
        vector<int> p(n, -1);
        set<int> s;
        for (int i = 0; i < n; i += 1)
            s.insert(i);
        for (int i = 0; i < n; i += 1)
            if (b[i] == 0) {
                q.push(i);
                s.erase(i);
            }
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            for (auto it = s.begin(); it != s.end();)
                if (b[*it] and b[*it] % a[u] == 0) {
                    q.push(*it);
                    p[*it] = u;
                    it = s.erase(it);
                }
                else it = next(it);
        }
        LL x = -1, y = LLONG_MAX;
        for (int i = 0; i < n; i += 1) if (not s.contains(i)) {
            LL py = (pre / a[i] + 1) * a[i];
            if (y > py) {
                x = i;
                y = py;
            }
        }
        function<void(int)> DFS = [&](int u) {
            if (p[u] == -1) return;
            DFS(p[u]);
            b[p[u]] = b[u];
        };
        DFS(x);
        ans += y;
        pre = b[x] = y;
        //cout << x << " " << y << "\n";
    }
    cout << ans;
}