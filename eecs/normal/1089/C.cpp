#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, d[maxn][maxn];
bool mark[maxn];
vector<int> G[maxn], ok[maxn][maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    while (m--) {
        int k, lst = 0;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            if (lst) G[x].push_back(lst), G[lst].push_back(x), d[x][lst] = d[lst][x] = 1;
            lst = x;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<int> cand;
    for (int $ = 1; $ <= n; $++) {
        fill(mark + 1, mark + n + 1, 1);
        for (int iter = 1; ; iter++) {
            if (iter > 10) assert(0);
            int mn = INT_MAX, u = 0, v;
            for (int i = 1; i <= n; i++) if (mark[i]) {
                cand.clear();
                for (int j = 1; j <= n; j++) {
                    if (mark[j]) ok[i][j].clear(), cand.push_back(j);
                }
                int mx = 0;
                for (int j : G[i]) if (mark[j]) {
                    int cnt = 0;
                    for (int k : cand) if (d[j][k] < d[i][k]) {
                        ok[i][k].push_back(j), cnt++;
                    }
                    mx = max(mx, cnt);
                }
                if (mx < mn) u = i, mn = mx;
            }
            cout << u << endl;
            string str;
            cin >> str;
            if (str == "FOUND") break;
            cin >> v;
            for (int i = 1; i <= n; i++) {
                if (mark[i] && !count(ok[u][i].begin(), ok[u][i].end(), v)) mark[i] = 0;
            }
        }
    }
    return 0;
}