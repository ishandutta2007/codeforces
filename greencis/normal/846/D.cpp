#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, q, x[250005], y[250005], t[250005], u[505][505];

bool check(int mid) {
    for (int i = 505; i--; )
        for (int j = 505; j--; )
            u[i][j] = 0;
    for (int i = 0; i < q; ++i)
        if (t[i] <= mid)
            u[y[i]][x[i]] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            u[i][j] += u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
    for (int i = k; i <= n; ++i)
        for (int j = k; j <= m; ++j)
            if (u[i][j] - u[i][j - k] - u[i - k][j] + u[i - k][j - k] == k * k)
                return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> q;
    for (int i = 0; i < q; ++i)
        cin >> y[i] >> x[i] >> t[i];

    int L = 0, R = 1000000001;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid))
            R = mid;
        else
            L = mid + 1;
    }
    if (L == 1000000001)
        L = -1;
    cout << L << endl;

    return 0;
}