#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, a[305][305];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> g[90005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    int kk = k;
    int dir = 0;
    int x = 1, y = 1;
    int cnt = 0;
    int lft = (k == 1 ? n * m : 2);
    while (cnt < n * m) {
        a[y][x] = k;
        g[k].push_back(y), g[k].push_back(x);
        --lft;
        ++cnt;
        if (!lft)
            --k, lft = (k == 1 ? n * m - cnt : 2);
        x += dx[dir];
        y += dy[dir];
        if (a[y][x] || x <= 0 || x > m || y <= 0 || y > n) {
            x -= dx[dir];
            y -= dy[dir];
            ++dir %= 4;
            x += dx[dir];
            y += dy[dir];
        }
    }

    for (int i = 1; i <= kk; ++i) {
        cout << g[i].size() / 2;
        for (int j : g[i])
            cout << " " << j;
        cout << "\n";
    }

    return 0;
}