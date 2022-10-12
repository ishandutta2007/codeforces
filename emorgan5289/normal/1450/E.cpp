#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 205;
int w[N][N], v[N], c[N];
int n;

void dfs(int i) {
    v[i] = 1;
    for (int j = 0; j < n; j++)
        if (w[i][j] != inf) {
            if (v[j] && c[i] == c[j])
                cout << "NO\n", exit(0);
            if (!v[j]) c[j] = c[i]^1, dfs(j);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = inf;
    while (m--) {
        int x, y, b; cin >> x >> y >> b; x--, y--;
        if (b) w[x][y] = 1, w[y][x] = -1;
        else w[x][y] = w[y][x] = 1;
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        w[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cmin(w[i][j], w[i][k]+w[k][j]);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (w[i][j] > w[i][k]+w[k][j]) 
                    cout << "NO\n", exit(0);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (w[i][j] > w[x][y])
                x = i, y = j;
    cout << "YES\n" << w[x][y] << "\n";
    for (int i = 0; i < n; i++)
        cout << w[x][i] << " \n"[i == n-1];
}