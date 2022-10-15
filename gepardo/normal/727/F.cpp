#include <iostream>

using namespace std;

const long long inf = 123456789012345678;

int n, k;
long long a[1000];
long long b[1000000];
long long dl[1000][1000], dr[1000][1000];
long long res[1000][1000], ans[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k; n++;
    a[0] = 0;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];
    for (int i = 0; i <= n; i++) ans[i] = inf;
    for (int p = 0; p < n; p++)
    {
        if (a[p] > 0) continue;
        for (int i = 0; i <= n; i++)
            res[p][i] = dl[p][i] = dr[p][i] = -inf;
        res[p][0] = dl[p][0] = dr[p][0] = 0;
        for (int i = p+1; i < n; i++)
        {
            dl[i][0] = 0;
            for (int j = 1; j <= n; j++)
            {
                dl[i][j] = max(dl[i-1][j], dl[i-1][j-1] + a[i]);
                if (dl[i][j] < 0) dl[i][j] = -inf;
            }
        }
        for (int i = p-1; i >= 0; i--)
        {
            dr[i][0] = 0;
            for (int j = 1; j <= n; j++)
            {
                dr[i][j] = max(dr[i+1][j], dr[i+1][j-1] + a[i]);
                if (dr[i][j] > -a[p]) dr[i][j] = -inf;
            }
        }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n-i-1; j++)
                if (dl[n-1][i] >= 0 && dr[0][j] <= -a[p])
                    res[p][i+j+1] = max(res[p][i+j+1], dr[0][j] + a[p]);
        for (int i = 0; i <= n; i++)
            ans[i] = min(ans[i], -res[p][i]);
    }
    for (int i = 0; i < k; i++)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int m = (l + r + 1) / 2;
            if (ans[m] <= b[i]) l = m; else r = m-1;
        }
        cout << n-l << '\n';
    }
    return 0;
}