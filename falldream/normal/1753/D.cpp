#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 300001
#define ll long long
using namespace std;
inline int read() {
    int x; scanf("%d", &x);
    return x;
}
struct edge{
    int to, next, w;
}e[MN * 3 + 5];
int n, m, P, Q, N, cnt, head[MN + 5];
ll d[MN + 5];
char *s[MN + 5];
const int dis[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > >q;

inline void ins(int f, int t, int w) {
    e[++cnt] = (edge){t, head[f], w}; head[f] = cnt;
}

inline int id(int x, int y) {
    return (x - 1) * m + y;
}

void dij() {
    q.push(make_pair(0LL, N + 1));
    for (int i = 1; i <= N; ++i) d[i] = 1e18;
    while(!q.empty()) {
        int x = q.top().second;
        ll w = q.top().first;
        q.pop();
        if (d[x] != w) continue;
        for(int j = head[x]; j; j = e[j].next) {
            if (w + e[j].w < d[e[j].to]) {
                d[e[j].to] = w + e[j].w;
                q.push(make_pair(d[e[j].to], e[j].to));
            }
        }
    }
}

int main() {
    n = read(); m = read(); P = read(); Q = read(); N = n * m;
    for (int i = 1; i <= n; ++i) {
        s[i] = new char[m + 5];
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '#') continue;
            if (s[i][j] == '.') {
                ins(N + 1, id(i, j), 0);
                continue;
            }
            int x = i, y = j;
            if (s[i][j] == 'U') ++x;
            if (s[i][j] == 'D') --x;
            if (s[i][j] == 'L') ++y;
            if (s[i][j] == 'R') --y;
            for (int k = 0; k < 4; ++k) {
                int xx = x + dis[k][0];
                int yy = y + dis[k][1];
                if (xx == i && yy == j) continue;
                if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
                if (s[xx][yy] == '#') continue;
                int w = (xx == i || yy == j) ? Q : P;
                ins(id(xx, yy), id(i, j), w);
            }
        }
    }
    dij();
    ll ans = 2e18;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '#') continue;
            if (i < n && s[i + 1][j] != '#') ans = min(ans, d[id(i ,j)] + d[id(i + 1, j)]);
            if (j < m && s[i][j + 1] != '#') ans = min(ans, d[id(i, j)] + d[id(i, j + 1)]);
        }
    }
    if (ans >= 1e18) puts("-1");
    else cout << ans;
    return 0;
}