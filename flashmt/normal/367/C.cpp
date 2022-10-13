#include <bits/stdc++.h>
using namespace std;

int ok(int m, int n)
{
    if (m % 2) return (m - 1LL) * m / 2 + 1 <= n;
    return (m - 1LL) * m / 2 + (m / 2) <= n;
}

int main()
{
    int n, m, x, a[100100];
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> x >> a[i];
    sort(a, a + m, greater <int>());
    
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        if (ok(i, n)) ans += a[i - 1];
    
    cout << ans << endl;
}