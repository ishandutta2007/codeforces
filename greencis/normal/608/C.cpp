#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n, dp[2001005];
pii a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int idx = 0;
    for (int i = 0; i < 2001005; ++i) {
        if (idx < n && a[idx].first == i) {
            dp[i] = 1 + (i - a[idx].second - 1 >= 0 ? dp[i - a[idx].second - 1] : 0);
            ++idx;
        } else if (i > 0) dp[i] = dp[i-1];
    }
    int ans = n;
    for (int i = 0; i < 2001005; ++i)
        ans = min(ans, n - dp[i]);
    cout << ans;

    return 0;
}