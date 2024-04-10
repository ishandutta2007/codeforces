#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, m, k;
char s[1000][1005];
int sx, sy;
int dist[1000][1000];
PII q[1000000];

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const char dc[4] = {'D', 'L', 'R', 'U'};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) {
        scanf("%s", s[i]);
    }
    if (k % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    forn(i, n) forn(j, m) if (s[i][j] == 'X') {
        sx = i;
        sy = j;
        s[i][j] = '.';
    }
    forn(i, n) forn(j, m) {
        dist[i][j] = INF;
    }
    dist[sx][sy] = 0;
    q[0] = mp(sx, sy);
    int qh, qt;
    for (qh = 0, qt = 1; qh < qt; ++qh) {
        int x = q[qh].first;
        int y = q[qh].second;
        forn(dir, 4) {
            int xx = x + dx[dir];
            if (xx < 0 || xx >= n) {
                continue;
            }
            int yy = y + dy[dir];
            if (yy < 0 || yy >= m || s[xx][yy] == '*' || dist[xx][yy] != INF) {
                continue;
            }
            dist[xx][yy] = dist[x][y] + 1;
            q[qt++] = mp(xx, yy);
        }
    }
    if (qt == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    string ans;
    int x = sx, y = sy;
    forn(i, k) {
        int rem = k - 1 - i;
        forn(dir, 4) {
            int xx = x + dx[dir];
            if (xx < 0 || xx >= n) {
                continue;
            }
            int yy = y + dy[dir];
            if (yy < 0 || yy >= m || dist[xx][yy] > rem) {
                continue;
            }
            x = xx;
            y = yy;
            ans += dc[dir];
            break;
        }
    }
    assert(dist[x][y] == 0);
    assert(int(ans.size()) == k);
    printf("%s\n", ans.c_str());
    return 0;
}