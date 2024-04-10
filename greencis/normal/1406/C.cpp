#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;

vector<int> g[100100];
int sz[100100], pred[100100], leaf[100100];

int dfs(int v, int p = -1) {
    sz[v] = 1;
    pred[v] = p;
    int lf = v;
    for (int to : g[v]) {
        if (to == p) continue;
        lf = dfs(to, v);
        sz[v] += sz[to];
    }
    leaf[v] = lf;
    return lf;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1);
        bool good = false;
        for (int i = 1; i <= n; ++i) {
            if (sz[i] * 2 == n) {
                int lf = leaf[i];
                int plf = pred[leaf[i]];
                int pszi = pred[i];
                cout << lf << ' ' << plf << '\n';
                cout << lf << ' ' << pszi << '\n';
                good = true;
                break;
            }
        }
        if (!good) {
            cout << "1 " << g[1][0] << '\n';
            cout << "1 " << g[1][0] << '\n';
        }
    }
}