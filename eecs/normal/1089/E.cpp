#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[9][9];
vector<array<int, 2>> path;

int main() {
    scanf("%d", &n);
    function<void(int, int, int)> dfs = [&](int cur, int x, int y) {
        vis[x][y] = 1, path.push_back({x, y});
        if (cur == n) {
            if (x == 8 && y == 8) {
                for (auto &p : path) {
                    printf("%c%d ", p[0] + 'a' - 1, p[1]);
                }
                exit(0);
            }
        } else {
            for (int i = 1; i <= 8; i++) {
                if (!vis[i][y]) dfs(cur + 1, i, y);
            }
            for (int i = 1; i <= 8; i++) {
                if (!vis[x][i]) dfs(cur + 1, x, i);
            }
        }
        vis[x][y] = 0, path.pop_back();
    };
    dfs(0, 1, 1);
    return 0;
}