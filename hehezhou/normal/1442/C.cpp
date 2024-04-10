#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
vector < pair < int, int > > son[200010];
int dis1[200010][2];
inline void bfs1() {
    deque < pair < int, int > > dq;
    memset(dis1, 0x3f, sizeof dis1);
    dis1[1][0] = 0;
    dq.push_back({1, 0});
    while (!dq.empty()) {
        int cur = dq.front().first, curd = dq.front().second;
        dq.pop_front();
        for (auto v : son[cur]) {
            int w = v.second ^ curd;
            if (dis1[v.first][v.second] > dis1[cur][curd] + w) {
                dis1[v.first][v.second] = dis1[cur][curd] + w;
                if (v.second) dq.push_back({v.first, v.second});
                else dq.push_front({v.first, v.second});
            }
        }
    }
}
int dis2[200010][2];
inline void bfs2() {
    queue < pair < int, int > > q;
    memset(dis2, -1, sizeof dis2);
    dis2[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        int cur = q.front().first, curd = q.front().second;
        q.pop();
        for (auto v : son[cur]) {
            int w = v.second ^ curd;
            if (dis1[v.first][v.second] == dis1[cur][curd] + w) {
                if (dis2[v.first][v.second] == -1) {
                    dis2[v.first][v.second] = dis2[cur][curd] + 1;
                    q.push({v.first, v.second});
                }
            }
        }
    }
}
int dis3[200010][30];
inline void bfs3() {
    queue < pair < int, int > > q;
    memset(dis3, -1, sizeof dis3);
    dis3[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        int cur = q.front().first, curd = q.front().second;
        q.pop();
        for (auto v : son[cur]) {
            int w = (curd & 1) ^ v.second;
            if (curd + w == 30) continue;
            if (dis3[v.first][w + curd] == -1) {
                dis3[v.first][w + curd] = dis3[cur][curd] + 1;
                q.push({v.first, w + curd});
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back({v, 0});
        son[v].push_back({u, 1});
    }
    bfs1();
    if (dis1[n][0] < 30 || dis1[n][1] < 30) {
        bfs3();
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 30; i++) if (dis3[n][i] != -1) ans = min(ans, dis3[n][i] + (1 << i) - 1);
        printf("%d\n", ans);
    }
    else {
        bfs2();
        int ans = 1;
        int qwq = min(dis1[n][0], dis1[n][1]);
        for (int i = 0; i < qwq; i++) ans = ans * 2 % mod;
        int d = 0x3f3f3f3f;
        if (qwq == dis1[n][0]) d = min(d, dis2[n][0]);
        if (qwq == dis1[n][1]) d = min(d, dis2[n][1]);
        ans--;
        printf("%d\n", (ans + d) % mod);
    }
}