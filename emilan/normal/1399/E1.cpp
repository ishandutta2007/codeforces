#include <functional>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

struct Seg {
    int weight, cnt;
    bool operator<(const Seg& o) const {
        return (weight + 1) / 2ll * cnt < (o.weight + 1) / 2ll * o.cnt;
    }
};

int main() {
    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 1; i < n; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            x--, y--;
            adj[x].emplace_back(y, w);
            adj[y].emplace_back(x, w);
        }

        multiset<Seg> we;
        long long sum = 0;
        vector<bool> vis(n);
        vis[0] = true;
        function<int(int)> dfs = [&](int x) {
            if (x && adj[x].size() == 1) return 1;
            int cnt = 0;
            for (auto& i : adj[x]) {
                if (vis[i.first]) continue;
                vis[i.first] = true;
                int de = dfs(i.first);
                cnt += de;
                we.insert({i.second, de});
                sum += (long long)i.second * de;
            }
            return cnt;
        };
        dfs(0);

        int mv = 0;
        while (sum > s) {
            auto it = --we.end();
            sum -= (it->weight + 1) / 2ll * it->cnt;

            auto cur = *it;
            we.erase(it);

            cur.weight /= 2;
            we.insert(cur);
            mv++;
        }
        cout << mv << '\n';
    }
}