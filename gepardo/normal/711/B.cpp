#include <iostream>
#define int long long

using namespace std;

int n, m;
int a[1000][1000];
int sx, sy;

main()
{
    cin >> n;
    if (n == 1) { cout << 1; return 0; }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0) sx = i, sy = j;
        }
    int sr = (sx == 0) ? 1 : 0;
    int ssr = 0, ssx = 0;
    for (int i = 0; i < n; i++)
        ssr += a[sr][i],
        ssx += a[sx][i];
    a[sx][sy] = ssr - ssx;
    if (a[sx][sy] <= 0) { cout << -1; return 0; }
    for (int i = 0; i < n; i++)
    {
        int q = 0, w = 0;
        for (int j = 0; j < n; j++)
            q += a[i][j],
            w += a[j][i];
        if (q != ssr || w != ssr) { cout << -1; return 0; }
    }
    int q = 0, w = 0;
    for (int i = 0; i < n; i++)
        q += a[i][i],
        w += a[n - i - 1][i];
    if (q != ssr || w != ssr) { cout << -1; return 0; }
    cout << a[sx][sy];
    return 0;
}