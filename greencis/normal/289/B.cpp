#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, d, a[105][105], mn = 1e9;
int cnt[10005];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> d;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j], mn = min(mn, a[i][j]);
    int sum = 0;
    int sum2 = 0;
    int cnt1 = n * m;
    int cnt2 = 0;
    int ans = 1e9;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            a[i][j] -= mn;
            if (a[i][j] % d) {
                cout << "-1";
                return 0;
            }
            ++cnt[a[i][j] / d];
            sum += a[i][j] / d;
        }

    ans = sum;
    for (int i = 1; i <= 10000; ++i) {
        sum -= cnt1 - cnt[i - 1];
        cnt1 -= cnt[i - 1];
        cnt2 += cnt[i - 1];
        sum2 += cnt2;
        ans = min(ans, sum + sum2);
    }
    cout << ans << endl;

    return 0;
}