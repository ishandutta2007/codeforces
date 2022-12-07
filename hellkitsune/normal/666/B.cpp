#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

vector<int> g[3000], rev[3000];
int n, m;
int dist[3000][3000], rd[3000][3000];
const int INF = 1e8;
queue<int> q;
vector<int> ans;
int best = -INF;
int mx[3000][5], mxv[3000][5];
int rmx[3000][5], rmxv[3000][5];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        rev[to].pb(from);
    }
    REP(i, n) REP(j, n) dist[i][j] = rd[i][j] = -INF;
    REP(i, n) {
        dist[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) if (dist[i][to] == -INF) {
                dist[i][to] = dist[i][v] + 1;
                q.push(to);
            }
        }
    }
    REP(i, n) {
        rd[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : rev[v]) if (rd[i][to] == -INF) {
                rd[i][to] = rd[i][v] + 1;
                q.push(to);
            }
        }
    }
    REP(i, n) {
        REP(j, 5) mx[i][j] = -INF;
        REP(j, n) if (j != i && dist[i][j] != -INF) {
            REP(k, 5) if (mx[i][k] < dist[i][j]) {
                for (int t = 4; t > k; --t) {
                    mx[i][t] = mx[i][t - 1];
                    mxv[i][t] = mxv[i][t - 1];
                }
                mx[i][k] = dist[i][j];
                mxv[i][k] = j;
                break;
            }
        }
    }
    REP(i, n) {
        REP(j, 5) rmx[i][j] = -INF;
        REP(j, n) if (j != i && rd[i][j] != -INF) {
            REP(k, 5) if (rmx[i][k] < rd[i][j]) {
                for (int t = 4; t > k; --t) {
                    rmx[i][t] = rmx[i][t - 1];
                    rmxv[i][t] = rmxv[i][t - 1];
                }
                rmx[i][k] = rd[i][j];
                rmxv[i][k] = j;
                break;
            }
        }
    }
    REP(i, n) REP(j, n) if (i != j && dist[i][j] != -INF) {
        REP(p, 5) if (rmx[i][p] != -INF) REP(q, 5) if (mx[j][q] != -INF) {
            if (rmxv[i][p] == j || mxv[j][q] == i || rmxv[i][p] == mxv[j][q]) continue;
            int cur = rmx[i][p] + mx[j][q] + dist[i][j];
            if (cur > best) {
                best = cur;
                ans.clear();
                ans.pb(rmxv[i][p]);
                ans.pb(i);
                ans.pb(j);
                ans.pb(mxv[j][q]);
            }
        }
    }
   // printf("%d\n", best);
    for (int x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}