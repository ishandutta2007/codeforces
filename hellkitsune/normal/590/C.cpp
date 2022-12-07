#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[1005][1005];
int dist[3][1005][1005];
queue<PII> q;

void bfs(int (&dist)[1005][1005]) {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int d = dist[y][x] + 1;
        q.pop();
        if (y > 0 && s[y - 1][x] != '#' && dist[y - 1][x] < 0) {
            dist[y - 1][x] = d;
            q.push(mp(y - 1, x));
        }
        if (y < n - 1 && s[y + 1][x] != '#' && dist[y + 1][x] < 0) {
            dist[y + 1][x] = d;
            q.push(mp(y + 1, x));
        }
        if (x > 0 && s[y][x - 1] != '#' && dist[y][x - 1] < 0) {
            dist[y][x - 1] = d;
            q.push(mp(y, x - 1));
        }
        if (x < m - 1 && s[y][x + 1] != '#' && dist[y][x + 1] < 0) {
            dist[y][x + 1] = d;
            q.push(mp(y, x + 1));
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    for (char x = '1'; x <= '3'; ++x) {
        int ind = x - '1';
        REP(i, n) REP(j, m) if (s[i][j] == x) {
            dist[ind][i][j] = 0;
            q.push(mp(i, j));
        } else {
            dist[ind][i][j] = -1;
        }
        bfs(dist[ind]);
    }
    int ans = 12341234;
    REP(i, n) REP(j, m) if (s[i][j] == '.' && dist[0][i][j] >= 0 && dist[1][i][j] >= 0 && dist[2][i][j] >= 0) {
        int tot = 0;
        REP(k, 3) tot += dist[k][i][j];
        tot -= 2;
        ans = min(ans, tot);
    }
    int x = 0, y = 1, z = 2;
    REP(times, 3) {
        char c = '1' + x;
        REP(i, n) REP(j, m) if (s[i][j] == c) {
            dist[0][i][j] = 0;
            q.push(mp(i, j));
        } else {
            dist[0][i][j] = -1;
        }
        bfs(dist[0]);
        int minA = 12341234, minB = 12341234;
        char cy = '1' + y;
        char cz = '1' + z;
        REP(i, n) REP(j, m) if (s[i][j] == cy && dist[0][i][j] >= 0) {
            minA = min(minA, dist[0][i][j]);
        } else if (s[i][j] == cz && dist[0][i][j] >= 0) {
            minB = min(minB, dist[0][i][j]);
        }
        ans = min(ans, minA + minB - 2);
        int tmp = x;
        x = y;
        y = z;
        z = tmp;
    }
    if (ans > 12341230) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}