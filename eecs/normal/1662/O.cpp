#include <bits/stdc++.h>
using namespace std;

int T, n, ban1[25][360], ban2[25][360], ok[25][360];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(ok, 0, sizeof(ok));
        memset(ban1, 0, sizeof(ban1));
        memset(ban2, 0, sizeof(ban2));
        while (n--) {
            char op[2];
            int x, y, z;
            scanf("%s %d %d %d", op, &x, &y, &z);
            if (op[0] == 'C') {
                for (int i = y; i ^ z; ++i %= 360) ban1[x][i]++;
            } else {
                for (int i = x; i < y; i++) ban2[i][z]++;
            }
        }
        queue<pair<int, int>> Q;
        auto chk = [&](int x, int y) {
            if (!ok[x][y]) Q.emplace(x, y), ok[x][y] = 1;
        };
        for (int i = 0; i < 360; i++) {
            chk(0, i);
        }
        while (!Q.empty()) {
            auto p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            if (x > 20) continue;
            if (x && !ban1[x][y]) chk(x - 1, y);
            if (!ban1[x + 1][y]) chk(x + 1, y);
            if (!ban2[x][y]) chk(x, (y + 359) % 360);
            if (!ban2[x][(y + 1) % 360]) chk(x, (y + 1) % 360);
        }
        if (count(ok[21], ok[21] + 360, 1)) puts("YES");
        else puts("NO");
    }
    return 0;
}