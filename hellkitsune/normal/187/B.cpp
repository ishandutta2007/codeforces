#include <iostream>
#include <algorithm>

using namespace std;

const int inf = (int)1e9;

int n, m, r;
int a[60][60][60];
int t[60][60][60], tt[60][60];

int main(void)
{
    cin >> n >> m >> r;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cin >> a[i][j][k];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            t[0][i][j] = inf;
    for (int z = 0; z < m; ++z)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tt[i][j] = a[z][i][j];
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    tt[i][j] = min(tt[i][j], tt[i][k] + tt[k][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                t[0][i][j] = min(t[0][i][j], tt[i][j]);
    }
    for (int z = 1; z <= n; ++z)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                t[z][i][j] = t[z - 1][i][j];
                for (int k = 0; k < n; ++k)
                    t[z][i][j] = min(t[z][i][j], t[z - 1][i][k] + t[0][k][j]);
            }
    }
    int ss, ttt, k;
    for (int i = 0; i < r; ++i)
    {
        cin >> ss >> ttt >> k; --ss; --ttt;
        cout << t[min(k, n)][ss][ttt] << endl;
    }
    return 0;
}