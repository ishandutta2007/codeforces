#include <bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;

int n, m, k, x, y, z;
vector<int> e[N], d[N];
int ans[N], v[N], u[N];


int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &z);
            e[x].push_back(y);
            d[x].push_back(z);
            e[y].push_back(x);
            d[y].push_back(z);
        }

        memset(ans, 0x7f, sizeof(ans));
        memset(v, 0, sizeof(v));
        memset(u, 0, sizeof(u));
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            for (int j = 0; j < e[x].size(); j++) {
                ans[e[x][j]] = min(ans[e[x][j]], d[x][j]);
                u[e[x][j]] = 1;
            }
            v[x] = 1;
        }


        int res = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        if (!v[i] && u[i] && ans[i] < 1e9 + 7) {
            res = min(res, ans[i]);
        }
        if (res != 1e9 + 7) cout << res << endl;
        else cout << -1 << endl;
    }
}