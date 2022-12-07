#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, m, mx;
int dist[4][1000][1000];
char s[1000][1001];
int sx, sy, tx, ty;
int qt = 0;

struct S {
    int k, i, j;
    S(int k, int i, int j) : k(k), i(i), j(j) {}
    S() {}
};

S q[4000000], nq[4000000];

inline bool cmpX(const S &lhs, const S &rhs) {
    return lhs.i < rhs.i;
}

inline bool cmpY(const S &lhs, const S &rhs) {
    return lhs.j < rhs.j;
}

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    scanf("%d%d%d", &n, &m, &mx);
    forn(i, n) scanf("%s", s[i]);
    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    --sx, --sy, --tx, --ty;
    memset(dist, -1, sizeof dist);
    forn(i, 4) {
        dist[i][sx][sy] = 0;
        q[qt++] = S(i, sx, sy);
    }
    int newDist = 0;
    while (true) {
        ++newDist;
        int nqt = 0;
        sort(q, q + qt, cmpX);
        for (int dir = 0; dir < 2; ++dir) {
            forn(ind, qt) {
                int k = dir;
                int ii = q[ind].i;
                int j = q[ind].j;
                if (dir == 1) {
                    for (int i = ii + 1; i <= min(ii + mx, n - 1); ++i) {
                        if (dist[k][i][j] != -1 || s[i][j] == '#') {
                            break;
                        }
                        dist[k][i][j] = newDist;
                        nq[nqt++] = S(k, i, j);
                    }
                } else {
                    for (int i = ii - 1; i >= max(ii - mx, 0); --i) {
                        if (dist[k][i][j] != -1 || s[i][j] == '#') {
                            break;
                        }
                        dist[k][i][j] = newDist;
                        nq[nqt++] = S(k, i, j);
                    }
                }
            }
            if (dir == 0) {
                reverse(q, q + qt);
            }
        }
        sort(q, q + qt, cmpY);
        for (int dir = 2; dir < 4; ++dir) {
            forn(ind, qt) {
                int k = dir;
                int i = q[ind].i;
                int jj = q[ind].j;
                if (dir == 3) {
                    for (int j = jj + 1; j <= min(jj + mx, m - 1); ++j) {
                        if (dist[k][i][j] != -1 || s[i][j] == '#') {
                            break;
                        }
                        dist[k][i][j] = newDist;
                        nq[nqt++] = S(k, i, j);
                    }
                } else {
                    for (int j = jj - 1; j >= max(jj - mx, 0); --j) {
                        if (dist[k][i][j] != -1 || s[i][j] == '#') {
                            break;
                        }
                        dist[k][i][j] = newDist;
                        nq[nqt++] = S(k, i, j);
                    }
                }
            }
            if (dir == 2) {
                reverse(q, q + qt);
            }
        }
        if (nqt == 0) {
            break;
        }
        forn(i, nqt) {
            q[i] = nq[i];
        }
        qt = nqt;
    }
    int best = INF;
    forn(i, 4) if (dist[i][tx][ty] != -1) {
        best = min(best, dist[i][tx][ty]);
    }
    if (best == INF) {
        best = -1;
    }
    cout << best << endl;
    return 0;
}