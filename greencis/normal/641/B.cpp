#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, q;
int t[10005], x[10005], y[10005], z[10005];
int a[105][105];

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = 0;

    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> x[i];
        if (t[i] == 3) cin >> y[i] >> z[i];
    }

    for (int i = q - 1; i >= 0; --i) {
        if (t[i] == 3) {
            a[x[i]][y[i]] = z[i];
        } else if (t[i] == 1) {
            for (int j = m; j >= 1; --j)
                a[x[i]][j + 1] = a[x[i]][j];
            a[x[i]][1] = a[x[i]][m + 1];
        } else {
            for (int j = n; j >= 1; --j)
                a[j + 1][x[i]] = a[j][x[i]];
            a[1][x[i]] = a[n + 1][x[i]];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}