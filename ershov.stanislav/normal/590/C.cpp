#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define y1 my1

using namespace std;

const int N = 1e3 + 100;
char a[N][N];
int n, m;
int used[N][N];
int curused = 0;
int dist[3][N][N];

void solve(int type) {
    queue<pair<int, int> > q;
    curused++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' + (char) type) {
                q.push(mp(i, j));
                used[i][j] = curused;
                dist[type][i][j] = 0;
            }
        }
    }
    while (sz(q)) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first - 1 >= 0 && a[cur.first - 1][cur.second] != '#') {
            if (used[cur.first - 1][cur.second] < curused) {
                used[cur.first - 1][cur.second] = curused;
                q.push(mp(cur.first - 1, cur.second));
                dist[type][cur.first - 1][cur.second] = dist[type][cur.first][cur.second] + 1;
            }
        }
        if (cur.first + 1 < n && a[cur.first + 1][cur.second] != '#') {
            if (used[cur.first + 1][cur.second] < curused) {
                used[cur.first + 1][cur.second] = curused;
                q.push(mp(cur.first + 1, cur.second));
                dist[type][cur.first + 1][cur.second] = dist[type][cur.first][cur.second] + 1;
            }
        }
        if (cur.second - 1 >= 0 && a[cur.first][cur.second - 1] != '#') {
            if (used[cur.first][cur.second - 1] < curused) {
                used[cur.first][cur.second - 1] = curused;
                q.push(mp(cur.first, cur.second - 1));
                dist[type][cur.first][cur.second - 1] = dist[type][cur.first][cur.second] + 1;
            }
        }
        if (cur.second + 1 < m && a[cur.first][cur.second + 1] != '#') {
            if (used[cur.first][cur.second + 1] < curused) {
                used[cur.first][cur.second + 1] = curused;
                q.push(mp(cur.first, cur.second + 1));
                dist[type][cur.first][cur.second + 1] = dist[type][cur.first][cur.second] + 1;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                dist[k][i][j] = 1e8;
            }
        }
    }
    solve(0);
    solve(1);
    solve(2);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                int cur = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
                cur -= 2;
                if (cur == -2) {
                    cout << "greger";
                }
                ans = min(ans, cur);
            }
        }
    }
    int mn1 = INF, mn2 = INF, mn3 = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                mn2 = min(mn2, dist[1][i][j] - 1);
                mn3 = min(mn3, dist[2][i][j] - 1);
            }
        }
    }
    ans = min(ans, mn3 + mn2);
    mn1 = INF, mn2 = INF, mn3 = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '2') {
                mn1 = min(mn1, dist[0][i][j] - 1);
                mn3 = min(mn3, dist[2][i][j] - 1);
            }
        }
    }
    ans = min(ans, mn1 + mn3);
    mn1 = INF, mn2 = INF, mn3 = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '3') {
                mn1 = min(mn1, dist[0][i][j] - 1);
                mn2 = min(mn2, dist[1][i][j] - 1);
            }
        }
    }
    ans = min(ans, mn1 + mn2);
    if (ans < 1e7) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}