#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MN 1000
#define MX MN * MN
#define MF MX * 4
using namespace std;
int n, m, N, px[MX + 5], py[MX + 5], val[MX + 5], v[MX + 5], p[MX + 5];
int s[MF + 5], Size[MF + 5];
int sr[MF + 5];
int faceid[MN + 5][MN + 5][4], ff;
bool result[MN + 5][MN + 5];

inline int getfa(int x) { return s[x] ? s[x] = getfa(s[x]) : x; }
inline int id(int x, int y) { return (x - 1) * m + y; }
const int dis[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool cmp(const int &a, const int &b) {
    return v[a] < v[b];
}


int Query(int f, int v) {
    int fa = getfa(f);
    // if (r[fa] == f) {
    return (sr[fa] + (v & 1) * Size[fa]) & 1;
    // } else {
        // return (sl[fa] + (v & 1) * Size[fa]) & 1;
    // }
}

void Merge(int x, int y, int v) {
    v &= 1;
    if (x != -1) {
        int fax = getfa(x), fay = getfa(y); 
        if (fax == fay) return;
        s[fax] = fay;
        // sl[fay] = (sl[fax] + (Size[fay] + 1) * v) & 1;
        sr[fay] = (sr[fay] + (Size[fax] + 1) * v) & 1;
        Size[fay] += Size[fax] + 1;
    } else {
        int fay = getfa(y);
        Size[fay] += 1;
        sr[fay] = (sr[fay] + v) & 1;
    }
}

int main() {
    scanf("%d%d", &n, &m); N = n * m;
    for (int i = 1, cnt = 0; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ++cnt; p[cnt] = cnt;
            px[cnt] = i; py[cnt] = j;
            scanf("%d", &v[cnt]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            faceid[i][j][0] = ++ff;
            faceid[i][j][1] = ++ff;
            faceid[i][j][2] = ++ff;
            faceid[i][j][3] = ++ff;
        }
    }
    sort(p + 1, p + N + 1, cmp);
    for (int i = 1; i <= N; ++i) {
        int x = px[p[i]], y = py[p[i]], val = v[p[i]];
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            int xx = x + dis[j][0], yy = y + dis[j][1];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            sum += Query(faceid[xx][yy][j ^ 2], val);
            // printf("%d %d %d %d\n", x, y, j, Query(faceid[x][y][j], val));
        }
        sum &= 1;
        result[x][y] = sum;
        for (int j = 0; j < 4; ++j) {
            int xx = x + dis[j][0], yy = y + dis[j][1];
            if (xx < 1 || yy < 1 || xx > n || yy > m) {
                Merge(-1, faceid[x][y][(j + 2 + sum) & 3], val);
            } else {
                Merge(faceid[xx][yy][j ^ 2], faceid[x][y][(j + 2 + sum) & 3], val);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            putchar(result[i][j] ? '1' : '0');
        }
        if (i < n) puts("");
    }
    return 0;
}