#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int N = 1e6 + 228;

vector<int> G[N];
vector<int> _G[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        _G[b - 1].push_back(a - 1);
    }

    vector<int> dist(n, N);
    int s, t;
    cin >> s >> t;
    --s, --t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, t);
    dist[t] = 0;
    vector<int> used(n);
    vector<int> cnt(n);
    while (q.size()) {
        int v = q.top().second;
        q.pop();
        if (used[v])
            continue;
        used[v] = 1;
        for (auto i : _G[v]) {
            if (dist[i] > dist[v] + 1) {
                q.emplace(dist[v] + 1, i);
                dist[i] = dist[v] + 1;
            }
            ++cnt[i];
            if (cnt[i] == (int) G[i].size()) {
                bool c = true;
                for (auto j : G[i]) {
                    if (dist[j] != dist[v]) {
                        c = false;
                    }
                }

                if (c) {
                    dist[i] = dist[v];
                    q.emplace(dist[i], i);
                }
            }
        }
    }
    if (dist[s] == N) {
        cout << -1 << '\n';
    } else {
        cout << dist[s] << '\n';
    }
}