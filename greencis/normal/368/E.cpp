#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int full(int n) {
    if (n % 2 == 1)
        return n * (n - 1) / 2 + 1;
    return n * n / 2;
}

int n, m, x, p[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> x >> p[i];
    sort(p, p + m, greater<int>());
    int i = min(10000, m);
    for (; i >= 1; --i) {
        int cur = full(i);
        if (cur <= n)
            break;
    }
    ll ans = 0;
    while (i--)
        ans += p[i];
    cout << ans << endl;

    return 0;
}