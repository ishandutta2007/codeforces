#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int rot, i, j;
    S(int rot, int i, int j) : rot(rot), i(i), j(j) {}
};

int n, m;
char s[1000][1005];
int a[4][1000][1000];
int mask[256];
int dist[4][1000][1000];
queue<S> q;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int dm[4] = {2, 8, 4, 1};

inline int nx(int mask) {
    mask <<= 1;
    if (mask & 16) {
        mask ^= 17;
    }
    return mask;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    //1 - Up
    //2 - Right
    //4 - Down
    //8 - Left
    mask['+'] = 15;
    mask['-'] = 10;
    mask['|'] = 5;
    mask['^'] = 1;
    mask['>'] = 2;
    mask['v'] = 4;
    mask['<'] = 8;
    mask['L'] = 15 - 8;
    mask['R'] = 15 - 2;
    mask['U'] = 15 - 1;
    mask['D'] = 15 - 4;
    mask['*'] = 0;
    REP(i, n) REP(j, m) {
        a[0][i][j] = mask[(unsigned char)s[i][j]];
        REP(k, 3) {
            a[k + 1][i][j] = nx(a[k][i][j]);
        }
    }
    int x, y, xx, yy;
    scanf("%d%d%d%d", &x, &y, &xx, &yy), --x, --y, --xx, --yy;
    memset(dist, -1, sizeof dist);
    dist[0][x][y] = 0;
    q.push(S(0, x, y));
    while (!q.empty()) {
        S s = q.front();
        q.pop();
        REP(rot, 4) {
            int ni = s.i + dy[rot];
            int nj = s.j + dx[rot];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (dist[s.rot][ni][nj] != -1) continue;
            if (!(a[s.rot][s.i][s.j] & dm[rot])) continue;
            if (!(a[s.rot][ni][nj] & dm[rot ^ 1])) continue;
            dist[s.rot][ni][nj] = dist[s.rot][s.i][s.j] + 1;
            q.push(S(s.rot, ni, nj));
        }
        int nrot = s.rot + 1;
        if (nrot == 4) nrot = 0;
        if (dist[nrot][s.i][s.j] == -1) {
            dist[nrot][s.i][s.j] = dist[s.rot][s.i][s.j] + 1;
            q.push(S(nrot, s.i, s.j));
        }
    }
    int ans = -1;
    REP(i, 4) if (dist[i][xx][yy] != -1) {
        if (ans == -1 || dist[i][xx][yy] < ans) {
            ans = dist[i][xx][yy];
        }
    }
    printf("%d\n", ans);
    return 0;
}