#include <functional>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

struct Seg {
    int weight, cnt;
    long long red;
    bool operator<(const Seg& o) const {
        return red < o.red;
    }
};

struct T3 {
    int t, w, c;
};

long long f(int w, int c) {
    return (w + 1) / 2ll * c;
}

int main() {
    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<vector<T3>> adj(n);
        for (int i = 1; i < n; i++) {
            int x, y, w, c;
            cin >> x >> y >> w >> c;
            x--, y--;
            adj[x].push_back({y, w, c});
            adj[y].push_back({x, w, c});
        }

        multiset<Seg> we1, we2;
        long long sum = 0;
        vector<bool> vis(n);
        vis[0] = true;
        function<int(int)> dfs = [&](int x) {
            if (x && adj[x].size() == 1) return 1;
            int cnt = 0;
            for (auto& i : adj[x]) {
                if (vis[i.t]) continue;
                vis[i.t] = true;
                int de = dfs(i.t);
                cnt += de;

                if (i.c == 1) we1.insert({i.w, de, f(i.w, de)});
                else we2.insert({i.w, de, f(i.w, de)});

                sum += (long long)i.w * de;
            }
            return cnt;
        };
        dfs(0);

        for (int i = 0; i < 2; i++) we1.insert({0, 0, 0});
        we2.insert({0, 0, 0});

        auto we1it1 = --we1.end();
        auto we1it2 = we1it1;
        we1it2--;
        auto we2it = --we2.end();

        int mv = 0;
        while (sum > s) {
            if (sum - we1it1->red <= s || we1it1->red +
                max(we1it2->red, f(we1it1->weight / 2, we1it1->cnt)) >
                we2it->red) {
                sum -= we1it1->red;
                auto cur = *we1it1;
                we1.erase(we1it1);
                cur.weight /= 2;
                cur.red = f(cur.weight, cur.cnt);
                we1.insert(cur);

                we1it1 = --we1.end();
                we1it2 = we1it1;
                we1it2--;

                mv++;
            } else {
                sum -= we2it->red;
                auto cur = *we2it;
                we2.erase(we2it);
                cur.weight /= 2;
                cur.red = f(cur.weight, cur.cnt);
                we2.insert(cur);

                we2it = --we2.end();
                mv += 2;
            }
        }
        cout << mv << '\n';
    }
}