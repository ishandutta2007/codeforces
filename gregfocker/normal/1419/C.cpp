#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

int solve()
{
    int n;
    int x;
    int sum = 0;
    int cnt = 0;

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cnt += (a == x);
        sum += a;
    }
    if (cnt == n)
    {
        return 0;
    }
    if (cnt >= 1)
    {
        return 1;
    }
    if (sum == n * x)
    {
        return 1;
    }
    return 2;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << "\n";
    }
}