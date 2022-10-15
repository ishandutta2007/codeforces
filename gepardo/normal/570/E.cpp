#include <iostream>
#include <algorithm>

using namespace std;

const int mod = (int)1e9 + 7;

int n, m;
char a[600][600];
unsigned int f[600][600], pf[600][600];
int ans = 0;

inline char q(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    return a[i][j];
}

inline char Q(int i, int j)
{
    i = n - 1 - i, j = m - 1 - j;
    if (i < 0 || j < 0 || i >= n || j >= m) return -1;
    return a[i][j];
}

inline void addPaths(int i, int j, int k, int l, int p)
{
    if (!p) return;
    bool ok = false;
    if (i + k == n - 1 && j + l == m - 1) ok = true;
    if (i + k == n - 2 && j + l == m - 1) ok = true;
    if (i + k == n - 1 && j + l == m - 2) ok = true;
    if (!ok) return;
    ans += p, ans %= mod;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            for (int k = 0; k < min(n, i + j + 1); k++)
                pf[j][k] = f[j][k];
        for (int j = 0; j < m; j++)
            for (int k = 0; k < min(n, i + j + 1); k++)
            {
                int l = i + j - k;
                f[j][k] = 0;

                if (q(i, j) != Q(k, l)) continue;

                if (i == 0 && j == 0 && k == 0) f[j][k] = 1;

                if          (k > 0) f[j][k] += pf[j][k - 1];
                                    f[j][k] += pf[j][k];
                if (j > 0 && k > 0) f[j][k] += f[j - 1][k - 1];
                if (j > 0)          f[j][k] += f[j - 1][k];

                f[j][k] %= mod;
            }
        for (int j = 0; j < m; j++)
            for (int k = 0; k < min(n, i + j + 1); k++)
                addPaths(i, j, k, i + j - k, f[j][k]);
    }
    cout << ans;

}