#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

unordered_set<int> g[100100];
int used[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    for (int tst = 1; tst <= ttt; ++tst) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].insert(y);
            g[y].insert(x);
        }
        if (k * ll(k - 1) / 2 > m) {
            cout << "-1\n";
            continue;
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 1; i <= n; ++i)
            if ((int)g[i].size() <= k - 1)
                q.emplace(g[i].size(), i);
        bool found_clique = false;
        while (!q.empty() && k * ll(k - 1) / 2 <= m) {
            int cur = q.top().second;
            q.pop();
            //cerr << cur << " " << g[cur].size() << endl;
            if (used[cur] == tst) continue;
            if ((int)g[cur].size() > k - 1) continue;
            if ((int)g[cur].size() == k - 1) {
                vector<int> neighbors = vector<int>(all(g[cur]));
                neighbors.push_back(cur);
                random_shuffle(all(neighbors));
                bool good = true;
                for (int i = 0; i < k && good; ++i) {
                    int ni = neighbors[i];
                    for (int j = i + 1; j < k; ++j) {
                        int nj = neighbors[j];
                        if (g[ni].find(nj) == g[ni].end()) {
                            good = false;
                            break;
                        }
                    }
                }
                if (good) {
                    found_clique = true;
                    cout << "2\n";
                    for (int x : neighbors)
                        cout << x << ' ';
                    cout << "\n";
                    break;
                }
            }
            used[cur] = tst;
            for (int to : g[cur]) {
                g[to].erase(cur);
                q.emplace(g[to].size(), to);
                --m;
            }
            g[cur].clear();
        }
        if (found_clique) continue;
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (used[i] != tst)
                ans.push_back(i);
        }
        if (ans.empty() || k * ll(k - 1) / 2 > m) cout << "-1\n";
        else {
            cout << "1 " << ans.size() << "\n";
            for (int x : ans)
                cout << x << ' ';
            cout << "\n";
        }
    }
}