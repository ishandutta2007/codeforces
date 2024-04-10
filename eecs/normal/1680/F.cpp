#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, n, m, f[maxn];
vector<int> G[maxn];
mt19937 eng(time(0));

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    int cnt, num;
    auto dfs = [&](auto self, int x) -> void {
        for (int i : G[x]) {
            if (!~f[i]) f[i] = !f[x], self(self, i);
            else if (f[i] == f[x]) cnt++, num = !f[i];
        }
    };
    auto chk = [&]() {
        fill(f + 1, f + n + 1, -1);
        for (int i = 1; i <= n; i++) {
            shuffle(G[i].begin(), G[i].end(), eng);
        }
        int rt = eng() % n + 1;
        f[rt] = eng() % 2;
        cnt = num = 0, dfs(dfs, rt);
        if (cnt <= 2) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << (f[i] ^ num);
            cout << "\n";
        }
        return cnt <= 2;
    };
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v), G[v].push_back(u);
        }
        for (int i = 1; i <= 30; i++) {
            if (chk()) goto nxt;
        }
        cout << "NO\n";
    nxt:;
    }
    return 0;
}