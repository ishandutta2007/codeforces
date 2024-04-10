#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a[2005];
ld ans;
ll dp2[5005],dp[10505];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ++dp2[a[j] - a[i]];
    for (int i = 0; i < 5005; ++i)
        for (int j = 0; j < 5005; ++j)
            dp[i + j] += dp2[i] * dp2[j];
    for (int i = 0; i < 10505; ++i)
        for (int j = i + 1; j < 5005; ++j)
            ans += (ld)dp2[j] * (ld)dp[i];
    cerr << ans << endl;
    cout << setprecision(17) << fixed << ans / ld(n) / ld(n) / ld(n) / ld(n-1) / ld(n-1) / ld(n-1) * 8;

    return 0;
}