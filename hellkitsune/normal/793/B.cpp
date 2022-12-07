#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[1005][1005];
int x, y, xx, yy;
int d[1000][1000][4];
pair<PII, int> q[4000005], nq[4000005];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%s", s[i]);
    }
    forn(i, n) forn(j, m) {
        if (s[i][j] == 'S') {
            x = i;
            y = j;
            s[i][j] = '.';
        }
        if (s[i][j] == 'T') {
            xx = i;
            yy = j;
            s[i][j] = '.';
        }
    }
    memset(d, -1, sizeof d);
    forn(i, 4) {
        d[x][y][i] = 0;
        q[i] = mp(mp(x, y), i);
    }
    int qh = 0, qt = 4;
    while (qt > 0) {
        int nqt = 0;
        qh = 0;
        while (qh < qt) {
            int x = q[qh].first.first;
            int y = q[qh].first.second;
            int odir = q[qh].second;
            ++qh;
            forn(dir, 4) if (dir == odir) {
                int xx = x + dx[dir];
                if (xx < 0 || xx >= n) continue;
                int yy = y + dy[dir];
                if (yy < 0 || yy >= m) continue;
                if (s[xx][yy] == '*' || d[xx][yy][dir] != -1) continue;
                d[xx][yy][dir] = d[x][y][odir];
                q[qt++] = mp(mp(xx, yy), dir);
            }
        }
        forn(qh, qt) {
            int x = q[qh].first.first;
            int y = q[qh].first.second;
            int odir = q[qh].second;
            forn(dir, 4) if (dir != odir) {
                int xx = x + dx[dir];
                if (xx < 0 || xx >= n) continue;
                int yy = y + dy[dir];
                if (yy < 0 || yy >= m) continue;
                if (s[xx][yy] == '*' || d[xx][yy][dir] != -1) continue;
                d[xx][yy][dir] = d[x][y][odir] + 1;
                nq[nqt++] = mp(mp(xx, yy), dir);
            }
        }
        qt = nqt;
        forn(i, qt) q[i] = nq[i];
    }
//    forn(i, 4) cerr << d[xx][yy][i] << endl;
    forn(i, 4) if (d[xx][yy][i] != -1 && d[xx][yy][i] <= 2) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}