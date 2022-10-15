#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = 1000;
const int inf = 123456789;

int n;
int c[maxN][maxN], f[maxN][maxN];
int p[maxN]; queue <int> q;
int s, t;

bool findIncreasingWay()
{
    while (!q.empty()) q.pop();
    for (int i = 0; i < n; i++) p[i] = -1;
    p[s] = 0; q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int i = 0; i < n; i++)
            if (p[i] < 0 && c[v][i] - f[v][i] > 0)
            {
                p[i] = v;
                q.push(i);
            }
    }
    return p[t] >= 0;
}

void findMaxFlow()
{
    while (findIncreasingWay())
    {
        int cf = inf;
        int v = t;
        while (v != s)
        {
            int q = p[v];
            cf = min(cf, c[q][v] - f[q][v]);
            v = q;
        }
        v = t;
        while (v != s)
        {
            int q = p[v];
            f[q][v] += cf;
            f[v][q] -= cf;
            v = q;
        }
    }
}

int main()
{
    int k, m; cin >> k >> m;
    s = 0, t = 2 * k + 1;
    n = 2 * k + 2;
    for (int i = 1; i <= k; i++) cin >> c[s][i];
    for (int i = 1; i <= k; i++) cin >> c[i + k][t];
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        c[a][b + k] = inf;
        c[b][a + k] = inf;
    }
    for (int i = 1; i <= k; i++) c[i][i + k] = inf;
    findMaxFlow();
    for (int i = 1; i <= k; i++) if (c[s][i] != f[s][i]) { cout << "NO"; return 0; }
    for (int i = 1; i <= k; i++) if (c[i + k][t] != f[i + k][t]) { cout << "NO"; return 0; }
    cout << "YES" << endl;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++) cout << f[i][j + k] << " ";
        cout << endl;
    }
}